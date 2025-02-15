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
 *    names of other contributors may be used to endorse or promote products   *
 *    derived from this software without specific prior written permission.    *
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
 * \file conf.c
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 2017-07-18
 * \brief Configuration functions
 *
 * \details This file contains functions that operate on  the user's configuration
 * map.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <strings.h>
#include <assert.h>
#include <ctype.h>

#include "conf.h"
#include "sc.h"
#include "utils/dictionary.h"

#ifndef DEFAULT_COPY_TO_CLIPBOARD_CMD
#define DEFAULT_COPY_TO_CLIPBOARD_CMD ""
#endif

#ifndef DEFAULT_PASTE_FROM_CLIPBOARD_CMD
#define DEFAULT_PASTE_FROM_CLIPBOARD_CMD ""
#endif

#ifndef DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD
#define DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD ""
#endif

static void config_init_default(void);
static bool free_entry(const char *key, void *value_, void *data);

typedef struct {
    const char *key;
    ConfigValue value;
} ConfigEntry;

static ConfigEntry default_config[] = {
#ifdef AUTOBACKUP
    { "autobackup", { .tag = CONFIGVALUE_INT, .i = 0 } },
#endif
    { "autocalc",                        { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "autowrap",                        { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "command_timeout",                 { .tag = CONFIGVALUE_INT,  .i = 3000  } },
    { "copy_to_clipboard_delimited_tab", { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "debug",                           { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "exec_lua",                        { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "external_functions",              { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "half_page_scroll",                { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "help",                            { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "ignore_hidden",                   { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "ignorecase",                      { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "import_delimited_as_text",        { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "input_bar_bottom",                { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "mapping_timeout",                 { .tag = CONFIGVALUE_INT,  .i = 1500  } },
    { "nocurses",                        { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "numeric",                         { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "numeric_decimal",                 { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "numeric_zero",                    { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "overlap",                         { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "quiet",                           { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "quit_afterload",                  { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "show_cursor",                     { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "tm_gmtoff",                       { .tag = CONFIGVALUE_INT,  .i = 0     } },
    { "trigger",                         { .tag = CONFIGVALUE_BOOL, .b = true  } },
    { "truncate",                        { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "underline_grid",                  { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "version",                         { .tag = CONFIGVALUE_BOOL, .b = false } },
    { "xlsx_readformulas",               { .tag = CONFIGVALUE_BOOL, .b = false } },

    { "newline_action", { .tag = CONFIGVALUE_INT,  .i = CONFIG_NEWLINE_ACTION_NONE } },

    {
        .key = "default_copy_to_clipboard_cmd",
        .value = {
             .tag = CONFIGVALUE_STRING,
             .s = DEFAULT_COPY_TO_CLIPBOARD_CMD,
        }
    },
    {
        .key = "default_open_file_under_cursor_cmd",
        .value = {
             .tag = CONFIGVALUE_STRING,
             .s = DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD,
        }
    },
    {
        .key = "default_paste_from_clipboard_cmd",
        .value = {
             .tag = CONFIGVALUE_STRING,
             .s = DEFAULT_PASTE_FROM_CLIPBOARD_CMD,
        }
    },
};

static Map *config_map = NULL;

/**
 * \brief Initializes a map as the program's configuration map and populates it with default
 *        values.
 *
 * \param map An already allocated map which will be filled with the default config values and be
 *            set as the config map.
 * \return none
 */
void
config_init(Map *map) {
    config_map = map;
    config_init_default();
}

/**
 * \brief Frees all the string values inside the map.
 * 
 * \return none
 */
void
config_deinit(void) {
    map_iterate(config_map, free_entry, NULL);
}

static bool
free_entry(const char *key, void *value_, void *data) {
    ConfigValue *const value = value_;
    if (value->tag == CONFIGVALUE_STRING)
        free(value->s);
    return true;
}

static void
config_init_default(void) {
    for (size_t i = 0; i < sizeof(default_config) / sizeof(default_config[0]); i++) {
        if (default_config[i].value.tag == CONFIGVALUE_STRING) {
            default_config[i].value.s = strdup(default_config[i].value.s);
        }
        map_put(config_map, default_config[i].key, &default_config[i].value);
    }

    // Calculate GMT offset (not on Solaris, doesn't have tm_gmtoff)
#if defined(USELOCALE) && !defined(__sun)
    time_t t = time(NULL);
    struct tm * lt = localtime(&t);
    map_put(config_map, "tm_gmtoff", &(ConfigValue){
        .tag = CONFIGVALUE_INT,
        .i = lt->tm_gmtoff,
    });
#endif
}

ConfigValue *
config_get_value(const char *key) {
    return map_get(config_map, key);
}

typedef struct {
    char *buffer;
    size_t len;
    size_t capacity;
    bool resizable;
} StringBuffer;

static bool
stringbuffer_append(const char *key, void *value, void *data) {
    ConfigValue *const cv = value;
    StringBuffer *const str = data;

    int size;
    switch (cv->tag) {
        case CONFIGVALUE_BOOL:
            size = snprintf(NULL, 0, "%s = %s\n", key, cv->b ? "true" : "false");
            break;
        case CONFIGVALUE_STRING:
            size = snprintf(NULL, 0, "%s = %s\n", key, cv->s);
            break;
        case CONFIGVALUE_INT:
            size = snprintf(NULL, 0, "%s = %ld\n", key, cv->i);
            break;
        case CONFIGVALUE_DOUBLE:
            size = snprintf(NULL, 0, "%s = %f\n", key, cv->d);
            break;
    }

    if (str->len + size >= str->capacity) {
        if (str->capacity > 0)
            str->capacity *= 2;
        else
            str->capacity += 32;

        str->buffer = realloc(str->buffer, str->capacity);
        if (!str->buffer)
            return false;
    }

    switch (cv->tag) {
        case CONFIGVALUE_BOOL:
            str->len += sprintf(str->buffer + str->len, "%s = %s\n", key, cv->b ? "true" : "false");
            break;
        case CONFIGVALUE_STRING:
            str->len += sprintf(str->buffer + str->len, "%s = %s\n", key, cv->s);
            break;
        case CONFIGVALUE_INT:
            str->len += sprintf(str->buffer + str->len, "%s = %ld\n", key, cv->i);
            break;
        case CONFIGVALUE_DOUBLE:
            str->len += sprintf(str->buffer + str->len, "%s = %f\n", key, cv->d);
            break;
    }
    return true;
}

char *
config_get_strings(char *buffer, size_t size) {
    StringBuffer str;
    if (buffer != NULL) {
        str = (StringBuffer){
            .buffer = buffer,
            .len = 0,
            .capacity = size,
            .resizable = false,
        };
    } else {
        str = (StringBuffer){
            .buffer = NULL,
            .len = 0,
            .capacity = 0,
            .resizable = true,
        };
    }

    map_iterate(config_map, stringbuffer_append, &str);
    return str.buffer;
}

char *
config_get_string(const char *key) {
    ConfigValue *const value = map_get(config_map, key);
    if (value && value->tag == CONFIGVALUE_STRING)
       return value->s;
    return NULL;
}

int64_t
config_get_int(const char *key) {
    ConfigValue *const value = map_get(config_map, key);
    if (value && value->tag == CONFIGVALUE_INT)
       return value->i;
    return 0;
}

bool
config_get_bool(const char *key) {
    ConfigValue *const value = map_get(config_map, key);
    if (value && value->tag == CONFIGVALUE_BOOL)
       return value->b;
    return false;
}

double
config_get_double(const char *key) {
    ConfigValue *const value = map_get(config_map, key);
    if (value && value->tag == CONFIGVALUE_DOUBLE)
       return value->d;
    return 0;
}

int8_t
config_set_int(const char *key, int64_t value) {
    ConfigValue *const prev_value = map_get(config_map, key);
    if (!prev_value || prev_value->tag != CONFIGVALUE_INT)
       return -1;

    if (prev_value->i == value)
       return 1;

    *prev_value = (ConfigValue){
       .tag = CONFIGVALUE_INT,
       .i = value,
    };
    return 0;
}

int8_t
config_set_string(const char *key, const char *value) {
    ConfigValue *const prev_value = map_get(config_map, key);
    if (!prev_value || prev_value->tag != CONFIGVALUE_STRING)
       return -1;

    if (!strcmp(prev_value->s, value))
       return 1;

    free(prev_value->s);
    *prev_value = (ConfigValue){
       .tag = CONFIGVALUE_STRING,
       .s = strdup(value),
    };

    return 0;
}

int8_t
config_set_bool(const char *key, bool value) {
    ConfigValue *const prev_value = map_get(config_map, key);
    if (!prev_value || prev_value->tag != CONFIGVALUE_BOOL)
        return -1;

    if (prev_value->b == value)
        return 1;

    prev_value->b = value;
    return 0;
}

int8_t
config_set_double(const char *key, double value) {
    ConfigValue *const prev_value = map_get(config_map, key);
    if (!prev_value || prev_value->tag != CONFIGVALUE_DOUBLE)
        return -1;

    if (prev_value->d == value)
        return 1;

    prev_value->d = value;
    return 0;
}

int8_t
config_set_value(const char *key, ConfigValue value) {
    const ConfigValue *const prev_value = map_get(config_map, key);

    if (prev_value == NULL)
        return -1;

    switch (prev_value->tag) {
        case CONFIGVALUE_INT:
            return config_set_int(key, value.i);
            break;
        case CONFIGVALUE_STRING:
            return config_set_string(key, value.s);
            break;
        case CONFIGVALUE_BOOL:
            config_set_bool(key, value.b);
            break;
        case CONFIGVALUE_DOUBLE:
            return config_set_double(key, value.d);
            break;
    }
    return -1;
}

void
config_parse_str(const char *str, bool split_on_blanks) {
    char key[90];
    char value[90];
    int i;

    while (*str != 0) {
        /* remove leading field separators */
        if (*str == ' ' || *str == '\n') {
            str++;
            continue;
        }

        /* collect the key */
        i = 0;
        for (;;) {
            if (*str == '=') {
                /* we are done with the key */
                key[i] = 0;
                break;
            }
            if (*str == 0 || *str == '\n' || (split_on_blanks && *str == ' ')) {
                /* got only a key: pretend the value is 1 */
                key[i] = 0;
                config_set_bool(key, true);
                break;
            }
            if (*str == ' ') {
                /* spaces in the key are invalid */
                return;
            }

            key[i++] = *str++;

            if (i >= sizeof(key)) {
                /* won't have room for final '\0' */
                return;
            }
        }

        if (*str != '=') {
            /* no value to collect */
            continue;
        }
	str++;

        /* collect the value */
        i = 0;
        for (;;) {
            if (*str == 0 || *str == '\n' || (split_on_blanks && *str == ' ')) {
                /* we are done with the value */
                value[i] = '\0';

                const ConfigValue *const old = config_get_value(key);
                switch (old->tag) {
                    case CONFIGVALUE_BOOL: {
                        errno = 0;
                        const long n = strtol(value, NULL, 10);
                        if (errno) {
                            if(!strcasecmp(value, "true"))
                                config_set_bool(key, true);
                            else
                                config_set_bool(key, false);
                        } else {
                            config_set_bool(key, (bool) n);
                        }
                        break;
                    }
                    case CONFIGVALUE_INT: {
                        const long n = strtol(value, NULL, 10);
                        config_set_int(key, n);
                        break;
                    }
                    case CONFIGVALUE_STRING: {
                        config_set_string(key, value);
                        break;
                    }
                    case CONFIGVALUE_DOUBLE: {
                        const double d = strtod(value, NULL);
                        config_set_bool(key, d);
                        break;
                    }
                }
                break;
            }

            value[i++] = *str++;

            if (i >= sizeof(value)) {
                /* won't have room for final '\0' */
                return;
            }
        }
    }
}

// TODO: change input to char *
/* \brief Parses a string in the format "set key = value" and sets the config specified config
 * value appropriately.
 * parameter[in] char * cmd
 * return int:
 * 0 if config parameter changed
 * 1 if config parameter was valid but previous and new values are the same
 * -1 on error
 */
#include <wchar.h>
#include "utils/string.h"
#include "tui.h"
int
change_config_parameter(wchar_t *inputline) {
    static char line[BUFFERSIZE];
    const size_t len = wcstombs(line, inputline, BUFFERSIZE);

    if (len == (size_t)-1)
        return -1;

    size_t i = 0;

    // Skip leading spaces
    for (; i < len && isspace(line[i]); i++);

    // Make sure "set" is the first word
    if (i >= len || strncmp(&line[i], "set ", 4)) {
        sc_error("Invalid command: '%s'", line);
        return -1;
    }

    // Skip spaces after "set"
    for (i += 4; i < len && isspace(line[i]); i++);

    // Get key string, stopping at '=' or whitespace
    char *const key = line + i;
    for (; i < len && line[i] != '=' && !isspace(line[i]); i++);

    const size_t key_len = line + i - key;

    if (i >= len || key_len == 0) {
        sc_error("Invalid command: '%s'", line);
        return -1;
    }

    // Skip spaces between key name and '='
    for (; i < len && isspace(line[i]); i++);
    if (i >= len || line[i] != '=') {
        sc_error("Badly formed set command: expected '='");
        return -1;
    }

    // Skip spaces between '=' and value
    for (i += 1; i < len && isspace(line[i]); i++);

    // Get value string, stopping at whitespace or the end of the string
    char *const value = line + i;
    for (; i < len && !isspace(line[i]); i++);

    const size_t value_len = line + i - value;
    value[value_len] = '\0';
    key[key_len] = '\0';

    if (value_len == 0) {
        sc_error("Expected value after '='");
        return -1;
    }

    ConfigValue *const old_value = config_get_value(key);

    if (!old_value) {
        sc_error("Invalid key config variable: '%s'", key);
        return -1;
    }

    int ret;
    switch (old_value->tag) {
        case CONFIGVALUE_STRING:
            ret = config_set_string(key, value);
            break;
        case CONFIGVALUE_BOOL:
            if (!strcmp(value, "1") || !strcmp(value, "true") || !strcmp(value, "on")) {
                ret = config_set_bool(key, true);
            } else if (!strcmp(value, "0") || !strcmp(value, "false") || !strcmp(value, "off")) {
                ret = config_set_bool(key, false);
            } else {
                ret = -1;
            }
            break;
        case CONFIGVALUE_INT:
            errno = 0;
            long long l = strtoll(key, NULL, 10);
            if (errno)
                ret = -1;
            else
                ret = config_set_int(key, l);
            break;
        case CONFIGVALUE_DOUBLE:
            errno = 0;
            double d = strtod(key, NULL);
            if (errno)
                ret = -1;
            else
                ret = config_set_double(key, d);
            break;
    }

    switch (ret) {
        case 1:
            sc_error("Could not set config variable '%s' to value '%s'", key, value);
            break;
        case -1:
            sc_info("Config variable '%s' unchanged. Current value is '%s'", key, value);
            break;
        case 0:
            sc_info("Config variable '%s' changed to '%s'", key, value);
            break;
        default:
            assert(false);
    }

    return ret;
}
