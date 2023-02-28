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
 * \file input.c
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 2021-04-02
 * \brief functions to handle stdin
 */

#include <sys/time.h>
#include <string.h>
#include <ctype.h>   // for isdigit
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "main.h"
#include "tui.h"
#include "maps.h"
#include "cmds/cmds.h"
#include "history.h"
#include "conf.h"
#include "utils/string.h"
#include "cmds/cmds_visual.h"
#include "buffer.h"
#include "digraphs.h"

static wint_t wd;          // char read from stdin
static int d;              // char read from stdin
int return_value;          // return value of getch()
int cmd_multiplier = 0;    // Multiplier
int cmd_pending = 0;       // Command pending
int cmd_digraph = 0;
static wint_t digraph;
#ifdef MOUSE
MEVENT event;              // mouse event
#endif

/**
 * \brief Reads stdin for a valid command
 *
 * \details Read characters from stdin to an input buffer. When filled,
 * validate the command and call the appropriate handler. When a timeout
 * is reached, flush the buffer.
 *
 * \param buffer
 *
 * \return none
 */
void
handle_input(SC *const sc, Buffer *const buffer) {
    struct timeval start_tv, m_tv, init_tv; // For measuring timeout
    gettimeofday(&start_tv, NULL);
    gettimeofday(&m_tv, NULL);
    gettimeofday(&init_tv, NULL); // keep time when entering handle_input
    long msec = (m_tv.tv_sec - start_tv.tv_sec) * 1000L +
                (m_tv.tv_usec - start_tv.tv_usec) / 1000L;
    long msec_init = (m_tv.tv_sec - init_tv.tv_sec) * 1000L +
                (m_tv.tv_usec - init_tv.tv_usec) / 1000L;

    cmd_multiplier = 0;
    cmd_pending = 0;

    /* add char to buffer until valid command found.
     * important: buffer may contain a valid command (for instance,
     * just a letter in insert mode) but that buffer start may also
     * be a possible mapping! (for instace kj in insert mode to exit the mode).
     * if so, wait a mapping_timeout (1500ms), before triggering has_cmd..
     */
    while (
            ( ! has_cmd(buffer, msec) && msec <= config_get_int("command_timeout")) ||
            ( could_be_mapping(buffer) && msec_init < config_get_int("mapping_timeout"))
          ) {

        // if command pending, refresh 'ef' only. Multiplier and cmd pending
        if (cmd_pending) ui_print_mult_pend();

        // Modify cursor state according to the current mode
        ui_handle_cursor();

        // Read new character from stdin
        return_value = ui_getch(&wd);
        d = wd;
#ifdef MOUSE
        if (d == KEY_MOUSE) {
            getmouse (&event);
            ui_handle_mouse(event);
            return;
        }
#endif

        if ( (d == OKEY_ESC || d == ctl('g')) && curmode != EDIT_MODE) {
            break_waitcmd_loop(sc, buffer);
            ui_clr_header(1);
            ui_show_header();
            return;
        }

        // Handle multiplier of commands in NORMAL VISUAL and EDIT modes
        if ( return_value != -1 && isdigit(d)
                && (buffer_get(buffer, 0) == '\0' || iswdigit(buffer_get(buffer, 0)))
                && (curmode == NORMAL_MODE || curmode == VISUAL_MODE || curmode == EDIT_MODE)
                && (cmd_multiplier || d != L'0')
                && (!config_get_bool("numeric"))
           ) {
            cmd_multiplier *= 10;
            cmd_multiplier += (int) (d - '0');
            if (cmd_multiplier > MAX_MULTIPLIER) cmd_multiplier = 0;

            gettimeofday(&start_tv, NULL);
            msec = (m_tv.tv_sec - start_tv.tv_sec) * 1000L +
                (m_tv.tv_usec - start_tv.tv_usec) / 1000L;

            ui_print_mult_pend();
            continue;
        }


        /*
         * Handle special characters input: BS TAB ENTER HOME END DEL PGUP
         * PGDOWN and alphanumeric characters
         */
        if (is_idchar(d) || return_value != -1) {
            // If in NORMAL, VISUAL or EDITION mode, added '?' cmd_pending at the left of MODE
            if ( (curmode == NORMAL_MODE && d >= ' ') || //FIXME
                    (curmode == EDIT_MODE   && d >= ' ') ||
                    (curmode == VISUAL_MODE && d >= ' ') ) {
                cmd_pending = 1;
            }
            if (cmd_digraph) {
                if (digraph == 0) {
                    digraph = wd;
                    continue;
                }
                wd = get_digraph(digraph, wd);
                cmd_digraph = 0;
                digraph = 0;

            } else if (! cmd_digraph && wd == ctl('k')) {
                cmd_digraph = 1;
                continue;
            }
            buffer_append(buffer, wd);

            // Replace maps in buffer
            // break if nore mapping
            if (replace_maps(buffer) == 1)
                break;
        }

        /*
         * Update time stamp to reset timeout after each loop
         * (start_tv changes only if current mode is COMMAND, INSERT or
         * EDIT) and for each user input as well.
         */
        gettimeofday(&m_tv, NULL);
        msec = (m_tv.tv_sec - start_tv.tv_sec) * 1000L +
            (m_tv.tv_usec - start_tv.tv_usec) / 1000L;

        msec_init = (m_tv.tv_sec - init_tv.tv_sec) * 1000L +
            (m_tv.tv_usec - init_tv.tv_usec) / 1000L;
        if (msec_init > 4000) gettimeofday(&init_tv, NULL); // just to avoid overload
        fix_timeout(&start_tv);

        // to handle map of ESC
        if ((buffer_get(buffer, 0) == OKEY_ESC ||
                buffer_get(buffer, 0) == ctl('g')) && curmode != EDIT_MODE) {
            break_waitcmd_loop(sc, buffer);
            ui_print_mult_pend();
            ui_refresh_pad(0);
            return;
        }

    }
    if (msec >= config_get_int("command_timeout")) { // timeout. Command incomplete
        cmd_pending = 0;      // No longer wait for a command, set flag.
        cmd_multiplier = 0;   // Reset multiplier
    } else {                  // Execute command or mapping
        cmd_pending = 0;
        ui_clr_header(1);     // Clean second line

        // Handle command and repeat as many times as the multiplier dictates
        handle_mult(sc, &cmd_multiplier, buffer, msec);
    }
    ui_print_mult_pend();
    buffer_reset(buffer);        // Flush the buffer
    return;
}

/**
 * \brief Break waiting command loop
 *
 * \return none
 */
void
break_waitcmd_loop(SC *const sc, Buffer *const buffer) {
    if (curmode == COMMAND_MODE) {
#ifdef HISTORY_FILE
        del_item_from_history(commandline_history, 0);
        commandline_history->pos = 0;
        set_comp(0);
#endif
    } else if (curmode == INSERT_MODE) {
#ifdef INS_HISTORY_FILE
        del_item_from_history(insert_history, 0);
        insert_history->pos = 0;
#endif
    } else if (curmode == VISUAL_MODE) {
        exit_visualmode(sc);
    }
    if (curmode == INSERT_MODE && lastmode == EDIT_MODE)     {
        if (inputline_pos && wcslen(inputline) >= inputline_pos) {
            real_inputline_pos--;
            int l = wcwidth(inputline[real_inputline_pos]);
            inputline_pos -= l;
        }
        chg_mode(insert_edit_submode == '=' ? 'e' : 'E');
        lastmode=NORMAL_MODE;
        ui_show_header();
    } else if (curmode == EDIT_MODE && lastmode == INSERT_MODE) {
        chg_mode(insert_edit_submode);
        lastmode=NORMAL_MODE;
        ui_show_header();
    } else {
        chg_mode('.');
        lastmode=NORMAL_MODE;
        inputline[0] = L'\0';  // clean inputline
        buffer_reset(buffer);
        ui_update(TRUE);
    }
    cmd_pending = 0;       // No longer wait for command. Set flag.
    cmd_multiplier = 0;    // Reset the multiplier
    return;
}

/**
 * \brief Handle timeout depending on the current mode
 *
 * Handle timeout depending on the current mode. There is NO timeout
 * for COMMAND, INSERT, and EDIT modes.
 *
 * \param[in] start_tv
 *
 * \return none
 */

void
fix_timeout(struct timeval *const start_tv) {
    switch (curmode) {
        case COMMAND_MODE:
        case INSERT_MODE:
            gettimeofday(start_tv, NULL);
            break;
        case VISUAL_MODE:
        case EDIT_MODE:
        case NORMAL_MODE:
            if (d != 0) gettimeofday(start_tv, NULL);
    }
    return;
}

/**
 * \brief Traverse 'stuffbuff' and determine if there is a valid command.
 *
 * Traverse 'stuffbuff' and determine if there is a valid
 * command (e.g. buffer = "diw").
 *
 * \param[in]buf
 * \param[in]timeout
 * \return none
 */

bool
has_cmd(Buffer *const buf, long timeout) {
    const size_t len = buffer_size(buf);
    if (!len)
        return 0;

    Buffer * auxb = buffer_create(len);
    bool found = false;

    for (size_t k = 0; k < len; k++) {
        buffer_append(auxb, buffer_get(buf, k));
        if (is_single_command(auxb, timeout)) {
            found = true;
            break;
        }
    }
    buffer_destroy(auxb);

    return found;
}

void do_commandmode(SC *const sc, Buffer *const sb);
void do_normalmode(SC *const sc, Buffer *const buf);
void do_insertmode(SC *const sc, Buffer *const sb);
void do_editmode(SC *const sc, Buffer *const sb);
void do_visualmode(SC *const sc, Buffer *const sb);

/**
 * \brief Use specific functions for every command on each mode
 *
 * \param[in] sb
 *
 * \return none
 */

void
exec_single_cmd(SC *const sc, Buffer *const sb) {
    switch (curmode) {
        case NORMAL_MODE:
            do_normalmode(sc, sb);
            break;
        case INSERT_MODE:
            do_insertmode(sc, sb);
            break;
        case COMMAND_MODE:
            do_commandmode(sc, sb);
            break;
        case EDIT_MODE:
            do_editmode(sc, sb);
            break;
        case VISUAL_MODE:
            do_visualmode(sc, sb);
            break;
    }
    return;
}

/**
 * \brief Handle the final command to be executed, using the multiplier
 *
 * \param[in] cmd_multiplier
 * \param[in] buf
 * \param[in] timeout
 *
 * \return none
 */

void
handle_mult(SC *const sc, int *cmd_multiplier, Buffer *buf, long timeout) {
    if (*cmd_multiplier == 0)
        *cmd_multiplier = 1;

    const int len = buffer_size(buf);
    Buffer *temp_buf = buffer_create(len);

    buffer_append_buffer(temp_buf, buf);

    for (int i = 1; i < *cmd_multiplier; i++)
        buffer_append_buffer(buf, temp_buf);

    exec_mult(sc, buf, timeout);
    if (*cmd_multiplier > 1) {
        *cmd_multiplier = 1;
        if (curmode != EDIT_MODE) ui_update(TRUE);
    }

    *cmd_multiplier = 0;

    return;
}

/**
 * \brief Handle multiple command execution in sequence
 *
 * \return none
 */
void
exec_mult(SC *const sc, Buffer *buf, long timeout) {
    int k, res;
    const size_t buf_len = buffer_size(buf);

    if (buf_len == 0)
    	return;

    // Try to execute the whole buffer content
    if ((res = is_single_command(buf, timeout))) {
        if (res == EDITION_CMD)
        	buffer_copy(lastcmd_buffer, buf); // save stdin buffer content in lastcmd buffer
        exec_single_cmd(sc, buf);

    // If not possible, traverse blockwise
    } else {
        Buffer * auxb = buffer_create(buf_len);
        for (k = 0; k < buf_len; k++) {
            buffer_append(auxb, buffer_get(buf, k));

            if ((res = is_single_command(auxb, timeout))) {
                if (res == EDITION_CMD)
                	buffer_copy(lastcmd_buffer, buf); // save stdin buffer content in lastcmd buffer
                exec_single_cmd(sc, auxb);
                buffer_reset(auxb);
                k++; // Take the first K values from 'buf'
                while (k--)
                    buffer_remove_first(buf);
                // Execute again
                if (cmd_multiplier == 0) break;
                exec_mult(sc, buf, timeout);
                break;
            }
        }
        buffer_destroy(auxb);
        auxb = NULL;
    }
    return;
}
