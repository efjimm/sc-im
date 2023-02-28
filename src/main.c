/*******************************************************************************
 * Copyright (c) 2013-2021, Andrés Martinelli <andmarti@gmail.com>             *
 * All rights reserved.                                                        *
 *                                                                             *
 * This file is a part of sc-im                                                *
 *                                                                             *
 * sc-im is a spreadsheet program that is based on sc. The original authors    *
 * of sc are James Gosling and Mark Weiser, and mods were later added by       *
 * Chuck Martin.                                                               *
 *                                                                             *
 * Redistribution and use in source and binary forms, with or without          *
 * modification, are permitted provided that the following conditions are met: *
 * 1. Redistributions of source code must retain the above copyright           *
 *    notice, this list of conditions and the following disclaimer.            *
 * 2. Redistributions in binary form must reproduce the above copyright        *
 *    notice, this list of conditions and the following disclaimer in the      *
 *    documentation and/or other materials provided with the distribution.     *
 * 3. All advertising materials mentioning features or use of this software    *
 *    must display the following acknowledgement:                              *
 *    This product includes software developed by Andrés Martinelli            *
 *    <andmarti@gmail.com>.                                                    *
 * 4. Neither the name of the Andrés Martinelli nor the                        *
 *   names of other contributors may be used to endorse or promote products    *
 *   derived from this software without specific prior written permission.     *
 *                                                                             *
 * THIS SOFTWARE IS PROVIDED BY ANDRES MARTINELLI ''AS IS'' AND ANY            *
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED   *
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE      *
 * DISCLAIMED. IN NO EVENT SHALL ANDRES MARTINELLI BE LIABLE FOR ANY           *
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;*
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE       *
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.           *
 *******************************************************************************/

/**
 * \file main.c
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 2021-05-22
 * \brief The main file of sc-im
 * \details This is the main file for sc-im.
 * \see Homepage: https://github.com/andmarti1424/sc-im
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>   // for F_GETFL O_NONBLOCK F_SETFL
#include <locale.h>
#include <wchar.h>
#include <sys/ioctl.h> // for ioctl

#ifndef NO_WORDEXP
#include <wordexp.h>
#endif

#include "main.h"
#include "actions/shift.h"
#include "macros.h"
#include "tui.h"
#include "input.h"
#include "marks.h"
#include "format.h"
#include "maps.h"
#include "yank.h"
#include "file.h"
#include "utils/dictionary.h"
#include "utils/string.h"
#include "history.h"
#include "conf.h"
#include "buffer.h"
#include "cmds/cmds.h"
#include "vmtbl.h"   // for growtbl
#include "actions/filter.h"
#include "graph.h"
#include "sheet.h"

#ifdef UNDO
#include "undo.h"
#endif

#ifdef XLUA
#include "lua.h"
#endif

typedef enum {
    EXPORT_TYPE_NONE,
    EXPORT_TYPE_CSV,
    EXPORT_TYPE_TAB,
    EXPORT_TYPE_MARKDOWN,
    EXPORT_TYPE_PLAINTEXT,
    EXPORT_TYPE_LEN,
} ExportType;

static ExportType export_type = EXPORT_TYPE_NONE;

// global variable to store a session
struct session *session;

// this variable stores the filename passed to sc-im via argv
// by design, if more than one is passed, we keep the last one.
char loadingfile[PATHLEN] = { '\0' };

// app attributes. TODO: should be later added to conf
int calc_order = BYROWS;
char dpoint = '.'; /* Default decimal point character */
char thsep = ','; /* Default thousands separator character */

// check
int changed;
int cellassign;
int arg = 1;
int brokenpipe = FALSE; /* Set to true if SIGPIPE is received */
int optimize  = 0; /* Causes numeric expressions to be optimizedv */
int rndtoeven = 0;
int rowsinrange = 1;
int colsinrange = DEFWIDTH;
FILE * fdoutput;  /* Output file descriptor (stdout or file) */

// used by interp
char line[FBUFLEN];
int linelim = -1;
double eval_result;
char * seval_result;


/* shall_quit is a variable to determinate if sc-im must be closed
 * shall_quit=0 means normal operation of app
 * shall_quit=1 means :q
 * shall_quit=-1 means ERROR or SIGABRT signal
 * shall_quit=2 means :q!
 * TODO: add macros here
 */
int shall_quit = 0;

unsigned int curmode;
unsigned int lastmode;

Buffer * buffer;
Buffer * lastcmd_buffer;
struct history * commandline_history;
struct history * insert_history;
char stderr_buffer[1024] = "";
struct timeval startup_tv, current_tv; /* Runtime timer */

#ifdef AUTOBACKUP
struct timeval lastbackup_tv; /* Last backup timer */
#ifdef HAVE_PTHREAD
#include <pthread.h>
int pthread_exists = 0; /* Return status of pthread_create */
pthread_t fthread;
#endif
#endif

static bool argv_show_usage(const void *);
static bool argv_show_version(const void *);
static bool argv_set_export(const void *);
static void export_to_file(ExportType);

extern graphADT graph;

/**
 * \brief The main() function
 *
 * \details The main() function of sc-im. It is the first function called when
 * the applicaiton is executed.
 *
 * \param[in] argc (argument count) is the number of strings pointed to by argv. This
 * is passed to main() by the system.
 *
 * \param[in] argv (argument vector) is a is a one-dimensional array of strings.
 * Each string is one of the arguments that was passed to the program. The
 * first string is the executable's name. This is passed to main() by
 * the system.
 *
 * \return 0 on success; -1 on errors
 */
int
main(int argc, char **argv) {
    // Define how the file stream should be buffered. Error if unsuccessful.
    if (setvbuf(stderr, stderr_buffer, _IOFBF, STDERRBUF) != 0) {
        fprintf(stderr, "Error setting stderr buffer\n");
        return -1;
    }

    // set up signals so we can catch them
    signals();

#ifdef USELOCALE
    // Set location dependent information. This is used by some libraries.
    //setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "");
#endif

    SC sc = {
        .user_config = map_new(),
    };

    config_init(sc.user_config);

    // Read the main() parameters and set config values as necessary
    read_argv(argc, argv);

    wchar_t stdin_buffer[BUFFERSIZE] = { L'\0' };

    // take this out of here -->
    calc_order = BYROWS;
    prescale = 1.0;
    optimize = 0; // <----

    // create basic structures that will depend on the loaded file
    create_structures();

    // create main session
    session = calloc(1, sizeof(*session));

    /*
     * create a new roman struct for each file passed as argv
     * and attach it to main session
     * DISABLED BY DESIGN
     * readfile_argv(argc, argv);
     */

    /* load file passed as argv to sc-im.
     * if more than one file is passed, consider the last one.
     */
    load_file(strlen(loadingfile) ? loadingfile : NULL);

    /*
     * check if session->cur_doc is NULL (no file passed as argv).
     * if so, create an empty doc with just one sheet
     */
    if (session->cur_doc == NULL) create_empty_wb();

    if (export_type != EXPORT_TYPE_NONE) {
        export_to_file(export_type);
        config_set_bool("quit_afterload", true);
    }

    // if starting tui..
    if (!config_get_bool("nocurses")) {
        // create command line history structure
#ifdef HISTORY_FILE
        commandline_history = (struct history *) create_history(':');
        load_history(commandline_history, ':'); // load the command history file
#endif
#ifdef INS_HISTORY_FILE
        insert_history = (struct history *) create_history('=');
        load_history(insert_history, '='); // load the insert history file
#endif

        // and initiate NCURSES
        ui_start_screen();

#ifdef USECOLORS
        if (get_d_colors_param() == NULL) {
            start_default_ucolors();
        /*
         * in case we decide to change colors
         * this creates a dictionary and stores in it
         * the relationship between macros and the keys values
         * that are defined in .sc files
         */
            set_colors_param_dict();
        }
#endif
    }

    /*
     * If the 'output' parameter is defined, sc-im saves its output to that file.
     * To achieve that, we open the output file and keep it open until exit.
     * otherwise, sc-im will output to stdout.
     */
    if (config_get_string("output") != NULL) {
        fdoutput = fopen(config_get_string("output"), "w+");
        if (fdoutput == NULL) {
            sc_error("Cannot open file: %s.", config_get_string("output"));
            return exit_app(-1);
        }

        if (!config_get_bool("nocurses")) { // WE MUST STOP SCREEN!
            ui_stop_screen();

            // if output is set, nocurses should always be 1 !
            config_set_bool("nocurses", true);
        }
    }

#ifdef XLUA
    doLuainit();
#endif

    /*
     * load_rc. Since we are not sure what people put it their scimrc file,
     * other than configuration variables and mappings,
     * we call the load_rc() routine after session / roman / sheet are alloc'ed.
     */
    load_rc();

    // check input from stdin (pipeline)
    // and send it to interp
    read_stdin();

    // change curmode to NORMAL_MODE
    chg_mode('.');

    // initiate ui
    FILE *f;
    if (!config_get_bool("nocurses")) {
        // we show welcome screen if no spreadsheet was passed to sc-im
        // and no input was sent throw pipeline
        if (!session->cur_doc->name && !wcslen(stdin_buffer)) {
            ui_do_welcome();
            // show mode and cell's details in status bar
            ui_print_mode();
            ui_show_celldetails();
        } else {
            ui_show_header();
            ui_update(TRUE);
        }
    } else {
        f = fopen("/dev/tty", "rw");
        if (f == NULL) sc_error("fatal error loading stdin");
    }

    // handle input from keyboard
    // this should only take place if curses ui
    if (!config_get_bool("nocurses"))
        buffer = buffer_create(0);

    wchar_t nocurses_buffer[BUFFERSIZE];

    // runtime timer
    gettimeofday(&startup_tv, NULL);

    #ifdef AUTOBACKUP
    //gettimeofday(&lastbackup_tv, NULL);
    lastbackup_tv = (struct timeval) {0};
    #endif

    while (!shall_quit && !config_get_bool("quit_afterload")) {
        // save current time for runtime timer
        gettimeofday(&current_tv, NULL);

        // autobackup if it is time to do so
        handle_backup();

        if (!config_get_bool("nocurses")) {
            handle_input(&sc, buffer);
        } else if (fgetws(nocurses_buffer, BUFFERSIZE, f) != NULL) {
            sc_debug("Interp will receive: %ls", nocurses_buffer);
            send_to_interp(nocurses_buffer);
        }

        /*
         * shall_quit=0 means normal operation of app
         * shall_quit=1 means :q
         * shall_quit=-1 means ERROR or ABRT signal
         * shall_quit=2 means :q!
         */
        if (shall_quit == 1 && modcheck()) shall_quit = 0;
    }
    if (config_get_bool("nocurses") && f != NULL) fclose(f);

    return shall_quit == -1 ? exit_app(-1) : exit_app(0);
}


/**
 * \brief Creates the basic structures used by sc-im
 * \return none
 */
void
create_structures(void) {

    // initiate mark array
    create_mark_array();

    // create last command buffer
    lastcmd_buffer = buffer_create(0);

    // create yank list structure
    init_yanklist();

    /* Assign NULL to colformats
    int c;
    for (c = 0; c < COLFORMATS; c++)
        colformat[c] = NULL;
    */

    // init calc chain graph
    graph = GraphCreate();
}


/**
 * \brief read_stdin()
 * \return none
 */
void
read_stdin(void) {
    //sc_debug("reading stdin from pipeline");
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    fd_set savefds = readfds;
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    FILE * f = stdin;
    //FILE * f = fopen("/dev/tty", "rw");
    wchar_t stdin_buffer[BUFFERSIZE] = { L'\0' };

    if (select(1, &readfds, NULL, NULL, &timeout)) {
        //sc_debug("there is data");
        while (f != NULL && fgetws(stdin_buffer, BUFFERSIZE, f) != NULL) {
            sc_debug("Interp will receive: %ls", stdin_buffer);
            send_to_interp(stdin_buffer);
        }
        fflush(f);
    } else {
        //sc_debug("there is NO data");
    }
    readfds = savefds;
    if (f != NULL) fclose(f);

    if ( !freopen("/dev/tty", "rw", stdin)) {
        perror(NULL);
        exit(-1);
    }
    //sc_debug("finish reading");
}


/**
 * \brief Delete basic structures that depend on the loaded files.
 * \return none
 */
void
delete_structures(void) {

    // Free marks array
    free_marks_array();

    // Free yanklist
    free_yanklist();

    // Free custom col formats
    free_formats();

    // Free last_command buffer
    buffer_destroy(lastcmd_buffer);

    //buffer_free_all();

    // Free ranges
    free_ranges();

    // Free filters
    free_filters();

    // Free undo list - from start of list
#ifdef UNDO
    clear_undo_list();
#endif

    // Free deleted ents
    flush_saved();

    // Free calc chain graph
    destroy_graph(graph);

    // Free tbl / sheet / roman / session
    free_session(session);

    // Free custom_colors
    free_custom_colors();

    // Free lua stuff
#ifdef XLUA
    doLuaclose();
#endif

    config_deinit();
}


/**
 * \brief Cleans things up just before exiting the program.
 *
 * \param[in] status
 * \param[out] status
 *
 * \return status is returned unchanged:
 *         return 0 on normal exit.
 *         return -1 on error.
 */
int
exit_app(int status) {
    // free history
    if (!config_get_bool("nocurses")) {

#ifdef HISTORY_FILE
        if (!save_history(commandline_history, "w")) sc_error("Could not save commandline history");
        if (commandline_history != NULL) destroy_history(commandline_history);
#endif

#ifdef INS_HISTORY_FILE
        if (!save_history(insert_history, "a")) sc_error("Could not save input mode history");
        if (insert_history != NULL) destroy_history(insert_history);
#endif
    }

    // wait for autobackup thread to finish, just in case
    #if defined(AUTOBACKUP) && defined(HAVE_PTHREAD)
    if (pthread_exists) pthread_join (fthread, NULL);
    #endif

    // remove backup file
#ifdef AUTOBACKUP
    char * filename = session->cur_doc->name;
    if (filename != NULL && strlen(filename) && backup_exists(filename)) remove_backup(filename);
#endif

    // erase structures
    delete_structures();

    // Free mappings
    del_maps();

    // Erase stdin
    //buffer_destroy(buffer);

    // stop CURSES screen
    if (!config_get_bool("nocurses"))
        ui_stop_screen();

    // close fdoutput
    if (config_get_string("output") != NULL && config_get_string("output")[0] != '\0' && fdoutput != NULL) {
        fclose(fdoutput);
    }

    return status;
}

/**
 * \brief Read command line parameters and store them in a dictionary
 *
 * \details Read parameters passed to sc-im executable and
 * store them in user_conf dictionary.
 *
 * \param[in] argc (argument count) is the number of strings pointed to by
 * argv.
 * \param[in] argv (argument vector) is a one-dimensional array of strings.
 * Each string is one of the arguments that was passed to the program. The
 * first string is the executable's name.
 *
 * \return none
 */
void
read_argv(int argc, char **argv) {
    typedef struct {
        // Takes a void pointer to the arg union, which can be cast to any member type
        bool (*fn)(const void *);
        union {
            const char *s;
            void *v;
            double d;
            int64_t i;
        } arg;
    } FnContainer;

    Map *const arg_map = map_new();

    map_put(arg_map, "--help", &(FnContainer){ .fn = argv_show_usage });
    map_put(arg_map, "--version", &(FnContainer){ .fn = argv_show_version });

    map_put(arg_map, "--export-csv", &(FnContainer){
        .fn = argv_set_export,
        .arg.i = EXPORT_TYPE_CSV,
    });
    map_put(arg_map, "--export-tab", &(FnContainer){
        .fn = argv_set_export,
        .arg.i = EXPORT_TYPE_TAB,
    });
    map_put(arg_map, "--export-txt", &(FnContainer){
        .fn = argv_set_export,
        .arg.i = EXPORT_TYPE_PLAINTEXT,
    });
    map_put(arg_map, "--export-mkd", &(FnContainer){
        .fn = argv_set_export,
        .arg.i = EXPORT_TYPE_MARKDOWN,
    });

    for (int i = 1; i < argc; i++) {
        if (!strncmp(argv[i], "--", 2)) {
            const FnContainer *const container = map_get(arg_map, argv[i]);
            if (container != NULL && container->fn(&container->arg)) {
                config_set_bool("quit_afterload", true);
                break;
            } else {
                config_parse_str(argv[i] + 2, 0);
            }
        } else {
            strncpy(loadingfile, argv[i], PATHLEN-1);
        }
    }

    map_free(arg_map);
}

bool
argv_set_export(const void *v) {
    const int64_t *const type = v;
    export_type = *type;
    return false;
}

void
export_to_file(ExportType type) {
    const int max_row = session->cur_doc->cur_sh->maxrow;
    const int max_col = session->cur_doc->cur_sh->maxcol;

    switch (type) {
        case EXPORT_TYPE_CSV: {
            export_delim(NULL, ',', 0, 0, max_row, max_col, 0);
            break;
        }
        case EXPORT_TYPE_TAB:
            export_delim(NULL, '\t', 0, 0, max_row, max_col, 0);
            break;
        case EXPORT_TYPE_MARKDOWN:
            export_markdown(NULL, 0, 0, max_row, max_col);
            break;
        case EXPORT_TYPE_PLAINTEXT:
            export_plain(NULL, 0, 0, max_row, max_col);
            break;
        default:
            break;
    }
}

/**
 * \brief Set up signals catched by sc-im
 * \return none
 */
void
signals(void) {
    void sig_int(int);
    void sig_abrt(int);
    void sig_term(int);
    void sig_nopipe(int);
    void sig_winchg(int);
    void sig_tstp(int);
    void sig_cont(int);

    signal(SIGINT, sig_int);
    signal(SIGABRT, sig_abrt);
    signal(SIGTERM, sig_term); // kill
    signal(SIGPIPE, sig_nopipe);
    //(void) signal(SIGALRM, time_out);
    signal(SIGWINCH, sig_winchg);
    //(void) signal(SIGBUS, doquit);
    //(void) signal(SIGFPE, doquit);
    signal(SIGTSTP, sig_tstp);
    signal(SIGCONT, sig_cont);
    return;
}


/**
 * \brief Handles the SIGPIPE signal
 * \return none
 */
void
sig_nopipe(int sig) {
    sc_error("brokenpipe!");
    brokenpipe = TRUE;
    return;
}


/**
 * \brief Handles the SIGTSTP signal
 * \return none
 */
void
sig_tstp(int sig) {
    //sc_info("Got SIGTSTP.");
    def_prog_mode();
    endwin();
    signal(SIGTSTP, SIG_DFL);  /* set handler to default */
    kill(getpid(), SIGTSTP);   /* call the default handler */
}


/**
 * \brief Handles the SIGCONT signal
 * \return none
 */
void
sig_cont(int sig) {
    signal(SIGTSTP, sig_tstp); /* set handler back to this */
    sig_winchg(SIGWINCH);
    reset_prog_mode();
    refresh();
    ui_update(TRUE);
    //sc_info("Got SIGCONT.");
}


/**
 * \brief Handles the SIGINT signal
 * \return none
 */
void
sig_int(int sig) {
    if ( !config_get_bool("debug")) {
        sc_error("Got SIGINT. Press «:q<Enter>» to quit sc-im");
    } else if (buffer_size(buffer)) {
        break_waitcmd_loop(buffer);
    } else {
        shall_quit = 2;
    }
    return;
}


/**
 * \brief Handles the SIGABRT signal
 * \return none
 */
void
sig_abrt(int sig) {
    sc_error("Error !!!Quitting sc-im.");
    shall_quit = -1; // error !
    return;
}


/**
 * \brief Handles the SIGABRT signal
 * \return none
 */
void
sig_term(int sig) {
    sc_error("Got SIGTERM signal. Quitting sc-im.");
    shall_quit = 2;
    return;
}

#include "version.h"

/**
 * \brief Send the version number to standard output.
 * \return none
 * TODO Split this into two commands. One prints the version number
 * the other prints the version number along with the other information.
 */
bool
argv_show_version(const void *v) {
    config_set_bool("nocurses", true);
    sc_info("sc-im - %s", rev);
#ifdef NCURSES
    sc_info("-DNCURSES");
#endif
#ifdef MAXROWS
    sc_info("-DMAXROWS %d", MAXROWS);
#endif
#ifdef UNDO
    sc_info("-DUNDO");
#endif
#ifdef XLS
    sc_info("-DXLS");
#endif
#ifdef XLSX
    sc_info("-DXLSX");
#endif
#ifdef XLSX_EXPORT
    sc_info("-DXLSX_EXPORT");
#endif
#ifdef XLUA
    sc_info("-DXLUA");
#endif
#ifdef DEFAULT_COPY_TO_CLIPBOARD_CMD
    sc_info("-DDEFAULT_COPY_TO_CLIPBOARD_CMD=\"%s\"", DEFAULT_COPY_TO_CLIPBOARD_CMD);
#endif
#ifdef DEFAULT_PASTE_FROM_CLIPBOARD_CMD
    sc_info("-DDEFAULT_PASTE_FROM_CLIPBOARD_CMD=\"%s\"", DEFAULT_PASTE_FROM_CLIPBOARD_CMD);
#endif
#ifdef DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD
    sc_info("-DDEFAULT_OPEN_FILE_UNDER_CURSOR_CMD=\"%s\"", DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD);
#endif
#ifdef USELOCALE
    sc_info("-DUSELOCALE");
#endif
#ifdef MOUSE
    sc_info("-DMOUSE");
#endif
#ifdef USECOLORS
    sc_info("-DUSECOLORS");
#endif
#ifdef _XOPEN_SOURCE_EXTENDED
    sc_info("-D_XOPEN_SOURCE_EXTENDED");
#endif
#ifdef _GNU_SOURCE
    sc_info("-D_GNU_SOURCE");
#endif
#ifdef SNAME
    sc_info("-DSNAME=\"%s\"", SNAME);
#endif
#ifdef HELP_PATH
    sc_info("-DHELP_PATH=\"%s\"", HELP_PATH);
#endif
#ifdef LIBDIR
    sc_info("-DLIBDIR=\"%s\"", LIBDIR);
#endif
#ifdef DFLT_PAGER
    sc_info("-DDFLT_PAGER=\"%s\"", DFLT_PAGER);
#endif
#ifdef DFLT_EDITOR
    sc_info("-DDFLT_EDITOR=\"%s\"", DFLT_EDITOR);
#endif
#ifdef CONFIG_DIR
    sc_info("-DCONFIG_DIR=\"%s\"", CONFIG_DIR);
#endif
#ifdef CONFIG_FILE
    sc_info("-DCONFIG_FILE=\"%s\"", CONFIG_FILE);
#endif
#ifdef HISTORY_DIR
    sc_info("-DHISTORY_DIR=\"%s\"", HISTORY_DIR);
#endif
#ifdef HISTORY_FILE
    sc_info("-DHISTORY_FILE=\"%s\"", HISTORY_FILE);
#endif
#ifdef INS_HISTORY_FILE
    sc_info("-DINS_HISTORY_FILE=\"%s\"", INS_HISTORY_FILE);
#endif
#ifdef HAVE_PTHREAD
    sc_info("-DHAVE_PTHREAD");
#endif
#ifdef AUTOBACKUP
    sc_info("-DAUTOBACKUP");
#endif
    config_set_bool("quit_afterload", true);
    return true;
}


/**
 * \brief Print usage message to stdout text and quit
 * \return none
 */
 // NOTE this is a quick and dirty command to search for arguments used in the sources (macOS 10.14)
 // grep "get_conf_value(\"" -r ./src/*.c | grep get_conf_value |sed 's/"//g' |sed 's/.*get_conf_value(//g'|cut -d ')' -f1 |sort|uniq|sed 's/^/--/g'
bool
argv_show_usage(const void *v) {
  config_set_bool("nocurses", true);
  printf("\
sc-im - sc-improvised\
\n\
\nUsage: sc-im [arguments] [file]          specified file\
\n   or: sc-im [arguments] -               read text from stdin\
\n\
\nArguments:\
\n\
\n  --autocalc                  Set variable 'autocalc'.\
\n  --copy_to_clipboard_delimited_tab  Set variable 'copy_to_clipboard_delimited_tab'\
\n  --debug                     Set variable 'debug'\
\n  --default_copy_to_clipboard_cmd=COMMAND  set variable 'default_copy_from_clipboard_cmd'\
\n  --default_paste_from_clipboard_cmd=COMMAND  set variable 'default_paste_from_clipboard_cmd'\
\n  --default_open_file_under_cursor_cmd=COMMAND  set variable 'default_open_file_under_cursor_cmd'\
\n  --export-csv                Export to csv without interaction\
\n  --export-tab                Export to tab without interaction\
\n  --export-txt                Export to txt without interaction\
\n  --export-mkd                Export to markdown without interaction\
\n  --external_functions        Set variable 'external_functions'\
\n  --half_page_scroll          Set variable 'half_page_scroll'\
\n  --ignorecase                Set variable 'ignorecase'\
\n  --import_delimited_as_text Import text as\
\n  --newline_action={j or l}   Set variable 'newline_action'\
\n  --nocurses                  Run interactive but without ncurses interface.\
\n  --numeric                   Set variable 'numeric'\
\n  --numeric_decimal           Set variable 'numeric_decimal'\
\n  --output=FILE               Save the results in FILE\
\n  --overlap                   Set variable 'overlap variable'\
\n  --quit_afterload            Quit after loading all the files\
\n  --show_cursor               Make the screen cursor follow the active cell\
\n  --tm_gmtoff={seconds}       set gmt offset used for converting datetimes to localtime.\
\n  --txtdelim={\",\" or \";\" or \"\\t\" or \"|\"}  Sets delimiter when opening a .tab of .csv file");
#ifdef XLSX
  printf("\n\
\n  --sheet=SHEET               Open SHEET when loading xlsx file. Default is 1.\
\n  --xlsx_readformulas         Set variable 'xlsx_readformulas'");
#endif
  printf("\n\
\n  --version                   Print version information and exit\
\n  --help                      Print Help (this message) and exit\n");
    return true;
}
