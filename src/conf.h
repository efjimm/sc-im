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
 * @file conf.h
 * @author Andrés Martinelli <andmarti@gmail.com>
 * @date 2017-07-18
 * @brief Header file for conf.c
 */

#ifndef CONF_H
#define CONF_H

#include <wchar.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils/map.h"

enum ConfigNewlineAction {
    CONFIG_NEWLINE_ACTION_NONE,
    CONFIG_NEWLINE_ACTION_DOWN,
    CONFIG_NEWLINE_ACTION_RIGHT,
};

enum ConfigValueType {
    CONFIGVALUE_BOOL,
    CONFIGVALUE_STRING,
    CONFIGVALUE_INT,
    CONFIGVALUE_DOUBLE,
};

typedef struct {
    uint8_t tag;
    union {
        char *s;
        bool b;
        int64_t i;
        double d;
    };
} ConfigValue;

void config_init(Map *map);
void config_deinit(void);

char *config_get_string(const char *key);
int64_t config_get_int(const char *key);
bool config_get_bool(const char *key);
int change_config_parameter(wchar_t *inputline);
char *config_get_strings(char *buffer, size_t size);

int8_t config_set_value(const char *key, ConfigValue value);
int8_t config_set_int(const char *key, int64_t value);
int8_t config_set_string(const char *key, const char *value);
int8_t config_set_double(const char *key, double value);
int8_t config_set_bool(const char *key, bool value);
void config_parse_str(const char *str, bool split_on_blanks);
#endif
