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
 * \file buffer.c
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 2017-07-18
 * \brief buffer functions used by stdin and mappings
 */

#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <string.h>

#include "buffer.h"
#include "macros.h"
#include "utils/string.h"

// TODO: use utf8
union Buffer {
    struct {
        uint32_t len;
        uint32_t capacity;
        uint32_t *chars;
    };

    Buffer *next;
};

#define POOL_SIZE 1024

typedef struct Pool Pool;

struct Pool {
    Buffer buffers[POOL_SIZE];
    Pool *prev;
};

static size_t pool_len = POOL_SIZE;
static Pool *pool_tail = NULL;
static Buffer *free_list = NULL;

static Buffer *
buffer_alloc(void) {
    if (free_list) {
        Buffer *const ret = free_list;
        free_list = free_list->next;
        return ret;
    }

    if (pool_len >= POOL_SIZE) {
        Pool *const new_pool = malloc(sizeof(*new_pool));

        *new_pool = (Pool){
            .prev = pool_tail,
        };

        pool_tail = new_pool;
        pool_len = 0;
    }

    return &pool_tail->buffers[pool_len++];
}

static void
buffer_free(Buffer *buf) {
    free(buf->chars);
    *buf = (Buffer){
        .next = free_list,
    };
    free_list = buf;
}

static void
buffer_ensure_capacity(Buffer *buf, size_t capacity) {
    if (buf->capacity < capacity) {
        buf->chars = realloc(buf->chars, sizeof(buf->chars) * capacity);
        buf->capacity = capacity;
    }
}

void
buffer_free_all(void) {
    Pool *temp = pool_tail;
    Pool *prev;

    for(; temp; temp = prev) {
        for (size_t i = 0; i < POOL_SIZE; i++) {
            if (temp->buffers[i].chars)
                free(temp->buffers[i].chars);
        }
        prev = temp->prev;
        free(temp);
    }
}

Buffer *
buffer_create(size_t initial_capacity) {
    Buffer *ret = buffer_alloc();
    const size_t real_capacity = initial_capacity < 4 ? 4 : initial_capacity;

    *ret = (Buffer){
        .capacity = real_capacity,
        .chars = malloc(sizeof(uint32_t) * real_capacity),
    };

    return ret;
}

void
buffer_destroy(Buffer *buf) {
    buffer_free(buf);
}

void
buffer_append(Buffer *const buf, uint32_t d) {
    if (buf->len >= buf->capacity)
        buf->chars = realloc(buf->chars, sizeof(*buf->chars) * (buf->capacity += 2));

    buf->chars[buf->len++] = d;
}

void
buffer_remove(Buffer *const buf, size_t pos) {
    if (pos >= buf->len)
        return;

    if (pos + 1 == buf->len) {
        buf->len--;
        return;
    }

    memmove(&buf->chars[pos], &buf->chars[pos + 1], buf->len - (pos + 1));
    buf->len--;
}

void
buffer_reset(Buffer *const buf) {
    buf->len = 0;
}

size_t
buffer_size(const Buffer *const buf) {
    return buf->len;
}

size_t
buffer_printable_len(const Buffer *const buf) {
    size_t total = 0;

    for (size_t i = 0; i < buf->len; i++) {
        if (!is_idchar(buf->chars[i]))
            total++;
    }

    return total;
}

uint32_t
buffer_get(const Buffer *const buf, size_t pos) {
    if (pos >= buf->len) // TODO: disallow this
        return '\0';

    return buf->chars[pos];
}

bool
buffer_contains(const Buffer *const buf, uint32_t ch) {
    for (size_t i = 0; i < buf->len; i++)
        if (buf->chars[i] == ch)
            return true;

    return false;
}

void
buffer_append_buffer(Buffer *const dest, const Buffer *const src) {
    if (dest == NULL || src == NULL)
        return;

    buffer_ensure_capacity(dest, dest->len + src->len);

    for (size_t i = 0; i < src->len; i++) {
        buffer_append(dest, src->chars[i]);
    }
}
