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
 * \brief buffer functions used by stdin andm mappings
 */

#include <stdlib.h>
#include <wchar.h>

#include "buffer.h"
#include "macros.h"
#include "utils/string.h"


/**
* \brief Create buffer as list of blocks
* \return b
*/
struct block *
create_buf(void) {
    struct block *const ret = malloc(sizeof(*ret));

    *ret = (struct block){
        .value = '\0',
        .pnext = NULL,
    };

    return ret;
}


/**
* \brief Add a int32_t to a buffer
* \param[in] buf
* \param[in] d
* \return none
*/
void
buffer_append(struct block *const buf, int32_t d) {
    if (buf->value == '\0') {
        buf->value = d;
    } else {
        struct block *const b = malloc(sizeof(*b));
        b->value = d;
        b->pnext = NULL;

        struct block *aux = buf;
        for (; aux->pnext != NULL; aux = aux->pnext);
        aux->pnext = b;
    }
}


/**
* \brief Replaces the elements of 'dest' with the elements of 'src'
* \param[in] dest
* \param[in] src
* \return none
*/
void
buffer_copy(struct block *const dest, struct block *const src) {
    buffer_reset(dest);

    const int len = get_bufsize(src);
    for (int i = 0; i < len; i++)
        buffer_append(dest, get_bufval(src, i));
}


/**
* \brief Remove a piece of a buffer
* \param[in] buf
* \param[in] pos
* \return none
*/
// FIXME
void
buffer_remove(struct block **const buf, size_t pos) {
    if (buf == NULL || *buf == NULL)
        return;

    if (pos == 0) {
        struct block *const temp = *buf;
        *buf = temp->pnext;
        free(temp);
        return;
    }

    struct block *prev = *buf;
    struct block *current = *buf;

    for (int i = 0; i < pos; i++) {
        prev = current;
        current = current->pnext;

        if (current == NULL) // pos is out of bounds
            return;
    }

    prev->pnext = current->pnext;
    free(current);
}

/**
* \brief Replaces the initial node of a buffer with '\0' and removes all other nodes
* \param[in] buf
* \return none
*/
void
buffer_reset(struct block *const buf) {
    if (buf == NULL)
        return;

    {
        struct block *current, *next;
        for (current = buf->pnext; current != NULL; current = next) {
            next = current->pnext;
            free(current);
        }
    }

    buf->value = '\0';
    buf->pnext = NULL;
    return;
}


/**
* \brief Delete all blocks of a buffer including the initial node
* \details Delete all blocks of a buffer including the initial node
* \param buf
* \return none
*/
void
buffer_free(struct block *const buf) {
    if (buf == NULL)
        return;

    buffer_reset(buf);
    free(buf);
    return;
}


/**
* \brief Get size of buffer (included special chars)
* \param[in] buf
* \return c size of buffer
*/
size_t
get_bufsize(const struct block *const buf) {
    if (buf == NULL || buf->value == '\0')
        return 0;

    size_t ret = 0;
    for (const struct block *b_aux = buf; b_aux != NULL; b_aux = b_aux->pnext) {
        ret++;
    }

    return ret;
}


/**
* \brief Get printable buffer length (excluded special chars)
* \details Get printable bufferlength, which excludes special characters
* as they should never be printed to a screen.
* \param[in] buf
* \return c printable buffer length
*/
size_t
get_pbuflen(const struct block *const buf) {
    if (buf == NULL || buf->value == '\0')
        return 0;

    size_t ret = 0;
    for (const struct block *b_aux = buf; b_aux != NULL; b_aux = b_aux->pnext) {
        if (!is_idchar(b_aux->value))
            ret++;
    }

    return ret;
}


/**
* \brief Return the int value of n block
* \param[in] buf
* \param[in] d
* \return none
*/
int get_bufval(struct block * buf, int d) {
    int i;
    struct block * b_aux = buf;
    for (i = 0; i < d; i++) {
        b_aux = b_aux->pnext;
    }
    return b_aux->value;
}


/**
* \brief Return an int value if found in a buffer
* \details Search a buffer for a given integer value.
* \return 0 if not found, 1 if found
*/
int find_val(struct block * buf, int value) {
    struct block * b_aux = buf;
    while ( b_aux != NULL && b_aux->value != '\0' ) {
        if (b_aux->value == value) return 1;
        b_aux = b_aux->pnext;
    }
    return 0;
}


/**
* \brief Delete the first element in a buffer
* \param[in] buf
* \return none
*/
struct block * dequeue (struct block * buf) {
    if (buf == NULL) return buf;
    struct block * sig;
    if (buf->value == '\0') return buf;

    if (buf->pnext == NULL) {
       buf->value = '\0';
    } else {
        sig = buf->pnext;
        //free(buf);
        buf = sig;
    }
    return buf;
}
