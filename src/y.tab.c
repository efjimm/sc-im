/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/evan/documents/packages/source/scim-test/src/gram.y"

#include <stdlib.h>

#include "sc.h"
#include "cmds/cmds.h"
#include "interp.h"
#include "macros.h"
#include "actions/sort.h"
#include "actions/filter.h"
#include "maps.h"
#include "marks.h"
#include "xmalloc.h" // for scxfree
#include "actions/hide_show.h"
#include "cmds/cmds_normal.h"
#include "conf.h"
#include "pipe.h"
#include "main.h"
#include "file.h"
#include "tui.h"
#include "undo.h"
#include "yank.h"
#include "graph.h"
#include "utils/dictionary.h"
#include "trigger.h"
#include "actions/shift.h"
#include "clipboard.h"
#include "actions/plot.h"
#include "actions/subtotal.h"
#include "actions/freeze.h"
#include "sheet.h"
#include "vmtbl.h"
#include "cmds/cmds_command.h"

void yyerror(char *err);               // error routine for yacc (gram.y)
int yylex();
extern struct session * session;

#ifdef USELOCALE
#include <locale.h>
#endif

#ifndef MSDOS
#include <unistd.h>
#endif

#define ENULL (struct enode *) 0

#line 119 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    COL = 259,                     /* COL  */
    NUMBER = 260,                  /* NUMBER  */
    FNUMBER = 261,                 /* FNUMBER  */
    RANGE = 262,                   /* RANGE  */
    VAR = 263,                     /* VAR  */
    WORD = 264,                    /* WORD  */
    MAPWORD = 265,                 /* MAPWORD  */
    PLUGIN = 266,                  /* PLUGIN  */
    S_SHOW = 267,                  /* S_SHOW  */
    S_HIDE = 268,                  /* S_HIDE  */
    S_SHOWROW = 269,               /* S_SHOWROW  */
    S_HIDEROW = 270,               /* S_HIDEROW  */
    S_SHOWCOL = 271,               /* S_SHOWCOL  */
    S_HIDECOL = 272,               /* S_HIDECOL  */
    S_FREEZE = 273,                /* S_FREEZE  */
    S_UNFREEZE = 274,              /* S_UNFREEZE  */
    S_MARK = 275,                  /* S_MARK  */
    S_AUTOFIT = 276,               /* S_AUTOFIT  */
    S_PAD = 277,                   /* S_PAD  */
    S_DELETECOL = 278,             /* S_DELETECOL  */
    S_DATEFMT = 279,               /* S_DATEFMT  */
    S_SUBTOTAL = 280,              /* S_SUBTOTAL  */
    S_RSUBTOTAL = 281,             /* S_RSUBTOTAL  */
    S_FORMAT = 282,                /* S_FORMAT  */
    S_FMT = 283,                   /* S_FMT  */
    S_LET = 284,                   /* S_LET  */
    S_LABEL = 285,                 /* S_LABEL  */
    S_LEFTSTRING = 286,            /* S_LEFTSTRING  */
    S_RIGHTSTRING = 287,           /* S_RIGHTSTRING  */
    S_LEFTJUSTIFY = 288,           /* S_LEFTJUSTIFY  */
    S_RIGHTJUSTIFY = 289,          /* S_RIGHTJUSTIFY  */
    S_CENTER = 290,                /* S_CENTER  */
    S_SORT = 291,                  /* S_SORT  */
    S_FILTERON = 292,              /* S_FILTERON  */
    S_GOTO = 293,                  /* S_GOTO  */
    S_GOTOB = 294,                 /* S_GOTOB  */
    S_CCOPY = 295,                 /* S_CCOPY  */
    S_CPASTE = 296,                /* S_CPASTE  */
    S_PLOT = 297,                  /* S_PLOT  */
    S_LOCK = 298,                  /* S_LOCK  */
    S_UNLOCK = 299,                /* S_UNLOCK  */
    S_DEFINE = 300,                /* S_DEFINE  */
    S_UNDEFINE = 301,              /* S_UNDEFINE  */
    S_DETAIL = 302,                /* S_DETAIL  */
    S_EVAL = 303,                  /* S_EVAL  */
    S_SEVAL = 304,                 /* S_SEVAL  */
    S_ERROR = 305,                 /* S_ERROR  */
    S_FILL = 306,                  /* S_FILL  */
    S_STRTONUM = 307,              /* S_STRTONUM  */
    S_DELETEROW = 308,             /* S_DELETEROW  */
    S_VALUEIZEALL = 309,           /* S_VALUEIZEALL  */
    S_SHIFT = 310,                 /* S_SHIFT  */
    S_GETNUM = 311,                /* S_GETNUM  */
    S_YANKAREA = 312,              /* S_YANKAREA  */
    S_PASTEYANKED = 313,           /* S_PASTEYANKED  */
    S_GETSTRING = 314,             /* S_GETSTRING  */
    S_GETEXP = 315,                /* S_GETEXP  */
    S_GETFMT = 316,                /* S_GETFMT  */
    S_GETFORMAT = 317,             /* S_GETFORMAT  */
    S_RECALC = 318,                /* S_RECALC  */
    S_EXECUTE = 319,               /* S_EXECUTE  */
    S_QUIT = 320,                  /* S_QUIT  */
    S_EXPORT = 321,                /* S_EXPORT  */
    S_REBUILD_GRAPH = 322,         /* S_REBUILD_GRAPH  */
    S_PRINT_GRAPH = 323,           /* S_PRINT_GRAPH  */
    S_SYNCREFS = 324,              /* S_SYNCREFS  */
    S_REDO = 325,                  /* S_REDO  */
    S_UNDO = 326,                  /* S_UNDO  */
    S_IMAP = 327,                  /* S_IMAP  */
    S_CMAP = 328,                  /* S_CMAP  */
    S_NEWSHEET = 329,              /* S_NEWSHEET  */
    S_NEXTSHEET = 330,             /* S_NEXTSHEET  */
    S_PREVSHEET = 331,             /* S_PREVSHEET  */
    S_DELSHEET = 332,              /* S_DELSHEET  */
    S_MOVETOSHEET = 333,           /* S_MOVETOSHEET  */
    S_RENAMESHEET = 334,           /* S_RENAMESHEET  */
    S_NMAP = 335,                  /* S_NMAP  */
    S_VMAP = 336,                  /* S_VMAP  */
    S_INOREMAP = 337,              /* S_INOREMAP  */
    S_CNOREMAP = 338,              /* S_CNOREMAP  */
    S_NNOREMAP = 339,              /* S_NNOREMAP  */
    S_VNOREMAP = 340,              /* S_VNOREMAP  */
    S_NUNMAP = 341,                /* S_NUNMAP  */
    S_IUNMAP = 342,                /* S_IUNMAP  */
    S_CUNMAP = 343,                /* S_CUNMAP  */
    S_VUNMAP = 344,                /* S_VUNMAP  */
    S_COLOR = 345,                 /* S_COLOR  */
    S_CELLCOLOR = 346,             /* S_CELLCOLOR  */
    S_UNFORMAT = 347,              /* S_UNFORMAT  */
    S_REDEFINE_COLOR = 348,        /* S_REDEFINE_COLOR  */
    S_DEFINE_COLOR = 349,          /* S_DEFINE_COLOR  */
    S_SET = 350,                   /* S_SET  */
    S_FCOPY = 351,                 /* S_FCOPY  */
    S_FSUM = 352,                  /* S_FSUM  */
    S_TRIGGER = 353,               /* S_TRIGGER  */
    S_UNTRIGGER = 354,             /* S_UNTRIGGER  */
    S_OFFSCR_SC_COLS = 355,        /* S_OFFSCR_SC_COLS  */
    S_OFFSCR_SC_ROWS = 356,        /* S_OFFSCR_SC_ROWS  */
    S_NB_FROZEN_ROWS = 357,        /* S_NB_FROZEN_ROWS  */
    S_NB_FROZEN_COLS = 358,        /* S_NB_FROZEN_COLS  */
    S_NB_FROZEN_SCREENROWS = 359,  /* S_NB_FROZEN_SCREENROWS  */
    S_NB_FROZEN_SCREENCOLS = 360,  /* S_NB_FROZEN_SCREENCOLS  */
    K_AUTOBACKUP = 361,            /* K_AUTOBACKUP  */
    K_NOAUTOBACKUP = 362,          /* K_NOAUTOBACKUP  */
    K_AUTOCALC = 363,              /* K_AUTOCALC  */
    K_NOAUTOCALC = 364,            /* K_NOAUTOCALC  */
    K_DEBUG = 365,                 /* K_DEBUG  */
    K_NODEBUG = 366,               /* K_NODEBUG  */
    K_TRG = 367,                   /* K_TRG  */
    K_NOTRG = 368,                 /* K_NOTRG  */
    K_EXTERNAL_FUNCTIONS = 369,    /* K_EXTERNAL_FUNCTIONS  */
    K_NOEXTERNAL_FUNCTIONS = 370,  /* K_NOEXTERNAL_FUNCTIONS  */
    K_EXEC_LUA = 371,              /* K_EXEC_LUA  */
    K_NOEXEC_LUA = 372,            /* K_NOEXEC_LUA  */
    K_HALF_PAGE_SCROLL = 373,      /* K_HALF_PAGE_SCROLL  */
    K_NOHALF_PAGE_SCROLL = 374,    /* K_NOHALF_PAGE_SCROLL  */
    K_NOCURSES = 375,              /* K_NOCURSES  */
    K_CURSES = 376,                /* K_CURSES  */
    K_NUMERIC = 377,               /* K_NUMERIC  */
    K_NONUMERIC = 378,             /* K_NONUMERIC  */
    K_NUMERIC_DECIMAL = 379,       /* K_NUMERIC_DECIMAL  */
    K_NONUMERIC_DECIMAL = 380,     /* K_NONUMERIC_DECIMAL  */
    K_NUMERIC_ZERO = 381,          /* K_NUMERIC_ZERO  */
    K_NONUMERIC_ZERO = 382,        /* K_NONUMERIC_ZERO  */
    K_OVERLAP = 383,               /* K_OVERLAP  */
    K_NOOVERLAP = 384,             /* K_NOOVERLAP  */
    K_INPUT_BAR_BOTTOM = 385,      /* K_INPUT_BAR_BOTTOM  */
    K_IGNORE_HIDDEN = 386,         /* K_IGNORE_HIDDEN  */
    K_NOIGNORE_HIDDEN = 387,       /* K_NOIGNORE_HIDDEN  */
    K_UNDERLINE_GRID = 388,        /* K_UNDERLINE_GRID  */
    K_TRUNCATE = 389,              /* K_TRUNCATE  */
    K_NOTRUNCATE = 390,            /* K_NOTRUNCATE  */
    K_AUTOWRAP = 391,              /* K_AUTOWRAP  */
    K_NOAUTOWRAP = 392,            /* K_NOAUTOWRAP  */
    K_QUIET = 393,                 /* K_QUIET  */
    K_NOQUIET = 394,               /* K_NOQUIET  */
    K_QUIT_AFTERLOAD = 395,        /* K_QUIT_AFTERLOAD  */
    K_NOQUIT_AFTERLOAD = 396,      /* K_NOQUIT_AFTERLOAD  */
    K_XLSX_READFORMULAS = 397,     /* K_XLSX_READFORMULAS  */
    K_NOXLSX_READFORMULAS = 398,   /* K_NOXLSX_READFORMULAS  */
    K_DEFAULT_COPY_TO_CLIPBOARD_CMD = 399, /* K_DEFAULT_COPY_TO_CLIPBOARD_CMD  */
    K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD = 400, /* K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD  */
    K_COPY_TO_CLIPBOARD_DELIMITED_TAB = 401, /* K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
    K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB = 402, /* K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
    K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD = 403, /* K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD  */
    K_IGNORECASE = 404,            /* K_IGNORECASE  */
    K_NOIGNORECASE = 405,          /* K_NOIGNORECASE  */
    K_TM_GMTOFF = 406,             /* K_TM_GMTOFF  */
    K_COMMAND_TIMEOUT = 407,       /* K_COMMAND_TIMEOUT  */
    K_MAPPING_TIMEOUT = 408,       /* K_MAPPING_TIMEOUT  */
    K_NEWLINE_ACTION = 409,        /* K_NEWLINE_ACTION  */
    K_SHOW_CURSOR = 410,           /* K_SHOW_CURSOR  */
    K_NOSHOW_CURSOR = 411,         /* K_NOSHOW_CURSOR  */
    K_ERROR = 412,                 /* K_ERROR  */
    K_INVALID = 413,               /* K_INVALID  */
    K_FIXED = 414,                 /* K_FIXED  */
    K_SUM = 415,                   /* K_SUM  */
    K_PROD = 416,                  /* K_PROD  */
    K_AVG = 417,                   /* K_AVG  */
    K_STDDEV = 418,                /* K_STDDEV  */
    K_COUNT = 419,                 /* K_COUNT  */
    K_ROWS = 420,                  /* K_ROWS  */
    K_COLS = 421,                  /* K_COLS  */
    K_ABS = 422,                   /* K_ABS  */
    K_FROW = 423,                  /* K_FROW  */
    K_FCOL = 424,                  /* K_FCOL  */
    K_ACOS = 425,                  /* K_ACOS  */
    K_ASIN = 426,                  /* K_ASIN  */
    K_ATAN = 427,                  /* K_ATAN  */
    K_ATAN2 = 428,                 /* K_ATAN2  */
    K_CEIL = 429,                  /* K_CEIL  */
    K_COS = 430,                   /* K_COS  */
    K_EXP = 431,                   /* K_EXP  */
    K_FABS = 432,                  /* K_FABS  */
    K_FLOOR = 433,                 /* K_FLOOR  */
    K_HYPOT = 434,                 /* K_HYPOT  */
    K_LN = 435,                    /* K_LN  */
    K_LOG = 436,                   /* K_LOG  */
    K_PI = 437,                    /* K_PI  */
    K_POW = 438,                   /* K_POW  */
    K_SIN = 439,                   /* K_SIN  */
    K_SQRT = 440,                  /* K_SQRT  */
    K_TAN = 441,                   /* K_TAN  */
    K_DTR = 442,                   /* K_DTR  */
    K_RTD = 443,                   /* K_RTD  */
    K_MAX = 444,                   /* K_MAX  */
    K_MIN = 445,                   /* K_MIN  */
    K_RND = 446,                   /* K_RND  */
    K_ROUND = 447,                 /* K_ROUND  */
    K_IF = 448,                    /* K_IF  */
    K_PV = 449,                    /* K_PV  */
    K_FV = 450,                    /* K_FV  */
    K_PMT = 451,                   /* K_PMT  */
    K_HOUR = 452,                  /* K_HOUR  */
    K_MINUTE = 453,                /* K_MINUTE  */
    K_SECOND = 454,                /* K_SECOND  */
    K_MONTH = 455,                 /* K_MONTH  */
    K_DAY = 456,                   /* K_DAY  */
    K_YEAR = 457,                  /* K_YEAR  */
    K_NOW = 458,                   /* K_NOW  */
    K_DATE = 459,                  /* K_DATE  */
    K_DTS = 460,                   /* K_DTS  */
    K_TTS = 461,                   /* K_TTS  */
    K_FMT = 462,                   /* K_FMT  */
    K_REPLACE = 463,               /* K_REPLACE  */
    K_SUBSTR = 464,                /* K_SUBSTR  */
    K_UPPER = 465,                 /* K_UPPER  */
    K_LOWER = 466,                 /* K_LOWER  */
    K_CAPITAL = 467,               /* K_CAPITAL  */
    K_STON = 468,                  /* K_STON  */
    K_SLEN = 469,                  /* K_SLEN  */
    K_EQS = 470,                   /* K_EQS  */
    K_EXT = 471,                   /* K_EXT  */
    K_EVALUATE = 472,              /* K_EVALUATE  */
    K_SEVALUATE = 473,             /* K_SEVALUATE  */
    K_LUA = 474,                   /* K_LUA  */
    K_NVAL = 475,                  /* K_NVAL  */
    K_SVAL = 476,                  /* K_SVAL  */
    K_LOOKUP = 477,                /* K_LOOKUP  */
    K_HLOOKUP = 478,               /* K_HLOOKUP  */
    K_VLOOKUP = 479,               /* K_VLOOKUP  */
    K_INDEX = 480,                 /* K_INDEX  */
    K_STINDEX = 481,               /* K_STINDEX  */
    K_GETENT = 482,                /* K_GETENT  */
    K_TBLSTYLE = 483,              /* K_TBLSTYLE  */
    K_TBL = 484,                   /* K_TBL  */
    K_LATEX = 485,                 /* K_LATEX  */
    K_SLATEX = 486,                /* K_SLATEX  */
    K_TEX = 487,                   /* K_TEX  */
    K_FRAME = 488,                 /* K_FRAME  */
    K_RNDTOEVEN = 489,             /* K_RNDTOEVEN  */
    K_FILENAME = 490,              /* K_FILENAME  */
    K_MYROW = 491,                 /* K_MYROW  */
    K_MYCOL = 492,                 /* K_MYCOL  */
    K_LASTROW = 493,               /* K_LASTROW  */
    K_LASTCOL = 494,               /* K_LASTCOL  */
    K_COLTOA = 495,                /* K_COLTOA  */
    K_CRACTION = 496,              /* K_CRACTION  */
    K_CRROW = 497,                 /* K_CRROW  */
    K_CRCOL = 498,                 /* K_CRCOL  */
    K_ROWLIMIT = 499,              /* K_ROWLIMIT  */
    K_COLLIMIT = 500,              /* K_COLLIMIT  */
    K_PAGESIZE = 501,              /* K_PAGESIZE  */
    K_ERR = 502,                   /* K_ERR  */
    K_REF = 503,                   /* K_REF  */
    K_LOCALE = 504,                /* K_LOCALE  */
    K_SET8BIT = 505,               /* K_SET8BIT  */
    K_ASCII = 506,                 /* K_ASCII  */
    K_CHR = 507,                   /* K_CHR  */
    K_FACT = 508                   /* K_FACT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRING 258
#define COL 259
#define NUMBER 260
#define FNUMBER 261
#define RANGE 262
#define VAR 263
#define WORD 264
#define MAPWORD 265
#define PLUGIN 266
#define S_SHOW 267
#define S_HIDE 268
#define S_SHOWROW 269
#define S_HIDEROW 270
#define S_SHOWCOL 271
#define S_HIDECOL 272
#define S_FREEZE 273
#define S_UNFREEZE 274
#define S_MARK 275
#define S_AUTOFIT 276
#define S_PAD 277
#define S_DELETECOL 278
#define S_DATEFMT 279
#define S_SUBTOTAL 280
#define S_RSUBTOTAL 281
#define S_FORMAT 282
#define S_FMT 283
#define S_LET 284
#define S_LABEL 285
#define S_LEFTSTRING 286
#define S_RIGHTSTRING 287
#define S_LEFTJUSTIFY 288
#define S_RIGHTJUSTIFY 289
#define S_CENTER 290
#define S_SORT 291
#define S_FILTERON 292
#define S_GOTO 293
#define S_GOTOB 294
#define S_CCOPY 295
#define S_CPASTE 296
#define S_PLOT 297
#define S_LOCK 298
#define S_UNLOCK 299
#define S_DEFINE 300
#define S_UNDEFINE 301
#define S_DETAIL 302
#define S_EVAL 303
#define S_SEVAL 304
#define S_ERROR 305
#define S_FILL 306
#define S_STRTONUM 307
#define S_DELETEROW 308
#define S_VALUEIZEALL 309
#define S_SHIFT 310
#define S_GETNUM 311
#define S_YANKAREA 312
#define S_PASTEYANKED 313
#define S_GETSTRING 314
#define S_GETEXP 315
#define S_GETFMT 316
#define S_GETFORMAT 317
#define S_RECALC 318
#define S_EXECUTE 319
#define S_QUIT 320
#define S_EXPORT 321
#define S_REBUILD_GRAPH 322
#define S_PRINT_GRAPH 323
#define S_SYNCREFS 324
#define S_REDO 325
#define S_UNDO 326
#define S_IMAP 327
#define S_CMAP 328
#define S_NEWSHEET 329
#define S_NEXTSHEET 330
#define S_PREVSHEET 331
#define S_DELSHEET 332
#define S_MOVETOSHEET 333
#define S_RENAMESHEET 334
#define S_NMAP 335
#define S_VMAP 336
#define S_INOREMAP 337
#define S_CNOREMAP 338
#define S_NNOREMAP 339
#define S_VNOREMAP 340
#define S_NUNMAP 341
#define S_IUNMAP 342
#define S_CUNMAP 343
#define S_VUNMAP 344
#define S_COLOR 345
#define S_CELLCOLOR 346
#define S_UNFORMAT 347
#define S_REDEFINE_COLOR 348
#define S_DEFINE_COLOR 349
#define S_SET 350
#define S_FCOPY 351
#define S_FSUM 352
#define S_TRIGGER 353
#define S_UNTRIGGER 354
#define S_OFFSCR_SC_COLS 355
#define S_OFFSCR_SC_ROWS 356
#define S_NB_FROZEN_ROWS 357
#define S_NB_FROZEN_COLS 358
#define S_NB_FROZEN_SCREENROWS 359
#define S_NB_FROZEN_SCREENCOLS 360
#define K_AUTOBACKUP 361
#define K_NOAUTOBACKUP 362
#define K_AUTOCALC 363
#define K_NOAUTOCALC 364
#define K_DEBUG 365
#define K_NODEBUG 366
#define K_TRG 367
#define K_NOTRG 368
#define K_EXTERNAL_FUNCTIONS 369
#define K_NOEXTERNAL_FUNCTIONS 370
#define K_EXEC_LUA 371
#define K_NOEXEC_LUA 372
#define K_HALF_PAGE_SCROLL 373
#define K_NOHALF_PAGE_SCROLL 374
#define K_NOCURSES 375
#define K_CURSES 376
#define K_NUMERIC 377
#define K_NONUMERIC 378
#define K_NUMERIC_DECIMAL 379
#define K_NONUMERIC_DECIMAL 380
#define K_NUMERIC_ZERO 381
#define K_NONUMERIC_ZERO 382
#define K_OVERLAP 383
#define K_NOOVERLAP 384
#define K_INPUT_BAR_BOTTOM 385
#define K_IGNORE_HIDDEN 386
#define K_NOIGNORE_HIDDEN 387
#define K_UNDERLINE_GRID 388
#define K_TRUNCATE 389
#define K_NOTRUNCATE 390
#define K_AUTOWRAP 391
#define K_NOAUTOWRAP 392
#define K_QUIET 393
#define K_NOQUIET 394
#define K_QUIT_AFTERLOAD 395
#define K_NOQUIT_AFTERLOAD 396
#define K_XLSX_READFORMULAS 397
#define K_NOXLSX_READFORMULAS 398
#define K_DEFAULT_COPY_TO_CLIPBOARD_CMD 399
#define K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD 400
#define K_COPY_TO_CLIPBOARD_DELIMITED_TAB 401
#define K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB 402
#define K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD 403
#define K_IGNORECASE 404
#define K_NOIGNORECASE 405
#define K_TM_GMTOFF 406
#define K_COMMAND_TIMEOUT 407
#define K_MAPPING_TIMEOUT 408
#define K_NEWLINE_ACTION 409
#define K_SHOW_CURSOR 410
#define K_NOSHOW_CURSOR 411
#define K_ERROR 412
#define K_INVALID 413
#define K_FIXED 414
#define K_SUM 415
#define K_PROD 416
#define K_AVG 417
#define K_STDDEV 418
#define K_COUNT 419
#define K_ROWS 420
#define K_COLS 421
#define K_ABS 422
#define K_FROW 423
#define K_FCOL 424
#define K_ACOS 425
#define K_ASIN 426
#define K_ATAN 427
#define K_ATAN2 428
#define K_CEIL 429
#define K_COS 430
#define K_EXP 431
#define K_FABS 432
#define K_FLOOR 433
#define K_HYPOT 434
#define K_LN 435
#define K_LOG 436
#define K_PI 437
#define K_POW 438
#define K_SIN 439
#define K_SQRT 440
#define K_TAN 441
#define K_DTR 442
#define K_RTD 443
#define K_MAX 444
#define K_MIN 445
#define K_RND 446
#define K_ROUND 447
#define K_IF 448
#define K_PV 449
#define K_FV 450
#define K_PMT 451
#define K_HOUR 452
#define K_MINUTE 453
#define K_SECOND 454
#define K_MONTH 455
#define K_DAY 456
#define K_YEAR 457
#define K_NOW 458
#define K_DATE 459
#define K_DTS 460
#define K_TTS 461
#define K_FMT 462
#define K_REPLACE 463
#define K_SUBSTR 464
#define K_UPPER 465
#define K_LOWER 466
#define K_CAPITAL 467
#define K_STON 468
#define K_SLEN 469
#define K_EQS 470
#define K_EXT 471
#define K_EVALUATE 472
#define K_SEVALUATE 473
#define K_LUA 474
#define K_NVAL 475
#define K_SVAL 476
#define K_LOOKUP 477
#define K_HLOOKUP 478
#define K_VLOOKUP 479
#define K_INDEX 480
#define K_STINDEX 481
#define K_GETENT 482
#define K_TBLSTYLE 483
#define K_TBL 484
#define K_LATEX 485
#define K_SLATEX 486
#define K_TEX 487
#define K_FRAME 488
#define K_RNDTOEVEN 489
#define K_FILENAME 490
#define K_MYROW 491
#define K_MYCOL 492
#define K_LASTROW 493
#define K_LASTCOL 494
#define K_COLTOA 495
#define K_CRACTION 496
#define K_CRROW 497
#define K_CRCOL 498
#define K_ROWLIMIT 499
#define K_COLLIMIT 500
#define K_PAGESIZE 501
#define K_ERR 502
#define K_REF 503
#define K_LOCALE 504
#define K_SET8BIT 505
#define K_ASCII 506
#define K_CHR 507
#define K_FACT 508

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "/home/evan/documents/packages/source/scim-test/src/gram.y"

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode * enode;
    char * sval;
    struct range_s rval;

#line 687 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_COL = 4,                        /* COL  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_FNUMBER = 6,                    /* FNUMBER  */
  YYSYMBOL_RANGE = 7,                      /* RANGE  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_WORD = 9,                       /* WORD  */
  YYSYMBOL_MAPWORD = 10,                   /* MAPWORD  */
  YYSYMBOL_PLUGIN = 11,                    /* PLUGIN  */
  YYSYMBOL_S_SHOW = 12,                    /* S_SHOW  */
  YYSYMBOL_S_HIDE = 13,                    /* S_HIDE  */
  YYSYMBOL_S_SHOWROW = 14,                 /* S_SHOWROW  */
  YYSYMBOL_S_HIDEROW = 15,                 /* S_HIDEROW  */
  YYSYMBOL_S_SHOWCOL = 16,                 /* S_SHOWCOL  */
  YYSYMBOL_S_HIDECOL = 17,                 /* S_HIDECOL  */
  YYSYMBOL_S_FREEZE = 18,                  /* S_FREEZE  */
  YYSYMBOL_S_UNFREEZE = 19,                /* S_UNFREEZE  */
  YYSYMBOL_S_MARK = 20,                    /* S_MARK  */
  YYSYMBOL_S_AUTOFIT = 21,                 /* S_AUTOFIT  */
  YYSYMBOL_S_PAD = 22,                     /* S_PAD  */
  YYSYMBOL_S_DELETECOL = 23,               /* S_DELETECOL  */
  YYSYMBOL_S_DATEFMT = 24,                 /* S_DATEFMT  */
  YYSYMBOL_S_SUBTOTAL = 25,                /* S_SUBTOTAL  */
  YYSYMBOL_S_RSUBTOTAL = 26,               /* S_RSUBTOTAL  */
  YYSYMBOL_S_FORMAT = 27,                  /* S_FORMAT  */
  YYSYMBOL_S_FMT = 28,                     /* S_FMT  */
  YYSYMBOL_S_LET = 29,                     /* S_LET  */
  YYSYMBOL_S_LABEL = 30,                   /* S_LABEL  */
  YYSYMBOL_S_LEFTSTRING = 31,              /* S_LEFTSTRING  */
  YYSYMBOL_S_RIGHTSTRING = 32,             /* S_RIGHTSTRING  */
  YYSYMBOL_S_LEFTJUSTIFY = 33,             /* S_LEFTJUSTIFY  */
  YYSYMBOL_S_RIGHTJUSTIFY = 34,            /* S_RIGHTJUSTIFY  */
  YYSYMBOL_S_CENTER = 35,                  /* S_CENTER  */
  YYSYMBOL_S_SORT = 36,                    /* S_SORT  */
  YYSYMBOL_S_FILTERON = 37,                /* S_FILTERON  */
  YYSYMBOL_S_GOTO = 38,                    /* S_GOTO  */
  YYSYMBOL_S_GOTOB = 39,                   /* S_GOTOB  */
  YYSYMBOL_S_CCOPY = 40,                   /* S_CCOPY  */
  YYSYMBOL_S_CPASTE = 41,                  /* S_CPASTE  */
  YYSYMBOL_S_PLOT = 42,                    /* S_PLOT  */
  YYSYMBOL_S_LOCK = 43,                    /* S_LOCK  */
  YYSYMBOL_S_UNLOCK = 44,                  /* S_UNLOCK  */
  YYSYMBOL_S_DEFINE = 45,                  /* S_DEFINE  */
  YYSYMBOL_S_UNDEFINE = 46,                /* S_UNDEFINE  */
  YYSYMBOL_S_DETAIL = 47,                  /* S_DETAIL  */
  YYSYMBOL_S_EVAL = 48,                    /* S_EVAL  */
  YYSYMBOL_S_SEVAL = 49,                   /* S_SEVAL  */
  YYSYMBOL_S_ERROR = 50,                   /* S_ERROR  */
  YYSYMBOL_S_FILL = 51,                    /* S_FILL  */
  YYSYMBOL_S_STRTONUM = 52,                /* S_STRTONUM  */
  YYSYMBOL_S_DELETEROW = 53,               /* S_DELETEROW  */
  YYSYMBOL_S_VALUEIZEALL = 54,             /* S_VALUEIZEALL  */
  YYSYMBOL_S_SHIFT = 55,                   /* S_SHIFT  */
  YYSYMBOL_S_GETNUM = 56,                  /* S_GETNUM  */
  YYSYMBOL_S_YANKAREA = 57,                /* S_YANKAREA  */
  YYSYMBOL_S_PASTEYANKED = 58,             /* S_PASTEYANKED  */
  YYSYMBOL_S_GETSTRING = 59,               /* S_GETSTRING  */
  YYSYMBOL_S_GETEXP = 60,                  /* S_GETEXP  */
  YYSYMBOL_S_GETFMT = 61,                  /* S_GETFMT  */
  YYSYMBOL_S_GETFORMAT = 62,               /* S_GETFORMAT  */
  YYSYMBOL_S_RECALC = 63,                  /* S_RECALC  */
  YYSYMBOL_S_EXECUTE = 64,                 /* S_EXECUTE  */
  YYSYMBOL_S_QUIT = 65,                    /* S_QUIT  */
  YYSYMBOL_S_EXPORT = 66,                  /* S_EXPORT  */
  YYSYMBOL_S_REBUILD_GRAPH = 67,           /* S_REBUILD_GRAPH  */
  YYSYMBOL_S_PRINT_GRAPH = 68,             /* S_PRINT_GRAPH  */
  YYSYMBOL_S_SYNCREFS = 69,                /* S_SYNCREFS  */
  YYSYMBOL_S_REDO = 70,                    /* S_REDO  */
  YYSYMBOL_S_UNDO = 71,                    /* S_UNDO  */
  YYSYMBOL_S_IMAP = 72,                    /* S_IMAP  */
  YYSYMBOL_S_CMAP = 73,                    /* S_CMAP  */
  YYSYMBOL_S_NEWSHEET = 74,                /* S_NEWSHEET  */
  YYSYMBOL_S_NEXTSHEET = 75,               /* S_NEXTSHEET  */
  YYSYMBOL_S_PREVSHEET = 76,               /* S_PREVSHEET  */
  YYSYMBOL_S_DELSHEET = 77,                /* S_DELSHEET  */
  YYSYMBOL_S_MOVETOSHEET = 78,             /* S_MOVETOSHEET  */
  YYSYMBOL_S_RENAMESHEET = 79,             /* S_RENAMESHEET  */
  YYSYMBOL_S_NMAP = 80,                    /* S_NMAP  */
  YYSYMBOL_S_VMAP = 81,                    /* S_VMAP  */
  YYSYMBOL_S_INOREMAP = 82,                /* S_INOREMAP  */
  YYSYMBOL_S_CNOREMAP = 83,                /* S_CNOREMAP  */
  YYSYMBOL_S_NNOREMAP = 84,                /* S_NNOREMAP  */
  YYSYMBOL_S_VNOREMAP = 85,                /* S_VNOREMAP  */
  YYSYMBOL_S_NUNMAP = 86,                  /* S_NUNMAP  */
  YYSYMBOL_S_IUNMAP = 87,                  /* S_IUNMAP  */
  YYSYMBOL_S_CUNMAP = 88,                  /* S_CUNMAP  */
  YYSYMBOL_S_VUNMAP = 89,                  /* S_VUNMAP  */
  YYSYMBOL_S_COLOR = 90,                   /* S_COLOR  */
  YYSYMBOL_S_CELLCOLOR = 91,               /* S_CELLCOLOR  */
  YYSYMBOL_S_UNFORMAT = 92,                /* S_UNFORMAT  */
  YYSYMBOL_S_REDEFINE_COLOR = 93,          /* S_REDEFINE_COLOR  */
  YYSYMBOL_S_DEFINE_COLOR = 94,            /* S_DEFINE_COLOR  */
  YYSYMBOL_S_SET = 95,                     /* S_SET  */
  YYSYMBOL_S_FCOPY = 96,                   /* S_FCOPY  */
  YYSYMBOL_S_FSUM = 97,                    /* S_FSUM  */
  YYSYMBOL_S_TRIGGER = 98,                 /* S_TRIGGER  */
  YYSYMBOL_S_UNTRIGGER = 99,               /* S_UNTRIGGER  */
  YYSYMBOL_S_OFFSCR_SC_COLS = 100,         /* S_OFFSCR_SC_COLS  */
  YYSYMBOL_S_OFFSCR_SC_ROWS = 101,         /* S_OFFSCR_SC_ROWS  */
  YYSYMBOL_S_NB_FROZEN_ROWS = 102,         /* S_NB_FROZEN_ROWS  */
  YYSYMBOL_S_NB_FROZEN_COLS = 103,         /* S_NB_FROZEN_COLS  */
  YYSYMBOL_S_NB_FROZEN_SCREENROWS = 104,   /* S_NB_FROZEN_SCREENROWS  */
  YYSYMBOL_S_NB_FROZEN_SCREENCOLS = 105,   /* S_NB_FROZEN_SCREENCOLS  */
  YYSYMBOL_K_AUTOBACKUP = 106,             /* K_AUTOBACKUP  */
  YYSYMBOL_K_NOAUTOBACKUP = 107,           /* K_NOAUTOBACKUP  */
  YYSYMBOL_K_AUTOCALC = 108,               /* K_AUTOCALC  */
  YYSYMBOL_K_NOAUTOCALC = 109,             /* K_NOAUTOCALC  */
  YYSYMBOL_K_DEBUG = 110,                  /* K_DEBUG  */
  YYSYMBOL_K_NODEBUG = 111,                /* K_NODEBUG  */
  YYSYMBOL_K_TRG = 112,                    /* K_TRG  */
  YYSYMBOL_K_NOTRG = 113,                  /* K_NOTRG  */
  YYSYMBOL_K_EXTERNAL_FUNCTIONS = 114,     /* K_EXTERNAL_FUNCTIONS  */
  YYSYMBOL_K_NOEXTERNAL_FUNCTIONS = 115,   /* K_NOEXTERNAL_FUNCTIONS  */
  YYSYMBOL_K_EXEC_LUA = 116,               /* K_EXEC_LUA  */
  YYSYMBOL_K_NOEXEC_LUA = 117,             /* K_NOEXEC_LUA  */
  YYSYMBOL_K_HALF_PAGE_SCROLL = 118,       /* K_HALF_PAGE_SCROLL  */
  YYSYMBOL_K_NOHALF_PAGE_SCROLL = 119,     /* K_NOHALF_PAGE_SCROLL  */
  YYSYMBOL_K_NOCURSES = 120,               /* K_NOCURSES  */
  YYSYMBOL_K_CURSES = 121,                 /* K_CURSES  */
  YYSYMBOL_K_NUMERIC = 122,                /* K_NUMERIC  */
  YYSYMBOL_K_NONUMERIC = 123,              /* K_NONUMERIC  */
  YYSYMBOL_K_NUMERIC_DECIMAL = 124,        /* K_NUMERIC_DECIMAL  */
  YYSYMBOL_K_NONUMERIC_DECIMAL = 125,      /* K_NONUMERIC_DECIMAL  */
  YYSYMBOL_K_NUMERIC_ZERO = 126,           /* K_NUMERIC_ZERO  */
  YYSYMBOL_K_NONUMERIC_ZERO = 127,         /* K_NONUMERIC_ZERO  */
  YYSYMBOL_K_OVERLAP = 128,                /* K_OVERLAP  */
  YYSYMBOL_K_NOOVERLAP = 129,              /* K_NOOVERLAP  */
  YYSYMBOL_K_INPUT_BAR_BOTTOM = 130,       /* K_INPUT_BAR_BOTTOM  */
  YYSYMBOL_K_IGNORE_HIDDEN = 131,          /* K_IGNORE_HIDDEN  */
  YYSYMBOL_K_NOIGNORE_HIDDEN = 132,        /* K_NOIGNORE_HIDDEN  */
  YYSYMBOL_K_UNDERLINE_GRID = 133,         /* K_UNDERLINE_GRID  */
  YYSYMBOL_K_TRUNCATE = 134,               /* K_TRUNCATE  */
  YYSYMBOL_K_NOTRUNCATE = 135,             /* K_NOTRUNCATE  */
  YYSYMBOL_K_AUTOWRAP = 136,               /* K_AUTOWRAP  */
  YYSYMBOL_K_NOAUTOWRAP = 137,             /* K_NOAUTOWRAP  */
  YYSYMBOL_K_QUIET = 138,                  /* K_QUIET  */
  YYSYMBOL_K_NOQUIET = 139,                /* K_NOQUIET  */
  YYSYMBOL_K_QUIT_AFTERLOAD = 140,         /* K_QUIT_AFTERLOAD  */
  YYSYMBOL_K_NOQUIT_AFTERLOAD = 141,       /* K_NOQUIT_AFTERLOAD  */
  YYSYMBOL_K_XLSX_READFORMULAS = 142,      /* K_XLSX_READFORMULAS  */
  YYSYMBOL_K_NOXLSX_READFORMULAS = 143,    /* K_NOXLSX_READFORMULAS  */
  YYSYMBOL_K_DEFAULT_COPY_TO_CLIPBOARD_CMD = 144, /* K_DEFAULT_COPY_TO_CLIPBOARD_CMD  */
  YYSYMBOL_K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD = 145, /* K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD  */
  YYSYMBOL_K_COPY_TO_CLIPBOARD_DELIMITED_TAB = 146, /* K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
  YYSYMBOL_K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB = 147, /* K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
  YYSYMBOL_K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD = 148, /* K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD  */
  YYSYMBOL_K_IGNORECASE = 149,             /* K_IGNORECASE  */
  YYSYMBOL_K_NOIGNORECASE = 150,           /* K_NOIGNORECASE  */
  YYSYMBOL_K_TM_GMTOFF = 151,              /* K_TM_GMTOFF  */
  YYSYMBOL_K_COMMAND_TIMEOUT = 152,        /* K_COMMAND_TIMEOUT  */
  YYSYMBOL_K_MAPPING_TIMEOUT = 153,        /* K_MAPPING_TIMEOUT  */
  YYSYMBOL_K_NEWLINE_ACTION = 154,         /* K_NEWLINE_ACTION  */
  YYSYMBOL_K_SHOW_CURSOR = 155,            /* K_SHOW_CURSOR  */
  YYSYMBOL_K_NOSHOW_CURSOR = 156,          /* K_NOSHOW_CURSOR  */
  YYSYMBOL_K_ERROR = 157,                  /* K_ERROR  */
  YYSYMBOL_K_INVALID = 158,                /* K_INVALID  */
  YYSYMBOL_K_FIXED = 159,                  /* K_FIXED  */
  YYSYMBOL_K_SUM = 160,                    /* K_SUM  */
  YYSYMBOL_K_PROD = 161,                   /* K_PROD  */
  YYSYMBOL_K_AVG = 162,                    /* K_AVG  */
  YYSYMBOL_K_STDDEV = 163,                 /* K_STDDEV  */
  YYSYMBOL_K_COUNT = 164,                  /* K_COUNT  */
  YYSYMBOL_K_ROWS = 165,                   /* K_ROWS  */
  YYSYMBOL_K_COLS = 166,                   /* K_COLS  */
  YYSYMBOL_K_ABS = 167,                    /* K_ABS  */
  YYSYMBOL_K_FROW = 168,                   /* K_FROW  */
  YYSYMBOL_K_FCOL = 169,                   /* K_FCOL  */
  YYSYMBOL_K_ACOS = 170,                   /* K_ACOS  */
  YYSYMBOL_K_ASIN = 171,                   /* K_ASIN  */
  YYSYMBOL_K_ATAN = 172,                   /* K_ATAN  */
  YYSYMBOL_K_ATAN2 = 173,                  /* K_ATAN2  */
  YYSYMBOL_K_CEIL = 174,                   /* K_CEIL  */
  YYSYMBOL_K_COS = 175,                    /* K_COS  */
  YYSYMBOL_K_EXP = 176,                    /* K_EXP  */
  YYSYMBOL_K_FABS = 177,                   /* K_FABS  */
  YYSYMBOL_K_FLOOR = 178,                  /* K_FLOOR  */
  YYSYMBOL_K_HYPOT = 179,                  /* K_HYPOT  */
  YYSYMBOL_K_LN = 180,                     /* K_LN  */
  YYSYMBOL_K_LOG = 181,                    /* K_LOG  */
  YYSYMBOL_K_PI = 182,                     /* K_PI  */
  YYSYMBOL_K_POW = 183,                    /* K_POW  */
  YYSYMBOL_K_SIN = 184,                    /* K_SIN  */
  YYSYMBOL_K_SQRT = 185,                   /* K_SQRT  */
  YYSYMBOL_K_TAN = 186,                    /* K_TAN  */
  YYSYMBOL_K_DTR = 187,                    /* K_DTR  */
  YYSYMBOL_K_RTD = 188,                    /* K_RTD  */
  YYSYMBOL_K_MAX = 189,                    /* K_MAX  */
  YYSYMBOL_K_MIN = 190,                    /* K_MIN  */
  YYSYMBOL_K_RND = 191,                    /* K_RND  */
  YYSYMBOL_K_ROUND = 192,                  /* K_ROUND  */
  YYSYMBOL_K_IF = 193,                     /* K_IF  */
  YYSYMBOL_K_PV = 194,                     /* K_PV  */
  YYSYMBOL_K_FV = 195,                     /* K_FV  */
  YYSYMBOL_K_PMT = 196,                    /* K_PMT  */
  YYSYMBOL_K_HOUR = 197,                   /* K_HOUR  */
  YYSYMBOL_K_MINUTE = 198,                 /* K_MINUTE  */
  YYSYMBOL_K_SECOND = 199,                 /* K_SECOND  */
  YYSYMBOL_K_MONTH = 200,                  /* K_MONTH  */
  YYSYMBOL_K_DAY = 201,                    /* K_DAY  */
  YYSYMBOL_K_YEAR = 202,                   /* K_YEAR  */
  YYSYMBOL_K_NOW = 203,                    /* K_NOW  */
  YYSYMBOL_K_DATE = 204,                   /* K_DATE  */
  YYSYMBOL_K_DTS = 205,                    /* K_DTS  */
  YYSYMBOL_K_TTS = 206,                    /* K_TTS  */
  YYSYMBOL_K_FMT = 207,                    /* K_FMT  */
  YYSYMBOL_K_REPLACE = 208,                /* K_REPLACE  */
  YYSYMBOL_K_SUBSTR = 209,                 /* K_SUBSTR  */
  YYSYMBOL_K_UPPER = 210,                  /* K_UPPER  */
  YYSYMBOL_K_LOWER = 211,                  /* K_LOWER  */
  YYSYMBOL_K_CAPITAL = 212,                /* K_CAPITAL  */
  YYSYMBOL_K_STON = 213,                   /* K_STON  */
  YYSYMBOL_K_SLEN = 214,                   /* K_SLEN  */
  YYSYMBOL_K_EQS = 215,                    /* K_EQS  */
  YYSYMBOL_K_EXT = 216,                    /* K_EXT  */
  YYSYMBOL_K_EVALUATE = 217,               /* K_EVALUATE  */
  YYSYMBOL_K_SEVALUATE = 218,              /* K_SEVALUATE  */
  YYSYMBOL_K_LUA = 219,                    /* K_LUA  */
  YYSYMBOL_K_NVAL = 220,                   /* K_NVAL  */
  YYSYMBOL_K_SVAL = 221,                   /* K_SVAL  */
  YYSYMBOL_K_LOOKUP = 222,                 /* K_LOOKUP  */
  YYSYMBOL_K_HLOOKUP = 223,                /* K_HLOOKUP  */
  YYSYMBOL_K_VLOOKUP = 224,                /* K_VLOOKUP  */
  YYSYMBOL_K_INDEX = 225,                  /* K_INDEX  */
  YYSYMBOL_K_STINDEX = 226,                /* K_STINDEX  */
  YYSYMBOL_K_GETENT = 227,                 /* K_GETENT  */
  YYSYMBOL_K_TBLSTYLE = 228,               /* K_TBLSTYLE  */
  YYSYMBOL_K_TBL = 229,                    /* K_TBL  */
  YYSYMBOL_K_LATEX = 230,                  /* K_LATEX  */
  YYSYMBOL_K_SLATEX = 231,                 /* K_SLATEX  */
  YYSYMBOL_K_TEX = 232,                    /* K_TEX  */
  YYSYMBOL_K_FRAME = 233,                  /* K_FRAME  */
  YYSYMBOL_K_RNDTOEVEN = 234,              /* K_RNDTOEVEN  */
  YYSYMBOL_K_FILENAME = 235,               /* K_FILENAME  */
  YYSYMBOL_K_MYROW = 236,                  /* K_MYROW  */
  YYSYMBOL_K_MYCOL = 237,                  /* K_MYCOL  */
  YYSYMBOL_K_LASTROW = 238,                /* K_LASTROW  */
  YYSYMBOL_K_LASTCOL = 239,                /* K_LASTCOL  */
  YYSYMBOL_K_COLTOA = 240,                 /* K_COLTOA  */
  YYSYMBOL_K_CRACTION = 241,               /* K_CRACTION  */
  YYSYMBOL_K_CRROW = 242,                  /* K_CRROW  */
  YYSYMBOL_K_CRCOL = 243,                  /* K_CRCOL  */
  YYSYMBOL_K_ROWLIMIT = 244,               /* K_ROWLIMIT  */
  YYSYMBOL_K_COLLIMIT = 245,               /* K_COLLIMIT  */
  YYSYMBOL_K_PAGESIZE = 246,               /* K_PAGESIZE  */
  YYSYMBOL_K_ERR = 247,                    /* K_ERR  */
  YYSYMBOL_K_REF = 248,                    /* K_REF  */
  YYSYMBOL_K_LOCALE = 249,                 /* K_LOCALE  */
  YYSYMBOL_K_SET8BIT = 250,                /* K_SET8BIT  */
  YYSYMBOL_K_ASCII = 251,                  /* K_ASCII  */
  YYSYMBOL_K_CHR = 252,                    /* K_CHR  */
  YYSYMBOL_K_FACT = 253,                   /* K_FACT  */
  YYSYMBOL_254_ = 254,                     /* ';'  */
  YYSYMBOL_255_ = 255,                     /* '?'  */
  YYSYMBOL_256_ = 256,                     /* ':'  */
  YYSYMBOL_257_ = 257,                     /* '|'  */
  YYSYMBOL_258_ = 258,                     /* '&'  */
  YYSYMBOL_259_ = 259,                     /* '<'  */
  YYSYMBOL_260_ = 260,                     /* '='  */
  YYSYMBOL_261_ = 261,                     /* '>'  */
  YYSYMBOL_262_ = 262,                     /* '!'  */
  YYSYMBOL_263_ = 263,                     /* '+'  */
  YYSYMBOL_264_ = 264,                     /* '-'  */
  YYSYMBOL_265_ = 265,                     /* '#'  */
  YYSYMBOL_266_ = 266,                     /* '*'  */
  YYSYMBOL_267_ = 267,                     /* '/'  */
  YYSYMBOL_268_ = 268,                     /* '%'  */
  YYSYMBOL_269_ = 269,                     /* '^'  */
  YYSYMBOL_270_ = 270,                     /* '{'  */
  YYSYMBOL_271_ = 271,                     /* '}'  */
  YYSYMBOL_272_ = 272,                     /* '@'  */
  YYSYMBOL_273_ = 273,                     /* '('  */
  YYSYMBOL_274_ = 274,                     /* ')'  */
  YYSYMBOL_275_ = 275,                     /* ','  */
  YYSYMBOL_276_ = 276,                     /* '.'  */
  YYSYMBOL_277_ = 277,                     /* '~'  */
  YYSYMBOL_278_ = 278,                     /* '$'  */
  YYSYMBOL_YYACCEPT = 279,                 /* $accept  */
  YYSYMBOL_command = 280,                  /* command  */
  YYSYMBOL_term = 281,                     /* term  */
  YYSYMBOL_e = 282,                        /* e  */
  YYSYMBOL_expr_list = 283,                /* expr_list  */
  YYSYMBOL_range = 284,                    /* range  */
  YYSYMBOL_var = 285,                      /* var  */
  YYSYMBOL_var_or_range = 286,             /* var_or_range  */
  YYSYMBOL_num = 287,                      /* num  */
  YYSYMBOL_strarg = 288,                   /* strarg  */
  YYSYMBOL_setlist = 289,                  /* setlist  */
  YYSYMBOL_setitem = 290                   /* setitem  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  223
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  279
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  360
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  932

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   508


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   262,     2,   265,   278,   268,   258,     2,
     273,   274,   266,   263,   275,   264,   276,   267,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   256,   254,
     259,   260,   261,   255,   272,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   269,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   270,   257,   271,   277,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   429,   429,   435,   476,   482,   487,   492,   496,   501,
     505,   512,   518,   524,   525,   526,   527,   530,   535,   542,
     544,   546,   548,   550,   552,   554,   568,   583,   588,   601,
     607,   615,   624,   634,   640,   642,   646,   650,   654,   658,
     662,   666,   670,   675,   679,   684,   698,   699,   701,   703,
     707,   711,   712,   717,   723,   725,   730,   735,   739,   744,
     749,   755,   760,   765,   770,   777,   778,   779,   780,   785,
     790,   828,   850,   867,   881,   896,   902,   911,   917,   922,
     927,   932,   938,   943,   948,   954,   959,   963,   968,   972,
     979,   999,  1010,  1015,  1020,  1025,  1030,  1035,  1040,  1046,
    1050,  1060,  1068,  1076,  1080,  1084,  1085,  1086,  1088,  1096,
    1112,  1113,  1115,  1117,  1123,  1149,  1156,  1160,  1165,  1166,
    1168,  1177,  1187,  1192,  1198,  1206,  1208,  1211,  1213,  1222,
    1231,  1237,  1241,  1242,  1247,  1258,  1277,  1279,  1282,  1284,
    1286,  1288,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1314,  1316,  1318,  1319,  1320,  1321,
    1322,  1323,  1324,  1326,  1327,  1328,  1329,  1330,  1331,  1333,
    1334,  1335,  1337,  1338,  1339,  1340,  1341,  1342,  1343,  1345,
    1347,  1349,  1351,  1353,  1354,  1355,  1356,  1357,  1358,  1359,
    1360,  1362,  1366,  1368,  1369,  1370,  1372,  1373,  1375,  1377,
    1378,  1379,  1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,
    1396,  1398,  1400,  1402,  1404,  1406,  1412,  1413,  1414,  1415,
    1416,  1418,  1420,  1423,  1424,  1425,  1427,  1428,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,
    1467,  1468,  1469,  1472,  1473,  1476,  1480,  1485,  1490,  1495,
    1500,  1507,  1516,  1522,  1523,  1526,  1527,  1528,  1529,  1532,
    1533,  1545,  1546,  1551,  1553,  1554,  1557,  1561,  1563,  1566,
    1568,  1570,  1571,  1573,  1575,  1576,  1578,  1582,  1583,  1584,
    1586,  1587,  1588,  1590,  1591,  1592,  1594,  1595,  1596,  1599,
    1600,  1601,  1604,  1605,  1606,  1609,  1611,  1612,  1615,  1617,
    1620,  1621,  1622,  1623,  1626,  1627,  1628,  1631,  1632,  1633,
    1637,  1638,  1639,  1641,  1642,  1643,  1645,  1646,  1647,  1650,
    1651,  1652,  1655,  1656,  1657,  1663,  1670,  1678,  1680,  1683,
    1685,  1693,  1695,  1696,  1702,  1703,  1709,  1710,  1716,  1718,
    1719
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "COL",
  "NUMBER", "FNUMBER", "RANGE", "VAR", "WORD", "MAPWORD", "PLUGIN",
  "S_SHOW", "S_HIDE", "S_SHOWROW", "S_HIDEROW", "S_SHOWCOL", "S_HIDECOL",
  "S_FREEZE", "S_UNFREEZE", "S_MARK", "S_AUTOFIT", "S_PAD", "S_DELETECOL",
  "S_DATEFMT", "S_SUBTOTAL", "S_RSUBTOTAL", "S_FORMAT", "S_FMT", "S_LET",
  "S_LABEL", "S_LEFTSTRING", "S_RIGHTSTRING", "S_LEFTJUSTIFY",
  "S_RIGHTJUSTIFY", "S_CENTER", "S_SORT", "S_FILTERON", "S_GOTO",
  "S_GOTOB", "S_CCOPY", "S_CPASTE", "S_PLOT", "S_LOCK", "S_UNLOCK",
  "S_DEFINE", "S_UNDEFINE", "S_DETAIL", "S_EVAL", "S_SEVAL", "S_ERROR",
  "S_FILL", "S_STRTONUM", "S_DELETEROW", "S_VALUEIZEALL", "S_SHIFT",
  "S_GETNUM", "S_YANKAREA", "S_PASTEYANKED", "S_GETSTRING", "S_GETEXP",
  "S_GETFMT", "S_GETFORMAT", "S_RECALC", "S_EXECUTE", "S_QUIT", "S_EXPORT",
  "S_REBUILD_GRAPH", "S_PRINT_GRAPH", "S_SYNCREFS", "S_REDO", "S_UNDO",
  "S_IMAP", "S_CMAP", "S_NEWSHEET", "S_NEXTSHEET", "S_PREVSHEET",
  "S_DELSHEET", "S_MOVETOSHEET", "S_RENAMESHEET", "S_NMAP", "S_VMAP",
  "S_INOREMAP", "S_CNOREMAP", "S_NNOREMAP", "S_VNOREMAP", "S_NUNMAP",
  "S_IUNMAP", "S_CUNMAP", "S_VUNMAP", "S_COLOR", "S_CELLCOLOR",
  "S_UNFORMAT", "S_REDEFINE_COLOR", "S_DEFINE_COLOR", "S_SET", "S_FCOPY",
  "S_FSUM", "S_TRIGGER", "S_UNTRIGGER", "S_OFFSCR_SC_COLS",
  "S_OFFSCR_SC_ROWS", "S_NB_FROZEN_ROWS", "S_NB_FROZEN_COLS",
  "S_NB_FROZEN_SCREENROWS", "S_NB_FROZEN_SCREENCOLS", "K_AUTOBACKUP",
  "K_NOAUTOBACKUP", "K_AUTOCALC", "K_NOAUTOCALC", "K_DEBUG", "K_NODEBUG",
  "K_TRG", "K_NOTRG", "K_EXTERNAL_FUNCTIONS", "K_NOEXTERNAL_FUNCTIONS",
  "K_EXEC_LUA", "K_NOEXEC_LUA", "K_HALF_PAGE_SCROLL",
  "K_NOHALF_PAGE_SCROLL", "K_NOCURSES", "K_CURSES", "K_NUMERIC",
  "K_NONUMERIC", "K_NUMERIC_DECIMAL", "K_NONUMERIC_DECIMAL",
  "K_NUMERIC_ZERO", "K_NONUMERIC_ZERO", "K_OVERLAP", "K_NOOVERLAP",
  "K_INPUT_BAR_BOTTOM", "K_IGNORE_HIDDEN", "K_NOIGNORE_HIDDEN",
  "K_UNDERLINE_GRID", "K_TRUNCATE", "K_NOTRUNCATE", "K_AUTOWRAP",
  "K_NOAUTOWRAP", "K_QUIET", "K_NOQUIET", "K_QUIT_AFTERLOAD",
  "K_NOQUIT_AFTERLOAD", "K_XLSX_READFORMULAS", "K_NOXLSX_READFORMULAS",
  "K_DEFAULT_COPY_TO_CLIPBOARD_CMD", "K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD",
  "K_COPY_TO_CLIPBOARD_DELIMITED_TAB",
  "K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB",
  "K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD", "K_IGNORECASE", "K_NOIGNORECASE",
  "K_TM_GMTOFF", "K_COMMAND_TIMEOUT", "K_MAPPING_TIMEOUT",
  "K_NEWLINE_ACTION", "K_SHOW_CURSOR", "K_NOSHOW_CURSOR", "K_ERROR",
  "K_INVALID", "K_FIXED", "K_SUM", "K_PROD", "K_AVG", "K_STDDEV",
  "K_COUNT", "K_ROWS", "K_COLS", "K_ABS", "K_FROW", "K_FCOL", "K_ACOS",
  "K_ASIN", "K_ATAN", "K_ATAN2", "K_CEIL", "K_COS", "K_EXP", "K_FABS",
  "K_FLOOR", "K_HYPOT", "K_LN", "K_LOG", "K_PI", "K_POW", "K_SIN",
  "K_SQRT", "K_TAN", "K_DTR", "K_RTD", "K_MAX", "K_MIN", "K_RND",
  "K_ROUND", "K_IF", "K_PV", "K_FV", "K_PMT", "K_HOUR", "K_MINUTE",
  "K_SECOND", "K_MONTH", "K_DAY", "K_YEAR", "K_NOW", "K_DATE", "K_DTS",
  "K_TTS", "K_FMT", "K_REPLACE", "K_SUBSTR", "K_UPPER", "K_LOWER",
  "K_CAPITAL", "K_STON", "K_SLEN", "K_EQS", "K_EXT", "K_EVALUATE",
  "K_SEVALUATE", "K_LUA", "K_NVAL", "K_SVAL", "K_LOOKUP", "K_HLOOKUP",
  "K_VLOOKUP", "K_INDEX", "K_STINDEX", "K_GETENT", "K_TBLSTYLE", "K_TBL",
  "K_LATEX", "K_SLATEX", "K_TEX", "K_FRAME", "K_RNDTOEVEN", "K_FILENAME",
  "K_MYROW", "K_MYCOL", "K_LASTROW", "K_LASTCOL", "K_COLTOA", "K_CRACTION",
  "K_CRROW", "K_CRCOL", "K_ROWLIMIT", "K_COLLIMIT", "K_PAGESIZE", "K_ERR",
  "K_REF", "K_LOCALE", "K_SET8BIT", "K_ASCII", "K_CHR", "K_FACT", "';'",
  "'?'", "':'", "'|'", "'&'", "'<'", "'='", "'>'", "'!'", "'+'", "'-'",
  "'#'", "'*'", "'/'", "'%'", "'^'", "'{'", "'}'", "'@'", "'('", "')'",
  "','", "'.'", "'~'", "'$'", "$accept", "command", "term", "e",
  "expr_list", "range", "var", "var_or_range", "num", "strarg", "setlist",
  "setitem", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,    59,    63,    58,   124,    38,    60,
      61,    62,    33,    43,    45,    35,    42,    47,    37,    94,
     123,   125,    64,    40,    41,    44,    46,   126,    36
};
#endif

#define YYPACT_NINF (-366)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-275)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     993,  -366,    34,    38,    17,    41,    23,    55,    40,    63,
      65,    74,    43,    83,     8,   138,   138,    72,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,    67,    44,
     138,  -366,    86,   138,   138,    92,   138,   149,   131,   131,
      94,   237,   138,    93,  -366,   138,   246,  -171,  -169,   138,
     138,   138,    98,  -366,   100,  -366,   101,  -366,  -366,  -366,
    -366,  -366,   102,   104,   106,  -366,  -366,   107,   108,   109,
     112,   119,   120,   121,   122,   123,   124,   126,   127,   129,
     130,    22,   138,   135,   137,  -366,    92,  -366,   138,   138,
     136,   139,   142,   143,   146,   147,   169,  -366,  -366,  -366,
    -366,  -113,   -85,   -84,   -78,   -77,   -76,   -73,   -72,    33,
     -69,   226,  -366,  -366,     4,  -366,  -366,   -39,   188,  -366,
     -63,   193,   198,   -63,   212,   213,   214,   220,   -43,   -36,
     -35,   -33,  -366,  -366,  -366,   228,  -366,  -366,  -366,  -366,
       1,     1,   229,   232,   138,  -366,  -366,   233,   234,  -366,
    -366,   138,  -366,  -366,  -366,  -366,   138,  -366,  -366,  -366,
     -37,  -366,  -366,  -366,   409,   409,   131,   235,   940,   298,
     409,  -366,   517,  -366,   517,  -366,     1,     1,  -366,  -366,
     243,   244,  -366,   245,   249,  -366,  -366,  -366,  -366,  -366,
     252,   253,   254,  -366,  -366,  -366,  -366,   255,   257,   258,
     263,   264,   265,  -366,  -366,  -366,  -366,  -366,  -366,   266,
    -366,   267,   268,  1253,  -366,   271,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,   278,   284,   236,   291,   293,   294,
     306,   324,   138,   138,   329,     3,  -366,  -366,   331,    -3,
      12,   149,  -366,   295,   334,   336,  -366,  -366,   131,   131,
     131,   131,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,   -63,   341,  -366,  -366,  -234,     0,   409,    61,
      75,    76,    78,    81,    82,    89,    90,   111,   114,   115,
     116,   125,   132,   133,   134,   145,   150,   151,   152,   153,
     155,  -366,   156,   157,   158,   238,   239,   240,   241,   247,
     248,   250,   274,   276,   277,   279,   280,   281,   290,   292,
     296,   299,  -366,   300,   301,   304,   305,   307,   308,   309,
     310,   312,   313,   322,   343,   351,   355,   356,   357,   361,
     365,   366,   369,   370,   371,   385,   387,  -366,  -366,  -366,
    -366,   388,  -366,  -366,   389,   395,   396,   397,  1105,   987,
    -366,   131,   131,   131,   131,    15,   131,    80,   131,   131,
     131,   131,   131,   131,   131,     1,  -366,  -366,    85,    88,
     128,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,   342,   360,   159,  -366,   160,  -366,   162,  -366,   259,
    -366,   262,  -366,   288,  -366,   319,  -366,   367,  -366,   399,
    -366,   413,  -366,   414,  -366,   415,  -366,   416,   417,  -366,
     418,   420,  -366,   423,  -366,   424,  -366,   425,  -366,   429,
    -366,   430,   432,   434,  -366,   436,   438,  -366,   440,   441,
     442,   443,   444,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,   138,  -366,  -366,   376,  -366,   131,
    -366,   377,  -366,   392,   393,   500,   517,   517,   517,   517,
     231,   289,  -366,   138,   138,   138,   138,   138,   138,   138,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   113,   113,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   113,   113,   113,   113,   113,   131,   131,
     131,   131,   131,   131,   363,  -366,   517,  -203,   354,   333,
     131,   131,   386,   386,   131,   386,  -234,  -234,  -234,   297,
     297,   297,  -366,  -366,   302,   445,   503,   505,   512,   521,
     532,   562,   700,   701,   703,   705,   706,   707,   708,   709,
     711,   712,   718,   719,   721,   722,   724,   725,   731,    92,
      92,   733,    92,   734,     1,     1,     1,    19,   735,  -366,
    -366,   669,  -366,  -366,  -366,  -366,   736,   149,   117,   447,
     467,   475,   476,   478,   481,   479,   482,   487,   489,   491,
    1798,  1816,  1834,  1852,  1870,  1888,   716,  1906,  1924,  1942,
    1960,  1978,   941,  1996,  2014,  1156,  2032,  2050,  2068,  2086,
    2104,  1175,   492,  -243,   495,  1209,   498,   513,  2122,  1228,
    1247,  1266,  1285,  1304,  2140,  2158,  2176,  2194,  2212,  2230,
     -60,  1323,  1342,  1361,  1380,  1399,  2248,  2266,  2284,  2302,
    2320,  1418,  1437,  2338,  2356,  1456,  1475,  1494,  1513,   504,
     -63,  1532,   522,  1551,   523,  1570,   525,  1589,   526,  2374,
    2392,  2410,  2428,  2446,  2464,   409,   131,   386,   386,   386,
     138,   138,   747,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,   131,  -366,  -366,   131,
    -366,   131,  -366,   131,  -366,   131,  -366,   131,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,   131,  -366,  -366,
    -366,  -366,  -366,   131,  -366,  -366,   131,  -366,  -366,  -366,
    -366,  -366,   131,   131,  -366,   131,   131,  -366,  -366,   131,
     131,   131,   131,   131,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,   131,   131,   131,   131,   131,   131,  -366,  -366,  -366,
    -366,  -366,   131,   131,  -366,  -366,   131,   131,   131,   138,
     131,   138,   131,   138,   131,   138,   131,   138,   131,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,   275,  -366,   785,  -366,
    2482,  2500,  2518,  2536,  2554,  2572,  2590,  2608,  2626,   517,
    -193,  2644,  -182,  2662,  2680,  1608,  1627,  1646,  1665,  2698,
    1684,  1703,  2716,  1722,  1741,  2734,  2752,  2770,  2788,  2806,
     528,  2824,   531,  1760,   533,  1779,   529,   629,   535,   694,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,   131,  -366,  -366,  -366,  -366,   131,   131,   131,   131,
    -366,   131,   131,  -366,   131,   131,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,   131,   131,   131,   131,  -366,  -366,   131,
    -366,  -366,   131,   517,  2842,  2860,  2878,  2896,  2914,  2932,
    2950,  2968,  2986,  3004,  3022,  3040,  3058,  3076,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,   116,     0,   117,   118,   119,
     121,   120,     0,     0,     0,    73,    74,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,     0,     0,   281,   105,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    13,
      14,    22,    21,    20,    19,    38,    36,    42,    40,     0,
      47,     0,    17,    12,     0,   266,   272,     0,     0,   273,
     274,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    54,    58,   275,   276,
       0,     0,     0,     0,    56,    57,    62,     0,     0,    61,
      65,     0,    68,    69,   279,   280,     0,   112,    90,   231,
     228,   229,   240,   242,     0,     0,     0,     0,     0,     0,
       0,   251,   113,   134,   130,   131,     0,     0,    66,    18,
       0,     0,   123,     0,     0,   125,   126,   127,    51,   114,
       0,     0,     0,    70,    71,    75,    76,     0,     0,     0,
       0,     0,     0,    85,    86,    88,    87,    89,   100,     0,
     101,     0,     0,   109,   106,     0,    99,    93,    94,    95,
      96,    97,    98,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    49,    50,   267,     0,     0,
       0,     0,    11,     0,     0,     0,    53,    10,     3,     0,
       0,     0,    43,   278,   277,    59,    60,    55,    63,    64,
     108,   110,   111,     0,   233,   227,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,   217,   218,
     219,     0,   239,   241,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    28,     0,     0,
       0,   115,    78,    80,    77,    79,    82,    84,    81,    83,
      91,     0,     0,     0,   297,   298,   300,   301,   303,   304,
     306,   307,   309,   310,   312,   313,   315,   328,   330,   331,
     333,   337,   339,   340,   342,   284,   289,   286,   316,   318,
     288,   291,   292,   294,   295,   320,   321,   322,   324,   325,
     327,     0,     0,   347,   349,     0,   334,   336,   356,   352,
     354,   343,   359,   360,   282,    92,    24,    26,    23,    25,
      37,    35,    41,    39,    31,    30,    46,     0,   269,     0,
     268,     0,   265,     0,     0,     0,     2,     4,     5,     6,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,   253,     0,   258,   257,
       0,     0,   254,   255,     0,   256,   244,   245,   262,   246,
     247,   248,   250,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      48,     0,   270,    44,    45,    52,     0,     0,   273,     0,
     273,     0,   273,     0,   273,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   134,     0,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
       0,     0,     0,   103,   104,   296,   299,   302,   305,   308,
     311,   314,   329,   332,   338,   341,   283,   285,   317,   287,
     290,   293,   319,   323,   326,   345,   346,   348,   350,   335,
     357,   353,   355,   351,   344,   358,     0,   191,   135,     0,
     138,     0,   140,     0,   142,     0,   144,     0,   146,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   163,   164,
     165,   166,   167,     0,   169,   170,     0,   172,   173,   174,
     175,   176,     0,     0,   148,     0,     0,   151,   177,     0,
       0,     0,     0,     0,   183,   184,   185,   186,   187,   188,
     196,     0,     0,     0,     0,     0,     0,   199,   200,   201,
     193,   194,     0,     0,   223,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   237,   236,   238,   243,   137,   252,   124,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   271,   139,   141,   143,   145,   147,   162,   168,   171,
     150,     0,   149,   153,   152,   178,     0,     0,     0,     0,
     197,     0,     0,   198,     0,     0,   195,   214,   215,   220,
     221,   206,   205,     0,     0,     0,     0,   203,   202,     0,
     212,   211,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   180,
     181,   182,   190,   192,   222,   225,   208,   207,   210,   209,
     204,   213
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -366,  -366,  -160,   -38,  -365,    64,   140,   771,   -27,   -83,
    -366,  -366
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,   171,   829,   830,   119,   173,   121,   145,   156,
     213,   434
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     172,   174,   149,   214,   264,   265,   138,   139,   237,   237,
     350,   113,   114,   241,   177,   115,   116,   450,   159,   114,
     160,   161,   101,   116,   723,   208,   114,   103,   724,   115,
     116,  -274,   361,   362,   363,   364,   232,   114,    97,    98,
     115,   116,    99,   100,   105,   106,   102,   146,   111,   138,
     139,   351,   352,   686,   353,   354,   355,   356,   357,   104,
     358,   359,   360,   361,   362,   363,   364,   107,   108,   109,
     137,   114,   138,   139,   115,   116,   125,   126,   110,   122,
     124,   870,   871,   159,   114,   160,   161,   112,   116,   151,
     135,   136,   873,   871,   150,   154,   114,   175,   179,   183,
     116,   184,   188,   189,   190,   191,   178,   192,   462,   193,
     194,   195,   196,   253,   254,   197,   159,   114,   160,   161,
     115,   116,   198,   199,   200,   201,   202,   203,   266,   204,
     205,   349,   206,   207,   159,   114,   160,   161,   211,   116,
     212,   217,   114,   224,   218,   115,   116,   219,   220,   365,
     366,   221,   222,   114,   120,   123,   123,   116,   120,   120,
     120,   120,   120,   120,   120,   120,   123,   123,   120,   223,
     123,   225,   226,   120,   120,   155,   120,   158,   227,   228,
     229,   120,   123,   230,   231,   120,   120,   234,   239,   120,
     120,   120,   240,   241,   351,   352,   242,   353,   354,   355,
     356,   357,   243,   358,   359,   360,   361,   362,   363,   364,
     456,   457,   458,   459,   780,   781,   244,   248,   245,   246,
     261,   120,   120,   247,   249,   250,   155,   251,   120,   120,
     235,   252,   255,   115,   116,   256,   258,   259,   267,   263,
     438,   114,   138,   139,   115,   116,   367,   368,   369,   120,
     114,   120,   370,   115,   116,   371,   372,   373,   374,   447,
     375,   376,   162,   163,   140,   141,   377,   378,   379,   380,
     449,   461,   381,   382,   435,   540,   541,   164,   165,   166,
     117,   238,   238,   436,   120,   167,   118,   168,   169,   437,
     451,   120,   170,   118,   117,   439,   262,   440,   453,   441,
     118,   159,   114,   160,   161,   117,   116,   140,   141,   147,
     442,   118,   148,   536,   537,   538,   539,   542,   543,   545,
     546,   547,   548,   549,   550,   551,   552,   162,   163,   443,
     140,   141,   142,   446,   463,   143,   448,   454,   553,   117,
     544,   455,   164,   165,   166,   118,   460,   557,   464,   465,
     167,   466,   168,   169,   467,   468,   554,   170,   118,   555,
     162,   163,   469,   470,   117,   558,   159,   114,   160,   161,
     118,   116,   120,   120,   462,   164,   165,   166,   162,   163,
     590,   452,   592,   167,   471,   168,   169,   472,   473,   474,
     170,   118,   729,   164,   165,   166,   593,   594,   475,   556,
     832,   167,     0,   168,   169,   476,   477,   478,   170,   118,
     117,   591,   159,   114,   160,   161,   118,   116,   479,   559,
     560,   117,   561,   480,   481,   482,   483,   118,   484,   485,
     486,   487,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   635,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   671,   673,   675,   677,
     679,   680,   681,   682,   683,   684,   715,   716,   117,   718,
     140,   141,   687,   688,   118,   595,   689,   596,   692,   117,
     693,   488,   489,   490,   491,   118,   181,   694,   117,   562,
     492,   493,   563,   494,   118,   815,   695,   598,   600,   602,
     604,   606,   353,   354,   355,   356,   357,   696,   358,   359,
     360,   361,   362,   363,   364,   162,   163,   495,   564,   496,
     497,   597,   498,   499,   500,   632,   636,   720,   721,   722,
     164,   165,   166,   501,   690,   502,   364,   697,   167,   503,
     348,   169,   504,   505,   506,   170,   118,   507,   508,   565,
     509,   510,   511,   512,   120,   513,   514,   669,   672,   674,
     676,   678,   355,   356,   357,   515,   358,   359,   360,   361,
     362,   363,   364,   120,   120,   120,   120,   120,   120,   120,
     162,   163,   354,   355,   356,   357,   516,   358,   359,   360,
     361,   362,   363,   364,   517,   164,   165,   566,   518,   519,
     520,   633,   633,   167,   521,   168,   169,   685,   522,   523,
     170,   118,   524,   525,   526,  -275,  -275,  -275,   816,   358,
     359,   360,   361,   362,   363,   364,   162,   163,   527,   567,
     528,   529,   530,   670,   670,   670,   670,   670,   531,   532,
     533,   164,   165,   568,   569,   570,   571,   572,   573,   167,
     574,   168,   169,   575,   576,   577,   170,   118,   820,   578,
     579,   821,   580,   822,   581,   823,   582,   824,   583,   825,
     584,   585,   586,   587,   588,   698,   699,   691,   700,   826,
     701,   702,   703,   704,   705,   827,   706,   707,   828,   155,
     155,   730,   155,   708,   709,   831,   710,   711,   833,   712,
     713,   834,   835,   836,   837,   838,   714,   728,   717,   719,
     725,   727,   731,   839,   840,   841,   842,   843,   844,   732,
     819,   733,   734,   736,   845,   846,   735,   737,   847,   848,
     849,   738,   851,   739,   853,   740,   855,   763,   857,   764,
     859,   351,   352,   766,   353,   354,   355,   356,   357,   800,
     358,   359,   360,   361,   362,   363,   364,   767,   860,   127,
     128,   129,   130,   131,   132,   133,   134,   802,   804,   144,
     806,   808,   891,   897,   152,   153,   893,   157,   895,   900,
       0,     0,   176,     0,     0,     0,   180,   182,     0,     0,
     185,   186,   187,     0,     0,     0,     0,     0,     0,     0,
     120,   120,     0,   903,     0,     0,     0,     0,   904,   905,
     906,   907,     0,   908,   909,     0,   910,   911,     0,     0,
       0,     0,   209,   210,     0,   912,   913,   914,   915,   215,
     216,   916,     0,   850,   917,   852,     0,   854,     0,   856,
       0,   858,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,   236,   351,   352,     0,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   898,   899,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,   260,   351,   352,     0,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,   123,
       0,   123,     0,   123,   726,   123,     0,   123,   351,   352,
       0,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   901,   902,
     351,   352,     0,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
       0,   747,     0,  -132,     1,     0,     0,     0,     0,     0,
       0,     0,     0,   444,   445,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   239,     0,     0,
       0,     0,     0,     0,     0,   336,   337,   338,   339,   340,
     341,     0,     0,     0,     0,     0,     0,   342,   343,     0,
     344,   345,   346,   347,     0,   351,   352,     0,   353,   354,
     355,   356,   357,     0,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   589,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   599,   601,   603,   605,   607,   608,
     609,   351,   352,     0,   353,   354,   355,   356,   357,     0,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   535,   634,   637,   534,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   239,     0,     0,     0,     0,     0,     0,     0,
     336,   337,   338,   339,   340,   341,     0,     0,     0,     0,
       0,     0,   342,   343,     0,   344,   345,   346,   347,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     351,   352,     0,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,   351,
     352,   756,   353,   354,   355,   356,   357,     0,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,     0,
     762,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   817,   818,   351,   352,     0,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,   351,   352,   765,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,   351,   352,   769,   353,   354,   355,   356,   357,     0,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
     351,   352,   770,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,   351,
     352,   771,   353,   354,   355,   356,   357,     0,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,   351,   352,
     772,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,   351,   352,   773,
     353,   354,   355,   356,   357,     0,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,   351,   352,   782,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,   351,   352,   783,   353,   354,
     355,   356,   357,     0,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,   351,   352,   784,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,   351,   352,   785,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,   351,   352,   786,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,   351,   352,   792,   353,   354,   355,   356,   357,     0,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
     351,   352,   793,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,   351,
     352,   796,   353,   354,   355,   356,   357,     0,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,   351,   352,
     797,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,   351,   352,   798,
     353,   354,   355,   356,   357,     0,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,   351,   352,   799,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,   351,   352,   801,   353,   354,
     355,   356,   357,     0,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,   351,   352,   803,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,   351,   352,   805,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,   351,   352,   807,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,   351,   352,   876,   353,   354,   355,   356,   357,     0,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
     351,   352,   877,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,   351,
     352,   878,   353,   354,   355,   356,   357,     0,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,   351,   352,
     879,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,   351,   352,   881,
     353,   354,   355,   356,   357,     0,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,   351,   352,   882,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,   351,   352,   884,   353,   354,
     355,   356,   357,     0,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,   351,   352,   885,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,   351,   352,   894,   353,   354,   355,   356,
     357,     0,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,   351,   352,   896,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   741,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     742,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   743,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   744,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   745,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   746,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     748,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   749,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   750,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   751,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   752,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     754,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   755,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   757,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   758,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   759,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     760,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   761,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   768,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   774,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   775,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     776,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   777,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   778,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   779,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   787,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     788,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   789,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   790,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   791,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   794,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     795,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   809,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   810,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   811,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   812,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     813,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   814,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   861,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   862,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   863,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     864,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   865,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   866,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   867,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   868,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     869,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   872,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   874,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   875,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   880,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     883,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   886,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   887,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   888,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   889,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     890,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   892,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   918,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   919,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   920,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     921,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   922,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   923,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   924,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   925,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,   351,   352,
     926,   353,   354,   355,   356,   357,     0,   358,   359,   360,
     361,   362,   363,   364,     0,     0,   351,   352,   927,   353,
     354,   355,   356,   357,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,   351,   352,   928,   353,   354,   355,
     356,   357,     0,   358,   359,   360,   361,   362,   363,   364,
       0,     0,   351,   352,   929,   353,   354,   355,   356,   357,
       0,   358,   359,   360,   361,   362,   363,   364,     0,     0,
     351,   352,   930,   353,   354,   355,   356,   357,     0,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     931
};

static const yytype_int16 yycheck[] =
{
      38,    39,    29,    86,   164,   165,     5,     6,     5,     5,
     170,     3,     4,   256,    41,     7,     8,     5,     3,     4,
       5,     6,     5,     8,     5,     3,     4,     4,     9,     7,
       8,   274,   266,   267,   268,   269,     3,     4,     4,     5,
       7,     8,     4,     5,     4,     5,     5,     3,     5,     5,
       6,   254,   255,   256,   257,   258,   259,   260,   261,     4,
     263,   264,   265,   266,   267,   268,   269,     4,     5,     4,
       3,     4,     5,     6,     7,     8,     4,     5,     4,    15,
      16,   274,   275,     3,     4,     5,     6,     4,     8,     3,
      26,    27,   274,   275,    30,     3,     4,     3,     5,   270,
       8,   270,     4,     3,     3,     3,    42,     3,   268,     3,
       3,     3,     3,   140,   141,     3,     3,     4,     5,     6,
       7,     8,     3,     3,     3,     3,     3,     3,   166,     3,
       3,   169,     3,     3,     3,     4,     5,     6,     3,     8,
       3,     5,     4,   256,     5,     7,     8,     5,     5,   176,
     177,     5,     5,     4,    14,    15,    16,     8,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      30,   256,   256,    33,    34,    35,    36,    37,   256,   256,
     256,    41,    42,   256,   256,    45,    46,   256,   227,    49,
      50,    51,     4,   256,   254,   255,     3,   257,   258,   259,
     260,   261,     4,   263,   264,   265,   266,   267,   268,   269,
     248,   249,   250,   251,   274,   275,     4,   260,     5,     5,
     156,    81,    82,     3,   260,   260,    86,   260,    88,    89,
       4,     3,     3,     7,     8,     3,     3,     3,     3,   276,
       4,     4,     5,     6,     7,     8,     3,     3,     3,   109,
       4,   111,     3,     7,     8,     3,     3,     3,     3,   256,
       3,     3,   247,   248,   263,   264,     3,     3,     3,     3,
     273,   271,     5,     5,     3,   260,   261,   262,   263,   264,
     272,   278,   278,     5,   144,   270,   278,   272,   273,     5,
     278,   151,   277,   278,   272,     4,   156,     4,     3,     5,
     278,     3,     4,     5,     6,   272,     8,   263,   264,   265,
       4,   278,   268,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   247,   248,     5,
     263,   264,   265,     4,   273,   268,     5,     3,   365,   272,
     260,     5,   262,   263,   264,   278,     5,     5,   273,   273,
     270,   273,   272,   273,   273,   273,   271,   277,   278,   271,
     247,   248,   273,   273,   272,     5,     3,     4,     5,     6,
     278,     8,   232,   233,   534,   262,   263,   264,   247,   248,
       4,   241,     5,   270,   273,   272,   273,   273,   273,   273,
     277,   278,   275,   262,   263,   264,     4,     4,   273,   271,
     765,   270,    -1,   272,   273,   273,   273,   273,   277,   278,
     272,   449,     3,     4,     5,     6,   278,     8,   273,   260,
     260,   272,   260,   273,   273,   273,   273,   278,   273,   273,
     273,   273,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   579,   580,   272,   582,
     263,   264,   540,   541,   278,     5,   544,   276,     5,   272,
       5,   273,   273,   273,   273,   278,   270,     5,   272,   260,
     273,   273,   260,   273,   278,   685,     5,   463,   464,   465,
     466,   467,   257,   258,   259,   260,   261,     5,   263,   264,
     265,   266,   267,   268,   269,   247,   248,   273,   260,   273,
     273,   262,   273,   273,   273,   491,   492,   584,   585,   586,
     262,   263,   264,   273,   262,   273,   269,     5,   270,   273,
     272,   273,   273,   273,   273,   277,   278,   273,   273,   260,
     273,   273,   273,   273,   444,   273,   273,   523,   524,   525,
     526,   527,   259,   260,   261,   273,   263,   264,   265,   266,
     267,   268,   269,   463,   464,   465,   466,   467,   468,   469,
     247,   248,   258,   259,   260,   261,   273,   263,   264,   265,
     266,   267,   268,   269,   273,   262,   263,   260,   273,   273,
     273,   491,   492,   270,   273,   272,   273,   274,   273,   273,
     277,   278,   273,   273,   273,   259,   260,   261,   686,   263,
     264,   265,   266,   267,   268,   269,   247,   248,   273,   260,
     273,   273,   273,   523,   524,   525,   526,   527,   273,   273,
     273,   262,   263,   260,   260,   260,   260,   260,   260,   270,
     260,   272,   273,   260,   260,   260,   277,   278,   726,   260,
     260,   729,   260,   731,   260,   733,   260,   735,   260,   737,
     260,   260,   260,   260,   260,     5,     5,   262,     5,   747,
       5,     5,     5,     5,     5,   753,     5,     5,   756,   579,
     580,   274,   582,     5,     5,   763,     5,     5,   766,     5,
       5,   769,   770,   771,   772,   773,     5,   597,     5,     5,
       5,     5,   275,   781,   782,   783,   784,   785,   786,   274,
       3,   275,   274,   274,   792,   793,   275,   275,   796,   797,
     798,   274,   800,   274,   802,   274,   804,   275,   806,   274,
     808,   254,   255,   275,   257,   258,   259,   260,   261,   275,
     263,   264,   265,   266,   267,   268,   269,   274,     3,    18,
      19,    20,    21,    22,    23,    24,    25,   275,   275,    28,
     275,   275,   274,   274,    33,    34,   275,    36,   275,   274,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     690,   691,    -1,   871,    -1,    -1,    -1,    -1,   876,   877,
     878,   879,    -1,   881,   882,    -1,   884,   885,    -1,    -1,
      -1,    -1,    81,    82,    -1,   893,   894,   895,   896,    88,
      89,   899,    -1,   799,   902,   801,    -1,   803,    -1,   805,
      -1,   807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,   111,   254,   255,    -1,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,    -1,
      -1,    -1,    -1,   274,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   254,   255,    -1,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   799,
      -1,   801,    -1,   803,   275,   805,    -1,   807,   254,   255,
      -1,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,    -1,    -1,   274,   275,
     254,   255,    -1,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,    -1,
      -1,   275,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,
     250,   251,   252,   253,    -1,   254,   255,    -1,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,    -1,    -1,    -1,    -1,   444,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   254,   255,    -1,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,    -1,    -1,    -1,
      -1,   274,   491,   492,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,   250,   251,   252,   253,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     254,   255,    -1,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,   254,
     255,   275,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   690,   691,   254,   255,    -1,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,    -1,
      -1,    -1,   254,   255,   275,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
      -1,   254,   255,   275,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,    -1,    -1,    -1,
     254,   255,   275,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,   254,
     255,   275,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,    -1,    -1,    -1,   254,   255,
     275,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,    -1,   254,   255,   275,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,    -1,    -1,    -1,   254,   255,   275,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,    -1,   254,   255,   275,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,    -1,    -1,    -1,   254,   255,   275,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,    -1,   254,   255,   275,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,    -1,
      -1,    -1,   254,   255,   275,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
      -1,   254,   255,   275,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,    -1,    -1,    -1,
     254,   255,   275,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,   254,
     255,   275,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,    -1,    -1,    -1,   254,   255,
     275,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,    -1,   254,   255,   275,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,    -1,    -1,    -1,   254,   255,   275,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,    -1,   254,   255,   275,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,    -1,    -1,    -1,   254,   255,   275,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,    -1,   254,   255,   275,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,    -1,
      -1,    -1,   254,   255,   275,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
      -1,   254,   255,   275,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,    -1,    -1,    -1,
     254,   255,   275,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,   254,
     255,   275,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,    -1,    -1,    -1,   254,   255,
     275,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,    -1,   254,   255,   275,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,    -1,    -1,    -1,   254,   255,   275,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,    -1,   254,   255,   275,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,    -1,    -1,    -1,   254,   255,   275,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,    -1,   254,   255,   275,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,    -1,
      -1,    -1,   254,   255,   275,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,   254,   255,
     274,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,    -1,    -1,   254,   255,   274,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,    -1,    -1,   254,   255,   274,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
      -1,    -1,   254,   255,   274,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,    -1,    -1,
     254,   255,   274,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,    -1,    -1,    -1,    -1,
     274
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   280,     4,     5,     4,
       5,     5,     5,     4,     4,     4,     5,     4,     5,     4,
       4,     5,     4,     3,     4,     7,     8,   272,   278,   284,
     285,   286,   284,   285,   284,     4,     5,   286,   286,   286,
     286,   286,   286,   286,   286,   284,   284,     3,     5,     6,
     263,   264,   265,   268,   286,   287,     3,   265,   268,   287,
     284,     3,   286,   286,     3,   285,   288,   286,   285,     3,
       5,     6,   247,   248,   262,   263,   264,   270,   272,   273,
     277,   281,   282,   285,   282,     3,   286,   287,   284,     5,
     286,   270,   286,   270,   270,   286,   286,   286,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,   286,
     286,     3,     3,   289,   288,   286,   286,     5,     5,     5,
       5,     5,     5,     0,   256,   256,   256,   256,   256,   256,
     256,   256,     3,   286,   256,     4,   286,     5,   278,   227,
       4,   256,     3,     4,     4,     5,     5,     3,   260,   260,
     260,   260,     3,   287,   287,     3,     3,   286,     3,     3,
     286,   284,   285,   276,   281,   281,   282,     3,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   235,   236,   237,   238,
     239,   240,   247,   248,   250,   251,   252,   253,   272,   282,
     281,   254,   255,   257,   258,   259,   260,   261,   263,   264,
     265,   266,   267,   268,   269,   287,   287,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     5,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   290,     3,     5,     5,     4,     4,
       4,     5,     4,     5,   286,   286,     4,   256,     5,   273,
       5,   278,   285,     3,     3,     5,   282,   282,   282,   282,
       5,   271,   281,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   159,   274,   282,   282,   282,   282,
     260,   261,   282,   282,   260,   282,   282,   282,   282,   282,
     282,   282,   282,   287,   271,   271,   271,     5,     5,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   286,
       4,   282,     5,     4,     4,     5,   276,   262,   284,   286,
     284,   286,   284,   286,   284,   286,   284,   286,   286,   286,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   284,   285,   286,   282,   284,   286,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   284,
     285,   282,   284,   282,   284,   282,   284,   282,   284,   282,
     282,   282,   282,   282,   282,   274,   256,   282,   282,   282,
     262,   262,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   288,   288,     5,   288,     5,
     287,   287,   287,     5,     9,     5,   275,     5,   285,   275,
     274,   275,   274,   275,   274,   275,   274,   275,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   275,   274,   274,
     274,   274,   274,   275,   274,   274,   275,   274,   274,   274,
     274,   274,   275,   275,   274,   275,   275,   274,   274,   275,
     275,   275,   275,   275,   274,   274,   274,   274,   274,   274,
     274,   275,   275,   275,   275,   275,   275,   274,   274,   274,
     274,   274,   275,   275,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   274,
     274,   274,   274,   274,   274,   281,   282,   286,   286,     3,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   282,   283,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     284,   282,   284,   282,   284,   282,   284,   282,   284,   282,
       3,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   275,   274,   274,   274,   274,   275,   275,   275,   275,
     274,   275,   275,   274,   275,   275,   274,   274,   274,   274,
     274,   274,   274,   275,   275,   275,   275,   274,   274,   275,
     274,   274,   275,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   283,   283,   284,   284,   285,   285,   285,
     285,   285,   285,   286,   286,   287,   287,   287,   287,   288,
     288,   289,   289,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     4,     4,     4,     2,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     1,     3,     3,
       4,     4,     5,     4,     3,     4,     2,     4,     2,     4,
       2,     4,     2,     3,     5,     5,     4,     2,     5,     3,
       3,     2,     5,     3,     2,     3,     2,     2,     2,     3,
       3,     2,     2,     3,     3,     2,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     5,     5,     1,     2,     1,     3,     2,
       3,     3,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     6,     2,     2,     2,     7,     6,
       2,     2,     0,     1,     1,     5,     3,     5,     5,     7,
       5,     7,     5,     7,     5,     7,     5,     7,     5,     7,
       7,     5,     7,     7,     5,     5,     5,     5,     5,     5,
       5,     5,     7,     5,     5,     5,     5,     5,     7,     5,
       5,     7,     5,     5,     5,     5,     5,     5,     7,     9,
       9,     9,     9,     5,     5,     5,     5,     5,     5,     2,
       9,     5,     9,     5,     5,     7,     5,     7,     7,     5,
       5,     5,     7,     7,     9,     7,     7,     9,     9,     9,
       9,     7,     7,     9,     7,     7,     2,     2,     2,     2,
       7,     7,     9,     5,     5,     9,     3,     2,     1,     1,
       2,     1,     2,     2,     5,     5,     5,     5,     5,     2,
       1,     2,     1,     5,     3,     3,     3,     3,     3,     2,
       3,     1,     5,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     3,     1,     3,     3,     1,     2,     3,     3,
       4,     7,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     0,     2,     3,     1,     3,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* command: S_LET var_or_range '=' e  */
#line 429 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                  struct roman * roman = session->cur_doc;
                                  struct sheet * sh = roman->cur_sh;
                                  let(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode));
                                  }
#line 3117 "y.tab.c"
    break;

  case 3: /* command: S_LET var_or_range '='  */
#line 436 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                  // TODO get this code out of gram.y - reeval cells that depends on $2
                                  extern graphADT graph;
                                  struct roman * roman = session->cur_doc;
                                  struct sheet * sh = roman->cur_sh;
#ifdef UNDO
                                  // here we save in undostruct, all the ents that depends on the deleted one (before change)
                                  ents_that_depends_on_range(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col);
                                  create_undo_action();
                                  copy_to_undostruct(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, UNDO_DEL, HANDLE_DEPS, NULL);
#endif

                                  if (getVertex(graph, sh, lookat(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col), 0) != NULL) destroy_vertex(sh, lookat(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col));

                                  (yyvsp[-1].rval).left.vp->v = (double) 0.0;
                                  if ((yyvsp[-1].rval).left.vp->expr && !((yyvsp[-1].rval).left.vp->flags & is_strexpr)) {
                                      efree((yyvsp[-1].rval).left.vp->expr);
                                      (yyvsp[-1].rval).left.vp->expr = NULL;
                                  }
                                  (yyvsp[-1].rval).left.vp->cellerror = CELLOK;
                                  (yyvsp[-1].rval).left.vp->flags &= ~is_valid;
                                  (yyvsp[-1].rval).left.vp->flags |= is_changed;
                                  roman->modflg++;

                                  // clearing the value counts as a write, so run write triggers
                                  if (( (yyvsp[-1].rval).left.vp->trigger  ) && (((yyvsp[-1].rval).left.vp->trigger->flag & TRG_WRITE) == TRG_WRITE))
                                      do_trigger((yyvsp[-1].rval).left.vp, TRG_WRITE);

#ifdef UNDO
                                  // here we save in undostruct, all the ents that depends on the deleted one (after change)
                                  copy_to_undostruct(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, UNDO_ADD, HANDLE_DEPS, NULL);
                                  extern struct ent_ptr * deps;
                                  if (deps != NULL) {
                                      free(deps);
                                      deps = NULL;
                                  }
                                  end_undo_action();
#endif
                                  }
#line 3161 "y.tab.c"
    break;

  case 4: /* command: S_LABEL var_or_range '=' e  */
#line 476 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 0);
                                          }
#line 3171 "y.tab.c"
    break;

  case 5: /* command: S_LEFTSTRING var_or_range '=' e  */
#line 482 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), -1);
                                          }
#line 3181 "y.tab.c"
    break;

  case 6: /* command: S_RIGHTSTRING var_or_range '=' e  */
#line 487 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 1);
                                          }
#line 3191 "y.tab.c"
    break;

  case 7: /* command: S_LEFTJUSTIFY var_or_range  */
#line 492 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            ljustify(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3200 "y.tab.c"
    break;

  case 8: /* command: S_RIGHTJUSTIFY var_or_range  */
#line 496 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            rjustify(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3209 "y.tab.c"
    break;

  case 9: /* command: S_CENTER var_or_range  */
#line 501 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            center(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3218 "y.tab.c"
    break;

  case 10: /* command: S_FMT var_or_range STRING  */
#line 505 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            format_cell(sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                            scxfree((yyvsp[0].sval));
                                     }
#line 3229 "y.tab.c"
    break;

  case 11: /* command: S_DATEFMT var_or_range STRING  */
#line 512 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                       {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            dateformat(sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                            scxfree((yyvsp[0].sval));
                                       }
#line 3240 "y.tab.c"
    break;

  case 12: /* command: S_DATEFMT STRING  */
#line 518 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       dateformat(sh, lookat(sh, sh->currow, sh->curcol), lookat(sh, sh->currow, sh->curcol), (yyvsp[0].sval));
                                       scxfree((yyvsp[0].sval)); }
#line 3250 "y.tab.c"
    break;

  case 13: /* command: S_HIDE COL  */
#line 524 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { hide_col((yyvsp[0].ival), 1); }
#line 3256 "y.tab.c"
    break;

  case 14: /* command: S_HIDE NUMBER  */
#line 525 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { hide_row((yyvsp[0].ival), 1); }
#line 3262 "y.tab.c"
    break;

  case 15: /* command: S_SHOW COL  */
#line 526 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { show_col((yyvsp[0].ival), 1); }
#line 3268 "y.tab.c"
    break;

  case 16: /* command: S_SHOW NUMBER  */
#line 527 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { show_row((yyvsp[0].ival), 1); }
#line 3274 "y.tab.c"
    break;

  case 17: /* command: S_DELETECOL COL  */
#line 530 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       deletecol(sh, (yyvsp[0].ival), 1);
                                     }
#line 3284 "y.tab.c"
    break;

  case 18: /* command: S_DELETEROW NUMBER  */
#line 535 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       deleterow(sh, (yyvsp[0].ival), 1);
                                     }
#line 3294 "y.tab.c"
    break;

  case 19: /* command: S_HIDECOL COL  */
#line 542 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       hide_col((yyvsp[0].ival), 1); }
#line 3301 "y.tab.c"
    break;

  case 20: /* command: S_SHOWCOL COL  */
#line 544 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       show_col((yyvsp[0].ival), 1); }
#line 3308 "y.tab.c"
    break;

  case 21: /* command: S_HIDEROW NUMBER  */
#line 546 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       hide_row((yyvsp[0].ival), 1); }
#line 3315 "y.tab.c"
    break;

  case 22: /* command: S_SHOWROW NUMBER  */
#line 548 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       show_row((yyvsp[0].ival), 1); }
#line 3322 "y.tab.c"
    break;

  case 23: /* command: S_SHOWCOL COL ':' COL  */
#line 550 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       show_col((yyvsp[-2].ival), (yyvsp[0].ival)-(yyvsp[-2].ival)+1); }
#line 3329 "y.tab.c"
    break;

  case 24: /* command: S_SHOWROW NUMBER ':' NUMBER  */
#line 552 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       show_row((yyvsp[-2].ival), (yyvsp[0].ival)-(yyvsp[-2].ival)+1); }
#line 3336 "y.tab.c"
    break;

  case 25: /* command: S_HIDECOL COL ':' COL  */
#line 554 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       int c = sh->curcol, arg;
                                       if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
                                            sh->curcol = (yyvsp[-2].ival);
                                            arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
                                       } else {
                                            sh->curcol = (yyvsp[0].ival);
                                            arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
                                       }
                                       hide_col((yyvsp[-2].ival), arg);        // hide de un rango de columnas
                                       sh->curcol = c < sh->curcol ? c : c < sh->curcol + arg ? sh->curcol : c - arg;
                                     }
#line 3355 "y.tab.c"
    break;

  case 26: /* command: S_HIDEROW NUMBER ':' NUMBER  */
#line 568 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       int r = sh->currow, arg;      // hide de un rango de filas
                                       if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
                                           sh->currow = (yyvsp[-2].ival);
                                           arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
                                       } else {
                                           sh->currow = (yyvsp[0].ival);
                                           arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
                                       }
                                       hide_row((yyvsp[-2].ival), arg);
                                       sh->currow = r < sh->currow ? r : r < sh->currow + arg ? sh->currow : r - arg;
                                     }
#line 3374 "y.tab.c"
    break;

  case 27: /* command: S_VALUEIZEALL  */
#line 583 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       valueize_area(sh, 0, 0, sh->maxrow, sh->maxcol); }
#line 3383 "y.tab.c"
    break;

  case 28: /* command: S_SHIFT var_or_range STRING  */
#line 588 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       if (strlen((yyvsp[0].sval)) != 1 || ((yyvsp[0].sval)[0] != 'h' && (yyvsp[0].sval)[0] != 'j' && (yyvsp[0].sval)[0] != 'k' && (yyvsp[0].sval)[0] != 'l')) {
                                           sc_error("wrong parameter for shift command");
                                       } else {
                                           wchar_t wstr[2] = L"";
                                           swprintf(wstr, BUFFERSIZE, L"%c", (yyvsp[0].sval)[0]);
                                           shift(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, wstr[0]);
                                       }
                                       scxfree((yyvsp[0].sval));
                                     }
#line 3400 "y.tab.c"
    break;

  case 29: /* command: S_MARK COL var_or_range  */
#line 601 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       set_cell_mark((yyvsp[-1].ival) + 97, sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                     }
#line 3410 "y.tab.c"
    break;

  case 30: /* command: S_MARK COL var_or_range var_or_range  */
#line 607 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                              {
                                          struct roman * roman = session->cur_doc;
                                          struct sheet * sh = roman->cur_sh;
                                          srange * sr = create_range('\0', '\0', (yyvsp[-1].rval).left.vp, (yyvsp[0].rval).left.vp);
                                          unselect_ranges();
                                          set_range_mark((yyvsp[-2].ival) + 97, sh, sr);
                                     }
#line 3422 "y.tab.c"
    break;

  case 31: /* command: S_MARK COL STRING var_or_range  */
#line 615 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                            {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh;
                                       if ((sh = search_sheet(roman, (yyvsp[-1].sval))) != NULL ) {
                                           set_cell_mark((yyvsp[-2].ival) + 97, sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                       }
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3435 "y.tab.c"
    break;

  case 32: /* command: S_MARK COL STRING var_or_range var_or_range  */
#line 624 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                     {
                                          struct roman * roman = session->cur_doc;
                                          struct sheet * sh;
                                          if ((sh = search_sheet(roman, (yyvsp[-2].sval))) != NULL ) {
                                              srange * sr = create_range('\0', '\0', (yyvsp[-1].rval).left.vp, (yyvsp[0].rval).left.vp);
                                              unselect_ranges();
                                              set_range_mark((yyvsp[-3].ival) + 97, sh, sr);
                                          }
                                          scxfree((yyvsp[-2].sval));
                                     }
#line 3450 "y.tab.c"
    break;

  case 33: /* command: S_FILL var_or_range num num  */
#line 634 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       fill(sh, (yyvsp[-2].rval).left.vp, (yyvsp[-2].rval).right.vp, (yyvsp[-1].fval), (yyvsp[0].fval));
                                     }
#line 3460 "y.tab.c"
    break;

  case 34: /* command: S_FILL num num  */
#line 640 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { sc_error("Not enough parameters for fill command"); }
#line 3466 "y.tab.c"
    break;

  case 35: /* command: S_FREEZE NUMBER ':' NUMBER  */
#line 642 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[-2].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 1, 'r'); }
#line 3475 "y.tab.c"
    break;

  case 36: /* command: S_FREEZE NUMBER  */
#line 646 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[0].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 1, 'r'); }
#line 3484 "y.tab.c"
    break;

  case 37: /* command: S_FREEZE COL ':' COL  */
#line 650 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[-2].ival)), lookat(sh, 0, (yyvsp[0].ival)), 1, 'c'); }
#line 3493 "y.tab.c"
    break;

  case 38: /* command: S_FREEZE COL  */
#line 654 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[0].ival)), lookat(sh, 0, (yyvsp[0].ival)), 1, 'c'); }
#line 3502 "y.tab.c"
    break;

  case 39: /* command: S_UNFREEZE NUMBER ':' NUMBER  */
#line 658 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[-2].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 0, 'r'); }
#line 3511 "y.tab.c"
    break;

  case 40: /* command: S_UNFREEZE NUMBER  */
#line 662 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[0].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 0, 'r'); }
#line 3520 "y.tab.c"
    break;

  case 41: /* command: S_UNFREEZE COL ':' COL  */
#line 666 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[-2].ival)), lookat(sh, 0, (yyvsp[0].ival)), 0, 'c'); }
#line 3529 "y.tab.c"
    break;

  case 42: /* command: S_UNFREEZE COL  */
#line 670 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[0].ival)), lookat(sh, 0, (yyvsp[0].ival)), 0, 'c'); }
#line 3538 "y.tab.c"
    break;

  case 43: /* command: S_SORT range STRING  */
#line 675 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { sortrange(session->cur_doc->cur_sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                       //scxfree($3);
                                       //do not free here
                                     }
#line 3547 "y.tab.c"
    break;

  case 44: /* command: S_SUBTOTAL range COL STRING COL  */
#line 679 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                         {
                                       subtotal((yyvsp[-3].rval).left.vp->row, (yyvsp[-3].rval).left.vp->col, (yyvsp[-3].rval).right.vp->row,
                                                (yyvsp[-3].rval).right.vp->col, (yyvsp[-2].ival), (yyvsp[-1].sval), (yyvsp[0].ival), 0);
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3557 "y.tab.c"
    break;

  case 45: /* command: S_RSUBTOTAL range COL STRING COL  */
#line 684 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                       subtotal((yyvsp[-3].rval).left.vp->row, (yyvsp[-3].rval).left.vp->col, (yyvsp[-3].rval).right.vp->row,
                                                 (yyvsp[-3].rval).right.vp->col, (yyvsp[-2].ival), (yyvsp[-1].sval), (yyvsp[0].ival), 1);
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3567 "y.tab.c"
    break;

  case 46: /* command: S_AUTOFIT COL ':' COL  */
#line 698 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { auto_fit(session->cur_doc->cur_sh, (yyvsp[-2].ival), (yyvsp[0].ival), DEFWIDTH); }
#line 3573 "y.tab.c"
    break;

  case 47: /* command: S_AUTOFIT COL  */
#line 699 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { auto_fit(session->cur_doc->cur_sh, (yyvsp[0].ival), (yyvsp[0].ival), DEFWIDTH); }
#line 3579 "y.tab.c"
    break;

  case 48: /* command: S_PAD NUMBER COL ':' COL  */
#line 701 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                       pad(session->cur_doc->cur_sh, (yyvsp[-3].ival), 0, (yyvsp[-2].ival), session->cur_doc->cur_sh->maxrow, (yyvsp[0].ival)); }
#line 3586 "y.tab.c"
    break;

  case 49: /* command: S_PAD NUMBER COL  */
#line 703 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       pad(sh, (yyvsp[-1].ival), 0, (yyvsp[0].ival), sh->maxrow, (yyvsp[0].ival)); }
#line 3595 "y.tab.c"
    break;

  case 50: /* command: S_PAD NUMBER var_or_range  */
#line 707 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       pad(sh, (yyvsp[-1].ival), (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3604 "y.tab.c"
    break;

  case 51: /* command: S_GETFORMAT COL  */
#line 711 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {   getformat((yyvsp[0].ival), fdoutput); }
#line 3610 "y.tab.c"
    break;

  case 52: /* command: S_FORMAT COL NUMBER NUMBER NUMBER  */
#line 712 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                           {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       doformat(sh, (yyvsp[-3].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival));
                                       }
#line 3620 "y.tab.c"
    break;

  case 53: /* command: S_FORMAT NUMBER NUMBER  */
#line 717 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       dorowformat(sh, (yyvsp[-1].ival), (yyvsp[0].ival));
                                     }
#line 3630 "y.tab.c"
    break;

  case 54: /* command: S_FILTERON range  */
#line 723 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     { enable_filters((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                     }
#line 3637 "y.tab.c"
    break;

  case 55: /* command: S_GOTO var_or_range var_or_range  */
#line 725 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       moveto(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                     }
#line 3647 "y.tab.c"
    break;

  case 56: /* command: S_GOTO var_or_range  */
#line 730 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       moveto(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, -1, -1);
                                 }
#line 3657 "y.tab.c"
    break;

  case 57: /* command: S_GOTO num  */
#line 735 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       num_search(sh, (yyvsp[0].fval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 1); }
#line 3666 "y.tab.c"
    break;

  case 58: /* command: S_GOTO STRING  */
#line 739 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 1); }
#line 3675 "y.tab.c"
    break;

  case 59: /* command: S_GOTO '#' STRING  */
#line 744 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 1, 1); }
#line 3684 "y.tab.c"
    break;

  case 60: /* command: S_GOTO '%' STRING  */
#line 749 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 2, 1); }
#line 3693 "y.tab.c"
    break;

  case 61: /* command: S_GOTOB num  */
#line 755 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       num_search(sh, (yyvsp[0].fval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 0); }
#line 3702 "y.tab.c"
    break;

  case 62: /* command: S_GOTOB STRING  */
#line 760 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 0); }
#line 3711 "y.tab.c"
    break;

  case 63: /* command: S_GOTOB '#' STRING  */
#line 765 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 1, 0); }
#line 3720 "y.tab.c"
    break;

  case 64: /* command: S_GOTOB '%' STRING  */
#line 770 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 2, 0); }
#line 3729 "y.tab.c"
    break;

  case 65: /* command: S_CCOPY range  */
#line 777 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 { copy_to_clipboard((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3735 "y.tab.c"
    break;

  case 66: /* command: S_STRTONUM range  */
#line 778 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 { convert_string_to_number((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3741 "y.tab.c"
    break;

  case 67: /* command: S_CPASTE  */
#line 779 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 { paste_from_clipboard(); }
#line 3747 "y.tab.c"
    break;

  case 68: /* command: S_LOCK var_or_range  */
#line 780 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   lock_cells(sh, (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                 }
#line 3757 "y.tab.c"
    break;

  case 69: /* command: S_UNLOCK var_or_range  */
#line 785 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   unlock_cells(sh, (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                 }
#line 3767 "y.tab.c"
    break;

  case 70: /* command: S_NEWSHEET STRING  */
#line 790 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh;

                                   // do not need to alloc a new 'Sheet1'
                                   // just reuse the just allocated 'Sheet1' in load_file();
                                   if (! strcmp((yyvsp[0].sval), "Sheet1") && (sh = search_sheet(roman, (yyvsp[0].sval))) != NULL && sh->flags & is_allocated) {
                                       sh->flags &= ~is_allocated;
                                       sh->flags |= is_empty;
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');

                                   // if a sheet already exists with the name we are trying to create
                                   } else if ((sh = search_sheet(roman, (yyvsp[0].sval))) != NULL ) {
                                       sc_info("sheet already exist with that name");
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');

                                   // if a just allocated 'Sheet1' exists, reuse it and do not malloc a new one.
                                   } else if ((sh = search_sheet(roman, "Sheet1")) != NULL && sh->flags & is_allocated) {
                                       sh->flags &= ~is_allocated;
                                       sh->flags |= is_empty;
                                       free(sh->name);
                                       sh->name = (yyvsp[0].sval);
                                       chg_mode('.');
                                       ui_update(true);

                                   // if reached here, now yes malloc a new one
                                   } else {
                                       roman->cur_sh = new_sheet(roman, (yyvsp[0].sval));
                                       growtbl(roman->cur_sh, GROWNEW, 0, 0);
                                       erasedb(roman->cur_sh, 0);
                                       scxfree((yyvsp[0].sval));
                                       roman->modflg++;
                                       chg_mode('.');
                                       ui_update(true);
                                   }
                                 }
#line 3810 "y.tab.c"
    break;

  case 71: /* command: S_DELSHEET STRING  */
#line 828 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh;
                                   if ((sh = search_sheet(roman, (yyvsp[0].sval))) == NULL ) {
                                       sc_info("No sheet exists with that name");
                                       scxfree((yyvsp[0].sval));
                                   } else if (roman->cur_sh == sh && sh->next == NULL && sh->prev == NULL) {
                                       sc_info("Cannot delete the only sheet of document");
                                       scxfree((yyvsp[0].sval));
                                   } else {
                                       if (roman->cur_sh == sh && sh->next != NULL)
                                           roman->cur_sh = sh->next;
                                       else if (roman->cur_sh == sh)
                                           roman->cur_sh = sh->prev;
                                       delete_sheet(roman, sh, 0);
                                       sh = NULL;
                                       roman->modflg++;
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');
                                       ui_update(true);
                                   }
                                 }
#line 3837 "y.tab.c"
    break;

  case 72: /* command: S_DELSHEET  */
#line 850 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   if (sh->next == NULL && sh->prev == NULL) {
                                       sc_info("Cannot delete the only sheet of document");
                                   } else {
                                       if (roman->cur_sh == sh && sh->next != NULL)
                                           roman->cur_sh = sh->next;
                                       else if (roman->cur_sh == sh)
                                           roman->cur_sh = sh->prev;
                                       delete_sheet(roman, sh, 0);
                                       sh = NULL;
                                       roman->modflg++;
                                       chg_mode('.');
                                       ui_update(true);
                                   }
                                 }
#line 3859 "y.tab.c"
    break;

  case 73: /* command: S_NEXTSHEET  */
#line 867 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   if (roman->cur_sh->next != NULL) {
                                       roman->cur_sh = roman->cur_sh->next;
                                   } else if (roman->next != NULL) {
                                       session->cur_doc = roman->next;
                                       session->cur_doc->cur_sh = session->cur_doc->first_sh;
                                   } else {
                                       session->cur_doc = session->first_doc;
                                       session->cur_doc->cur_sh = session->cur_doc->first_sh;
                                   }
                                   chg_mode('.');
                                   ui_update(true);
                                 }
#line 3878 "y.tab.c"
    break;

  case 74: /* command: S_PREVSHEET  */
#line 881 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   if (roman->cur_sh->prev != NULL) {
                                       roman->cur_sh = roman->cur_sh->prev;
                                   } else if (roman->prev != NULL) {
                                       session->cur_doc = roman->prev;
                                       session->cur_doc->cur_sh = session->cur_doc->last_sh;
                                   } else {
                                       session->cur_doc = session->last_doc;
                                       session->cur_doc->cur_sh = session->cur_doc->last_sh;
                                   }
                                   chg_mode('.');
                                   ui_update(true);
                                 }
#line 3897 "y.tab.c"
    break;

  case 75: /* command: S_MOVETOSHEET STRING  */
#line 896 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct sheet * sh;
                                   if ((sh = search_sheet(session->cur_doc, (yyvsp[0].sval))) != NULL )
                                       session->cur_doc->cur_sh = sh;
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3908 "y.tab.c"
    break;

  case 76: /* command: S_RENAMESHEET STRING  */
#line 902 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct sheet * sh = session->cur_doc->cur_sh;
                                   if (sh->name != NULL) free(sh->name);
                                   session->cur_doc->modflg++;
                                   sh->name = (yyvsp[0].sval);
                                   chg_mode('.');
                                   ui_show_header();
                                 }
#line 3921 "y.tab.c"
    break;

  case 77: /* command: S_NMAP STRING STRING  */
#line 911 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), NORMAL_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3931 "y.tab.c"
    break;

  case 78: /* command: S_IMAP STRING STRING  */
#line 917 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), INSERT_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3941 "y.tab.c"
    break;

  case 79: /* command: S_VMAP STRING STRING  */
#line 922 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), VISUAL_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3951 "y.tab.c"
    break;

  case 80: /* command: S_CMAP STRING STRING  */
#line 927 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), COMMAND_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3961 "y.tab.c"
    break;

  case 81: /* command: S_NNOREMAP STRING STRING  */
#line 932 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), NORMAL_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3971 "y.tab.c"
    break;

  case 82: /* command: S_INOREMAP STRING STRING  */
#line 938 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), INSERT_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3981 "y.tab.c"
    break;

  case 83: /* command: S_VNOREMAP STRING STRING  */
#line 943 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), VISUAL_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3991 "y.tab.c"
    break;

  case 84: /* command: S_CNOREMAP STRING STRING  */
#line 948 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), COMMAND_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4001 "y.tab.c"
    break;

  case 85: /* command: S_NUNMAP STRING  */
#line 954 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   del_map((yyvsp[0].sval), NORMAL_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4010 "y.tab.c"
    break;

  case 86: /* command: S_IUNMAP STRING  */
#line 959 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   del_map((yyvsp[0].sval), INSERT_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4019 "y.tab.c"
    break;

  case 87: /* command: S_VUNMAP STRING  */
#line 963 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   del_map((yyvsp[0].sval), VISUAL_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4028 "y.tab.c"
    break;

  case 88: /* command: S_CUNMAP STRING  */
#line 968 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   del_map((yyvsp[0].sval), COMMAND_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4037 "y.tab.c"
    break;

  case 89: /* command: S_COLOR STRING  */
#line 972 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
#ifdef USECOLORS
                                   chg_color((yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4048 "y.tab.c"
    break;

  case 90: /* command: S_DETAIL var  */
#line 979 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   char det[BUFFERSIZE] = "";
                                   struct ent * e = (yyvsp[0].ent).vp;

                                   sprintf(det + strlen(det), "row: %d\n", e->row);
                                   sprintf(det + strlen(det), "col: %d\n", e->col);
                                   sprintf(det + strlen(det), "cellerror: %d\n"   , e->cellerror);
                                   sprintf(det + strlen(det), "flags:\n");
                                   sprintf(det + strlen(det), "is_valid: %d\n"    , e->flags & is_valid );
                                   sprintf(det + strlen(det), "is_deleted: %d\n"  , e->flags & is_deleted);
                                   sprintf(det + strlen(det), "is_changed: %d\n"  , e->flags & is_changed);
                                   sprintf(det + strlen(det), "is_strexpr: %d\n"  , e->flags & is_strexpr);
                                   sprintf(det + strlen(det), "is_leftflush: %d\n", e->flags & is_leftflush);
                                   sprintf(det + strlen(det), "is_locked: %d\n"   , e->flags & is_locked);
                                   sprintf(det + strlen(det), "is_label: %d\n"    , e->flags & is_label);
                                   sprintf(det + strlen(det), "iscleared: %d\n"   , e->flags & iscleared);
                                   sprintf(det + strlen(det), "may_sync: %d\n"    , e->flags & may_sync);
                                   ui_show_text((char *) &det);
                                   }
#line 4072 "y.tab.c"
    break;

  case 91: /* command: S_CELLCOLOR var_or_range STRING  */
#line 1000 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
#ifdef USECOLORS
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   if ( ! config_get_bool("nocurses"))
                                       color_cell(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4086 "y.tab.c"
    break;

  case 92: /* command: S_TRIGGER var_or_range STRING  */
#line 1010 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                        {
                                          set_trigger(session->cur_doc->cur_sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval));
                                          scxfree((yyvsp[0].sval));
                                        }
#line 4095 "y.tab.c"
    break;

  case 93: /* command: S_OFFSCR_SC_COLS NUMBER  */
#line 1015 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->offscr_sc_cols = (yyvsp[0].ival);
                                 }
#line 4105 "y.tab.c"
    break;

  case 94: /* command: S_OFFSCR_SC_ROWS NUMBER  */
#line 1020 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->offscr_sc_rows = (yyvsp[0].ival);
                                 }
#line 4115 "y.tab.c"
    break;

  case 95: /* command: S_NB_FROZEN_ROWS NUMBER  */
#line 1025 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->nb_frozen_rows = (yyvsp[0].ival);
                                 }
#line 4125 "y.tab.c"
    break;

  case 96: /* command: S_NB_FROZEN_COLS NUMBER  */
#line 1030 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->nb_frozen_cols = (yyvsp[0].ival);
                                 }
#line 4135 "y.tab.c"
    break;

  case 97: /* command: S_NB_FROZEN_SCREENROWS NUMBER  */
#line 1035 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                       {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->nb_frozen_screenrows = (yyvsp[0].ival);
                                 }
#line 4145 "y.tab.c"
    break;

  case 98: /* command: S_NB_FROZEN_SCREENCOLS NUMBER  */
#line 1040 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                       {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   sh->nb_frozen_screencols = (yyvsp[0].ival);
                                 }
#line 4155 "y.tab.c"
    break;

  case 99: /* command: S_UNTRIGGER var_or_range  */
#line 1046 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   del_trigger(session->cur_doc->cur_sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
                                   }
#line 4163 "y.tab.c"
    break;

  case 100: /* command: S_CELLCOLOR STRING  */
#line 1050 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! config_get_bool("nocurses"))
                                       color_cell(sh, sh->currow, sh->curcol, sh->currow, sh->curcol, (yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4177 "y.tab.c"
    break;

  case 101: /* command: S_UNFORMAT var_or_range  */
#line 1060 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! config_get_bool("nocurses")) unformat(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
#endif
                                   }
#line 4189 "y.tab.c"
    break;

  case 102: /* command: S_UNFORMAT  */
#line 1068 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! config_get_bool("nocurses")) unformat(sh, sh->currow, sh->curcol, sh->currow, sh->curcol);
#endif
                                   }
#line 4201 "y.tab.c"
    break;

  case 103: /* command: S_REDEFINE_COLOR STRING NUMBER NUMBER NUMBER  */
#line 1076 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                      {
                                         redefine_color((yyvsp[-3].sval), (yyvsp[-2].ival), (yyvsp[-1].ival), (yyvsp[0].ival));
                                         scxfree((yyvsp[-3].sval)); }
#line 4209 "y.tab.c"
    break;

  case 104: /* command: S_DEFINE_COLOR STRING NUMBER NUMBER NUMBER  */
#line 1080 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                    {
                                         define_color((yyvsp[-3].sval), (yyvsp[-2].ival), (yyvsp[-1].ival), (yyvsp[0].ival));
                                         scxfree((yyvsp[-3].sval)); }
#line 4217 "y.tab.c"
    break;

  case 105: /* command: S_FCOPY  */
#line 1084 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { fcopy(session->cur_doc->cur_sh, ""); }
#line 4223 "y.tab.c"
    break;

  case 106: /* command: S_FCOPY strarg  */
#line 1085 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { fcopy(session->cur_doc->cur_sh, (yyvsp[0].sval)); }
#line 4229 "y.tab.c"
    break;

  case 107: /* command: S_FSUM  */
#line 1086 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { fsum(session->cur_doc->cur_sh);  }
#line 4235 "y.tab.c"
    break;

  case 108: /* command: S_PLOT STRING var_or_range  */
#line 1088 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                          {
                                     plot((yyvsp[-1].sval), (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
                                     scxfree((yyvsp[-1].sval));
                                   }
#line 4244 "y.tab.c"
    break;

  case 109: /* command: S_SET setlist  */
#line 1096 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { //if (! loading) sc_debug("INT: Config value changed");
                                   }
#line 4251 "y.tab.c"
    break;

  case 110: /* command: S_DEFINE strarg range  */
#line 1112 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { add_range((yyvsp[-1].sval), (yyvsp[0].rval).left, (yyvsp[0].rval).right, 1); }
#line 4257 "y.tab.c"
    break;

  case 111: /* command: S_DEFINE strarg var  */
#line 1113 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { add_range((yyvsp[-1].sval), (yyvsp[0].ent), (yyvsp[0].ent), 0); }
#line 4263 "y.tab.c"
    break;

  case 112: /* command: S_UNDEFINE var_or_range  */
#line 1115 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { del_range((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 4269 "y.tab.c"
    break;

  case 113: /* command: S_EVAL e  */
#line 1117 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     eval_result = eval(sh, NULL, (yyvsp[0].enode));
                                     efree((yyvsp[0].enode));
                                   }
#line 4280 "y.tab.c"
    break;

  case 114: /* command: S_EXECUTE STRING  */
#line 1123 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {

                                     inputline[0]=L'\0';

                                     #ifdef HISTORY_FILE
                                            commandline_history = (struct history *) create_history(':');
                                            load_history(commandline_history, ':'); // load the command history file
                                     #endif
                                     #ifdef INS_HISTORY_FILE
                                            insert_history = (struct history *) create_history('=');
                                            load_history(insert_history, '='); // load the insert history file
                                     #endif

                                     (void) swprintf(inputline, BUFFERSIZE, L"%s", (yyvsp[0].sval));

                                     Buffer *auxb = buffer_create(1);
                                     buffer_append(auxb, OKEY_ENTER);
                                     // TODO: pass this as a parameter
                                     SC *const sc = (SC *)((uint8_t *)session - offsetof(SC, session));
                                     do_commandmode(sc, auxb);
                                     buffer_reset(auxb);
                                     buffer_destroy(auxb);
                                     auxb = NULL;
                                     inputline[0]=L'\0';
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4311 "y.tab.c"
    break;

  case 115: /* command: S_EXPORT STRING STRING  */
#line 1149 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     swprintf(inputline, BUFFERSIZE, L"e! %s %s", (yyvsp[-1].sval), (yyvsp[0].sval));
                                     do_export(0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol);
                                     scxfree((yyvsp[-1].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4323 "y.tab.c"
    break;

  case 116: /* command: S_QUIT  */
#line 1156 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     printf("quitting. unsaved changes will be lost.\n");
                                     shall_quit = 2; // unsaved changes are lost!
                                   }
#line 4332 "y.tab.c"
    break;

  case 117: /* command: S_REBUILD_GRAPH  */
#line 1160 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     rebuild_graph();
                                     ui_update(false);
                                   }
#line 4341 "y.tab.c"
    break;

  case 118: /* command: S_PRINT_GRAPH  */
#line 1165 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { print_vertexs(); }
#line 4347 "y.tab.c"
    break;

  case 119: /* command: S_SYNCREFS  */
#line 1166 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { sync_refs(session->cur_doc->cur_sh); }
#line 4353 "y.tab.c"
    break;

  case 120: /* command: S_UNDO  */
#line 1168 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
#ifdef UNDO
                                     do_undo();
                                     // sync_refs(session->cur_doc->cur_sh);
                                     EvalAll();
                                     ui_update(true);
#endif
                                   }
#line 4366 "y.tab.c"
    break;

  case 121: /* command: S_REDO  */
#line 1177 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
#ifdef UNDO
                                     do_redo();
                                     // sync_refs(session->cur_doc->cur_sh);
                                     EvalAll();
                                     ui_update(true);
#endif
                                   }
#line 4379 "y.tab.c"
    break;

  case 122: /* command: S_RECALC  */
#line 1187 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     EvalAll();
                                     //ui_update(1);
                                     //changed = 0;
                                   }
#line 4389 "y.tab.c"
    break;

  case 123: /* command: S_GETNUM var_or_range  */
#line 1192 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     getnum(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput);
                                   }
#line 4399 "y.tab.c"
    break;

  case 124: /* command: S_GETNUM '{' STRING '}' '!' var_or_range  */
#line 1198 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                  {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-3].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     getnum(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput);
                                     scxfree((yyvsp[-3].sval));
                                   }
#line 4412 "y.tab.c"
    break;

  case 125: /* command: S_GETSTRING var_or_range  */
#line 1206 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { getstring((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4418 "y.tab.c"
    break;

  case 126: /* command: S_GETEXP var_or_range  */
#line 1208 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { getexp((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4424 "y.tab.c"
    break;

  case 127: /* command: S_GETFMT var_or_range  */
#line 1211 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { getfmt((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4430 "y.tab.c"
    break;

  case 128: /* command: S_YANKAREA '{' STRING '}' '!' var_or_range STRING  */
#line 1213 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                           {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-4].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     yank_area(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval)[0], 1);
                                     scxfree((yyvsp[-4].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4444 "y.tab.c"
    break;

  case 129: /* command: S_PASTEYANKED '{' STRING '}' NUMBER STRING  */
#line 1222 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                    {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-3].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     paste_yanked_ents(sh, (yyvsp[-1].ival), (yyvsp[0].sval)[0]);
                                     scxfree((yyvsp[-3].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4458 "y.tab.c"
    break;

  case 130: /* command: S_SEVAL e  */
#line 1231 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     seval_result = seval(sh, NULL, (yyvsp[0].enode)); // always make sure this seval_result is always freed afterwards
                                     efree((yyvsp[0].enode));
                                   }
#line 4469 "y.tab.c"
    break;

  case 131: /* command: S_ERROR STRING  */
#line 1237 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   { sc_error((yyvsp[0].sval));
                                     //free $2
                                   }
#line 4477 "y.tab.c"
    break;

  case 133: /* command: error  */
#line 1242 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                 {
                     sc_error("syntax error: %s", line);
                     YYABORT;
                 }
#line 4486 "y.tab.c"
    break;

  case 134: /* term: var  */
#line 1247 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    if ((yyvsp[0].ent).vf & GET_ENT)
                                        (yyval.enode) = (yyvsp[0].ent).expr;
                                    else {
                                       (yyvsp[0].ent).sheet = NULL;
                                       (yyval.enode) = new_var(O_VAR, (yyvsp[0].ent));
                                       (yyval.enode)->range.left.expr = NULL;
                                       (yyval.enode)->range.right.expr = NULL;
                                    }
                                  }
#line 4501 "y.tab.c"
    break;

  case 135: /* term: '{' STRING '}' '!' var  */
#line 1258 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    struct sheet * sh;
                                    if ((sh = search_sheet(roman, (yyvsp[-3].sval))) != NULL) {
                                        struct ent_ptr ep;
                                        ep.vf = (yyvsp[0].ent).vf;
                                        ep.vp = lookat(sh, (yyvsp[0].ent).vp->row, (yyvsp[0].ent).vp->col);
                                        ep.sheet = sh;
                                        (yyval.enode) = new_var(O_VAR, ep);
                                        (yyval.enode)->range.left.expr = NULL;
                                        (yyval.enode)->range.right.expr = NULL;
                                        scxfree((yyvsp[-3].sval));
                                    } else {
                                        //sc_debug("not sheet found");
                                        (yyval.enode) = NULL;
                                        scxfree((yyvsp[-3].sval));
                                    }
                                  }
#line 4524 "y.tab.c"
    break;

  case 136: /* term: '@' K_FIXED term  */
#line 1277 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('f', (yyvsp[0].enode), ENULL); }
#line 4530 "y.tab.c"
    break;

  case 137: /* term: '(' '@' K_FIXED ')' term  */
#line 1280 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('F', (yyvsp[0].enode), ENULL); }
#line 4536 "y.tab.c"
    break;

  case 138: /* term: '@' K_SUM '(' var_or_range ')'  */
#line 1283 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SUM, new_range(REDUCE | SUM, (yyvsp[-1].rval)), ENULL); }
#line 4542 "y.tab.c"
    break;

  case 139: /* term: '@' K_SUM '(' range ',' e ')'  */
#line 1285 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SUM, new_range(REDUCE | SUM, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4548 "y.tab.c"
    break;

  case 140: /* term: '@' K_PROD '(' var_or_range ')'  */
#line 1287 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(PROD, new_range(REDUCE | PROD, (yyvsp[-1].rval)), ENULL); }
#line 4554 "y.tab.c"
    break;

  case 141: /* term: '@' K_PROD '(' range ',' e ')'  */
#line 1289 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(PROD, new_range(REDUCE | PROD, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4560 "y.tab.c"
    break;

  case 142: /* term: '@' K_AVG '(' var_or_range ')'  */
#line 1291 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(AVG, new_range(REDUCE | AVG, (yyvsp[-1].rval)), ENULL); }
#line 4566 "y.tab.c"
    break;

  case 143: /* term: '@' K_AVG '(' range ',' e ')'  */
#line 1293 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(AVG, new_range(REDUCE | AVG, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4572 "y.tab.c"
    break;

  case 144: /* term: '@' K_STDDEV '(' var_or_range ')'  */
#line 1295 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STDDEV, new_range(REDUCE | STDDEV, (yyvsp[-1].rval)), ENULL); }
#line 4578 "y.tab.c"
    break;

  case 145: /* term: '@' K_STDDEV '(' range ',' e ')'  */
#line 1297 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STDDEV, new_range(REDUCE | STDDEV, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4584 "y.tab.c"
    break;

  case 146: /* term: '@' K_COUNT '(' var_or_range ')'  */
#line 1299 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(COUNT, new_range(REDUCE | COUNT, (yyvsp[-1].rval)), ENULL); }
#line 4590 "y.tab.c"
    break;

  case 147: /* term: '@' K_COUNT '(' range ',' e ')'  */
#line 1301 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(COUNT, new_range(REDUCE | COUNT, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4596 "y.tab.c"
    break;

  case 148: /* term: '@' K_MAX '(' var_or_range ')'  */
#line 1303 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MAX, new_range(REDUCE | MAX, (yyvsp[-1].rval)), ENULL); }
#line 4602 "y.tab.c"
    break;

  case 149: /* term: '@' K_MAX '(' range ',' e ')'  */
#line 1305 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MAX, new_range(REDUCE | MAX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4608 "y.tab.c"
    break;

  case 150: /* term: '@' K_MAX '(' e ',' expr_list ')'  */
#line 1307 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LMAX, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4614 "y.tab.c"
    break;

  case 151: /* term: '@' K_MIN '(' var_or_range ')'  */
#line 1309 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MIN, new_range(REDUCE | MIN, (yyvsp[-1].rval)), ENULL); }
#line 4620 "y.tab.c"
    break;

  case 152: /* term: '@' K_MIN '(' range ',' e ')'  */
#line 1311 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MIN, new_range(REDUCE | MIN, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4626 "y.tab.c"
    break;

  case 153: /* term: '@' K_MIN '(' e ',' expr_list ')'  */
#line 1313 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LMIN, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4632 "y.tab.c"
    break;

  case 154: /* term: '@' K_ROWS '(' var_or_range ')'  */
#line 1315 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new_range(REDUCE | 'R', (yyvsp[-1].rval)); }
#line 4638 "y.tab.c"
    break;

  case 155: /* term: '@' K_COLS '(' var_or_range ')'  */
#line 1317 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new_range(REDUCE | 'C', (yyvsp[-1].rval)); }
#line 4644 "y.tab.c"
    break;

  case 156: /* term: '@' K_ABS '(' e ')'  */
#line 1318 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ABS, (yyvsp[-1].enode), ENULL); }
#line 4650 "y.tab.c"
    break;

  case 157: /* term: '@' K_FROW '(' e ')'  */
#line 1319 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FROW, (yyvsp[-1].enode), ENULL); }
#line 4656 "y.tab.c"
    break;

  case 158: /* term: '@' K_FCOL '(' e ')'  */
#line 1320 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FCOL, (yyvsp[-1].enode), ENULL); }
#line 4662 "y.tab.c"
    break;

  case 159: /* term: '@' K_ACOS '(' e ')'  */
#line 1321 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ACOS, (yyvsp[-1].enode), ENULL); }
#line 4668 "y.tab.c"
    break;

  case 160: /* term: '@' K_ASIN '(' e ')'  */
#line 1322 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ASIN, (yyvsp[-1].enode), ENULL); }
#line 4674 "y.tab.c"
    break;

  case 161: /* term: '@' K_ATAN '(' e ')'  */
#line 1323 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ATAN, (yyvsp[-1].enode), ENULL); }
#line 4680 "y.tab.c"
    break;

  case 162: /* term: '@' K_ATAN2 '(' e ',' e ')'  */
#line 1325 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ATAN2, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4686 "y.tab.c"
    break;

  case 163: /* term: '@' K_CEIL '(' e ')'  */
#line 1326 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(CEIL, (yyvsp[-1].enode), ENULL); }
#line 4692 "y.tab.c"
    break;

  case 164: /* term: '@' K_COS '(' e ')'  */
#line 1327 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(COS, (yyvsp[-1].enode), ENULL); }
#line 4698 "y.tab.c"
    break;

  case 165: /* term: '@' K_EXP '(' e ')'  */
#line 1328 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(EXP, (yyvsp[-1].enode), ENULL); }
#line 4704 "y.tab.c"
    break;

  case 166: /* term: '@' K_FABS '(' e ')'  */
#line 1329 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FABS, (yyvsp[-1].enode), ENULL); }
#line 4710 "y.tab.c"
    break;

  case 167: /* term: '@' K_FLOOR '(' e ')'  */
#line 1330 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FLOOR, (yyvsp[-1].enode), ENULL); }
#line 4716 "y.tab.c"
    break;

  case 168: /* term: '@' K_HYPOT '(' e ',' e ')'  */
#line 1332 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(HYPOT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4722 "y.tab.c"
    break;

  case 169: /* term: '@' K_LN '(' e ')'  */
#line 1333 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LOG, (yyvsp[-1].enode), ENULL); }
#line 4728 "y.tab.c"
    break;

  case 170: /* term: '@' K_LOG '(' e ')'  */
#line 1334 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LOG10, (yyvsp[-1].enode), ENULL); }
#line 4734 "y.tab.c"
    break;

  case 171: /* term: '@' K_POW '(' e ',' e ')'  */
#line 1336 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(POW, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4740 "y.tab.c"
    break;

  case 172: /* term: '@' K_SIN '(' e ')'  */
#line 1337 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SIN, (yyvsp[-1].enode), ENULL); }
#line 4746 "y.tab.c"
    break;

  case 173: /* term: '@' K_SQRT '(' e ')'  */
#line 1338 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SQRT, (yyvsp[-1].enode), ENULL); }
#line 4752 "y.tab.c"
    break;

  case 174: /* term: '@' K_TAN '(' e ')'  */
#line 1339 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(TAN, (yyvsp[-1].enode), ENULL); }
#line 4758 "y.tab.c"
    break;

  case 175: /* term: '@' K_DTR '(' e ')'  */
#line 1340 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DTR, (yyvsp[-1].enode), ENULL); }
#line 4764 "y.tab.c"
    break;

  case 176: /* term: '@' K_RTD '(' e ')'  */
#line 1341 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(RTD, (yyvsp[-1].enode), ENULL); }
#line 4770 "y.tab.c"
    break;

  case 177: /* term: '@' K_RND '(' e ')'  */
#line 1342 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(RND, (yyvsp[-1].enode), ENULL); }
#line 4776 "y.tab.c"
    break;

  case 178: /* term: '@' K_ROUND '(' e ',' e ')'  */
#line 1344 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ROUND, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4782 "y.tab.c"
    break;

  case 179: /* term: '@' K_IF '(' e ',' e ',' e ')'  */
#line 1346 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(IF,  (yyvsp[-5].enode),new(',',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4788 "y.tab.c"
    break;

  case 180: /* term: '@' K_PV '(' e ',' e ',' e ')'  */
#line 1348 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(PV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4794 "y.tab.c"
    break;

  case 181: /* term: '@' K_FV '(' e ',' e ',' e ')'  */
#line 1350 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4800 "y.tab.c"
    break;

  case 182: /* term: '@' K_PMT '(' e ',' e ',' e ')'  */
#line 1352 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(PMT, (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4806 "y.tab.c"
    break;

  case 183: /* term: '@' K_HOUR '(' e ')'  */
#line 1353 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(HOUR, (yyvsp[-1].enode), ENULL); }
#line 4812 "y.tab.c"
    break;

  case 184: /* term: '@' K_MINUTE '(' e ')'  */
#line 1354 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MINUTE, (yyvsp[-1].enode), ENULL); }
#line 4818 "y.tab.c"
    break;

  case 185: /* term: '@' K_SECOND '(' e ')'  */
#line 1355 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SECOND, (yyvsp[-1].enode), ENULL); }
#line 4824 "y.tab.c"
    break;

  case 186: /* term: '@' K_MONTH '(' e ')'  */
#line 1356 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MONTH, (yyvsp[-1].enode), ENULL); }
#line 4830 "y.tab.c"
    break;

  case 187: /* term: '@' K_DAY '(' e ')'  */
#line 1357 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DAY, (yyvsp[-1].enode), ENULL); }
#line 4836 "y.tab.c"
    break;

  case 188: /* term: '@' K_YEAR '(' e ')'  */
#line 1358 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(YEAR, (yyvsp[-1].enode), ENULL); }
#line 4842 "y.tab.c"
    break;

  case 189: /* term: '@' K_NOW  */
#line 1359 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(NOW, ENULL, ENULL);}
#line 4848 "y.tab.c"
    break;

  case 190: /* term: '@' K_DTS '(' e ',' e ',' e ')'  */
#line 1361 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4854 "y.tab.c"
    break;

  case 191: /* term: NUMBER '.' NUMBER '.' NUMBER  */
#line 1363 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DTS, new_const(O_CONST, (double) (yyvsp[-4].ival)),
                                         new(',', new_const(O_CONST, (double) (yyvsp[-2].ival)),
                                         new_const(O_CONST, (double) (yyvsp[0].ival))));}
#line 4862 "y.tab.c"
    break;

  case 192: /* term: '@' K_TTS '(' e ',' e ',' e ')'  */
#line 1367 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(TTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4868 "y.tab.c"
    break;

  case 193: /* term: '@' K_STON '(' e ')'  */
#line 1368 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STON, (yyvsp[-1].enode), ENULL); }
#line 4874 "y.tab.c"
    break;

  case 194: /* term: '@' K_SLEN '(' e ')'  */
#line 1369 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SLEN, (yyvsp[-1].enode), ENULL); }
#line 4880 "y.tab.c"
    break;

  case 195: /* term: '@' K_EQS '(' e ',' e ')'  */
#line 1371 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(EQS, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4886 "y.tab.c"
    break;

  case 196: /* term: '@' K_DATE '(' e ')'  */
#line 1372 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DATE, (yyvsp[-1].enode), ENULL); }
#line 4892 "y.tab.c"
    break;

  case 197: /* term: '@' K_DATE '(' e ',' e ')'  */
#line 1374 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(DATE, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4898 "y.tab.c"
    break;

  case 198: /* term: '@' K_FMT '(' e ',' e ')'  */
#line 1376 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FMT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4904 "y.tab.c"
    break;

  case 199: /* term: '@' K_UPPER '(' e ')'  */
#line 1377 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(UPPER, (yyvsp[-1].enode), ENULL); }
#line 4910 "y.tab.c"
    break;

  case 200: /* term: '@' K_LOWER '(' e ')'  */
#line 1378 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LOWER, (yyvsp[-1].enode), ENULL); }
#line 4916 "y.tab.c"
    break;

  case 201: /* term: '@' K_CAPITAL '(' e ')'  */
#line 1379 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(CAPITAL, (yyvsp[-1].enode), ENULL); }
#line 4922 "y.tab.c"
    break;

  case 202: /* term: '@' K_INDEX '(' range ',' e ')'  */
#line 1381 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4928 "y.tab.c"
    break;

  case 203: /* term: '@' K_INDEX '(' e ',' range ')'  */
#line 1383 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4934 "y.tab.c"
    break;

  case 204: /* term: '@' K_INDEX '(' range ',' e ',' e ')'  */
#line 1385 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4940 "y.tab.c"
    break;

  case 205: /* term: '@' K_LOOKUP '(' range ',' e ')'  */
#line 1387 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4946 "y.tab.c"
    break;

  case 206: /* term: '@' K_LOOKUP '(' e ',' range ')'  */
#line 1389 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4952 "y.tab.c"
    break;

  case 207: /* term: '@' K_HLOOKUP '(' range ',' e ',' e ')'  */
#line 1391 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4958 "y.tab.c"
    break;

  case 208: /* term: '@' K_HLOOKUP '(' e ',' range ',' e ')'  */
#line 1393 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-3].rval)), new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4964 "y.tab.c"
    break;

  case 209: /* term: '@' K_VLOOKUP '(' range ',' e ',' e ')'  */
#line 1395 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4970 "y.tab.c"
    break;

  case 210: /* term: '@' K_VLOOKUP '(' e ',' range ',' e ')'  */
#line 1397 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-3].rval)), new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4976 "y.tab.c"
    break;

  case 211: /* term: '@' K_STINDEX '(' range ',' e ')'  */
#line 1399 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4982 "y.tab.c"
    break;

  case 212: /* term: '@' K_STINDEX '(' e ',' range ')'  */
#line 1401 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4988 "y.tab.c"
    break;

  case 213: /* term: '@' K_STINDEX '(' range ',' e ',' e ')'  */
#line 1403 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4994 "y.tab.c"
    break;

  case 214: /* term: '@' K_EXT '(' e ',' e ')'  */
#line 1405 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(EXT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 5000 "y.tab.c"
    break;

  case 215: /* term: '@' K_LUA '(' e ',' e ')'  */
#line 1407 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                  #ifdef XLUA
                                  (yyval.enode) = new(LUA, (yyvsp[-3].enode), (yyvsp[-1].enode));
                                  #endif
                                  }
#line 5010 "y.tab.c"
    break;

  case 216: /* term: '@' K_MYROW  */
#line 1412 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MYROW, ENULL, ENULL);}
#line 5016 "y.tab.c"
    break;

  case 217: /* term: '@' K_MYCOL  */
#line 1413 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(MYCOL, ENULL, ENULL);}
#line 5022 "y.tab.c"
    break;

  case 218: /* term: '@' K_LASTROW  */
#line 1414 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LASTROW, ENULL, ENULL);}
#line 5028 "y.tab.c"
    break;

  case 219: /* term: '@' K_LASTCOL  */
#line 1415 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(LASTCOL, ENULL, ENULL);}
#line 5034 "y.tab.c"
    break;

  case 220: /* term: '@' K_NVAL '(' e ',' e ')'  */
#line 1417 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(NVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 5040 "y.tab.c"
    break;

  case 221: /* term: '@' K_SVAL '(' e ',' e ')'  */
#line 1419 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 5046 "y.tab.c"
    break;

  case 222: /* term: '@' K_REPLACE '(' e ',' e ',' e ')'  */
#line 1421 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(REPLACE, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 5052 "y.tab.c"
    break;

  case 223: /* term: '@' K_EVALUATE '(' e ')'  */
#line 1423 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                    { (yyval.enode) = new(EVALUATE, (yyvsp[-1].enode), ENULL); }
#line 5058 "y.tab.c"
    break;

  case 224: /* term: '@' K_SEVALUATE '(' e ')'  */
#line 1424 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                    { (yyval.enode) = new(SEVALUATE, (yyvsp[-1].enode), ENULL); }
#line 5064 "y.tab.c"
    break;

  case 225: /* term: '@' K_SUBSTR '(' e ',' e ',' e ')'  */
#line 1426 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SUBSTR, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 5070 "y.tab.c"
    break;

  case 226: /* term: '(' e ')'  */
#line 1427 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = (yyvsp[-1].enode); }
#line 5076 "y.tab.c"
    break;

  case 227: /* term: '+' term  */
#line 1428 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = (yyvsp[0].enode); }
#line 5082 "y.tab.c"
    break;

  case 228: /* term: NUMBER  */
#line 1430 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new_const(O_CONST, (double) (yyvsp[0].ival)); }
#line 5088 "y.tab.c"
    break;

  case 229: /* term: FNUMBER  */
#line 1431 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new_const(O_CONST, (yyvsp[0].fval)); }
#line 5094 "y.tab.c"
    break;

  case 230: /* term: '@' K_PI  */
#line 1432 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(PI_, ENULL, ENULL); }
#line 5100 "y.tab.c"
    break;

  case 231: /* term: STRING  */
#line 1433 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new_str((yyvsp[0].sval)); }
#line 5106 "y.tab.c"
    break;

  case 232: /* term: '~' term  */
#line 1434 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 5112 "y.tab.c"
    break;

  case 233: /* term: '!' term  */
#line 1435 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 5118 "y.tab.c"
    break;

  case 234: /* term: '@' K_FILENAME '(' e ')'  */
#line 1437 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FILENAME, (yyvsp[-1].enode), ENULL); }
#line 5124 "y.tab.c"
    break;

  case 235: /* term: '@' K_COLTOA '(' e ')'  */
#line 1438 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(COLTOA, (yyvsp[-1].enode), ENULL);}
#line 5130 "y.tab.c"
    break;

  case 236: /* term: '@' K_ASCII '(' e ')'  */
#line 1439 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ASCII, (yyvsp[-1].enode), ENULL); }
#line 5136 "y.tab.c"
    break;

  case 237: /* term: '@' K_SET8BIT '(' e ')'  */
#line 1440 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(SET8BIT, (yyvsp[-1].enode), ENULL); }
#line 5142 "y.tab.c"
    break;

  case 238: /* term: '@' K_CHR '(' e ')'  */
#line 1441 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(CHR, (yyvsp[-1].enode), ENULL);}
#line 5148 "y.tab.c"
    break;

  case 239: /* term: '@' K_ERR  */
#line 1442 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5154 "y.tab.c"
    break;

  case 240: /* term: K_ERR  */
#line 1443 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5160 "y.tab.c"
    break;

  case 241: /* term: '@' K_REF  */
#line 1444 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(REF_, ENULL, ENULL); }
#line 5166 "y.tab.c"
    break;

  case 242: /* term: K_REF  */
#line 1445 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(REF_, ENULL, ENULL); }
#line 5172 "y.tab.c"
    break;

  case 243: /* term: '@' K_FACT '(' e ')'  */
#line 1446 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(FACT, (yyvsp[-1].enode), ENULL); }
#line 5178 "y.tab.c"
    break;

  case 244: /* e: e '+' e  */
#line 1450 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('+', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5184 "y.tab.c"
    break;

  case 245: /* e: e '-' e  */
#line 1451 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('-', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5190 "y.tab.c"
    break;

  case 246: /* e: e '*' e  */
#line 1452 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('*', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5196 "y.tab.c"
    break;

  case 247: /* e: e '/' e  */
#line 1453 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('/', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5202 "y.tab.c"
    break;

  case 248: /* e: e '%' e  */
#line 1454 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('%', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5208 "y.tab.c"
    break;

  case 249: /* e: '-' e  */
#line 1455 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('m', (yyvsp[0].enode), ENULL); }
#line 5214 "y.tab.c"
    break;

  case 250: /* e: e '^' e  */
#line 1456 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('^', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5220 "y.tab.c"
    break;

  case 252: /* e: e '?' e ':' e  */
#line 1458 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('?', (yyvsp[-4].enode), new(':', (yyvsp[-2].enode), (yyvsp[0].enode))); }
#line 5226 "y.tab.c"
    break;

  case 253: /* e: e ';' e  */
#line 1459 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(';', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5232 "y.tab.c"
    break;

  case 254: /* e: e '<' e  */
#line 1460 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('<', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5238 "y.tab.c"
    break;

  case 255: /* e: e '=' e  */
#line 1461 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('=', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5244 "y.tab.c"
    break;

  case 256: /* e: e '>' e  */
#line 1462 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('>', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5250 "y.tab.c"
    break;

  case 257: /* e: e '&' e  */
#line 1463 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('&', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5256 "y.tab.c"
    break;

  case 258: /* e: e '|' e  */
#line 1464 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('|', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5262 "y.tab.c"
    break;

  case 259: /* e: e '<' '=' e  */
#line 1465 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('!', new('>', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5268 "y.tab.c"
    break;

  case 260: /* e: e '<' '>' e  */
#line 1467 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('!', new('=', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5274 "y.tab.c"
    break;

  case 261: /* e: e '>' '=' e  */
#line 1468 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('!', new('<', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5280 "y.tab.c"
    break;

  case 262: /* e: e '#' e  */
#line 1469 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new('#', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5286 "y.tab.c"
    break;

  case 263: /* expr_list: e  */
#line 1472 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ELIST, ENULL, (yyvsp[0].enode)); }
#line 5292 "y.tab.c"
    break;

  case 264: /* expr_list: expr_list ',' e  */
#line 1473 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.enode) = new(ELIST, (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5298 "y.tab.c"
    break;

  case 265: /* range: var ':' var  */
#line 1476 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    (yyval.rval).left = (yyvsp[-2].ent);
                                    (yyval.rval).right = (yyvsp[0].ent);
                                  }
#line 5307 "y.tab.c"
    break;

  case 266: /* range: RANGE  */
#line 1480 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.rval) = (yyvsp[0].rval); }
#line 5313 "y.tab.c"
    break;

  case 267: /* var: COL NUMBER  */
#line 1485 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-1].ival));
                                    (yyval.ent).vf = 0;
                                  }
#line 5323 "y.tab.c"
    break;

  case 268: /* var: '$' COL NUMBER  */
#line 1490 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-1].ival));
                                    (yyval.ent).vf = FIX_COL;
                                  }
#line 5333 "y.tab.c"
    break;

  case 269: /* var: COL '$' NUMBER  */
#line 1495 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-2].ival));
                                    (yyval.ent).vf = FIX_ROW;
                                  }
#line 5343 "y.tab.c"
    break;

  case 270: /* var: '$' COL '$' NUMBER  */
#line 1500 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-2].ival));
                                    (yyval.ent).vf = FIX_ROW | FIX_COL;
                                  }
#line 5353 "y.tab.c"
    break;

  case 271: /* var: '@' K_GETENT '(' e ',' e ')'  */
#line 1507 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                    struct roman * roman = session->cur_doc;
                                    struct sheet * sh = roman->cur_sh;
                                    (yyval.ent).vp = lookat(sh, eval(sh, NULL, (yyvsp[-3].enode)), eval(sh, NULL, (yyvsp[-1].enode)));
                                    (yyval.ent).vf = GET_ENT;
                                    if ((yyval.ent).expr != NULL) efree((yyval.ent).expr);
                                    (yyval.ent).expr = new(GETENT, (yyvsp[-3].enode), (yyvsp[-1].enode));
                                  }
#line 5366 "y.tab.c"
    break;

  case 272: /* var: VAR  */
#line 1516 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    (yyval.ent) = (yyvsp[0].rval).left;
                                  }
#line 5374 "y.tab.c"
    break;

  case 273: /* var_or_range: range  */
#line 1522 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.rval) = (yyvsp[0].rval); }
#line 5380 "y.tab.c"
    break;

  case 274: /* var_or_range: var  */
#line 1523 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.rval).left = (yyvsp[0].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 5386 "y.tab.c"
    break;

  case 275: /* num: NUMBER  */
#line 1526 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.fval) = (double) (yyvsp[0].ival); }
#line 5392 "y.tab.c"
    break;

  case 276: /* num: FNUMBER  */
#line 1527 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 5398 "y.tab.c"
    break;

  case 277: /* num: '-' num  */
#line 1528 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.fval) = -(yyvsp[0].fval); }
#line 5404 "y.tab.c"
    break;

  case 278: /* num: '+' num  */
#line 1529 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 5410 "y.tab.c"
    break;

  case 279: /* strarg: STRING  */
#line 1532 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  { (yyval.sval) = (yyvsp[0].sval); }
#line 5416 "y.tab.c"
    break;

  case 280: /* strarg: var  */
#line 1533 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                    char *s, *s1;
                                    s1 = (yyvsp[0].ent).vp->label;
                                    if (!s1)
                                    s1 = "NULL_STRING";
                                    s = scxmalloc((unsigned)strlen(s1)+1);
                                    (void) strcpy(s, s1);
                                    (yyval.sval) = s;
                                  }
#line 5430 "y.tab.c"
    break;

  case 283: /* setitem: K_OVERLAP '=' NUMBER  */
#line 1551 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("overlap=0", true);
                                     else         config_parse_str("overlap=1", true); }
#line 5437 "y.tab.c"
    break;

  case 284: /* setitem: K_OVERLAP  */
#line 1553 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("overlap=1", true); }
#line 5443 "y.tab.c"
    break;

  case 285: /* setitem: K_INPUT_BAR_BOTTOM '=' NUMBER  */
#line 1554 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                         {  if ((yyvsp[0].ival) == 0) config_parse_str("input_bar_bottom=0", true);
                                     else         config_parse_str("input_bar_bottom=1", true);
                                            ui_mv_bottom_bar(); }
#line 5451 "y.tab.c"
    break;

  case 286: /* setitem: K_INPUT_BAR_BOTTOM  */
#line 1557 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("input_bar_bottom=1", true);
                                                  ui_mv_bottom_bar();
                                  }
#line 5459 "y.tab.c"
    break;

  case 287: /* setitem: K_UNDERLINE_GRID '=' NUMBER  */
#line 1561 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {            if ((yyvsp[0].ival) == 0) config_parse_str("underline_grid=0", true);
                                                  else config_parse_str("underline_grid=1", true); }
#line 5466 "y.tab.c"
    break;

  case 288: /* setitem: K_UNDERLINE_GRID  */
#line 1563 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("underline_grid=1", true);
                                  }
#line 5473 "y.tab.c"
    break;

  case 289: /* setitem: K_NOOVERLAP  */
#line 1566 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("overlap=0", true); }
#line 5479 "y.tab.c"
    break;

  case 290: /* setitem: K_TRUNCATE '=' NUMBER  */
#line 1568 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("truncate=0", true);
                                     else         config_parse_str("truncate=1", true); }
#line 5486 "y.tab.c"
    break;

  case 291: /* setitem: K_TRUNCATE  */
#line 1570 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("truncate=1", true); }
#line 5492 "y.tab.c"
    break;

  case 292: /* setitem: K_NOTRUNCATE  */
#line 1571 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("truncate=0", true); }
#line 5498 "y.tab.c"
    break;

  case 293: /* setitem: K_AUTOWRAP '=' NUMBER  */
#line 1573 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("autowrap=0", true);
                                     else         config_parse_str("autowrap=1", true); }
#line 5505 "y.tab.c"
    break;

  case 294: /* setitem: K_AUTOWRAP  */
#line 1575 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("autowrap=1", true); }
#line 5511 "y.tab.c"
    break;

  case 295: /* setitem: K_NOAUTOWRAP  */
#line 1576 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("autowrap=0", true); }
#line 5517 "y.tab.c"
    break;

  case 296: /* setitem: K_AUTOBACKUP '=' NUMBER  */
#line 1578 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                                  char cmd[MAXCMD];
                                                  sprintf(cmd, "autobackup=%d", (yyvsp[0].ival));
                                                  config_parse_str(cmd, true); }
#line 5526 "y.tab.c"
    break;

  case 297: /* setitem: K_NOAUTOBACKUP  */
#line 1582 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("autobackup=0", true); }
#line 5532 "y.tab.c"
    break;

  case 298: /* setitem: K_AUTOCALC  */
#line 1583 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("autocalc=1", true); }
#line 5538 "y.tab.c"
    break;

  case 299: /* setitem: K_AUTOCALC '=' NUMBER  */
#line 1584 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("autocalc=0", true);
                                     else         config_parse_str("autocalc=1", true); }
#line 5545 "y.tab.c"
    break;

  case 300: /* setitem: K_NOAUTOCALC  */
#line 1586 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("autocalc=0", true); }
#line 5551 "y.tab.c"
    break;

  case 301: /* setitem: K_DEBUG  */
#line 1587 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("debug=1", true); }
#line 5557 "y.tab.c"
    break;

  case 302: /* setitem: K_DEBUG '=' NUMBER  */
#line 1588 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("debug=0", true);
                                     else         config_parse_str("debug=1", true); }
#line 5564 "y.tab.c"
    break;

  case 303: /* setitem: K_NODEBUG  */
#line 1590 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("debug=0", true); }
#line 5570 "y.tab.c"
    break;

  case 304: /* setitem: K_TRG  */
#line 1591 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("trigger=1", true); }
#line 5576 "y.tab.c"
    break;

  case 305: /* setitem: K_TRG '=' NUMBER  */
#line 1592 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("trigger=0", true);
                                     else         config_parse_str("trigger=1", true); }
#line 5583 "y.tab.c"
    break;

  case 306: /* setitem: K_NOTRG  */
#line 1594 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("trigger=0", true); }
#line 5589 "y.tab.c"
    break;

  case 307: /* setitem: K_EXTERNAL_FUNCTIONS  */
#line 1595 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("external_functions=1", true); }
#line 5595 "y.tab.c"
    break;

  case 308: /* setitem: K_EXTERNAL_FUNCTIONS '=' NUMBER  */
#line 1596 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                         {
                                     if ((yyvsp[0].ival) == 0) config_parse_str("external_functions=0", true);
                                     else         config_parse_str("external_functions=1", true); }
#line 5603 "y.tab.c"
    break;

  case 309: /* setitem: K_NOEXTERNAL_FUNCTIONS  */
#line 1599 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("external_functions=0", true); }
#line 5609 "y.tab.c"
    break;

  case 310: /* setitem: K_EXEC_LUA  */
#line 1600 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("exec_lua=1", true); }
#line 5615 "y.tab.c"
    break;

  case 311: /* setitem: K_EXEC_LUA '=' NUMBER  */
#line 1601 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                     if ((yyvsp[0].ival) == 0) config_parse_str("exec_lua=0", true);
                                     else         config_parse_str("exec_lua=1", true); }
#line 5623 "y.tab.c"
    break;

  case 312: /* setitem: K_NOEXEC_LUA  */
#line 1604 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("exec_lua=0", true); }
#line 5629 "y.tab.c"
    break;

  case 313: /* setitem: K_HALF_PAGE_SCROLL  */
#line 1605 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("half_page_scroll=1", true); }
#line 5635 "y.tab.c"
    break;

  case 314: /* setitem: K_HALF_PAGE_SCROLL '=' NUMBER  */
#line 1607 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("half_page_scroll=0", true);
                                     else         config_parse_str("half_page_scroll=1", true); }
#line 5642 "y.tab.c"
    break;

  case 315: /* setitem: K_NOHALF_PAGE_SCROLL  */
#line 1609 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("half_page_scroll=0", true); }
#line 5648 "y.tab.c"
    break;

  case 316: /* setitem: K_IGNORE_HIDDEN  */
#line 1611 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("ignore_hidden=1", true); }
#line 5654 "y.tab.c"
    break;

  case 317: /* setitem: K_IGNORE_HIDDEN '=' NUMBER  */
#line 1613 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("ignore_hidden=0", true);
                                     else         config_parse_str("ignore_hidden=1", true); }
#line 5661 "y.tab.c"
    break;

  case 318: /* setitem: K_NOIGNORE_HIDDEN  */
#line 1615 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("ignore_hidden=0", true); }
#line 5667 "y.tab.c"
    break;

  case 319: /* setitem: K_QUIET '=' NUMBER  */
#line 1617 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                     if ((yyvsp[0].ival) == 0) config_parse_str("quiet=0", true);
                                     else         config_parse_str("quiet=1", true); }
#line 5675 "y.tab.c"
    break;

  case 320: /* setitem: K_QUIET  */
#line 1620 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("quiet=1", true); }
#line 5681 "y.tab.c"
    break;

  case 321: /* setitem: K_NOQUIET  */
#line 1621 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("quiet=0", true); }
#line 5687 "y.tab.c"
    break;

  case 322: /* setitem: K_QUIT_AFTERLOAD  */
#line 1622 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("quit_afterload=1", true); }
#line 5693 "y.tab.c"
    break;

  case 323: /* setitem: K_QUIT_AFTERLOAD '=' NUMBER  */
#line 1624 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("quit_afterload=0", true);
                                     else         config_parse_str("quit_afterload=1", true); }
#line 5700 "y.tab.c"
    break;

  case 324: /* setitem: K_NOQUIT_AFTERLOAD  */
#line 1626 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("quit_afterload=0", true); }
#line 5706 "y.tab.c"
    break;

  case 325: /* setitem: K_XLSX_READFORMULAS  */
#line 1627 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("xlsx_readformulas=1", true); }
#line 5712 "y.tab.c"
    break;

  case 326: /* setitem: K_XLSX_READFORMULAS '=' NUMBER  */
#line 1629 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("xlsx_readformulas=0", true);
                                     else         config_parse_str("xlsx_readformulas=1", true); }
#line 5719 "y.tab.c"
    break;

  case 327: /* setitem: K_NOXLSX_READFORMULAS  */
#line 1631 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("xlsx_readformulas=0", true); }
#line 5725 "y.tab.c"
    break;

  case 328: /* setitem: K_NOCURSES  */
#line 1632 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if (! session->cur_doc->loading) config_parse_str("nocurses=1", true); }
#line 5731 "y.tab.c"
    break;

  case 329: /* setitem: K_NOCURSES '=' NUMBER  */
#line 1633 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if (! session->cur_doc->loading) {
                                         if ((yyvsp[0].ival) == 0) config_parse_str("nocurses=0", true);
                                         else         config_parse_str("nocurses=1", true); }
                                     }
#line 5740 "y.tab.c"
    break;

  case 330: /* setitem: K_CURSES  */
#line 1637 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if (! session->cur_doc->loading) config_parse_str("nocurses=0", true); }
#line 5746 "y.tab.c"
    break;

  case 331: /* setitem: K_NUMERIC  */
#line 1638 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric=1", true); }
#line 5752 "y.tab.c"
    break;

  case 332: /* setitem: K_NUMERIC '=' NUMBER  */
#line 1639 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("numeric=0", true);
                                     else         config_parse_str("numeric=1", true); }
#line 5759 "y.tab.c"
    break;

  case 333: /* setitem: K_NONUMERIC  */
#line 1641 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric=0", true); }
#line 5765 "y.tab.c"
    break;

  case 334: /* setitem: K_IGNORECASE  */
#line 1642 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("ignorecase=1", true); }
#line 5771 "y.tab.c"
    break;

  case 335: /* setitem: K_IGNORECASE '=' NUMBER  */
#line 1643 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("ignorecase=0", true);
                                     else         config_parse_str("ignorecase=1", true); }
#line 5778 "y.tab.c"
    break;

  case 336: /* setitem: K_NOIGNORECASE  */
#line 1645 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("ignorecase=0", true); }
#line 5784 "y.tab.c"
    break;

  case 337: /* setitem: K_NUMERIC_DECIMAL  */
#line 1646 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric_decimal=1", true); }
#line 5790 "y.tab.c"
    break;

  case 338: /* setitem: K_NUMERIC_DECIMAL '=' NUMBER  */
#line 1648 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("numeric_decimal=0", true);
                                     else         config_parse_str("numeric_decimal=1", true); }
#line 5797 "y.tab.c"
    break;

  case 339: /* setitem: K_NONUMERIC_DECIMAL  */
#line 1650 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric_decimal=0", true); }
#line 5803 "y.tab.c"
    break;

  case 340: /* setitem: K_NUMERIC_ZERO  */
#line 1651 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric_zero=1", true); }
#line 5809 "y.tab.c"
    break;

  case 341: /* setitem: K_NUMERIC_ZERO '=' NUMBER  */
#line 1653 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("numeric_zero=0", true);
                                     else         config_parse_str("numeric_zero=1", true); }
#line 5816 "y.tab.c"
    break;

  case 342: /* setitem: K_NONUMERIC_ZERO  */
#line 1655 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("numeric_zero=0", true); }
#line 5822 "y.tab.c"
    break;

  case 343: /* setitem: K_NEWLINE_ACTION  */
#line 1656 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("newline_action=0", true); }
#line 5828 "y.tab.c"
    break;

  case 344: /* setitem: K_NEWLINE_ACTION '=' WORD  */
#line 1657 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                   {
                                  char * s = (char *) (yyvsp[0].sval);
                                  if (s[0] =='j') config_parse_str("newline_action=j", true);
                                  else if (s[0] =='l')
                                  config_parse_str("newline_action=l", true);
                                  }
#line 5839 "y.tab.c"
    break;

  case 345: /* setitem: K_DEFAULT_COPY_TO_CLIPBOARD_CMD '=' strarg  */
#line 1663 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                    {
                                  char cmd[MAXCMD];
                                  char * s = (char *) (yyvsp[0].sval);
                                  sprintf(cmd, "default_copy_to_clipboard_cmd=%s", s);
                                  config_parse_str(cmd, false);
                                  scxfree(s);
                                  }
#line 5851 "y.tab.c"
    break;

  case 346: /* setitem: K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD '=' strarg  */
#line 1670 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                       {
                                  char cmd[MAXCMD];
                                  char * s = (char *) (yyvsp[0].sval);
                                  sprintf(cmd, "default_paste_from_clipboard_cmd=%s", s);
                                  config_parse_str(cmd, false);
                                  scxfree(s);
                                  }
#line 5863 "y.tab.c"
    break;

  case 347: /* setitem: K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
#line 1678 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                           {      config_parse_str("copy_to_clipboard_delimited_tab=1", true); }
#line 5869 "y.tab.c"
    break;

  case 348: /* setitem: K_COPY_TO_CLIPBOARD_DELIMITED_TAB '=' NUMBER  */
#line 1681 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("copy_to_clipboard_delimited_tab=0", true);
                                     else         config_parse_str("copy_to_clipboard_delimited_tab=1", true); }
#line 5876 "y.tab.c"
    break;

  case 349: /* setitem: K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
#line 1683 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                             {    config_parse_str("copy_to_clipboard_delimited_tab=0", true); }
#line 5882 "y.tab.c"
    break;

  case 350: /* setitem: K_DEFAULT_OPEN_FILE_UNDER_CURSOR_CMD '=' strarg  */
#line 1685 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                                         {
                                  char cmd[MAXCMD];
                                  char * s = (char *) (yyvsp[0].sval);
                                  sprintf(cmd, "default_open_file_under_cursor_cmd=%s", s);
                                  config_parse_str(cmd, false);
                                  scxfree(s);
                                  }
#line 5894 "y.tab.c"
    break;

  case 351: /* setitem: K_NEWLINE_ACTION '=' NUMBER  */
#line 1693 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                     if ((yyvsp[0].ival) == 0) config_parse_str("newline_action=0", true); }
#line 5901 "y.tab.c"
    break;

  case 352: /* setitem: K_COMMAND_TIMEOUT  */
#line 1695 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("command_timeout=3000", true); }
#line 5907 "y.tab.c"
    break;

  case 353: /* setitem: K_COMMAND_TIMEOUT '=' num  */
#line 1696 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "command_timeout=%d", (int) (yyvsp[0].fval));
                                     config_parse_str(s, true);
                                     scxfree(s);
                                     }
#line 5918 "y.tab.c"
    break;

  case 354: /* setitem: K_MAPPING_TIMEOUT  */
#line 1702 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("mapping_timeout=1500", true); }
#line 5924 "y.tab.c"
    break;

  case 355: /* setitem: K_MAPPING_TIMEOUT '=' num  */
#line 1703 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                     {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "mapping_timeout=%d", (int) (yyvsp[0].fval));
                                     config_parse_str(s, true);
                                     scxfree(s);
                                     }
#line 5935 "y.tab.c"
    break;

  case 356: /* setitem: K_TM_GMTOFF  */
#line 1709 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("tm_gmtoff=-10800", true); }
#line 5941 "y.tab.c"
    break;

  case 357: /* setitem: K_TM_GMTOFF '=' num  */
#line 1710 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "tm_gmtoff=%d", (int) (yyvsp[0].fval));
                                     config_parse_str(s, true);
                                     scxfree(s);
                                  }
#line 5952 "y.tab.c"
    break;

  case 358: /* setitem: K_SHOW_CURSOR '=' NUMBER  */
#line 1716 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {  if ((yyvsp[0].ival) == 0) config_parse_str("show_cursor=0", true);
                                     else         config_parse_str("show_cursor=1", true); }
#line 5959 "y.tab.c"
    break;

  case 359: /* setitem: K_SHOW_CURSOR  */
#line 1718 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("show_cursor=1", true); }
#line 5965 "y.tab.c"
    break;

  case 360: /* setitem: K_NOSHOW_CURSOR  */
#line 1719 "/home/evan/documents/packages/source/scim-test/src/gram.y"
                                  {               config_parse_str("show_cursor=0", true); }
#line 5971 "y.tab.c"
    break;


#line 5975 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

