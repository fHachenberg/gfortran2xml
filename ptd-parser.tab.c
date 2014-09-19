/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 26 "ptd-parser.y"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "gfortran2xml.h"

#ifdef MY_YYERROR   
   static void yywarning(const char *s);
   static void yyerror(const char *s);
#endif   

#ifdef DEBUG   
   int yydebug = 1;
#endif   
   
int is_formal_namespace = 0;
char* current_symtree = 0;
 extern int indent_level;

 extern char *yytext;

typedef struct {
  int first;
  int second;
} ii_type;

typedef struct {
  int type;
  void* ptr;
} ip_type;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 187 of yacc.c.  */
#line 391 "ptd-parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 404 "ptd-parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   809

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNRULES -- Number of states.  */
#define YYNSTATES  282

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     127,   128,     2,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    13,    18,    21,    25,
      28,    30,    35,    36,    43,    46,    47,    49,    51,    53,
      56,    57,    61,    65,    68,    70,    73,    76,    78,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   119,   121,
     123,   125,   127,   129,   131,   133,   135,   137,   139,   141,
     143,   147,   151,   154,   158,   165,   172,   178,   181,   187,
     190,   196,   203,   206,   212,   215,   221,   223,   226,   227,
     234,   236,   238,   241,   242,   249,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   306,   309,   311,   313,   315,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   358,   361,   364,
     368,   371,   374,   377,   380,   383,   386,   389,   391,   393,
     395,   397,   400,   405,   407,   409,   411,   414,   415,   424,
     426,   427,   428,   436,   437,   439,   440,   442,   443,   446,
     448,   450,   452,   454,   455,   459,   460,   465,   467,   469,
     470,   474,   475,   481,   483,   485,   487,   489,   491,   493,
     495,   497,   499,   501,   503
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     130,     0,    -1,   131,    -1,   130,   131,    -1,   130,   131,
      14,    -1,    -1,    15,   137,   132,   133,    -1,     6,   131,
      -1,   149,    21,   134,    -1,   149,   140,    -1,   135,    -1,
     134,     6,    21,   135,    -1,    -1,     6,    15,   137,   136,
     149,   140,    -1,    16,   138,    -1,    -1,     3,    -1,    22,
      -1,   138,    -1,   139,   138,    -1,    -1,    10,   141,    12,
      -1,    10,   141,    14,    -1,     7,   140,    -1,    13,    -1,
     141,    12,    -1,   141,    14,    -1,   142,    -1,   141,   142,
      -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,    89,    -1,    90,    -1,    91,    -1,    92,
      -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,
      -1,    98,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   126,    -1,     9,   100,     8,    -1,     9,   103,     8,
      -1,    99,   101,    -1,    99,   100,   101,    -1,    99,   100,
       8,   141,     9,   101,    -1,    99,     8,   141,     9,   100,
     101,    -1,    99,     8,   141,     9,   101,    -1,   109,   110,
      -1,   109,     8,   141,     9,   110,    -1,   111,   110,    -1,
     111,     8,   141,     9,   110,    -1,   102,   103,     8,   141,
       9,   104,    -1,   105,   106,    -1,   105,     8,   141,     9,
     106,    -1,   107,   108,    -1,   107,     8,   141,     9,   108,
      -1,   150,    -1,   149,   150,    -1,    -1,    17,   138,   151,
      18,     4,   152,    -1,   153,    -1,   154,    -1,    19,   138,
      -1,    -1,    20,   138,   155,   185,   156,   163,    -1,   127,
     157,   158,   159,   160,   161,   128,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    79,    -1,    78,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,
      -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,
      -1,    43,    -1,    44,    -1,    -1,   161,   162,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,    -1,    -1,   163,   164,
      -1,    81,   165,    -1,    81,   165,     1,    -1,    83,   166,
      -1,    84,   167,    -1,    85,   168,    -1,    55,   138,    -1,
      86,   169,    -1,    87,   172,    -1,    88,   173,    -1,     4,
      -1,     5,    -1,   128,    -1,     3,    -1,   127,   128,    -1,
     127,     4,   178,   128,    -1,   139,    -1,   139,    -1,   170,
      -1,   169,   170,    -1,    -1,   127,   138,   171,   185,   176,
     177,   166,   128,    -1,   139,    -1,    -1,    -1,     6,    15,
     137,   174,   149,     7,   175,    -1,    -1,    50,    -1,    -1,
      46,    -1,    -1,   179,   180,    -1,    69,    -1,    70,    -1,
      71,    -1,    72,    -1,    -1,   183,   181,   183,    -1,    -1,
     180,   183,   182,   183,    -1,     4,    -1,     3,    -1,    -1,
     127,   184,   128,    -1,    -1,   127,   187,   186,   188,   128,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,   138,    -1,   189,
      -1,     4,    -1,   127,   128,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   235,   235,   236,   237,   241,   240,   248,   251,   258,
     276,   277,   282,   281,   308,   313,   323,   325,   341,   346,
     353,   354,   355,   356,   357,   358,   359,   372,   373,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   411,   412,   413,   414,   415,   418,   419,   422,
     423,   426,   430,   431,   434,   435,   438,   439,   443,   442,
     447,   448,   451,   455,   454,   507,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   537,   538,   539,   540,
     544,   545,   546,   550,   551,   552,   553,   554,   555,   556,
     560,   561,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   597,   598,   607,   612,
     617,   622,   627,   632,   637,   641,   646,   656,   661,   665,
     670,   682,   686,   694,   697,   700,   701,   705,   704,   719,
     732,   734,   731,   738,   739,   742,   743,   747,   750,   758,
     759,   760,   761,   766,   765,   780,   779,   794,   795,   801,
     800,   812,   811,   824,   825,   826,   827,   828,   829,   830,
     831,   834,   841,   850,   852
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "FLOAT",
  "SYM_INDENT_INCR", "SYM_INDENT_DECR", "CODE_INDENT_INCR",
  "CODE_INDENT_DECR", "BEGIN_CODE_INDENT", "BEGIN_10_INDENT",
  "END_CODE_INDENT", "END_10_INDENT", "END_OF_FILE", "NAMESPACE",
  "PROCEDURE_NAME", "SYMTREE", "AMBIG", "FROM_NAMESPACE", "SYMBOL",
  "CONTAINS", "ATSIGN_NUM", "FL_UNKNOWN", "FL_PROGRAM", "FL_BLOCK_DATA",
  "FL_MODULE", "FL_VARIABLE", "FL_PARAMETER", "FL_LABEL", "FL_NAMELIST",
  "INTENT_UNKNOWN", "INTENT_IN", "INTENT_OUT", "INTENT_INOUT",
  "ACCESS_UNKNOWN", "ACCESS_PUBLIC", "ACCESS_PRIVATE", "PROC_UNKNOWN",
  "PROC_MODULE", "PROC_INTERNAL", "PROC_DUMMY", "PROC_INTRINSIC",
  "PROC_EXTERNAL", "PROC_ST_FUNCTION", "ALLOCATABLE", "DIMENSION",
  "EXTERNAL", "INTRINSIC", "OPTIONAL", "POINTER", "SAVE", "TARGET",
  "DUMMY", "COMMON", "RESULT", "ENTRY", "FUNCTION", "SUBROUTINE",
  "IMPLICIT_TYPE", "DATA", "USE_ASSOC", "IN_NAMELIST", "IN_COMMON",
  "SAVED_COMMON", "SEQUENCE", "ELEMENTAL", "PURE", "RECURSIVE",
  "AS_EXPLICIT", "AS_DEFERRED", "AS_ASSUMED_SIZE", "AS_ASSUMED_SHAPE",
  "INTEGER", "REAL", "COMPLEX", "LOGICAL", "CHARACTER", "DERIVED",
  "PROCEDURE", "UNKNOWN", "VALUE", "VALUE_PAREN_EXPR", "ARRAY_SPEC",
  "GENERIC_INTERFACES", "COMMON_MEMBERS", "COMPONENTS", "FORMAL_ARGLIST",
  "FORMAL_NAMESPACE", "NOP", "CONTINUE", "ASSIGN", "LABEL_ASSIGN",
  "POINTER_ASSIGN", "GOTO", "CALL", "RETURN", "PAUSE", "STOP", "IF",
  "ELSE", "ENDIF", "SELECT_CASE", "CASE", "END_SELECT", "WHERE",
  "END_WHERE", "FORALL", "END_FORALL", "DO", "END_DO", "DO_WHILE", "CYCLE",
  "EXIT", "ALLOCATE", "DEALLOCATE", "OPEN", "CLOSE", "BACKSPACE",
  "ENDFILE", "REWIND", "INQUIRE", "IOLENGTH", "READ", "WRITE", "TRANSFER",
  "DT_END", "'('", "')'", "$accept", "namespaces", "namespace", "@1",
  "namespace_body", "contained_namespaces", "contained_namespace", "@2",
  "namespace_name", "name", "names", "code_segment", "statement_list",
  "statement", "if_block", "do_block", "do_while_block", "select_block",
  "where_block", "forall_block", "symtrees", "symtree", "@3",
  "from_or_symbol", "from_namespace", "symbol", "@4", "symbol_attribute",
  "flavors", "intent", "access_types", "procedures", "bit_attributes",
  "bit_attribute", "symbol_info_list", "symbol_info", "value_expr",
  "array_spec", "generic_interfaces", "common_members", "components",
  "component", "@5", "formal_arglist", "formal_namespace", "@6", "@7",
  "pointer", "dimension", "dim_info", "array_type", "array_extents", "@8",
  "@9", "array_expr", "@10", "type_spec", "@11", "basic_typename", "type",
  "len_kind", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
     375,   376,   377,   378,   379,   380,   381,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   129,   130,   130,   130,   132,   131,   131,   133,   133,
     134,   134,   136,   135,   137,   137,   138,   138,   139,   139,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   143,   143,   143,   143,   144,   144,   145,
     145,   146,   147,   147,   148,   148,   149,   149,   151,   150,
     152,   152,   153,   155,   154,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   158,   158,   158,   158,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   163,   163,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   165,   165,
     165,   166,   166,   167,   168,   169,   169,   171,   170,   172,
     174,   175,   173,   176,   176,   177,   177,   178,   178,   179,
     179,   179,   179,   181,   180,   182,   180,   183,   183,   184,
     183,   186,   185,   187,   187,   187,   187,   187,   187,   187,
     187,   188,   188,   189,   189
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     4,     2,     3,     2,
       1,     4,     0,     6,     2,     0,     1,     1,     1,     2,
       0,     3,     3,     2,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     6,     6,     5,     2,     5,     2,
       5,     6,     2,     5,     2,     5,     1,     2,     0,     6,
       1,     1,     2,     0,     6,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     4,     1,     1,     1,     2,     0,     8,     1,
       0,     0,     7,     0,     1,     0,     1,     0,     2,     1,
       1,     1,     1,     0,     3,     0,     4,     1,     1,     0,
       3,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,     0,     2,     7,     0,     5,     1,     3,
      16,    17,    14,     0,     4,     0,     6,    20,    76,    78,
      20,     0,     0,    24,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     9,     0,    27,    29,
      30,    31,    32,    33,    34,    77,     0,    23,     0,     0,
       0,     0,     8,    10,     0,     0,    62,     0,     0,    72,
       0,    74,     0,    67,     0,    69,    25,    26,    28,     0,
      60,    61,    21,    22,    15,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,     0,
      11,     0,    66,     0,     0,    73,    75,    68,    70,    82,
      83,    20,    65,    64,    71,     0,    13,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   181,     0,   136,
       0,    86,    87,    88,    89,    90,    91,    92,    95,    94,
      93,     0,    84,   193,     0,   191,     0,   192,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   194,   182,   100,   101,   102,     0,   143,   150,
     147,   148,   149,     0,     0,   140,    18,   153,   141,   154,
     142,     0,   144,   155,   159,   145,     0,   146,   103,   104,
     105,   106,   107,   108,   109,   110,   139,   167,   151,    19,
     157,   156,    15,     0,   169,   170,   171,   172,     0,     0,
       0,   160,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    85,   111,   152,   178,
     177,   179,   168,   173,   163,     0,     0,   175,     0,   164,
     165,     0,   180,     0,   174,   166,     0,   161,   176,     0,
     162,   158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    13,    16,    72,    73,   119,     7,   196,
     197,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      17,    18,    66,   116,   117,   118,   135,   149,   161,   172,
     187,   215,   223,   257,   162,   181,   193,   195,   198,   200,
     202,   203,   230,   205,   207,   265,   280,   270,   276,   228,
     229,   262,   268,   273,   263,   266,   138,   150,   147,   166,
     167
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -247
static const yytype_int16 yypact[] =
{
      84,    84,    59,    83,  -247,  -247,    65,  -247,  -247,    62,
    -247,  -247,  -247,    78,  -247,    65,  -247,    64,  -247,  -247,
     188,    -7,   371,  -247,    94,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,    16,     9,    15,     0,     1,
      12,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,   280,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,    95,  -247,   115,   139,
     331,   149,   166,  -247,   371,    17,  -247,   162,   371,  -247,
     371,  -247,   371,  -247,   371,  -247,  -247,  -247,  -247,   187,
    -247,  -247,  -247,  -247,    59,   172,   409,   371,  -247,   371,
     449,   500,   540,   578,    14,  -247,    94,    43,   618,   669,
     -71,    -6,   -82,   -31,    65,    65,  -247,  -247,  -247,    78,
    -247,    23,  -247,   122,    38,  -247,  -247,  -247,  -247,  -247,
    -247,   239,  -247,  -247,  -247,    92,  -247,   190,    93,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,    13,  -247,
       8,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,    73,   174,  -247,    99,  -247,   123,  -247,  -247,  -247,
    -247,  -247,   236,    65,     2,   120,    65,    65,   126,    65,
     244,  -247,  -247,  -247,  -247,  -247,  -247,   277,  -247,  -247,
    -247,  -247,  -247,   119,    11,  -247,  -247,    65,  -247,    65,
    -247,    65,   126,  -247,    65,  -247,   259,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,    80,  -247,  -247,
    -247,  -247,    59,    -1,  -247,  -247,  -247,  -247,   147,    10,
      92,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,    10,  -247,   226,    78,   160,  -247,    10,  -247,
     245,    63,  -247,    10,  -247,  -247,   120,  -247,  -247,   168,
    -247,  -247
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,   164,  -247,  -247,  -247,   192,  -247,   -91,    -5,
    -160,   -16,     4,   700,  -247,  -247,  -247,  -247,  -247,  -247,
    -117,   -17,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,    46,  -247,  -247,
    -247,   121,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -246,  -247,    96,  -247,  -247,  -247,
    -247
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -139
static const yytype_int16 yytable[] =
{
      65,    12,   131,   105,    67,   189,   190,   191,    80,    82,
      19,    10,   163,   259,   260,   217,   267,   199,    68,   204,
      84,    69,   274,    78,    74,    97,    70,   278,   127,    68,
      11,    90,    69,   114,   115,   125,   151,   152,   153,   154,
     155,   156,   157,   158,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    10,    68,
     277,    20,    69,    21,    22,     6,    14,    23,    96,   128,
      15,    15,   100,     8,   101,    24,   102,    11,   103,     1,
       1,   159,   160,    68,    68,    15,    69,    69,     2,     2,
      71,   108,   126,   109,   168,   169,   170,   171,    81,   129,
     130,    83,    77,    89,    65,   136,    75,    76,    98,  -138,
     216,    79,    85,    90,   132,  -138,  -138,   256,  -138,  -138,
     192,   231,  -138,  -138,  -138,   164,  -138,   261,    68,   218,
    -138,    69,   134,   121,   122,   165,    69,    91,   271,   224,
     225,   226,   227,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    94,     5,    36,     9,   188,    37,
      99,    38,    95,    39,  -138,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   104,   219,   106,   219,    20,   220,    21,    22,   219,
    -138,    23,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   137,
     148,  -138,    68,   133,  -138,    69,  -138,   182,  -138,   173,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,    20,   194,    21,    22,
     206,   183,    23,   201,    65,   174,    15,   175,   176,   177,
     178,   179,   180,   139,   140,   141,   142,   143,   144,   145,
     146,   184,   185,   186,   222,   258,   269,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   272,    21,
      36,   275,    86,    37,    87,    38,   281,    39,   120,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   208,   209,   210,   211,   212,
     213,   214,   279,   221,     0,     0,   264,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      21,    36,     0,    92,    37,    93,    38,     0,    39,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      21,     0,    36,     0,     0,    37,     0,    38,     0,    39,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,     0,    37,     0,    38,     0,
      39,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,   110,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,     0,    37,     0,    38,     0,
      39,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   111,
       0,    36,     0,     0,    37,     0,    38,     0,    39,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   112,
       0,    36,     0,     0,    37,     0,    38,     0,    39,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,     0,     0,    37,     0,    38,     0,    39,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   123,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,     0,     0,    37,     0,    38,     0,    39,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   124,     0,
      36,     0,     0,    37,     0,    38,     0,    39,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,     0,     0,    37,     0,    38,     0,    39,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      88,    36,     0,     0,    37,     0,    38,     0,    39,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    88,     0,     0,     0,
      88,    88,    88,    88,     0,     0,     0,     0,    88,    88
};

static const yytype_int16 yycheck[] =
{
      17,     6,   119,    94,    20,     3,     4,     5,     8,     8,
      15,     3,     4,     3,     4,     4,   262,   177,   100,   179,
       8,   103,   268,     8,     8,     8,    22,   273,   110,   100,
      22,     8,   103,    19,    20,   106,    23,    24,    25,    26,
      27,    28,    29,    30,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     3,   100,
       7,     7,   103,     9,    10,    16,    14,    13,    74,   110,
      17,    17,    78,     0,    80,    21,    82,    22,    84,     6,
       6,    78,    79,   100,   100,    17,   103,   103,    15,    15,
       6,    97,   108,    99,    31,    32,    33,    34,   108,   114,
     115,   110,   103,    18,   131,   131,   100,   101,   101,     0,
       1,   106,   110,     8,   101,     6,     7,   128,     9,    10,
     128,   222,    13,    14,    15,   127,    17,   127,   100,   128,
      21,   103,   104,   100,   101,   150,   103,     8,   265,    69,
      70,    71,    72,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    15,     1,   102,     3,   173,   105,
       8,   107,     6,   109,    55,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     4,   197,    21,   199,     7,   201,     9,    10,   204,
      81,    13,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   127,
     127,   102,   100,   101,   105,   103,   107,   128,   109,    55,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     7,   127,     9,    10,
       6,   128,    13,   127,   271,    81,    17,    83,    84,    85,
      86,    87,    88,    73,    74,    75,    76,    77,    78,    79,
      80,    35,    36,    37,    15,   128,    50,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   128,     9,
     102,    46,    12,   105,    14,   107,   128,   109,   106,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    38,    39,    40,    41,    42,
      43,    44,   276,   202,    -1,    -1,   230,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
       9,   102,    -1,    12,   105,    14,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       9,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     9,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     9,
      -1,   102,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     9,
      -1,   102,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     9,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     9,    -1,
     102,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      70,   102,    -1,    -1,   105,    -1,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    96,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,   109
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    15,   130,   131,   131,    16,   137,     0,   131,
       3,    22,   138,   132,    14,    17,   133,   149,   150,   138,
       7,     9,    10,    13,    21,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   102,   105,   107,   109,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   150,   151,   140,   100,   103,
     141,     6,   134,   135,     8,   100,   101,   103,     8,   106,
       8,   108,     8,   110,     8,   110,    12,    14,   142,    18,
       8,     8,    12,    14,    15,     6,   141,     8,   101,     8,
     141,   141,   141,   141,     4,   137,    21,     9,   141,   141,
       9,     9,     9,     9,    19,    20,   152,   153,   154,   136,
     135,   100,   101,     9,     9,   106,   108,   110,   110,   138,
     138,   149,   101,   101,   104,   155,   140,   127,   185,    73,
      74,    75,    76,    77,    78,    79,    80,   187,   127,   156,
     186,    23,    24,    25,    26,    27,    28,    29,    30,    78,
      79,   157,   163,     4,   127,   138,   188,   189,    31,    32,
      33,    34,   158,    55,    81,    83,    84,    85,    86,    87,
      88,   164,   128,   128,    35,    36,    37,   159,   138,     3,
       4,     5,   128,   165,   127,   166,   138,   139,   167,   139,
     168,   127,   169,   170,   139,   172,     6,   173,    38,    39,
      40,    41,    42,    43,    44,   160,     1,     4,   128,   138,
     138,   170,    15,   161,    69,    70,    71,    72,   178,   179,
     171,   137,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   128,   162,   128,     3,
       4,   127,   180,   183,   185,   174,   184,   183,   181,    50,
     176,   149,   128,   182,   183,    46,   177,     7,   183,   166,
     175,   128
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 241 "ptd-parser.y"
    {
		  xmlf_namespace* ns = xml_new_namespace((yyvsp[(2) - (2)].stype), 0);
		  xml_add_namespace(ns);
		  xml_set_current_namespace(ns);
		  (yyval.ptype) = ns;
		;}
    break;

  case 8:
#line 252 "ptd-parser.y"
    {
                   xmlf_namespace* ns = (yyvsp[(0) - (3)].ptype);
                   xml_dump_namespace(fpxml, ns);
		  xml_free_namespace(ns);
		  xml_set_current_namespace(0);
		;}
    break;

  case 9:
#line 259 "ptd-parser.y"
    {
		  xmlf_namespace* ns = (yyvsp[(0) - (2)].ptype);
		  if (xml_is_global_procedure(ns)) {
		    xml_add_global_procedure(ns);
		  } else {
		    xml_dump_namespace(fpxml, ns);
		    xml_free_namespace(ns);
		  }
		  xml_set_current_namespace(0);
		;}
    break;

  case 12:
#line 282 "ptd-parser.y"
    {
		  xmlf_namespace* previous = xml_current_namespace();
		  xmlf_namespace* ns = xml_new_namespace((yyvsp[(3) - (3)].stype), previous);
		  xml_add_namespace(ns);
#ifdef DEBUG                  
                  fprintf(stderr, "\n\nfound %s namespace\n\n", ns->name);
#endif                  
		  xml_set_current_namespace(ns);
		;}
    break;

  case 14:
#line 309 "ptd-parser.y"
    {
		  (yyval.stype) = (yyvsp[(2) - (2)].stype);
		;}
    break;

  case 15:
#line 313 "ptd-parser.y"
    {
   /* there isn't a name to it (such as if just have program main and
    * no procedure(s) or function(s).  --Rickett, 07.16.05
    * the value F90Global for the name of the program namespace seems
    * acceptable.  --Rickett, 07.19.05
    */
   (yyval.stype) = "F90Global";
;}
    break;

  case 16:
#line 324 "ptd-parser.y"
    { (yyval.stype) = (yyvsp[(1) - (1)].stype); ;}
    break;

  case 17:
#line 326 "ptd-parser.y"
    {
   /* this is here to catch what gfortran generates for the name 
    * following 'symtree:' if it is referring to an external symbol
    * (a symbol in another module that has a corresponding use
    * statement).  there shouldn't be any other use of the @ symbol,
    * so the lexer catching it and any following number should be ok.
    * I'm not sure right now if gfortran does anything other than the
    * @ followed by one or more digits; it hasn't so far.
    * needs testing!  --Rickett, 09.14.05
    */
   (yyval.stype) = "externalSymbol";
;}
    break;

  case 18:
#line 342 "ptd-parser.y"
    {
		  (yyval.ptype) = xml_new_list();
		  xml_append_item((yyval.ptype), (yyvsp[(1) - (1)].stype));
		;}
    break;

  case 19:
#line 347 "ptd-parser.y"
    {
		  xml_append_item((yyvsp[(1) - (2)].ptype), (yyvsp[(2) - (2)].stype));
		  (yyval.ptype) = (yyvsp[(1) - (2)].ptype);
		;}
    break;

  case 78:
#line 443 "ptd-parser.y"
    { current_symtree = (yyvsp[(2) - (2)].stype); ;}
    break;

  case 83:
#line 455 "ptd-parser.y"
    {
		  xmlf_namespace* ns = xml_current_namespace();
		  xmlf_symbol* sym = xml_new_symbol((yyvsp[(2) - (2)].stype), ns);
		  xml_set_current_symbol(sym);
		  (yyval.ptype) = sym;
		;}
    break;

  case 84:
#line 462 "ptd-parser.y"
    {
		  xmlf_namespace* ns = xml_current_namespace();
		  xmlf_symbol* sym = (yyvsp[(3) - (6)].ptype);
                  /* both of these tests are necessary.  the 
                   * if($<ptype>6 != NULL) tests that the symbol isn't 
                   * a formal namespace, and the
                   * if(!is_formal_namespace) prevents the symbols that
                   * are the arguments to the procedure making up
                   * the formal namespace from being added.
                   * without the outer if, the formal arguments
                   * were not being added (due to the now inner if), but
                   * the formal namespace itself (e.g., by defining
                   * a subroutine w/in an interface), was getting added
                   * to the current namespace.  then, when dumping the
                   * namespace an error would occur.
                   * --Rickett, 09.08.05
                   */
                  if((yyvsp[(6) - (6)].ptype) != NULL)
                  {
                     if (! is_formal_namespace) {
#ifdef DEBUG                        
                           fprintf(stderr, "\n\nadding symbol with name %s "
                                   "to ns: %s\n\n", sym->name, ns->name);
#endif
                        xml_add_symbol(ns, sym);
                     }
#ifdef DEBUG                     
                     else
                        fprintf(stderr, "\nnot adding symbol %s because "
                                "it's in a formal namespace (%s?)\n\n",
                                sym->name, ns->name);
#endif                     
                  }/* end if(symbol_info_list != NULL) */
#ifdef DEBUG                  
                  else
                  {
                     fprintf(stderr, "\nsymbol_info_list is NULL\n");
                     fprintf(stderr, "did not add symbol %s to ns %s\n\n",
                             sym->name, ns->name);
                  }/* end else(symbol_info_list == NULL) */
#endif                  
		  xml_set_current_symbol(0);
		;}
    break;

  case 85:
#line 514 "ptd-parser.y"
    {
		  xmlf_symbol* sym = (yyvsp[(-1) - (7)].ptype);
		  sym->attr.flavor = (yyvsp[(2) - (7)].itype);
		  sym->attr.intent = (yyvsp[(3) - (7)].itype);
		  sym->attr.access_types = (yyvsp[(4) - (7)].itype);
		  sym->attr.procedures = (yyvsp[(5) - (7)].itype);
		  (yyval.itype) = (yyvsp[(2) - (7)].itype);
		;}
    break;

  case 95:
#line 534 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 99:
#line 541 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 102:
#line 547 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 109:
#line 557 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 110:
#line 560 "ptd-parser.y"
    { (yyval.itype) = 0; ;}
    break;

  case 111:
#line 562 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
                  int n = sym->attr.n_bit_attributes;
		  sym->attr.bit_attributes[n] = (yyvsp[(2) - (2)].itype);
                  sym->attr.n_bit_attributes += 1;
		;}
    break;

  case 135:
#line 594 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 137:
#line 599 "ptd-parser.y"
    {
   if((yyvsp[(2) - (2)].ptype) == NULL)
   {
      (yyval.ptype) = NULL;
   }/* end if(symbol_info == NULL) */
;}
    break;

  case 138:
#line 608 "ptd-parser.y"
    {
               xmlf_symbol* sym = xml_current_symbol(); 
               sym->value = (yyvsp[(2) - (2)].ptype);
            ;}
    break;

  case 139:
#line 613 "ptd-parser.y"
    {
               xmlf_symbol* sym = xml_current_symbol();
               sym->value = (yyvsp[(2) - (3)].ptype);
            ;}
    break;

  case 140:
#line 618 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->as = (yyvsp[(2) - (2)].ptype);
		;}
    break;

  case 141:
#line 623 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->generic = (yyvsp[(2) - (2)].ptype);
		;}
    break;

  case 142:
#line 628 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->common_head = (yyvsp[(2) - (2)].ptype);
		;}
    break;

  case 143:
#line 633 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->result = (yyvsp[(2) - (2)].ptype);
		;}
    break;

  case 144:
#line 638 "ptd-parser.y"
    {
		  /* components already added individually */
		;}
    break;

  case 145:
#line 642 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->formal = (yyvsp[(2) - (2)].ptype);
		;}
    break;

  case 146:
#line 647 "ptd-parser.y"
    {
   if((yyvsp[(2) - (2)].ptype) == NULL)
   {
      (yyval.ptype) = NULL;
   }
;}
    break;

  case 147:
#line 657 "ptd-parser.y"
    {
              fflush(NULL);
              (yyval.ptype) = 0; /* FIXME (no value) */
           ;}
    break;

  case 148:
#line 662 "ptd-parser.y"
    {
		  (yyval.ptype) = 0; /* FIXME (no value) */
		;}
    break;

  case 149:
#line 666 "ptd-parser.y"
    {
		  /* the scanner removes everything inside '(' ')' */
		  (yyval.ptype) = 0;
		;}
    break;

  case 150:
#line 670 "ptd-parser.y"
    {(yyval.ptype) = NULL;;}
    break;

  case 151:
#line 683 "ptd-parser.y"
    {
		  (yyval.ptype) = 0;
		;}
    break;

  case 152:
#line 687 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = (xmlf_arrayspec*) (yyvsp[(3) - (4)].ptype);
		  if (as) assert(as->rank == (yyvsp[(2) - (4)].itype));
		  (yyval.ptype) = as;
		;}
    break;

  case 153:
#line 694 "ptd-parser.y"
    { (yyval.ptype) = (yyvsp[(1) - (1)].ptype); ;}
    break;

  case 154:
#line 697 "ptd-parser.y"
    { (yyval.ptype) = (yyvsp[(1) - (1)].ptype); ;}
    break;

  case 157:
#line 705 "ptd-parser.y"
    {
		  (yyval.ptype) = xml_new_component((yyvsp[(2) - (2)].stype));
		;}
    break;

  case 158:
#line 709 "ptd-parser.y"
    {
		  xmlf_symbol* sym = xml_current_symbol();
		  xmlf_component* comp = (yyvsp[(3) - (8)].ptype);
		  comp->pointer = (yyvsp[(5) - (8)].itype);
		  comp->as = (yyvsp[(7) - (8)].ptype);
		  comp->sym = sym;
		  xml_add_component(sym, comp);
		;}
    break;

  case 159:
#line 719 "ptd-parser.y"
    { (yyval.ptype) = (yyvsp[(1) - (1)].ptype); ;}
    break;

  case 160:
#line 732 "ptd-parser.y"
    { is_formal_namespace = 1; ;}
    break;

  case 161:
#line 734 "ptd-parser.y"
    { is_formal_namespace = 0; ;}
    break;

  case 162:
#line 735 "ptd-parser.y"
    { (yyval.ptype) = 0; ;}
    break;

  case 163:
#line 738 "ptd-parser.y"
    { (yyval.itype) = 0; ;}
    break;

  case 164:
#line 739 "ptd-parser.y"
    { (yyval.itype) = 1; ;}
    break;

  case 165:
#line 742 "ptd-parser.y"
    { (yyval.itype) = 0; ;}
    break;

  case 166:
#line 743 "ptd-parser.y"
    { (yyval.itype) = 1; ;}
    break;

  case 167:
#line 747 "ptd-parser.y"
    {
		  (yyval.ptype) = 0;
		;}
    break;

  case 168:
#line 751 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = (xmlf_arrayspec*) (yyvsp[(2) - (2)].ptype);
		  as->type = (yyvsp[(1) - (2)].itype);
		  (yyval.ptype) = as;
		;}
    break;

  case 172:
#line 762 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 173:
#line 766 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = xml_new_arrayspec();
		  as->rank = 0;
		  as->lb[as->rank] = (yyvsp[(1) - (1)].itype);
		  (yyval.ptype) = as;
		;}
    break;

  case 174:
#line 773 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = (yyvsp[(2) - (3)].ptype);
		  as->ub[as->rank] = (yyvsp[(3) - (3)].itype);
		  as->rank += 1;
		  (yyval.ptype) = as;
		;}
    break;

  case 175:
#line 780 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = (xmlf_arrayspec*) (yyvsp[(1) - (2)].ptype);
		  as->lb[as->rank] = (yyvsp[(2) - (2)].itype);
		  (yyval.ptype) = as;
		;}
    break;

  case 176:
#line 786 "ptd-parser.y"
    {
		  xmlf_arrayspec* as = (xmlf_arrayspec*) (yyvsp[(1) - (4)].ptype);
		  as->ub[as->rank] = (yyvsp[(4) - (4)].itype);
		  as->rank += 1;
		  (yyval.ptype) = as;
		;}
    break;

  case 177:
#line 794 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 178:
#line 796 "ptd-parser.y"
    {
		  /* FIXME (variable name would be useful) */
		  (yyval.itype) = XMLF_ARRAY_VARDEF;
		;}
    break;

  case 179:
#line 801 "ptd-parser.y"
    {
		  /* FIXME, ignore expression for now */
		  ignore_until(')');
		;}
    break;

  case 180:
#line 806 "ptd-parser.y"
    {
		  (yyval.itype) = XMLF_ARRAY_NODEF;
		;}
    break;

  case 181:
#line 812 "ptd-parser.y"
    {
		  /* get typespec memory for type to use */
		  xmlf_typespec* ts = xml_typespec_from_ptr((yyvsp[(0) - (2)].ptype));
		  ts->typename = (yyvsp[(2) - (2)].itype);
		  (yyval.ptype) = ts;
		;}
    break;

  case 182:
#line 819 "ptd-parser.y"
    {
		  (yyval.ptype) = (yyvsp[(4) - (5)].ptype);
		;}
    break;

  case 183:
#line 824 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 184:
#line 825 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 185:
#line 826 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 186:
#line 827 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 187:
#line 828 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 188:
#line 829 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 189:
#line 830 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 190:
#line 831 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 191:
#line 835 "ptd-parser.y"
    {
		  xmlf_typespec* ts = (yyvsp[(0) - (1)].ptype);
		  strcpy(ts->name, (yyvsp[(1) - (1)].stype));
		  ts->kind_or_len = 0;
		  (yyval.ptype) = ts;
		;}
    break;

  case 192:
#line 842 "ptd-parser.y"
    {
		  xmlf_typespec* ts = (yyvsp[(0) - (1)].ptype);
		  strcpy(ts->name, "");
		  ts->kind_or_len = (yyvsp[(1) - (1)].itype);
		  (yyval.ptype) = ts;
		;}
    break;

  case 193:
#line 851 "ptd-parser.y"
    { (yyval.itype) = (yyvsp[(1) - (1)].itype); ;}
    break;

  case 194:
#line 853 "ptd-parser.y"
    { (yyval.itype) = 0; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2614 "ptd-parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 857 "ptd-parser.y"
      /*  start  of  programs  */

#ifdef MY_YYERROR
static void yywarning(const char *s)
{
   fprintf(stderr, s);
}

static void yyerror(const char *s)
{
   fprintf(stderr, s);
}
#endif

