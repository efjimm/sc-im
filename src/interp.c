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
 * \file interp.c
 * \author Andrés Martinelli <andmarti@gmail.com>
 * \date 24/05/2021
 * \brief source file that implements the eval seval functions
 * Based on SC
 *
 * \details Expression interpreter and assorted support routines
 * \details Original by James Gosling, September 1982
 * \details Modified by Mark Weiser and Bruce Israel, University of Maryland
 * \details More mods Robert Bond, 12/86
 * \details More mods by Alan Silverstein, 3-4/88.
 */

#include <sys/types.h>
#include <signal.h>
#include <setjmp.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>
#ifdef IEEE_MATH
#include <ieeefp.h>
#endif

#include "sc.h"
#include "macros.h"
#include "cmds/cmds.h"
#include "format.h"
#include "conf.h"
#include "tui.h"
#include "range.h"
#include "xmalloc.h" // for scxfree
#include "lex.h"     // for atocol
#include "function.h"
#include "interp.h"
#include "utils/string.h"
#include "trigger.h"
#ifdef XLUA
#include "lua.h"
#endif
#ifdef UNDO
#include "undo.h"
#endif
#include "graph.h"

extern int find_range(char * name, int len, struct ent * lmatch, struct ent * rmatch, struct range ** rng);
extern bool decimal;      /* Set if there was a decimal point in the number */
extern struct session * session;
extern graphADT graph;
extern WINDOW * input_win;

void exit_app();
//double fn1_eval      (double (* fn)(double, double), double arg);
//double fn2_eval      (double (* fn)(double, double), double arg1, double arg2);
//bool   constant      (const struct enode *const e);
//void   copydbuf      (int deltar, int deltac);
//void   decompile     (struct enode * e, int priority);
//void   index_arg     (char * s, struct enode * e);
//void   list_arg      (char * s, struct enode * e);
//void   one_arg       (char * s, struct enode * e);
//void   range_arg     (char * s, struct enode * e);
//void   three_arg     (char * s, struct enode * e);
//void   two_arg       (char * s, struct enode * e);
//void   two_arg_index (char * s, struct enode * e);

int exprerr;              /* Set by eval(sc, ) and seval(sc, ) if expression errors */
double prescale = 1.0;    /* Prescale for constants in let() */
int gmyrow = -1, gmycol = -1;       /* globals used to implement @myrow, @mycol cmds */
int rowoffset = 0, coloffset = 0;    /* row & col offsets for range functions */
jmp_buf fpe_save;
int    cellerror = CELLOK;    /**< is there an error in this cell */

struct go_save gs = { .g_type = G_NONE }; /* Use this structure to save the last 'g' command */

/***********************************************************************************************/

/**
 * \brief eval(sc, )
 * \param[in] ent
 * \param[in] e
 * \return double
 */
double
eval(SC *const sc, struct sheet * sh, struct ent * ent, struct enode * e) {
//  if (cellerror == CELLERROR || (ent && ent->cellerror == CELLERROR)) {
//  if (cellerror == CELLERROR) {
//      return (double) 0;
//  }
    if (e == NULL) {
        cellerror = CELLINVALID;
        return 0;
    }

    switch (e->op) {
    case '+':    return (eval(sc, sh, ent, e->left) + eval(sc, sh, ent, e->right));
    case '-':    {
            const double lhs = eval(sc, sh, ent, e->left);
            const double rhs = eval(sc, sh, ent, e->right);
            return lhs - rhs;
            }
    case '*':    return (eval(sc, sh, ent, e->left) * eval(sc, sh, ent, e->right));
    case '/':    {
            double num, denom;
            num = eval(sc, sh, ent, e->left);
            denom = eval(sc, sh, ent, e->right);
            if (cellerror) {
                cellerror = CELLINVALID;
                return ((double) 0);
            } else
            if (denom)
                return (num/denom);
            else {
                cellerror = CELLERROR;
                return ((double) 0);
            }
    }
    case '%':    {
            double num, denom;
            num = floor(eval(sc, sh, ent, e->left));
            denom = floor(eval(sc, sh, ent, e->right));
            if (denom)
                return (num - floor(num/denom)*denom);
            else {
                cellerror = CELLERROR;
                return ((double) 0);
            }
    }
    case '^':    return (fn2_eval(pow,eval(sc, sh, ent, e->left),eval(sc, sh, ent, e->right)));
    case '<':    return (eval(sc, sh, ent, e->left) < eval(sc, sh, ent, e->right));
    case '=':    {
            double l, r;
            l = eval(sc, sh, ent, e->left);
            r = eval(sc, sh, ent, e->right);
            return (l == r);
            }
    case '>':    return (eval(sc, sh, ent, e->left) > eval(sc, sh, ent, e->right));
    case '&':    return (eval(sc, sh, ent, e->left) && eval(sc, sh, ent, e->right));
    case '|':    return (eval(sc, sh, ent, e->left) || eval(sc, sh, ent, e->right));
    case IF:
    case '?':    return eval(sc, sh, ent, e->left) ? eval(sc, sh, ent, e->right->left)
                        : eval(sc, sh, ent, e->right->right);
    case 'm':    return (-eval(sc, sh, ent, e->left));
    case 'f':    {
            int rtmp = rowoffset;
            int ctmp = coloffset;
            double ret;
            rowoffset = coloffset = 0;
            ret = eval(sc, sh, ent, e->left);
            rowoffset = rtmp;
            coloffset = ctmp;
            return (ret);
            }
    case 'F':    return (eval(sc, sh, ent, e->left));
    case '!':    return (eval(sc, sh, ent, e->left) == 0.0);
    case ';':    return (((int) eval(sc, sh, ent, e->left) & 7) +
                (((int) eval(sc, sh, ent, e->right) & 7) << 3));

    case O_CONST:
            if (! isfinite(e->number)) {
                e->op = ERR_;
                e->number = (double) 0;
                cellerror = CELLERROR;
            }
            // Changed 06/03/2021 for #issue 499
            if (ent && ent->expr != NULL && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
            return (e->number);

    case GETENT:
            ;
            int r = eval(sc, sh, ent, e->left);
            int c = eval(sc, sh, ent, e->right);
            if (r < 0 || c < 0) {
                sc_debug("@getent shouldnt be called with negative parameters %d %d", r, c);
                return (double) 0;
            }
            struct ent * vp = *ATBL(sh, sh->tbl, r, c);
            if (ent && vp && ent->row == vp->row && ent->col == vp->col) {
                    sc_error("Circular reference in eval (cell %s%d)", coltoa(vp->col), vp->row);
                    e->op = ERR_;
                    e->left = NULL;
                    e->right = NULL;
                    cellerror = CELLERROR;
                    return (double) 0;
            }
            if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
            if (ent && vp) GraphAddEdge(getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh, lookat(sh, vp->row, vp->col), 1));
            if (vp && vp->flags & is_valid) return (vp->v);
            return (double) 0;

    case O_VAR:    {
            struct ent * vp = e->ref.vp;
            struct sheet * sh_vp = e->ref.sheet;
            if (sh_vp == NULL) sh_vp = sh;
            //sc_debug("var %d %d", vp->row, vp->col);
            //if (vp && ent && vp->row == ent->row && vp->col == ent->col && !(vp->flags & is_deleted) ) {
            if (vp && ent && vp == ent && !(vp->flags & is_deleted) ) {
                sc_error("Circular reference in eval (cell %s%d)", coltoa(vp->col), vp->row);
                //ERR propagates. comment to make it not to.
                cellerror = CELLERROR;

                //ent->cellerror = CELLERROR;
                GraphAddEdge( getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh_vp, lookat(sh_vp, vp->row, vp->col), 1) ) ;
                return (double) 0;
            }
            if (vp && vp->cellerror == CELLERROR && !(vp->flags & is_deleted)) {
                // here we store the dependences in a graph
                if (ent && vp) GraphAddEdge( getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1),
                                             getVertex(graph, sh_vp, lookat(sh_vp, vp->row, vp->col), 1) ) ;

                //does not change reference to @err in expression
                //uncomment to do so
                //e->op = ERR_;

                //ERR propagates. comment to make it not to.
                cellerror = CELLERROR;
                return (double) 0;
            }

            int row, col;
            if (vp && (rowoffset || coloffset)) {
                row = e->ref.vf & FIX_ROW ? vp->row : vp->row + rowoffset;
                col = e->ref.vf & FIX_COL ? vp->col : vp->col + coloffset;
                checkbounds(sh, &row, &col);
                vp = *ATBL(sh_vp, sh_vp->tbl, row, col);
            }


            if (!vp || vp->flags & is_deleted) {
                //if (vp != NULL && getVertex(graph, vp, 0) != NULL) destroy_vertex(vp);

                // commented for #538 21/04/21
                //e->op = REF_;
                //e->left = NULL;
                //e->right = NULL;

                //CELLREF propagates
                //cellerror = CELLREF;

                return (double) 0;
            }

            // here we store the dependences in a graph
            if (ent && vp) {
                vertexT * v_ent = getVertex(graph, sh, lookat(sh, ent->row, ent->col), 0);
                vertexT * v_vp = getVertex(graph, sh_vp, lookat(sh_vp, vp->row, vp->col), 0);
                if (v_ent != NULL && v_vp != NULL && GraphIsReachable(v_ent, v_vp, 1)) {
                    sc_error("Circular reference in eval (cell %s%d)", coltoa(vp->col), vp->row);
                    e->op = ERR_;
                    e->left = NULL;
                    e->right = NULL;
                    cellerror = CELLERROR;
                    return (double) 0;
                }
                GraphAddEdge( getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh_vp, lookat(sh_vp, vp->row, vp->col), 1) ) ;
            }

            if (vp->cellerror) {
                cellerror = CELLINVALID;
            }

            if (vp->cellerror == CELLERROR) {
                return (double) 0;
            }

            return (vp->v);
            }
    case SUM:
    case PROD:
    case AVG:
    case COUNT:
    case STDDEV:
    case MAX:
    case MIN:
    case INDEX:
    case LOOKUP:
    case HLOOKUP:
    case VLOOKUP: {
        int r, c, row, col;
        int maxr, maxc;
        int minr, minc;
        maxr = e->left->range.right.vp->row;
        maxc = e->left->range.right.vp->col;
        minr = e->left->range.left.vp->row;
        minc = e->left->range.left.vp->col;
        if (minr>maxr) r = maxr, maxr = minr, minr = r;
        if (minc>maxc) c = maxc, maxc = minc, minc = c;

        for (row=minr; ent != NULL && row <= maxr; row++) {
            for (col=minc; col <= maxc; col++) {
                if (ent->row == row && ent->col == col) {
                    sc_error("Circular reference in eval (cell %s%d)", coltoa(col), row);
                    e->op = ERR_;
                    cellerror = CELLERROR;
                    return (double) 0;
                }
                GraphAddEdge(getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh, lookat(sh, row, col), 1));
            }
        }

        switch (e->op) {
            case LOOKUP:
                return dolookup(sc, sh, e->right, minr, minc, maxr, maxc, 1, minc==maxc);
            case HLOOKUP:
                return dolookup(sc, sh, e->right->left, minr,minc,maxr,maxc,
                        (int) eval(sc, sh, ent, e->right->right), 0);
            case VLOOKUP:
                return dolookup(sc, sh, e->right->left, minr,minc,maxr,maxc,
                        (int) eval(sc, sh, ent, e->right->right), 1);
            case INDEX:
                return doindex(sc, sh, minr, minc, maxr, maxc, e->right);
            case SUM:
                return dosum(sc, sh, minr, minc, maxr, maxc, e->right);
            case PROD:
                return doprod(sc, sh, minr, minc, maxr, maxc, e->right);
            case AVG:
                return doavg(sc, sh, minr, minc, maxr, maxc, e->right);
            case COUNT:
                return docount(sc, sh, minr, minc, maxr, maxc, e->right);
            case STDDEV:
                return dostddev(sc, sh, minr, minc, maxr, maxc, e->right);
            case MAX:
                return domax(sc, sh, minr, minc, maxr, maxc, e->right);
            case MIN:
                return domin(sc, sh, minr, minc, maxr, maxc, e->right);
        }
    }
    case REDUCE | 'R':
    case REDUCE | 'C':
        {    int r, c;
        int maxr, maxc;
        int minr, minc;
        maxr = e->range.right.vp->row;
        maxc = e->range.right.vp->col;
        minr = e->range.left.vp->row;
        minc = e->range.left.vp->col;
        if (minr>maxr) r = maxr, maxr = minr, minr = r;
        if (minc>maxc) c = maxc, maxc = minc, minc = c;
            switch (e->op) {
                 case REDUCE | 'R': return (maxr - minr + 1);
                 case REDUCE | 'C': return (maxc - minc + 1);
        }
        }
    case ABS:    return (fn1_eval( fabs, eval(sc, sh, ent, e->left)));

    case FROW:
                 eval(sc, sh, ent, e->left);
                 return (dorow(e->left));
    case FCOL:
                 eval(sc, sh, ent, e->left);
                 return (docol(e->left));
    case ACOS:   return (fn1_eval( acos, eval(sc, sh, ent, e->left)));
    case ASIN:   return (fn1_eval( asin, eval(sc, sh, ent, e->left)));
    case ATAN:   return (fn1_eval( atan, eval(sc, sh, ent, e->left)));
    case ATAN2:  return (fn2_eval( atan2, eval(sc, sh, ent, e->left), eval(sc, sh, ent, e->right)));
    case CEIL:   return (fn1_eval( ceil, eval(sc, sh, ent, e->left)));
    case COS:    return (fn1_eval( cos, eval(sc, sh, ent, e->left)));
    case EXP:    return (fn1_eval( exp, eval(sc, sh, ent, e->left)));
    case FABS:   return (fn1_eval( fabs, eval(sc, sh, ent, e->left)));
    case FLOOR:  return (fn1_eval( floor, eval(sc, sh, ent, e->left)));
    case HYPOT:  return (fn2_eval( hypot, eval(sc, sh, ent, e->left), eval(sc, sh, ent, e->right)));
    case LOG:    return (fn1_eval( log, eval(sc, sh, ent, e->left)));
    case LOG10:  return (fn1_eval( log10, eval(sc, sh, ent, e->left)));
    case POW:    return (fn2_eval( pow, eval(sc, sh, ent, e->left), eval(sc, sh, ent, e->right)));
    case SIN:    return (fn1_eval( sin, eval(sc, sh, ent, e->left)));
    case SQRT:   return (fn1_eval( sqrt, eval(sc, sh, ent, e->left)));
    case TAN:    return (fn1_eval( tan, eval(sc, sh, ent, e->left)));
    case DTR:    return (dtr(eval(sc, sh, ent, e->left)));
    case RTD:    return (rtd(eval(sc, sh, ent, e->left)));
    case RND:
        if (rndtoeven)
            return rint(eval(sc, sh, ent, e->left));
        else {
            double temp = eval(sc, sh, ent, e->left);
            return (temp - floor(temp) < 0.5 ? floor(temp) : ceil(temp));
        }
    case ROUND:
        {
        int precision = (int) eval(sc, sh, ent, e->right);
        double scale = 1;
        if (0 < precision)
            do scale *= 10; while (0 < --precision);
        else if (precision < 0)
            do scale /= 10; while (++precision < 0);

        if (rndtoeven)
            return (rint(eval(sc, sh, ent, e->left) * scale) / scale);
        else {
            double temp = eval(sc, sh, ent, e->left);
            temp *= scale;
            /* xxx */
            /*
            temp = (temp > 0.0 ? floor(temp + 0.5) : ceil(temp - 0.5));
            */
            temp = ((temp - floor(temp)) < 0.5 ?
                floor(temp) : ceil(temp));
            return (temp / scale);
        }
        }
    case FV:
    case PV:
    case PMT:    return (finfunc(e->op, eval(sc, sh, ent, e->left), eval(sc, sh, ent, e->right->left), eval(sc, sh, ent, e->right->right)));
    case HOUR:   return (dotime(HOUR, eval(sc, sh, ent, e->left)));
    case MINUTE: return (dotime(MINUTE, eval(sc, sh, ent, e->left)));
    case SECOND: return (dotime(SECOND, eval(sc, sh, ent, e->left)));
    case MONTH:  return (dotime(MONTH, eval(sc, sh, ent, e->left)));
    case DAY:    return (dotime(DAY, eval(sc, sh, ent, e->left)));
    case YEAR:   return (dotime(YEAR, eval(sc, sh, ent, e->left)));

    case NOW:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (dotime(NOW, (double) 0.0));

    case DTS:    return (dodts((int) eval(sc, sh, ent, e->left),
                    (int)eval(sc, sh, ent, e->right->left),
                    (int)eval(sc, sh, ent, e->right->right)));
    case TTS:    return (dotts((int) eval(sc, sh, ent, e->left),
                    (int)eval(sc, sh, ent, e->right->left),
                    (int)eval(sc, sh, ent, e->right->right)));

    case EVALUATE:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return doevaluate(sc, seval(sc, sh, ent, e->left));

    case STON:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (doston(seval(sc, sh, ent, e->left)));

    case ASCII:  return (doascii(seval(sc, sh, ent, e->left)));

    case SLEN:   return (doslen(seval(sc, sh, ent, e->left)));

    case EQS:    return (doeqs(seval(sc, sh, ent, e->right), seval(sc, sh, ent, e->left)));

    case LMAX:   return dolmax(sc, sh, ent, e);

    case LMIN:   return dolmin(sc, sh, ent, e);

    case NVAL:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 char * s = seval(sc, sh, ent, e->left);
                 if (! s) { return (double) (0); }
                 char * sf = calloc(strlen(s)+1, sizeof(char));
                 strcpy(sf, s);
                 double n = eval(sc, sh, ent, e->right);
                 struct ent * ep = getent(sh, sf, n, 1);
                 if (! ep) { free(s); return (double) (0); }
                 if (ent && ep) GraphAddEdge(getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh, ep, 1));
                 return donval(sh, s, n);

    case MYROW:
                 // if @myrow is called before EvallJustOneVertex
                 // (this might happen during startup when loading file)
                 // gmyrow does not happen to have valid value. handle that.
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (gmyrow == -1 ? (ent ? ent->row + rowoffset : (double) sh->currow + rowoffset) : (double) (gmyrow + rowoffset));

    case MYCOL:
                 // if @mycol is called before EvallJustOneVertex
                 // (this might happen during startup when loading file)
                 // gmycol does not happen to have valid value. handle that.
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (gmycol == -1 ? (ent ? ent->col + coloffset : (double) sh->curcol + coloffset) : (double) (gmycol + coloffset));

    case LASTROW:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return ((double) sh->maxrow);

    case LASTCOL:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return ((double) sh->maxcol);

    case ERR_:
                 cellerror = CELLERROR;
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return ((double) 0);

    case REF_:
                 cellerror = CELLREF;
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return ((double) 0);

    case PI_:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return ((double) M_PI);

    case BLACK:  return ((double) COLOR_BLACK);
    case RED:    return ((double) COLOR_RED);
    case GREEN:  return ((double) COLOR_GREEN);
    case YELLOW: return ((double) COLOR_YELLOW);
    case BLUE:   return ((double) COLOR_BLUE);
    case MAGENTA: return ((double) COLOR_MAGENTA);
    case CYAN:   return ((double) COLOR_CYAN);
    case WHITE:  return ((double) COLOR_WHITE);
    case DEFAULT_COLOR: return ((double) DEFAULT_COLOR);
    case FACT:
        {
            double total = eval(sc, sh, ent, e->left);
            int i;
            for (i = eval(sc, sh, ent, e->left) - 1; i > 0; i--) {
                total *= i;
            }
            return total > 0 ? total : 1;
        }
    default:    sc_error ("Illegal numeric expression");
                exprerr = 1;
    }
    cellerror = CELLERROR;
    return ((double) 0.0);
}


/**
 * \brief seval(sc, )
 * \param[in] ent
 * \param[in] se
 * \return char *
 */
char * seval(SC *const sc, struct sheet * sh, struct ent * ent, struct enode * se) {
    struct sheet * sh_vp = sh;
    if (se == (struct enode *) 0) return (char *) 0;

    char * p;

    switch (se->op) {
    case O_SCONST:
            p = scxmalloc( (size_t) (strlen(se->str) + 1));
            (void) strcpy(p, se->str);

            if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
            return (p);

    case O_VAR:
            {
            struct ent * vp = se->ref.vp;
            sh_vp = se->ref.sheet;
            if (sh_vp == NULL) sh_vp = sh;

            if (vp && ent && vp->row == ent->row && vp->col == ent->col && sh_vp == sh) {
                sc_error("Circular reference in seval");
                se->op = ERR_;
                cellerror = CELLERROR;
                return (NULL);
            }

            int row, col;
            if (vp && (rowoffset || coloffset)) {
                row = se->ref.vf & FIX_ROW ? vp->row : vp->row + rowoffset;
                col = se->ref.vf & FIX_COL ? vp->col : vp->col + coloffset;
                checkbounds(sh, &row, &col);
                vp = *ATBL(sh, sh->tbl, row, col);
            }
            if ( !vp || !vp->label)
                return (NULL);
            p = scxmalloc( (size_t) (strlen(vp->label) + 1));
            (void) strcpy(p, vp->label);

            // here we store the cell dependences in a graph
            if (ent && vp) {
                GraphAddEdge(getVertex(graph, sh, lookat(sh, ent->row, ent->col), 1), getVertex(graph, sh_vp, lookat(sh_vp, vp->row, vp->col), 1) ) ;
            }
            return (p);
    }

    case '#':
            return (docat(seval(sc, sh, ent, se->left), seval(sc, sh, ent, se->right)));

    case 'f':
             {
             int rtmp = rowoffset;
             int ctmp = coloffset;
             char *ret;
             rowoffset = coloffset = 0;
             ret = seval(sc, sh, ent, se->left);
             rowoffset = rtmp;
             coloffset = ctmp;
             return (ret);
             }

    case 'F':    return (seval(sc, sh, ent, se->left));

    case IF:

    case '?':    return (eval(sc, sh, NULL, se->left) ? seval(sc, sh, ent, se->right->left) : seval(sc, sh, ent, se->right->right));

    case DATE:   return (dodate( (time_t) (eval(sc, sh, NULL, se->left)), seval(sc, sh, ent, se->right)));

    case FMT:    return (dofmt(seval(sc, sh, ent, se->left), eval(sc, sh, NULL, se->right)));

    case UPPER:  return (docase(UPPER, seval(sc, sh, ent, se->left)));

    case LOWER:  return (docase(LOWER, seval(sc, sh, ent, se->left)));

    case SET8BIT:  return (docase(SET8BIT, seval(sc, sh, ent, se->left)));

    case CAPITAL:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (docapital(seval(sc, sh, ent, se->left)));

    case STINDEX: {
        int r, c;
        int maxr, maxc;
        int minr, minc;
        maxr = se->left->range.right.vp->row;
        maxc = se->left->range.right.vp->col;
        minr = se->left->range.left.vp->row;
        minc = se->left->range.left.vp->col;
        if (minr>maxr) r = maxr, maxr = minr, minr = r;
        if (minc>maxc) c = maxc, maxc = minc, minc = c;
        return dostindex(sc, sh, minr, minc, maxr, maxc, se->right);
    }
    case EXT:
             if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
             return (doext(sc, sh, se));

#ifdef XLUA
    case LUA:
         ;
         int dg_store = eval(sc, sh, NULL, se->right);
         // add to depgraph ONLY if second parameter to @lua is 1
         if (dg_store == 1 && ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);

         if (ent) {
             ent->label = scxmalloc(sizeof(char)*4);
             strcpy(ent->label, "LUA");
         }
         if (! config_get_bool("exec_lua")) {
             sc_info("Execution of LUA scripts disabled");
             return NULL;
         }
         return (doLUA(sc, sh, se, dg_store));
#endif

    case SVAL:   return (dosval(sh, seval(sc, sh, ent, se->left), eval(sc, sh, NULL, se->right)));

    case REPLACE:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (doreplace(seval(sc, sh, ent, se->left),
                          seval(sc, sh, NULL, se->right->left),
                          seval(sc, sh, NULL, se->right->right)));

    case SUBSTR: return (dosubstr(seval(sc, sh, ent, se->left),
                (int) eval(sc, sh, NULL, se->right->left) - 1,
                (int) eval(sc, sh, NULL, se->right->right) - 1));

    case COLTOA:
                 if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
                 return (strcpy(scxmalloc( (size_t) 10), coltoa((int) eval(sc, sh, ent, se->left))));

    case CHR:
             if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
             return (strcpy(scxmalloc( (size_t) 10), dochr(eval(sc, sh, NULL, se->left))));

    case SEVALUATE:
             if (ent && getVertex(graph, sh, ent, 0) == NULL) GraphAddVertex(graph, sh, ent);
             return dosevaluate(sc, seval(sc, sh, ent, se->left));

    case FILENAME: {
             char * curfile = session->cur_doc->name;
             if (curfile == NULL) return curfile;
             int n = eval(sc, sh, NULL, se->left);
             char *s = strrchr(curfile, '/');
             if (n || s++ == NULL) s = curfile;
             p = scxmalloc( (size_t) (strlen(s) + 1));
             (void) strcpy(p, s);
             return (p);
    }
    default:
             sc_error("Illegal string expression");
             exprerr = 1;
             return (NULL);
    }
}


/**
 * \brief getent()
 *
 * \details Given a string representing a column name and a value which
 * is a row number, return a pointer to the selected cell's entry.
 * if alloc == 0 and no cell is alloc, return NULL.
 * Use only the integer part of the column number. Always
 * free the string
 *
 * \param[in] struct sheet * sh
 * \param[in] colstr
 * \param[in] rwodoub
 *
 * \return struct ent *
 */
struct ent * getent(struct sheet * sh, char * colstr, double rowdoub, int alloc) {
    int collen;                         /* length of string */
    int row, col;                       /* integer values   */
    struct ent *p = (struct ent *) 0;   /* selected entry   */

    if (!colstr) {
        cellerror = CELLERROR;
        return ((struct ent *) 0);
    }
    collen = strlen(colstr);
    col = atocol(colstr, collen);
    row = (int) floor(rowdoub);

    if (row >= 0
        && (row < sh->maxrows)                      /* in range */
        && (collen <= 2)                        /* not too long */
        && (col >= 0)
        && (col < sh->maxcols)) {                   /* in range */
            if (alloc) p = lookat(sh, row, col);
            else p = *ATBL(sh, sh->tbl, row, col);
            if ((p != NULL) && p->cellerror) cellerror = CELLINVALID;
    }
    scxfree(colstr);
    return (p);
}


/*
 * \brief eval_fpe()
 * \return none
 */
void eval_fpe() { /* Trap for FPE errors in eval */
#if defined(i386)
    sc_debug("eval_fpe i386");
    asm("    fnclex");
    asm("    fwait");
#else
 #ifdef IEEE_MATH
    (void)fpsetsticky((fp_except)0);    /* Clear exception */
 #endif /* IEEE_MATH */
#endif
    /* re-establish signal handler for next time */
    (void) signal(SIGFPE, eval_fpe);
    longjmp(fpe_save, 1);
}

/**
 * \brief fn1_eval()
 * \param[in] fn
 * \param[in] arg
 * \return double
 */
double
fn1_eval(double (*fn)(double), double arg) {
    double res;
    errno = 0;
    res = (*fn) (arg);
    if (errno) cellerror = CELLERROR;

    return res;
}


/**
 * \brief fn2_eval()
 * \param[in] fn
 * \param[in] arg1
 * \param[in] arg2
 * \return double
 */
double fn2_eval(double (*fn)(double, double), double arg1, double arg2) {
    double res;
    errno = 0;
    res = (*fn) (arg1, arg2);
    if (errno) cellerror = CELLERROR;
    return res;
}


/**
 * \brief new()
 * \param[in] op
 * \param[in] a1
 * \param[in] a2
 * \return struct enode *
 */
struct enode * new(int op, struct enode * a1, struct enode * a2) {
    //if (freeenodes) {
    //     p = freeenodes;
    //    freeenodes = p->left;
    //} else
    struct enode *const p = scxmalloc(sizeof(*p));
    memset(p, 0, sizeof(*p));
    p->op = op;
    p->left = a1;
    p->right = a2;
    return p;
}


/**
 * \brief new_var()
 * \param[in] op
 * \param[in] a1
 * \return struct enotde *
 */
struct enode * new_var(int op, struct ent_ptr a1) {
    //if (freeenodes) {
    //    p = freeenodes;
    //    freeenodes = p->left;
    //} else
    struct enode *const p = scxmalloc(sizeof(*p));
    memset(p, 0, sizeof(*p));
    p->op = op;
    p->ref = a1;
    return p;
}


/**
 * \brief new_range()
 * \param[in] op
 * \param[in] a1
 *
 * \return none
 */
struct enode * new_range(int op, struct range_s a1) {
    //if (freeenodes)
    //{   p = freeenodes;
    //    freeenodes = p->left;
    //}
    //else
    struct enode *const p = scxmalloc(sizeof(*p));
    memset(p, 0, sizeof(*p));
    p->op = op;
    p->range = a1;
    return p;
}


/**
 * \brief new_const()
 * \param[in] op
 * \param[in] a1
 * \return struct enotde *
 */
struct enode * new_const(int op, double a1) {
    //if (freeenodes) {    /* reuse an already free'd enode */
    //    p = freeenodes;
    //    freeenodes = p->left;
    //} else
    struct enode *const p = scxmalloc(sizeof(*p));

    memset(p, 0, sizeof(*p));
    p->op = op;
    p->number = a1;
    return p;
}


/**
 * \brief new_str()
 * \param[in] s
 * \return struct enode *
 */
struct enode * new_str(char * s) {
    //if (freeenodes) {    /* reuse an already free'd enode */
    //    p = freeenodes;
    //    freeenodes = p->left;
    //} else
    struct enode *const p = scxmalloc(sizeof(*p));
    memset(p, 0, sizeof(*p));
    p->op = O_SCONST;
    p->str = s;
    return (p);
}


/**
 * \brief Goto subroutines
 * \return none
 */
void g_free() {
    switch (gs.g_type) {
        case G_STR:
        case G_NSTR:
            scxfree(gs.g_s);
            break;
        default:
            break;
    }
    gs.g_type = G_NONE;
    gs.errsearch = 0;
}


/**
 * \brief go_previous()
 * \return none
 */
void go_previous() {
    int num = 0;

    switch (gs.g_type) {
        case G_NONE:
            sc_error("Nothing to repeat");
            break;
        case G_NUM:
            num_search(gs.g_sheet, gs.g_n, gs.g_row, gs.g_col, gs.g_lastrow, gs.g_lastcol, gs.errsearch, 0);
            break;
        case G_STR:
            gs.g_type = G_NONE;    /* Don't free the string */
            str_search(gs.g_sheet, gs.g_s, gs.g_row, gs.g_col, gs.g_lastrow, gs.g_lastcol, num, 0);
            break;
        default:
            sc_error("go_previous: internal error");
    }
}


/**
 * \brief go_last()
 * \return none
 */
void go_last() {
    int num = 0;

    switch (gs.g_type) {
    case G_NONE:
        sc_error("Nothing to repeat");
        break;
    case G_NUM:
        num_search(gs.g_sheet, gs.g_n, gs.g_row, gs.g_col, gs.g_lastrow, gs.g_lastcol, gs.errsearch, 1);
        break;
    case G_CELL:
        moveto(gs.g_sheet, gs.g_row, gs.g_col, gs.g_lastrow, gs.g_lastcol, gs.strow, gs.stcol);
        break;
    case G_XSTR:
    case G_NSTR:
        num++;
    case G_STR:
        gs.g_type = G_NONE;    /* Don't free the string */
        str_search(gs.g_sheet, gs.g_s, gs.g_row, gs.g_col, gs.g_lastrow, gs.g_lastcol, num, 1);
        break;

    default:
        sc_error("go_last: internal error");
    }
}


/**
 * \brief Place the cursor on a given cell.
 * \details Place the cursor on a given cell. If cornerrow >= 0, place
 * the cell at row cornerrow and column cornercol in the upper corner
 * of the screen possible.
 * \param[in] struct sheet * sh
 * \param[in] row
 * \param[in] col
 * \param[in] lastrow_
 * \param[in] lastcol_
 * \param[in] cornerrow
 * \param[in] cornercol
 * \return none
 */
void moveto(struct sheet * sh, int row, int col, int lastrow_, int lastcol_, int cornerrow, int cornercol) {
    int i;
    sh->lastrow = sh->currow;
    sh->lastcol = sh->curcol;
    sh->currow = row;
    sh->curcol = col;
    g_free();
    gs.g_sheet = sh;
    gs.g_type = G_CELL;
    gs.g_row = sh->currow;
    gs.g_col = sh->curcol;
    gs.g_lastrow = lastrow_;
    gs.g_lastcol = lastcol_;
    if (cornerrow >= 0) {
        gs.stflag = 1;
    } else
        gs.stflag = 0;

    for (rowsinrange = 0, i = row; i <= lastrow_; i++) {
        if (sh->row_hidden[i]) {
            sc_info("Cell's row is hidden");
            continue;
        }
        rowsinrange++;
    }
    for (colsinrange = 0, i = col; i <= lastcol_; i++) {
        if (sh->col_hidden[i]) {
            colsinrange = 0;
            sc_info("Cell's col is hidden");
            continue;
        }
        colsinrange += sh->fwidth[i];
    }
    //if (loading) changed = 0;
}


/**
 * \brief num_search()
 *
 * \details 'goto' either a given number, 'error', or 'invalid' starting
 * at (currow, curcol).
 * \details flow = 1, look forward
 * \details flow = 0, look backwards
 *
 * \param[in] struct sheet * sh
 * \param[in] n
 * \param[in] firstrow
 * \param[in] firstcol
 * \param[in] lastrow_
 * \param[in] lastcol_
 * \param[in] errsearch
 * \param[in] flow
 *
 * \return none
 */
void num_search(struct sheet * sh, double n, int firstrow, int firstcol, int lastrow_, int lastcol_, int errsearch, int flow) {
    struct ent * p;
    int r, c;
    int endr, endc;

    //if (!loading) remember(0);
    g_free();
    gs.g_sheet = sh;
    gs.g_type = G_NUM;
    gs.g_n = n;
    gs.g_row = firstrow;
    gs.g_col = firstcol;
    gs.g_lastrow = lastrow_;
    gs.g_lastcol = lastcol_;
    gs.errsearch = errsearch;
    gs.g_flow = flow;
    if (sh->currow >= firstrow && sh->currow <= lastrow_ && sh->curcol >= firstcol && sh->curcol <= lastcol_) {
        endr = sh->currow;
        endc = sh->curcol;
    } else {
        endr = lastrow_;
        endc = lastcol_;
    }
    r = endr;
    c = endc;

    while (1) {
        if (flow) { // search forward
            if (c < lastcol_)
                c++;
            else {
                if (r < lastrow_) {
                    while (++r < lastrow_ && sh->row_hidden[r]) /* */;
                    c = firstcol;
                } else {
                    r = firstrow;
                    c = firstcol;
                }
            }
        } else { // search backwards
            if (c > firstcol)
                c--;
            else {
                if (r > firstrow) {
                    while (--r > firstrow && sh->row_hidden[r]) /* */;
                    c = lastcol_;
                } else {
                    r = lastrow_;
                    c = lastcol_;
                }
            }
        }

        p = *ATBL(sh, sh->tbl, r, c);
        if (! sh->col_hidden[c] && p && (p->flags & is_valid) && (errsearch || (p->v == n)) && (! errsearch || (p->cellerror == errsearch)))    /* CELLERROR vs CELLINVALID */
            break;
        if (r == endr && c == endc) {
            if (errsearch) {
                sc_error("no %s cell found", errsearch == CELLERROR ? "ERROR" : "INVALID");
            } else {
                sc_error("Number not found");
            }
            return;
        }
    }

    sh->lastrow = sh->currow;
    sh->lastcol = sh->curcol;
    sh->currow = r;
    sh->curcol = c;
    rowsinrange = 1;
    colsinrange = sh->fwidth[sh->curcol];
}


/**
 * \brief 'goto' a cell containing a matching string
 * \details 'goto' a cell containing a matching string.
 * \details flow = 1, look forward
 * \details flow = 0, look backwards
 * \param[in] struct sheet * sh
 * \param[in] s
 * \param[in] firstrow
 * \param[in] firstcol
 * \param[in] lastrow_
 * \param[in] lastcol_
 * \param[in] num
 * \param[in] flow
 * \return none
 */
void str_search(struct sheet * sh, char * s, int firstrow, int firstcol, int lastrow_, int lastcol_, int num, int flow) {
    struct ent * p;
    int r, c;
    int endr, endc;
    char * tmp;
    regex_t preg;
    int errcode;

    sc_info("");
    if (config_get_bool("ignorecase"))
        errcode = regcomp(&preg, s, REG_EXTENDED | REG_ICASE);
    else
        errcode = regcomp(&preg, s, REG_EXTENDED);

    if (errcode) {
        scxfree(s);
        tmp = scxmalloc((size_t)160);
        regerror(errcode, &preg, tmp, sizeof(tmp));
        sc_error(tmp);
        scxfree(tmp);
        return;
    }

    g_free();
    gs.g_sheet = sh;
    gs.g_type = G_STR + num;
    gs.g_s = s;
    gs.g_row = firstrow;
    gs.g_col = firstcol;
    gs.g_lastrow = lastrow_;
    gs.g_lastcol = lastcol_;
    gs.g_flow = flow;

    if (sh->currow >= firstrow && sh->currow <= lastrow_ && sh->curcol >= firstcol && sh->curcol <= lastcol_) {
        endr = sh->currow;
        endc = sh->curcol;
    } else {
        endr = lastrow_;
        endc = lastcol_;
    }
    r = endr;
    c = endc;

    while (1) {
        if (flow) { // search forward
            if (c < lastcol_)
                c++;
            else {
                if (r < lastrow_) {
                    while (++r < lastrow_ && sh->row_hidden[r]) /* */;
                    c = firstcol;
                } else {
                    r = endr;
                    c = endc;
                    break;
                }
            }
        } else { // search backwards
            if (c > firstcol)
                c--;
            else {
                if (r > firstrow) {
                    while (--r > firstrow && sh->row_hidden[r]) /* */;
                    c = lastcol_;
                } else {
                    r = endr;
                    c = endc;
                    break;
                }
            }
        }

        p = *ATBL(sh, sh->tbl, r, c);
        if (gs.g_type == G_NSTR) {
            *line = '\0';
            if (p) {
                if (p->cellerror)
                    sprintf(line, "%s", p->cellerror == CELLERROR ?  "ERROR" : "INVALID");
                else if (p->flags & is_valid) {
                    if (p->format) {
                        if (*(p->format) == ctl('d')) {
                            time_t i = (time_t) (p->v);
                            strftime(line, sizeof(line), (p->format)+1,
                            localtime(&i));
                        } else
                            format(p->format, sh->precision[c], p->v, line, sizeof(line));
                    } else
                        engformat(sh->realfmt[c], sh->fwidth[c], sh->precision[c], p->v, line, sizeof(line));
                }
            }
        } else if (gs.g_type == G_XSTR) {
            *line = '\0';
            if (p && p->expr) {
                linelim = 0;
                decompile(p->expr, 0);    /* set line to expr */
                line[linelim] = '\0';
                if (*line == '?')
                    *line = '\0';
            }
        }
        if (! sh->col_hidden[c]) {
            if (gs.g_type == G_STR && p && p->label && regexec(&preg, p->label, 0, NULL, 0) == 0)
                break;
        } else            /* gs.g_type != G_STR */
        if (*line != '\0' && (regexec(&preg, line, 0, NULL, 0) == 0))
            break;
    }
    if (r == endr && c == endc) {
        sc_error("String not found");
        regfree(&preg);
        linelim = -1;
        return;
    }
    linelim = -1;
    sh->lastrow = sh->currow;
    sh->lastcol = sh->curcol;
    sh->currow = r;
    sh->curcol = c;
    rowsinrange = 1;
    colsinrange = sh->fwidth[sh->curcol];
    regfree(&preg);
}


/**
 * \brief Fill a range with constants
 * \param[in] struct sheet * sh
 * \param[in] v1
 * \param[in] v2
 * \param[in] start
 * \param[in] inc
 * \return none
 */
void fill(struct sheet * sh, struct ent * v1, struct ent * v2, double start, double inc) {
    int r, c;
    struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(sh, &maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

#ifdef UNDO
    create_undo_action();
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_DEL, IGNORE_DEPS, NULL);
#endif

    if (calc_order == BYROWS) {
        for (r = minr; r <= maxr; r++)
            for (c = minc; c <= maxc; c++) {
                n = lookat(sh, r, c);
                if (n->flags & is_locked) continue;
                (void) clearent(n);
                n->v = start;
                start += inc;
                n->flags |= (is_changed | is_valid);
                n->flags &= ~(iscleared);
            }
    }
    else if (calc_order == BYCOLS) {
        for (c = minc; c <= maxc; c++)
            for (r = minr; r <= maxr; r++) {
                n = lookat(sh, r, c);
                (void) clearent(n);
                n->v = start;
                start += inc;
                n->flags |= (is_changed | is_valid);
                n->flags &= ~(iscleared);
            }
    }
    else {
        sc_error(" Internal error calc_order");
    }
    EvalRange(sh, minr, minc, maxr, maxc);
#ifdef UNDO
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_ADD, IGNORE_DEPS, NULL);
    end_undo_action();
#endif
}


/**
 * \brief Lock a range of cells
 * \param[in] struct sheet * sh
 * \param[in] v1
 * \param[in] v2
 * \return none
 */
void lock_cells(struct sheet * sh, struct ent * v1, struct ent * v2) {
    int r, c;
    struct ent * n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(sh, &maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

#ifdef UNDO
    create_undo_action();
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_DEL, IGNORE_DEPS, NULL);
#endif
    for (r = minr; r <= maxr; r++)
        for (c = minc; c <= maxc; c++) {
            n = lookat(sh, r, c);
            n->flags |= is_locked;
        }
#ifdef UNDO
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_ADD, IGNORE_DEPS, NULL);
    end_undo_action();
#endif
    sc_info("Cells were locked");
}


/**
 * \brief Unlock a range of cells
 * \param[in] struct sheet * sh
 * \param[in] v1
 * \param[in] v2
 * \return none
 */
void unlock_cells(struct sheet * sh, struct ent * v1, struct ent * v2) {
    int r, c;
    struct ent * n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(sh, &maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

#ifdef UNDO
    create_undo_action();
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_DEL, IGNORE_DEPS, NULL);
#endif
    for (r = minr; r <= maxr; r++)
        for (c = minc; c <= maxc; c++) {
            n = lookat(sh, r, c);
            n->flags &= ~is_locked;
        }
#ifdef UNDO
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_ADD, IGNORE_DEPS, NULL);
    end_undo_action();
#endif
    sc_info("Cells were unlocked");
}


/**
 * \brief Set the numeric part of a cell
 * \param[in] v
 * \param[in] e
 * \return none
 */
void let(SC *const sc, struct roman * roman, struct sheet * sh, struct ent * v, struct enode * e) {
    if (locked_cell(sh, v->row, v->col)) return;

    #ifdef UNDO
    extern struct ent_ptr * deps;
    if (! roman->loading) {
        create_undo_action();
        // here we save in undostruct, all the ents that depends on the deleted one (before change)
        ents_that_depends_on_range(sh, v->row, v->col, v->row, v->col);
        copy_to_undostruct(sh, v->row, v->col, v->row, v->col, UNDO_DEL, HANDLE_DEPS, NULL);
    }
    #endif

    double val;
    unsigned isconstant = constant(e);

    if (v->row == sh->currow && v->col == sh->curcol) cellassign = 1;

    if (roman->loading && ! isconstant)
        val = (double) 0.0;
    else {
        exprerr = 0;
        (void) signal(SIGFPE, eval_fpe);
        if (setjmp(fpe_save)) {
            sc_error("Floating point exception in cell %s", v_name(v->row, v->col));
            val = (double)0.0;
            cellerror = CELLERROR;
        } else {
            cellerror = CELLOK;
            val = eval(sc, sh, v, e); // JUST NUMERIC VALUE
        }
        if (v->cellerror != cellerror) {
            v->flags |= is_changed;
            roman->modflg++;
            v->cellerror = cellerror;
        }
        (void) signal(SIGFPE, exit_app);
        if (exprerr) {
            efree(e);
            #ifdef UNDO
            if (! roman->loading) dismiss_undo_item(NULL);
            #endif
            return;
        }
    }

    if (isconstant) {
        /* prescale input unless it has a decimal */
        if ( ! roman->loading && !decimal && (prescale < (double) 0.9999999))
            val *= prescale;
        decimal = false;

        v->v = val;

        if ( !(v->flags & is_strexpr) ) {
            efree(v->expr);
            v->expr = (struct enode *) 0;
        }
        efree(e);
    } else if (! exprerr) {
        efree(v->expr);

        v->expr = e;
        v->flags &= ~is_strexpr;
        eval(sc, sh, v, e); // ADDED - here we store the cell dependences in a graph
    }
    if (v->cellerror == CELLOK) v->flags |= ( is_changed | is_valid );
    roman->modflg++;
    if (( v->trigger  ) && ((v->trigger->flag & TRG_WRITE) == TRG_WRITE))
        do_trigger(v,TRG_WRITE);


    if (! roman->loading && cellerror == CELLERROR) { /* issue #201 */
        if (v->expr) efree(v->expr);
        v->expr = NULL;
    }
    #ifdef UNDO
    if (! roman->loading) {
        // here we also save in undostruct, all the ents that depends on the deleted ones (after change)
        copy_to_undostruct(sh, v->row, v->col, v->row, v->col, UNDO_ADD, HANDLE_DEPS, NULL);
        if (deps != NULL) {
            free(deps);
            deps = NULL;
        }
        end_undo_action();
    }
    #endif

    return;
}


/**
 * \brief slet()
 * \param[in] v
 * \param[in] se
 * \param[in] flushdir
 * \return none
 */
void slet(SC *const sc, struct roman * roman, struct sheet * sh, struct ent * v, struct enode * se, int flushdir) {
    if (locked_cell(sh, v->row, v->col)) return;

    #ifdef UNDO
    extern struct ent_ptr * deps;
    if (! roman->loading) {
        // here we save in undostruct, all the ents that depends on the deleted one (before change)
        ents_that_depends_on_range(sh, v->row, v->col, v->row, v->col);
        create_undo_action();
        copy_to_undostruct(sh, v->row, v->col, v->row, v->col, UNDO_DEL, HANDLE_DEPS, NULL);
        add_undo_row_format(v->row, 'R', sh->row_format[v->row]);
    }
    #endif
    // No debe borrarse el vertex. Ver comentario en LET
    //if (getVertex(graph, lookat(v->row, v->col), 0) != NULL) destroy_vertex(lookat(v->row, v->col));

    char * p;
    if (v->row == sh->currow && v->col == sh->curcol) cellassign = 1;
    exprerr = 0;

    (void) signal(SIGFPE, eval_fpe);
    if (setjmp(fpe_save)) {
        sc_error ("Floating point exception in cell %s", v_name(v->row, v->col));
        cellerror = CELLERROR;
        p = "";
    } else if (v->flags & is_strexpr || v->expr) {
        cellerror = CELLOK;
        p = seval(sc, sh, v, se);
    } else {
        cellerror = CELLOK;
        p = seval(sc, sh, NULL, se);
    }
    if (v->cellerror != cellerror) {
        v->flags |= is_changed;
        roman->modflg++;
        v->cellerror = cellerror;
    }
    (void) signal(SIGFPE, exit_app);
    if (exprerr) {
        efree(se);
        sc_error("error in slet - exprerr");
    } else if (constant(se)) {
        label(v, p, flushdir);

        if (p) scxfree(p);
        p = NULL;
        efree(se);
        if (v->flags & is_strexpr) {
            efree(v->expr);
            v->expr = (struct enode *) 0;
            v->flags &= ~is_strexpr;
        }
        // entering new label for changing a datetime value
        if (v->format && v->format[0] == 'd') {
            struct tm tm;
            memset(&tm, 0, sizeof(struct tm));
            strptime(v->label, &v->format[1], &tm);
            v->v = (double) mktime(&tm);
            v->flags |= ( is_changed | is_valid );
            label(v, "", -1); // free label
        }
    } else {
        if (p) free(p);                     // This prevents leaks in string formulas - missing in old sc
        p = NULL;

        efree(v->expr);
        v->expr = se;

        p = seval(sc, sh, v, se);                 /* ADDED for #652 - here we store the cell dependences in a graph */
        if (p) scxfree(p);                    /***/

        v->flags |= (is_changed | is_strexpr);
        if (flushdir < 0) v->flags |= is_leftflush;

        if (flushdir == 0)
            v->flags |= is_label;
        else
            v->flags &= ~is_label;
    }
    roman->modflg++;
    if (( v->trigger  ) && ((v->trigger->flag & TRG_WRITE) == TRG_WRITE)) do_trigger(v,TRG_WRITE);

#ifdef UNDO
    if (! roman->loading) {
        // here we also save in undostruct, all the ents that depends on the deleted ones (after change)
        copy_to_undostruct(sh, v->row, v->col, v->row, v->col, UNDO_ADD, HANDLE_DEPS, NULL);
        if (deps != NULL) {
            free(deps);
            deps = NULL;
        }
        end_undo_action();
    }
#endif
    return;
}


/**
 * \brief format_cell()
 * \param[in] struct sheet * sh
 * \param[in] v1
 * \param[in] v2
 * \param[in] s
 * \return none
 */
void format_cell(struct sheet * sh, struct ent * v1, struct ent * v2, char *s) {
    int r, c;
    struct ent *n;
    int maxr, maxc;
    int minr, minc;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(sh, &maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    session->cur_doc->modflg++;

    for (r = minr; r <= maxr; r++)
        for (c = minc; c <= maxc; c++) {
            n = lookat(sh, r, c);
            if (locked_cell(sh, n->row, n->col))
                continue;
            if (n->format)
                scxfree(n->format);
            n->format = 0;
            if (s && *s != '\0')
                n->format = strcpy(scxmalloc( (unsigned) (strlen(s) + 1)), s);
            n->flags |= is_changed;
        }
    return;
}


/**
 * \brief Say if an expression is a constant or not
 * \param[in] e
 * \return 1 function is an expression
 * \return 0 function is not an expression
 */
bool
constant(const struct enode *const e) {
    return e == NULL
     || e->op == O_CONST
     || e->op == O_SCONST
     || (e->op == 'm' && constant(e->left))
     || (e->op != O_VAR
         && !(e->op & REDUCE)
         && constant(e->left)
         && constant(e->right)
         && e->op != EXT     /* functions look like constants but aren't */
#ifdef XLUA
         && e->op != LUA
#endif
         && e->op != NVAL
         && e->op != SVAL
         && e->op != NOW
         && e->op != MYROW
         && e->op != MYCOL
         && e->op != LASTROW
         && e->op != LASTCOL
         && e->op != NUMITER
         && e->op != FILENAME
         && optimize );
}


/**
 * \brief efree()
 * \param[in] e
 * \return none
 */
void efree(struct enode * e) {
    if (e) {
        /* for get ent ---> */
        if (e->range.left.vp && e->range.left.vf & GET_ENT) {
            efree(e->range.left.expr);
            e->range.left.expr = NULL;
        }
        if (e->range.right.vp && e->range.right.vf & GET_ENT) {
            efree(e->range.right.expr);
            e->range.right.expr = NULL;
        } /* <-- for get ent */

        if (e->op != O_VAR && e->op != O_CONST && e->op != O_SCONST && !(e->op & REDUCE) && e->op != ERR_) {
            if (e->left) efree(e->left);
            e->left = NULL;
            if (e->right) efree(e->right);
            e->right = NULL;
        }
        if (e->op == O_SCONST && e->str) {
            scxfree(e->str);
            e->str = NULL;
        } else if (e->op == EXT && e->last_func_str) {
            scxfree(e->last_func_str);
            e->last_func_str = NULL;
            if (e->left) efree(e->left);
            e->left = NULL;
            if (e->right) efree(e->right);
            e->right = NULL;
        }
        scxfree((char *) e);
        e = (struct enode *) 0;
    }
}


/**
 * \brief label()
 * \param[in] v
 * \param[in] s
 * \param[in] flushdir
 * \return none
 */
void label(struct ent * v, char * s, int flushdir) {
    struct roman * roman = session->cur_doc;
    if (v) {
        /*if (flushdir == 0 && v->flags & is_valid) {
            struct ent * tv;
            if (v->col > 0 && ((tv=lookat(v->row, v->col-1))->flags & is_valid) == 0)
            v = tv, flushdir = 1;
            else if (((tv=lookat(v->row, v->col+1))->flags & is_valid) == 0)
            v = tv, flushdir = -1;
            else flushdir = -1;
        }*/
        if (v->label) {
            scxfree((char *)(v->label));
        }
        if (s && s[0]) {
            v->label = scxmalloc((unsigned)(strlen(s)+1));
            (void) strcpy (v->label, s);
        } else
            v->label = (char *) 0;
        if (flushdir<0) v->flags |= is_leftflush;
        else v->flags &= ~is_leftflush;
        if (flushdir==0) v->flags |= is_label;
        else v->flags &= ~is_label;
        roman->modflg++;
    }
}


/**
 * \brief decodev()
 * \param[in] v
 * \return none
 */
void decodev(struct ent_ptr v) {
    struct range * r;
    if (v.sheet != NULL) {
        (void) sprintf(line + linelim, "{\"%s\"}!", v.sheet->name);
        linelim += strlen(line + linelim);
    }
    //if ( ! v.vp || v.vp->flags & is_deleted)
    //    (void) sprintf(line + linelim, "@ERR");
    //else
    if ( !find_range( (char *) 0, 0, v.vp, v.vp, &r) && !r->r_is_range) {
        (void) sprintf(line+linelim, "%s", r->r_name);
        linelim += strlen(line + linelim);
    } else if (v.vf == GET_ENT) {
        sprintf(line + linelim, "@getent(");
        linelim += strlen(line + linelim);
        if (v.expr && v.expr->left) decompile(v.expr->left, 0);
        line[linelim++] = ',';
        if (v.expr && v.expr->right) decompile(v.expr->right, 0);
        line[linelim++] = ')';
    } else {
        (void) sprintf( line + linelim, "%s%s%s%d", v.vf & FIX_COL ? "$" : "", coltoa(v.vp->col), v.vf & FIX_ROW ? "$" : "", v.vp->row);
        linelim += strlen(line + linelim);
    }
    return;
}


/**
 * \brief coltoa()
 * \details converts a number representing a column to its name.
 * Example 3 to "D"
 * \param[in] col
 * \return none
 */
char * coltoa(int col) {
    static char rname[3];
    char *p = rname;

    if (col > 25) {
        *p++ = col/26 + 'A' - 1;
        col %= 26;
    }
    *p++ = col+'A';
    *p = '\0';
    return (rname);
}


/**
 * \brief decompile_list()
 * \details To make list elements come out in the same order
 * they were entered, we must do a depth-first eval of the
 * ELIST tree.
 * \param[in] p
 * \return none
 */
void decompile_list(struct enode *p) {
    if (!p) return;
    decompile_list(p->left);    /* depth first */
    decompile(p->right, 0);
    line[linelim++] = ',';
}


/**
 * \brief decompile()
 * \param[in] e
 * \param[in] priority
 * \return none
 */
void decompile(struct enode *e, int priority) {
    char *s;
    if (e) {
    int mypriority;
    switch (e->op) {
    default: mypriority = 99; break;
    case ';': mypriority = 1; break;
    case '?': mypriority = 2; break;
    case ':': mypriority = 3; break;
    case '|': mypriority = 4; break;
    case '&': mypriority = 5; break;
    case '<': case '=': case '>': mypriority = 6; break;
    case '+': case '-': case '#': mypriority = 8; break;
    case '*': case '/': case '%': mypriority = 10; break;
    case '^': mypriority = 12; break;
    }
    if (mypriority<priority) line[linelim++] = '(';
    switch (e->op) {
    case 'f':
            for (s="@fixed "; (line[linelim++] = *s++); );
            linelim--;
            decompile(e->left, 30);
            break;
    case 'F':
            for (s="(@fixed)"; (line[linelim++] = *s++); );
            linelim--;
            decompile(e->left, 30);
            break;
    case 'm':
            if (priority != 0) line[linelim++] = '(';
            line[linelim++] = '-';
            decompile(e->left, 30);
            if (priority != 0) line[linelim++] = ')';
            break;
    case '!':
            line[linelim++] = '!';
            decompile(e->left, 30);
            break;
    case O_VAR:
            decodev(e->ref);
            break;

    case O_CONST:
            (void) sprintf(line+linelim, "%.15g", e->number);
            linelim += strlen(line+linelim);
            break;

    case O_SCONST:
            (void) sprintf(line+linelim, "\"%s\"", e->str);
            linelim += strlen(line+linelim);
            break;

    case SUM    : index_arg("@sum", e); break;
    case PROD   : index_arg("@prod", e); break;
    case AVG    : index_arg("@avg", e); break;
    case COUNT  : index_arg("@count", e); break;
    case STDDEV : index_arg("@stddev", e); break;
    case MAX    : index_arg("@max", e); break;
    case MIN    : index_arg("@min", e); break;
    case REDUCE | 'R': range_arg("@rows(", e); break;
    case REDUCE | 'C': range_arg("@cols(", e); break;
    case GETENT: two_arg("@getent(", e); break;
    case FROW:   one_arg("@frow(", e); break;
    case FCOL:   one_arg("@fcol(", e); break;
    case ABS:    one_arg("@abs(", e); break;
    case ACOS:   one_arg("@acos(", e); break;
    case ASIN:   one_arg("@asin(", e); break;
    case ATAN:   one_arg("@atan(", e); break;
    case ATAN2:  two_arg("@atan2(", e); break;
    case CEIL:   one_arg("@ceil(", e); break;
    case COS:    one_arg("@cos(", e); break;
    case EXP:    one_arg("@exp(", e); break;
    case FABS:   one_arg("@fabs(", e); break;
    case FLOOR:  one_arg("@floor(", e); break;
    case HYPOT:  two_arg("@hypot(", e); break;
    case LOG:    one_arg("@ln(", e); break;
    case LOG10:  one_arg("@log(", e); break;
    case POW:    two_arg("@pow(", e); break;
    case SIN:    one_arg("@sin(", e); break;
    case SQRT:   one_arg("@sqrt(", e); break;
    case TAN:    one_arg("@tan(", e); break;
    case DTR:    one_arg("@dtr(", e); break;
    case RTD:    one_arg("@rtd(", e); break;
    case RND:    one_arg("@rnd(", e); break;
    case ROUND:  two_arg("@round(", e); break;
    case HOUR:   one_arg("@hour(", e); break;
    case MINUTE: one_arg("@minute(", e); break;
    case SECOND: one_arg("@second(", e); break;
    case MONTH:  one_arg("@month(", e); break;
    case DAY:    one_arg("@day(", e); break;
    case YEAR:   one_arg("@year(", e); break;
    case NOW:
            for (s = "@now"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case DATE:
            if (e->right)
                two_arg("@date(", e);
            else
                one_arg("@date(", e);
            break;
    case FMT:   two_arg("@fmt(", e); break;
    case UPPER: one_arg("@upper(", e); break;
    case LOWER: one_arg("@lower(", e); break;
    case CAPITAL: one_arg("@capital(", e); break;
    case DTS:   three_arg("@dts(", e); break;
    case TTS:   three_arg("@tts(", e); break;
    case STON:  one_arg("@ston(", e); break;
    case ASCII: one_arg("@ascii(", e); break;
    case SLEN:  one_arg("@slen(", e); break;
    case EQS:   two_arg("@eqs(", e); break;
    case LMAX:  list_arg("@max(", e); break;
    case LMIN:  list_arg("@min(", e); break;
    case FV:    three_arg("@fv(", e); break;
    case PV:    three_arg("@pv(", e); break;
    case PMT:   three_arg("@pmt(", e); break;
    case NVAL:  two_arg("@nval(", e); break;
    case SVAL:  two_arg("@sval(", e); break;
    case EXT:   two_arg("@ext(", e); break;
    case EVALUATE: one_arg("@evaluate(", e); break;
    case SEVALUATE: one_arg("@sevaluate(", e); break;
#ifdef XLUA
    case LUA:   two_arg("@lua(", e); break;
#endif
    case SUBSTR:  three_arg("@substr(", e); break;
    case REPLACE: three_arg("@replace(", e); break;
    case STINDEX: index_arg("@stindex", e); break;
    case INDEX: index_arg("@index", e); break;
    case LOOKUP:  index_arg("@lookup", e); break;
    case HLOOKUP: two_arg_index("@hlookup", e); break;
    case VLOOKUP: two_arg_index("@vlookup", e); break;
    case IF:    three_arg("@if(", e); break;
    case MYROW:
            for (s = "@myrow"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case MYCOL:
            for (s = "@mycol"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case LASTROW:
            for (s = "@lastrow"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case LASTCOL:
            for (s = "@lastcol"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case COLTOA:   one_arg( "@coltoa(", e); break;
    case CHR:      one_arg( "@chr(", e); break;
    case FILENAME: one_arg( "@filename(", e); break;
    case NUMITER:
            for (s = "@numiter"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case ERR_:
            for (s = "@err"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case REF_:
            for (s = "@ref"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case PI_:
            for (s = "@pi"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case BLACK:
            for (s = "@black"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case RED:
            for (s = "@red"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case GREEN:
            for (s = "@green"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case YELLOW:
            for (s = "@yellow"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case BLUE:
            for (s = "@blue"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case MAGENTA:
            for (s = "@magenta"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case CYAN:
            for (s = "@cyan"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case WHITE:
            for (s = "@white"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case DEFAULT_COLOR:
            for (s = "@default_color"; (line[linelim++] = *s++); );
            linelim--;
            break;
    case FACT:    one_arg("@fact(", e); break;
    default:
            decompile(e->left, mypriority);
            line[linelim++] = e->op;
            decompile(e->right, mypriority+1);
            break;
    }
    if (mypriority<priority) line[linelim++] = ')';
    } else line[linelim++] = '?';
}


/**
 * \brief index_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void index_arg(char *s, struct enode *e) {
    if (e->right && e->right->op == ',') {
        two_arg_index(s, e);
        return;
    }
    for (; (line[linelim++] = *s++); );
    linelim--;
    range_arg("(", e->left);
    linelim--;
    if (e->right) {
        line[linelim++] = ',';
        decompile(e->right, 0);
    }
    line[linelim++] = ')';
}


/**
 * \brief two_arg_index()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void two_arg_index(char *s, struct enode *e) {
    for (; (line[linelim++] = *s++); );
    linelim--;
    range_arg("(", e->left);
    linelim--;
    line[linelim++] = ',';
    decompile(e->right->left, 0);
    line[linelim++] = ',';
    decompile(e->right->right, 0);
    line[linelim++] = ')';
}


/**
 * \brief list_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void list_arg(char *s, struct enode *e) {
    for (; (line[linelim++] = *s++); );
    linelim--;

    decompile(e->right, 0);
    line[linelim++] = ',';
    decompile_list(e->left);
    line[linelim - 1] = ')';
}


/**
 * \brief one_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void one_arg(char *s, struct enode *e) {
    for (; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->left, 0);
    line[linelim++] = ')';
}


/**
 * \brief two_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void two_arg(char *s, struct enode *e) {
    for (; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->left, 0);
    line[linelim++] = ',';
    decompile (e->right, 0);
    line[linelim++] = ')';
}


/**
 * \brief three_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void three_arg(char *s, struct enode *e) {
    for (; (line[linelim++] = *s++); );
    linelim--;
    decompile(e->left, 0);
    line[linelim++] = ',';
    decompile(e->right->left, 0);
    line[linelim++] = ',';
    decompile (e->right->right, 0);
    line[linelim++] = ')';
}


/**
 * \brief range_arg()
 * \param[in] s
 * \param[in] e
 * \return none
 */
void range_arg(char *s, struct enode *e) {
    struct range *r;

    for (; (line[linelim++] = *s++); );
    linelim--;
    if ( ! find_range((char *)0, 0, e->range.left.vp, e->range.right.vp, &r) && r->r_is_range) {
        (void) sprintf(line+linelim, "%s", r->r_name);
        linelim += strlen(line+linelim);
    } else {
        decodev(e->range.left);
        line[linelim++] = ':';
        decodev(e->range.right);
    }
    line[linelim++] = ')';
}


/**
 * \brief editfmt()
 * \param[in] struct sheet * sh
 * \param[in] row
 * \param[in] col
 * \return none
 */
void editfmt(struct sheet * sh, int row, int col) {
    struct ent * p = lookat(sh, row, col);
    if (p->format) {
        (void) sprintf(line, "fmt %s \"%s\"", v_name(row, col), p->format);
        linelim = strlen(line);
    }
}


/**
 * \brief editv()
 * \param[in] struct sheet * sh
 * \param[in] row
 * \param[in] col
 * \return none
 */
void editv(struct sheet * sh, int row, int col) {
    struct ent *p;

    p = lookat(sh, row, col);
    (void) sprintf(line, "let %s = ", v_name(row, col));
    linelim = strlen(line);
    if (p->flags & is_valid || p->expr) {
        if (p->flags & is_strexpr || p->expr == NULL) {
            (void) sprintf(line+linelim, "%.15g", p->v);
            linelim = strlen(line);
        } else
            editexp(sh, row, col);
    }
}


/**
 * \brief editexp()
 * \param[in] struct sheet * sh
 * \param[in] row
 * \param[in] col
 * \return none
 */
void editexp(struct sheet * sh, int row, int col) {
    struct ent * p;
    p = lookat(sh, row, col);
    //if ( !p || !p->expr ) return; 21/06/2014
    decompile(p->expr, 0);
    line[linelim] = '\0';
}


/**
 * \brief edits()
 * \param[in] struct sheet * sh
 * \param[in] row
 * \param[in] col
 * \param[in] saveinfile
 * \return none
 */
void edits(struct sheet * sh, int row, int col, int saveinfile) {
    struct ent *p;
    p = lookat(sh, row, col);

    if (saveinfile) {
        if (p->flags & is_label)
               (void) sprintf(line, "label %s = ", v_name(row, col));
        else
            (void) sprintf(line, "%sstring %s = ", ((p->flags & is_leftflush) ? "left" : "right"), v_name(row, col));
    }

    linelim = strlen(line);
    if (p->flags & is_strexpr && p->expr) {
    editexp(sh, row, col);
    } else if (p->label) {
        if (saveinfile) {
            (void) sprintf(line+linelim, "\"%s\"", p->label);
        } else {
            (void) sprintf(line+linelim, "%s", p->label);
        }
        linelim += strlen(line+linelim);
    } else {
        (void) sprintf(line+linelim, "\"");
        linelim += 1;
    }
 }


/**
 * \brief dateformat()
 * \param[in] struct sheet * sh
 * \param[in] v1
 * \param[in] v2
 * \param[in] fmt
 * \return none
 */
int dateformat(struct sheet * sh, struct ent *v1, struct ent *v2, char * fmt) {
    if ( ! fmt || *fmt == '\0') return -1;

    int r, c;
    struct ent * n;
    int maxr, maxc;
    int minr, minc;
    struct tm tm;

    maxr = v2->row;
    maxc = v2->col;
    minr = v1->row;
    minc = v1->col;
    if (minr>maxr) r = maxr, maxr = minr, minr = r;
    if (minc>maxc) c = maxc, maxc = minc, minc = c;
    checkbounds(sh, &maxr, &maxc);
    if (minr < 0) minr = 0;
    if (minc < 0) minc = 0;

    #ifdef UNDO
    create_undo_action();
    copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_DEL, IGNORE_DEPS, NULL);
    #endif
    for (r = minr; r <= maxr; r++) {
        for (c = minc; c <= maxc; c++) {
            n = lookat(sh, r, c);
            if (locked_cell(sh, n->row, n->col) || ! (n)->label) continue;

            // free all ent content but its label
            n->v = (double) 0;
            if (n->format) scxfree(n->format);
            if (n->expr) efree(n->expr);
            n->expr = NULL;

            memset(&tm, 0, sizeof(struct tm));
            strptime((n)->label, fmt, &tm);
            n->v = (double) mktime(&tm);
            n->flags |= ( is_changed | is_valid );
            label(n, "", -1); // free label

            // agrego formato de fecha
            n->format = 0;
            char * s = scxmalloc((unsigned)(strlen(fmt)+2));
            sprintf(s, "%c", 'd');
            strcat(s, fmt);
            n->format = s;
        }
    }
    #ifdef UNDO
        copy_to_undostruct(sh, minr, minc, maxr, maxc, UNDO_ADD, IGNORE_DEPS, NULL);
        end_undo_action();
    #endif
    session->cur_doc->modflg++; // increase just one time
    return 0;
}
