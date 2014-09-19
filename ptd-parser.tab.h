/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     FLOAT = 260,
     SYM_INDENT_INCR = 261,
     SYM_INDENT_DECR = 262,
     CODE_INDENT_INCR = 263,
     CODE_INDENT_DECR = 264,
     BEGIN_CODE_INDENT = 265,
     BEGIN_10_INDENT = 266,
     END_CODE_INDENT = 267,
     END_10_INDENT = 268,
     END_OF_FILE = 269,
     NAMESPACE = 270,
     PROCEDURE_NAME = 271,
     SYMTREE = 272,
     AMBIG = 273,
     FROM_NAMESPACE = 274,
     SYMBOL = 275,
     CONTAINS = 276,
     ATSIGN_NUM = 277,
     FL_UNKNOWN = 278,
     FL_PROGRAM = 279,
     FL_BLOCK_DATA = 280,
     FL_MODULE = 281,
     FL_VARIABLE = 282,
     FL_PARAMETER = 283,
     FL_LABEL = 284,
     FL_NAMELIST = 285,
     INTENT_UNKNOWN = 286,
     INTENT_IN = 287,
     INTENT_OUT = 288,
     INTENT_INOUT = 289,
     ACCESS_UNKNOWN = 290,
     ACCESS_PUBLIC = 291,
     ACCESS_PRIVATE = 292,
     PROC_UNKNOWN = 293,
     PROC_MODULE = 294,
     PROC_INTERNAL = 295,
     PROC_DUMMY = 296,
     PROC_INTRINSIC = 297,
     PROC_EXTERNAL = 298,
     PROC_ST_FUNCTION = 299,
     ALLOCATABLE = 300,
     DIMENSION = 301,
     EXTERNAL = 302,
     INTRINSIC = 303,
     OPTIONAL = 304,
     POINTER = 305,
     SAVE = 306,
     TARGET = 307,
     DUMMY = 308,
     COMMON = 309,
     RESULT = 310,
     ENTRY = 311,
     FUNCTION = 312,
     SUBROUTINE = 313,
     IMPLICIT_TYPE = 314,
     DATA = 315,
     USE_ASSOC = 316,
     IN_NAMELIST = 317,
     IN_COMMON = 318,
     SAVED_COMMON = 319,
     SEQUENCE = 320,
     ELEMENTAL = 321,
     PURE = 322,
     RECURSIVE = 323,
     AS_EXPLICIT = 324,
     AS_DEFERRED = 325,
     AS_ASSUMED_SIZE = 326,
     AS_ASSUMED_SHAPE = 327,
     INTEGER = 328,
     REAL = 329,
     COMPLEX = 330,
     LOGICAL = 331,
     CHARACTER = 332,
     DERIVED = 333,
     PROCEDURE = 334,
     UNKNOWN = 335,
     VALUE = 336,
     VALUE_PAREN_EXPR = 337,
     ARRAY_SPEC = 338,
     GENERIC_INTERFACES = 339,
     COMMON_MEMBERS = 340,
     COMPONENTS = 341,
     FORMAL_ARGLIST = 342,
     FORMAL_NAMESPACE = 343,
     NOP = 344,
     CONTINUE = 345,
     ASSIGN = 346,
     LABEL_ASSIGN = 347,
     POINTER_ASSIGN = 348,
     GOTO = 349,
     CALL = 350,
     RETURN = 351,
     PAUSE = 352,
     STOP = 353,
     IF = 354,
     ELSE = 355,
     ENDIF = 356,
     SELECT_CASE = 357,
     CASE = 358,
     END_SELECT = 359,
     WHERE = 360,
     END_WHERE = 361,
     FORALL = 362,
     END_FORALL = 363,
     DO = 364,
     END_DO = 365,
     DO_WHILE = 366,
     CYCLE = 367,
     EXIT = 368,
     ALLOCATE = 369,
     DEALLOCATE = 370,
     OPEN = 371,
     CLOSE = 372,
     BACKSPACE = 373,
     ENDFILE = 374,
     REWIND = 375,
     INQUIRE = 376,
     IOLENGTH = 377,
     READ = 378,
     WRITE = 379,
     TRANSFER = 380,
     DT_END = 381
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define FLOAT 260
#define SYM_INDENT_INCR 261
#define SYM_INDENT_DECR 262
#define CODE_INDENT_INCR 263
#define CODE_INDENT_DECR 264
#define BEGIN_CODE_INDENT 265
#define BEGIN_10_INDENT 266
#define END_CODE_INDENT 267
#define END_10_INDENT 268
#define END_OF_FILE 269
#define NAMESPACE 270
#define PROCEDURE_NAME 271
#define SYMTREE 272
#define AMBIG 273
#define FROM_NAMESPACE 274
#define SYMBOL 275
#define CONTAINS 276
#define ATSIGN_NUM 277
#define FL_UNKNOWN 278
#define FL_PROGRAM 279
#define FL_BLOCK_DATA 280
#define FL_MODULE 281
#define FL_VARIABLE 282
#define FL_PARAMETER 283
#define FL_LABEL 284
#define FL_NAMELIST 285
#define INTENT_UNKNOWN 286
#define INTENT_IN 287
#define INTENT_OUT 288
#define INTENT_INOUT 289
#define ACCESS_UNKNOWN 290
#define ACCESS_PUBLIC 291
#define ACCESS_PRIVATE 292
#define PROC_UNKNOWN 293
#define PROC_MODULE 294
#define PROC_INTERNAL 295
#define PROC_DUMMY 296
#define PROC_INTRINSIC 297
#define PROC_EXTERNAL 298
#define PROC_ST_FUNCTION 299
#define ALLOCATABLE 300
#define DIMENSION 301
#define EXTERNAL 302
#define INTRINSIC 303
#define OPTIONAL 304
#define POINTER 305
#define SAVE 306
#define TARGET 307
#define DUMMY 308
#define COMMON 309
#define RESULT 310
#define ENTRY 311
#define FUNCTION 312
#define SUBROUTINE 313
#define IMPLICIT_TYPE 314
#define DATA 315
#define USE_ASSOC 316
#define IN_NAMELIST 317
#define IN_COMMON 318
#define SAVED_COMMON 319
#define SEQUENCE 320
#define ELEMENTAL 321
#define PURE 322
#define RECURSIVE 323
#define AS_EXPLICIT 324
#define AS_DEFERRED 325
#define AS_ASSUMED_SIZE 326
#define AS_ASSUMED_SHAPE 327
#define INTEGER 328
#define REAL 329
#define COMPLEX 330
#define LOGICAL 331
#define CHARACTER 332
#define DERIVED 333
#define PROCEDURE 334
#define UNKNOWN 335
#define VALUE 336
#define VALUE_PAREN_EXPR 337
#define ARRAY_SPEC 338
#define GENERIC_INTERFACES 339
#define COMMON_MEMBERS 340
#define COMPONENTS 341
#define FORMAL_ARGLIST 342
#define FORMAL_NAMESPACE 343
#define NOP 344
#define CONTINUE 345
#define ASSIGN 346
#define LABEL_ASSIGN 347
#define POINTER_ASSIGN 348
#define GOTO 349
#define CALL 350
#define RETURN 351
#define PAUSE 352
#define STOP 353
#define IF 354
#define ELSE 355
#define ENDIF 356
#define SELECT_CASE 357
#define CASE 358
#define END_SELECT 359
#define WHERE 360
#define END_WHERE 361
#define FORALL 362
#define END_FORALL 363
#define DO 364
#define END_DO 365
#define DO_WHILE 366
#define CYCLE 367
#define EXIT 368
#define ALLOCATE 369
#define DEALLOCATE 370
#define OPEN 371
#define CLOSE 372
#define BACKSPACE 373
#define ENDFILE 374
#define REWIND 375
#define INQUIRE 376
#define IOLENGTH 377
#define READ 378
#define WRITE 379
#define TRANSFER 380
#define DT_END 381




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 60 "ptd-parser.y"
{
  int itype;
  double ftype;
  char* stype;
  void* ptype;
  struct { int first; int second; } iitype;
  struct { int kind; void* ptr;   } iptype;
}
/* Line 1489 of yacc.c.  */
#line 310 "ptd-parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

