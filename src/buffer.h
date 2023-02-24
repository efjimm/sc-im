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
 * \file buffer.h
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 2017-07-18
 * \brief Header file for buffer.c
 */

#include <wchar.h>
#include <wctype.h>
#include <stdint.h>
#include <stdbool.h>

// Block of buffer

struct block {
    uint32_t value;
    struct block *pnext;
};

struct block *buffer_create(void);
struct block *buffer_create_init(size_t initial_capacity);
void buffer_append(struct block *const buf, uint32_t d);
void buffer_remove (struct block **const buf_ptr, size_t pos);
void buffer_reset(struct block *const buf);
void buffer_free (struct block *const buf);
size_t buffer_size(const struct block *const buf);
size_t buffer_printable_len(const struct block *const buf);
uint32_t buffer_get(const struct block *const buf, size_t d);
bool buffer_contains(const struct block *const buf, uint32_t value);
void buffer_append_buffer(struct block *const dest, const struct block *const src);

static inline void
buffer_remove_first(struct block **const buf_ptr) {
    buffer_remove(buf_ptr, 0);
}

static inline void
buffer_copy(struct block *const dest, const struct block *const src) {
    buffer_reset(dest);
    buffer_append_buffer(dest, src);
}
