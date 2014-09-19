/** 

gfortran2xml v0.6

Copyright (2004). The Regents of the University of California. This material
was produced under U.S. Government contract W-7405-ENG-36 for Los Alamos
National Laboratory, which is operated by the University of California for
the U.S. Department of Energy. The U.S. Government has rights to use,
reproduce, and distribute this software. NEITHER THE GOVERNMENT NOR THE
UNIVERSITY MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LIABILITY
FOR THE USE OF THIS SOFTWARE. If software is modified to produce derivative
works, such modified software should be clearly marked, so as not to confuse
it with the version available from LANL.

Additionally, this program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version. Accordingly, this program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
the GNU General Public License for more details.

LA-CC-04-154

**/
/* scanner gfortran -fdump-parse-tree output */

%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include <assert.h>
/* #include "ptd-parser.yacc.tab.h" */
#include "ptd-parser.tab.h"
#include "gfortran2xml.h"

   /* maximum number of indentation changes we'll keep at once. */
#define MAX_INDENT_CHANGES 50
   
FILE* fpxml;

 int n_prev_indent = 8;
 int indentChanges[MAX_INDENT_CHANGES];
 int currNumIndentChanges = 0; 
int indent_diff = 0;
int code_indent_level = 0;

yyerror(char* s)
{
  fprintf(stderr, "ERROR [line %d]: %s\n", yylineno, s);
  fprintf(stderr, "  last token read was %s\n", yytext);
  exit(-1);
}


%}

DIGIT    [0-9]
EXPON    [de][-+]?{DIGIT}+

%%

[ \t]+  /* eat up whitespace */

\n { /* indentation is part of the grammar */
  register int c;
  int rc, c_out, end, begin;
  int n = 0;
  static int save_code = 0;

  if (save_code) {
     unput('\n');
     if(currNumIndentChanges > 0 && save_code != SYM_INDENT_INCR)
     {
        currNumIndentChanges--;
#ifdef DEBUG        
        fprintf(stderr, "\n\nreturning sym_indent_decr in save_code\n");
        fprintf(stderr, "currNumIndentChanges is now: %d\n\n",
                currNumIndentChanges);
#endif        
        return SYM_INDENT_DECR;
     }
     rc = save_code;
     save_code = 0;
    return rc;
  }

  while ((c = input()) == ' ') n++;

  if (c == EOF) {
    switch (n_prev_indent) { /* end code */
      case 6 : end = END_CODE_INDENT ;  break;
      case 10: end = END_10_INDENT;  break;
      default: end = END_OF_FILE;
    }
    return end;
  }

  /* check for Fortran line number (ignore by counting numerals as ' ') */

  if (n == 0) {
    while (c >= '0' && c <= '9') {
      n += 1;
      c = input();
    }
    while (c == ' ') {
      n += 1;
      c = input();
    }
  }
  unput(c);
  if (n && n != n_prev_indent) {

    if (code_indent_level) {
       if (n > n_prev_indent) 
          rc = CODE_INDENT_INCR;
       else
          rc = CODE_INDENT_DECR;
       n_prev_indent = n;
      return rc;
    }

    if (n_prev_indent == 6) {
       unput('\n');
       save_code = SYM_INDENT_INCR;
       n_prev_indent = n;
       currNumIndentChanges++;
      return END_CODE_INDENT;;
    }

    if (n == 6) {
       unput('\n');
      save_code = BEGIN_CODE_INDENT;
      n_prev_indent = n;
       currNumIndentChanges--;
      return SYM_INDENT_DECR;
    }

    if (n > n_prev_indent)
    {
       rc = SYM_INDENT_INCR;
       n_prev_indent = n; /* is this right? --Rickett, 09.02.05 */
       currNumIndentChanges++;
    }
    else
    {
       n_prev_indent = n;
       currNumIndentChanges--;
       rc = SYM_INDENT_DECR;
    }
    return rc;
  }
}

"-"*{DIGIT}+ { yylval.itype = atoi(yytext); return NUMBER; }

[+-]?{DIGIT}+"."{DIGIT}*({EXPON})?("_"{DIGIT}+)?     |
[+-]?{DIGIT}*"."{DIGIT}+({EXPON})?("_"{DIGIT}+)?     |
[+-]?{DIGIT}+{EXPON}("_"{DIGIT}+)?  {
	  yylval.ftype = atof(yytext); return FLOAT;
	}

"@"{DIGIT}+ { return ATSIGN_NUM; /* added by Rickett */ }

Namespace: { while (input() != '\n') ; unput('\n'); return NAMESPACE; }

"procedure name =" { return PROCEDURE_NAME; }

symtree: { return SYMTREE; }

Ambig	{ return AMBIG; }

"from namespace" { return FROM_NAMESPACE; }

symbol	{ return SYMBOL; }

  /* flavors */

UNKNOWN-FL	{ yylval.itype = FL_UNKNOWN; return FL_UNKNOWN; }
PROGRAM		{ yylval.itype = FL_PROGRAM; return FL_PROGRAM; }
BLOCK-DATA	{ yylval.itype = FL_BLOCK_DATA; return FL_BLOCK_DATA; }
MODULE		{ yylval.itype = FL_MODULE; return FL_MODULE; }
VARIABLE	{ yylval.itype = FL_VARIABLE; return FL_VARIABLE; }
PARAMETER	{ yylval.itype = FL_PARAMETER; return FL_PARAMETER; }
LABEL		{ yylval.itype = FL_LABEL; return FL_LABEL; }
  /* FL_PROCEDURE is PROCEDURE (see basic typenames) */
  /* FL_DERIVED is DERIVED (see basic typenames) */
NAMELIST	{ yylval.itype = FL_NAMELIST; return FL_NAMELIST; }

  /* intent */

UNKNOWN-INTENT	{ yylval.itype = INTENT_UNKNOWN; return INTENT_UNKNOWN; }
IN		{ yylval.itype = INTENT_IN; return INTENT_IN; }
OUT		{ yylval.itype = INTENT_OUT; return INTENT_OUT; }
INOUT		{ yylval.itype = INTENT_INOUT; return INTENT_INOUT; }

  /* access types */

UNKNOWN-ACCESS	{ yylval.itype = ACCESS_UNKNOWN; return ACCESS_UNKNOWN; }
PUBLIC		{ yylval.itype = ACCESS_PUBLIC; return ACCESS_PUBLIC; }
PRIVATE		{ yylval.itype = ACCESS_PRIVATE; return ACCESS_PRIVATE; }

  /* procedures */

UNKNOWN-PROC	{ yylval.itype = PROC_UNKNOWN; return PROC_UNKNOWN; }
MODULE-PROC	{ yylval.itype = PROC_MODULE; return PROC_MODULE; }
INTERNAL-PROC	{ yylval.itype = PROC_INTERNAL; return PROC_INTERNAL; }
DUMMY-PROC	{ yylval.itype = PROC_DUMMY; return PROC_DUMMY; }
INTRINSIC-PROC	{ yylval.itype = PROC_INTRINSIC; return PROC_INTRINSIC; }
EXTERNAL-PROC	{ yylval.itype = PROC_EXTERNAL; return PROC_EXTERNAL; }
STATEMENT-PROC	{ yylval.itype = PROC_ST_FUNCTION; return PROC_ST_FUNCTION; }

  /* bit attributes */

ALLOCATABLE	{ yylval.itype = ALLOCATABLE; return ALLOCATABLE; }
DIMENSION	{ yylval.itype = DIMENSION; return DIMENSION; }
EXTERNAL	{ yylval.itype = EXTERNAL; return EXTERNAL; }
INTRINSIC	{ yylval.itype = INTRINSIC; return INTRINSIC; }
OPTIONAL	{ yylval.itype = OPTIONAL; return OPTIONAL; }
POINTER		{ yylval.itype = POINTER; return POINTER; }
IMPLICIT-SAVE	{ yylval.itype = IMPLICIT_SAVE; return IMPLICIT_SAVE; }
SAVE		{ yylval.itype = SAVE; return SAVE; }
TARGET		{ yylval.itype = TARGET; return TARGET; }
DUMMY		{ yylval.itype = DUMMY; return DUMMY; }
COMMON		{ yylval.itype = COMMON; return COMMON; }
RESULT		{ yylval.itype = RESULT; return RESULT; }
ENTRY		{ yylval.itype = ENTRY; return ENTRY; }
FUNCTION	{ yylval.itype = FUNCTION; return FUNCTION; }
SUBROUTINE	{ yylval.itype = SUBROUTINE; return SUBROUTINE; }
IMPLICIT-TYPE	{ yylval.itype = IMPLICIT_TYPE; return IMPLICIT_TYPE; }
DATA		{ yylval.itype = DATA; return DATA; }
USE-ASSOC	{ yylval.itype = USE_ASSOC; return USE_ASSOC; }
IN-NAMELIST	{ yylval.itype = IN_NAMELIST; return IN_NAMELIST; }
IN-COMMON	{ yylval.itype = IN_COMMON; return IN_COMMON; }
SAVED-COMMON	{ yylval.itype = SAVED_COMMON; return SAVED_COMMON; }
SEQUENCE	{ yylval.itype = SEQUENCE; return SEQUENCE; }
ELEMENTAL	{ yylval.itype = ELEMENTAL; return ELEMENTAL; }
PURE		{ yylval.itype = PURE; return PURE; }
RECURSIVE	{ yylval.itype = RECURSIVE; return RECURSIVE; }

  /* pointer_or_dim */

  /* POINTER (see bit attributes) */
  /* DIMENSION (see bit attributes) */

  /* array type */

AS_EXPLICIT	  { yylval.itype = AS_EXPLICIT; return AS_EXPLICIT; }
AS_DEFERRED	  { yylval.itype = AS_DEFERRED; return AS_DEFERRED; }
AS_ASSUMED_SIZE	  { yylval.itype = AS_ASSUMED_SIZE; return AS_ASSUMED_SIZE; }
AS_ASSUMED_SHAPE  { yylval.itype = AS_ASSUMED_SHAPE; return AS_ASSUMED_SHAPE; }


  /* basic typenames */

INTEGER		{ yylval.itype = INTEGER; return INTEGER; }
REAL		{ yylval.itype = REAL; return REAL; }
COMPLEX		{ yylval.itype = COMPLEX; return COMPLEX; }
LOGICAL		{ yylval.itype = LOGICAL; return LOGICAL; }
CHARACTER	{ yylval.itype = CHARACTER; return CHARACTER; }
DERIVED		{ yylval.itype = DERIVED; return DERIVED; }
PROCEDURE	{ yylval.itype = PROCEDURE; return PROCEDURE; }
UNKNOWN		{ yylval.itype = UNKNOWN; return UNKNOWN; }

  /* symbol info */

value:		{
                  int c = input(); /* blank character */
		  c = input();
		  if (c == '(') {
		    while (input() != '\n') ;
		    c = ')';
		  }
		  unput(c);
		  yylval.itype = VALUE; return VALUE;
		}

"Array spec:"	{ yylval.itype = ARRAY_SPEC; return ARRAY_SPEC; }

result:		{ yylval.itype = RESULT; return RESULT; }

components:	{ yylval.itype = COMPONENTS; return COMPONENTS; }


"Generic interfaces:" {
  yylval.itype = GENERIC_INTERFACES; return GENERIC_INTERFACES;
}

"Common members:" {
  yylval.itype = COMMON_MEMBERS; return COMMON_MEMBERS;
}

"Formal arglist:" {
  yylval.itype = FORMAL_ARGLIST; return FORMAL_ARGLIST;
}

"Formal namespace" {
  yylval.itype = FORMAL_NAMESPACE; return FORMAL_NAMESPACE;
}

CONTAINS	{ yylval.itype = CONTAINS; return CONTAINS; }


"NOP"		{ while (input() != '\n') ; unput('\n'); return NOP; }
"CONTINUE"	{ while (input() != '\n') ; unput('\n'); return CONTINUE; }
"ASSIGN "	{ while (input() != '\n') ; unput('\n'); return ASSIGN; }
"LABEL ASSIGN "	{ while (input() != '\n') ; unput('\n'); return LABEL_ASSIGN; }
"POINTER ASSIGN " {
             while (input() != '\n') ; unput('\n'); return POINTER_ASSIGN;
                  }
"GOTO "		{ while (input() != '\n') ; unput('\n'); return GOTO; }
"CALL "		{ while (input() != '\n') ; unput('\n'); return CALL; }
"RETURN "	{ while (input() != '\n') ; unput('\n'); return RETURN; }
"PAUSE "	{ while (input() != '\n') ; unput('\n'); return PAUSE; }
"STOP "		{ while (input() != '\n') ; unput('\n'); return STOP; }
"IF "		{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return IF;
		}
"ELSE"		{ while (input() != '\n') ; unput('\n'); return ELSE; }
"ENDIF"		{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level -= 1;
		  return ENDIF;
		}
"SELECT CASE "	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return SELECT_CASE;
		}
"CASE"		{ while (input() != '\n') ; unput('\n'); return CASE; }
"END SELECT"	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level -= 1;
		  return END_SELECT;
		}
"WHERE "	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return WHERE;
		}
"END WHERE"	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level -= 1;
		  return END_WHERE;
		}
"FORALL "	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return FORALL;
		}
"END FORALL"	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level -= 1;
		  return END_FORALL;
		}
"DO"		{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return DO;
		}
"END DO"	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level -= 1;
		  return END_DO;
		}
"DO WHILE "	{
		  while (input() != '\n') ; unput('\n');
		  code_indent_level += 1;
		  return DO_WHILE;
		}
"CYCLE"		{ while (input() != '\n') ; unput('\n'); return CYCLE; }
"EXIT"		{ while (input() != '\n') ; unput('\n'); return EXIT; }
"ALLOCATE "	{ while (input() != '\n') ; unput('\n'); return ALLOCATE; }
"DEALLOCATE "	{ while (input() != '\n') ; unput('\n'); return DEALLOCATE; }
"OPEN"		{ while (input() != '\n') ; unput('\n'); return OPEN; }
"CLOSE"		{ while (input() != '\n') ; unput('\n'); return CLOSE; }
"BACKSPACE"	{ while (input() != '\n') ; unput('\n'); return BACKSPACE; }
"ENDFILE"	{ while (input() != '\n') ; unput('\n'); return ENDFILE; }
"REWIND"	{ while (input() != '\n') ; unput('\n'); return REWIND; }
"INQUIRE"	{ while (input() != '\n') ; unput('\n'); return INQUIRE; }
"IOLENGTH "	{ while (input() != '\n') ; unput('\n'); return IOLENGTH; }
"READ"		{ while (input() != '\n') ; unput('\n'); return READ; }
"WRITE"		{ while (input() != '\n') ; unput('\n'); return WRITE; }
"TRANSFER "	{ while (input() != '\n') ; unput('\n'); return TRANSFER; }
"DT_END"	{ while (input() != '\n') ; unput('\n'); return DT_END; }


[a-zA-Z0-9_]+	{ yylval.stype = strdup(yytext); return ID; }

.		{ return yytext[0]; }

%%

void ignore_until(int c)
{
  while (input() != c) ;
  unput(c);
}

int yywrap() {return 1;}

main(int argc, char* argv[])
{
  char* filename = "UNKNOWN.f90";
  char* language = "fortran";
  xmlf_namespace* global;
  fpxml = stdout;

  ++argv, --argc;
  if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
  else
    yyin = stdin;

  xml_open_file(fpxml);
  xml_open_library(fpxml, filename, language);

  xml_open_includes(fpxml);
  xml_close_includes(fpxml);
  xml_open_modules(fpxml);

  /* initialize namespace for procedures that are not in a module */

  global = xml_new_namespace("F90Global", 0);
  xml_add_namespace(global);

  yyparse();

  xml_dump_global_namespace(fpxml, global);

  xml_close_modules(fpxml);
  xml_close_library(fpxml);
  xml_close_file(fpxml);

  return 0;
}
