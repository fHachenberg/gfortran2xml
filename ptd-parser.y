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
%{
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

%}

%union {
  int itype;
  double ftype;
  char* stype;
  void* ptype;
  struct { int first; int second; } iitype;
  struct { int kind; void* ptr;   } iptype;
}

%start  namespaces

%token <stype> ID
%token <itype> NUMBER
%token <ftype> FLOAT

%token  SYM_INDENT_INCR
%token  SYM_INDENT_DECR
%token  CODE_INDENT_INCR
%token  CODE_INDENT_DECR
%token  BEGIN_CODE_INDENT
%token  BEGIN_10_INDENT
%token  END_CODE_INDENT
%token  END_10_INDENT
%token  END_OF_FILE

%token  NAMESPACE
%token  PROCEDURE_NAME
%token  SYMTREE
%token  AMBIG
%token  FROM_NAMESPACE
%token  SYMBOL
%token  CONTAINS

%token ATSIGN_NUM

/* flavors */

%token  FL_UNKNOWN
%token  FL_PROGRAM
%token  FL_BLOCK_DATA
%token  FL_MODULE
%token  FL_VARIABLE
%token  FL_PARAMETER
%token  FL_LABEL
/* %token  FL_PROCEDURE is PROCEDURE (see basic typenames) */
/* %token  FL_DERIVED is DERIVED (see basic typenames) */
%token  FL_NAMELIST

/* intent */

%token  INTENT_UNKNOWN
%token  INTENT_IN
%token  INTENT_OUT
%token  INTENT_INOUT

/* access types */

%token  ACCESS_UNKNOWN
%token  ACCESS_PUBLIC
%token  ACCESS_PRIVATE

/* procedures */

%token  PROC_UNKNOWN
%token  PROC_MODULE
%token  PROC_INTERNAL
%token  PROC_DUMMY
%token  PROC_INTRINSIC
%token  PROC_EXTERNAL
%token  PROC_ST_FUNCTION

/* bit_attribute */

%token  ALLOCATABLE
%token  DIMENSION
%token  EXTERNAL
%token  INTRINSIC
%token  OPTIONAL
%token  POINTER
%token  SAVE
%token  TARGET
%token  DUMMY
%token  COMMON
%token  RESULT
%token  ENTRY
%token  FUNCTION
%token  SUBROUTINE
%token  IMPLICIT_TYPE
%token  DATA
%token  USE_ASSOC
%token  IN_NAMELIST
%token  IN_COMMON
%token  SAVED_COMMON
%token  SEQUENCE
%token  ELEMENTAL
%token  PURE
%token  RECURSIVE

/* pointer_or_dim */

%token  POINTER
%token  DIMENSION

/* array type */

%token  AS_EXPLICIT
%token  AS_DEFERRED
%token  AS_ASSUMED_SIZE
%token  AS_ASSUMED_SHAPE

/* basic typenames */

%token  INTEGER
%token  REAL
%token  COMPLEX
%token  LOGICAL
%token  CHARACTER
%token  DERIVED
%token  PROCEDURE
%token  UNKNOWN

/* symbol_info */

%token  VALUE
%token  VALUE_PAREN_EXPR
%token  ARRAY_SPEC
%token  GENERIC_INTERFACES
%token  COMMON_MEMBERS
%token  RESULT
%token  COMPONENTS
%token  FORMAL_ARGLIST
%token  FORMAL_NAMESPACE

/* code segment */
%token  NOP
%token  CONTINUE
%token  ASSIGN
%token  LABEL_ASSIGN
%token  POINTER_ASSIGN
%token  GOTO
%token  CALL
%token  RETURN
%token  PAUSE
%token  STOP
%token  IF
%token  ELSE
%token  ENDIF
%token  SELECT_CASE
%token  CASE
%token  END_SELECT
%token  WHERE
%token  END_WHERE
%token  FORALL
%token  END_FORALL
%token  DO
%token  END_DO
%token  DO_WHILE
%token  CYCLE
%token  EXIT
%token  ALLOCATE
%token  DEALLOCATE
%token  OPEN
%token  CLOSE
%token  BACKSPACE
%token  ENDFILE
%token  REWIND
%token  INQUIRE
%token  IOLENGTH
%token  READ
%token  WRITE
%token  TRANSFER
%token  DT_END

%%      /*  beginning  of  rules  section  */

namespaces : namespace
           | namespaces namespace
           | namespaces namespace END_OF_FILE
           ;

namespace : NAMESPACE namespace_name
		{
		  xmlf_namespace* ns = xml_new_namespace($<stype>2, 0);
		  xml_add_namespace(ns);
		  xml_set_current_namespace(ns);
		  $<ptype>$ = ns;
		}
            namespace_body
          | SYM_INDENT_INCR namespace
          ;

namespace_body : symtrees CONTAINS contained_namespaces
		{
                   xmlf_namespace* ns = $<ptype>0;
                   xml_dump_namespace(fpxml, ns);
		  xml_free_namespace(ns);
		  xml_set_current_namespace(0);
		}
               | symtrees code_segment 
		{
		  xmlf_namespace* ns = $<ptype>0;
		  if (xml_is_global_procedure(ns)) {
		    xml_add_global_procedure(ns);
		  } else {
		    xml_dump_namespace(fpxml, ns);
		    xml_free_namespace(ns);
		  }
		  xml_set_current_namespace(0);
		}
                ;

/* the second rule causes a shift/reduce conflict.  see if can fix.
 * the default action to shift the SYM_INDENT_INCR works, but
 * i may try and get rid of the conflict. removing the conflict could
 * cause the parser to run slower though.  --Rickett, 09.13.05
 */
contained_namespaces : contained_namespace
| contained_namespaces SYM_INDENT_INCR CONTAINS contained_namespace 
/*                      | contained_namespaces CONTAINS contained_namespace */
;

contained_namespace : SYM_INDENT_INCR NAMESPACE namespace_name
		{
		  xmlf_namespace* previous = xml_current_namespace();
		  xmlf_namespace* ns = xml_new_namespace($<stype>3, previous);
		  xml_add_namespace(ns);
#ifdef DEBUG                  
                  fprintf(stderr, "\n\nfound %s namespace\n\n", ns->name);
#endif                  
		  xml_set_current_namespace(ns);
		}
                symtrees code_segment 
/* these next lines are the original rule but I've removed the
 * sym_indent_decr because it is getting sucked up with the namespace.
 * I'm not sure if this is always the case. --Rickett, 09.06.05
 */
/* : SYM_INDENT_INCR NAMESPACE namespace_name */
/* 		{ */
/* 		  xmlf_namespace* previous = xml_current_namespace(); */
/* 		  xmlf_namespace* ns = xml_new_namespace($<stype>3, previous); */
/* 		  xml_add_namespace(ns); */
/* 		  xml_set_current_namespace(ns); */
/* 		} */
/*          symtrees {fprintf(stderr, "\ncontained_namespace0\n\n");} */
/*          SYM_INDENT_DECR {fprintf(stderr, "\ncontained_namespace\n\n");} */
/*          code_segment */
                    ;

namespace_name : PROCEDURE_NAME name
		{
		  $<stype>$ = $<stype>2;
		}
| 
{
   /* there isn't a name to it (such as if just have program main and
    * no procedure(s) or function(s).  --Rickett, 07.16.05
    * the value F90Global for the name of the program namespace seems
    * acceptable.  --Rickett, 07.19.05
    */
   $<stype>$ = "F90Global";
}
               ;

name : ID
{ $<stype>$ = $<stype>1; }
| ATSIGN_NUM
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
   $<stype>$ = "externalSymbol";
}

     ;

names : name
		{
		  $<ptype>$ = xml_new_list();
		  xml_append_item($<ptype>$, $<stype>1);
		}
      | names name
		{
		  xml_append_item($<ptype>1, $<stype>2);
		  $<ptype>$ = $<ptype>1;
		}
      ;

code_segment : /* empty */
             | BEGIN_CODE_INDENT statement_list END_CODE_INDENT
| BEGIN_CODE_INDENT statement_list END_OF_FILE
| SYM_INDENT_DECR code_segment 
| END_10_INDENT
| statement_list END_CODE_INDENT
| statement_list END_OF_FILE
   /* | SYM_INDENT_DECR statement_list SYM_INDENT_INCR */
   /* | SYM_INDENT_DECR statement_list END_OF_FILE */
   /* | statement_list  */
   /* test.ptd has an error because of the "extra" sym_indent_decr,
    * and I say extra because there was no beginning sym_indent_incr.
    * if added sym_indent_decr before the begin_code_indent above, it'd
    * fix it for this one case, but that's not a fix.  need to figure
    * out how to fix.  --Rickett, 09.02.05
    * test.ptd is now helloWorld.ptd 
    */
             ;

statement_list : statement
               | statement_list statement
               ;

statement : if_block
          | do_block
          | do_while_block
          | select_block
          | where_block
          | forall_block
          | NOP
          | CONTINUE
          | ASSIGN
          | LABEL_ASSIGN
          | POINTER_ASSIGN
          | GOTO
          | CALL 
          | RETURN
          | PAUSE
          | STOP
          | CYCLE
          | EXIT
          | ALLOCATE
          | DEALLOCATE
          | OPEN
          | CLOSE
          | BACKSPACE
          | ENDFILE
          | REWIND
          | INQUIRE
          | IOLENGTH
          | READ
          | WRITE
          | TRANSFER
          | DT_END
          | CODE_INDENT_DECR ELSE CODE_INDENT_INCR
          | CODE_INDENT_DECR CASE CODE_INDENT_INCR
          ;

if_block : IF ENDIF
         | IF ELSE ENDIF
         | IF ELSE CODE_INDENT_INCR statement_list CODE_INDENT_DECR ENDIF
         | IF CODE_INDENT_INCR statement_list CODE_INDENT_DECR ELSE ENDIF
         | IF CODE_INDENT_INCR statement_list CODE_INDENT_DECR ENDIF
         ;

do_block : DO END_DO
         | DO CODE_INDENT_INCR statement_list CODE_INDENT_DECR END_DO
         ;

do_while_block : DO_WHILE END_DO
             | DO_WHILE CODE_INDENT_INCR statement_list CODE_INDENT_DECR END_DO
             ;

select_block : SELECT_CASE CASE
               CODE_INDENT_INCR statement_list CODE_INDENT_DECR END_SELECT
             ;

where_block : WHERE END_WHERE
            | WHERE CODE_INDENT_INCR statement_list CODE_INDENT_DECR END_WHERE
            ;

forall_block : FORALL END_FORALL
           | FORALL CODE_INDENT_INCR statement_list CODE_INDENT_DECR END_FORALL
           ;

symtrees : symtree 
         | symtrees symtree
         ;

symtree : SYMTREE name 
		{ current_symtree = $<stype>2; }
AMBIG NUMBER from_or_symbol 
        ;

from_or_symbol : from_namespace
               | symbol
               ;

from_namespace : FROM_NAMESPACE name
               ;

symbol : SYMBOL name
		{
		  xmlf_namespace* ns = xml_current_namespace();
		  xmlf_symbol* sym = xml_new_symbol($<stype>2, ns);
		  xml_set_current_symbol(sym);
		  $<ptype>$ = sym;
		}
         type_spec symbol_attribute symbol_info_list 
		{
		  xmlf_namespace* ns = xml_current_namespace();
		  xmlf_symbol* sym = $<ptype>3;
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
                  if($<ptype>6 != NULL)
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
		}
       ;

symbol_attribute : '('
                   flavors
                   intent
                   access_types
                   procedures
                   bit_attributes
                   ')'
		{
		  xmlf_symbol* sym = $<ptype>-1;
		  sym->attr.flavor = $<itype>2;
		  sym->attr.intent = $<itype>3;
		  sym->attr.access_types = $<itype>4;
		  sym->attr.procedures = $<itype>5;
		  $<itype>$ = $<itype>2;
		}
                 ;

flavors : FL_UNKNOWN
        | FL_PROGRAM
        | FL_BLOCK_DATA
        | FL_MODULE
        | FL_VARIABLE
        | FL_PARAMETER
        | FL_LABEL
        | PROCEDURE
        | DERIVED
        | FL_NAMELIST
		{ $<itype>$ = $<itype>1; }
        ;

intent : INTENT_UNKNOWN
       | INTENT_IN
       | INTENT_OUT
       | INTENT_INOUT
		{ $<itype>$ = $<itype>1; }
       ;

access_types : ACCESS_UNKNOWN
             | ACCESS_PUBLIC
             | ACCESS_PRIVATE
		{ $<itype>$ = $<itype>1; }
             ;

procedures : PROC_UNKNOWN
           | PROC_MODULE
           | PROC_INTERNAL
           | PROC_DUMMY
           | PROC_INTRINSIC
           | PROC_EXTERNAL
           | PROC_ST_FUNCTION
		{ $<itype>$ = $<itype>1; }
           ;

bit_attributes : /* empty */ { $<itype>$ = 0; }
               | bit_attributes bit_attribute
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
                  int n = sym->attr.n_bit_attributes;
		  sym->attr.bit_attributes[n] = $<itype>2;
                  sym->attr.n_bit_attributes += 1;
		}
               ;

bit_attribute : ALLOCATABLE
              | DIMENSION
              | EXTERNAL
              | INTRINSIC
              | OPTIONAL
              | POINTER
              | SAVE
              | TARGET
              | DUMMY
              | COMMON
              | RESULT
              | ENTRY
              | FUNCTION
              | SUBROUTINE
              | IMPLICIT_TYPE
              | DATA
              | USE_ASSOC
              | IN_NAMELIST
              | IN_COMMON
              | SAVED_COMMON
              | SEQUENCE
              | ELEMENTAL
              | PURE
              | RECURSIVE
		{ $<itype>$ = $<itype>1; }
              ;

symbol_info_list : /* empty */
| symbol_info_list symbol_info
{
   if($<ptype>2 == NULL)
   {
      $<ptype>$ = NULL;
   }/* end if(symbol_info == NULL) */
}
                 ;

symbol_info : VALUE value_expr
            {
               xmlf_symbol* sym = xml_current_symbol(); 
               sym->value = $<ptype>2;
            }
            | VALUE value_expr error
            {
               xmlf_symbol* sym = xml_current_symbol();
               sym->value = $<ptype>2;
            }  
            | ARRAY_SPEC array_spec
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->as = $<ptype>2;
		}
            | GENERIC_INTERFACES generic_interfaces
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->generic = $<ptype>2;
		}
            | COMMON_MEMBERS common_members
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->common_head = $<ptype>2;
		}
            | RESULT name
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->result = $<ptype>2;
		}
            | COMPONENTS components
		{
		  /* components already added individually */
		}
            | FORMAL_ARGLIST formal_arglist
		{
		  xmlf_symbol* sym = xml_current_symbol(); 
		  sym->formal = $<ptype>2;
		}
| FORMAL_NAMESPACE formal_namespace 
{
   if($<ptype>2 == NULL)
   {
      $<ptype>$ = NULL;
   }
}
   
            ;

value_expr : NUMBER
           {
              fflush(NULL);
              $<ptype>$ = 0; /* FIXME (no value) */
           }
           | FLOAT
		{
		  $<ptype>$ = 0; /* FIXME (no value) */
		}
           | ')'
		{
		  /* the scanner removes everything inside '(' ')' */
		  $<ptype>$ = 0;
		}
| ID {$<ptype>$ = NULL;} /* this case is only for allowing
                          * gfortran to dump out things such as 0_8
                          * as part of a value expression when dealing
                          * with expressions dependent on external
                          * symbols.  I don't think it arises in any
                          * other case, but not sure.  Allowing for
                          * the ID could allow more than we want, but
                          * it's probably ok for now.  needs testing.
                          * --Rickett, 09.14.05
                          */
           ;

array_spec : '(' ')'
		{
		  $<ptype>$ = 0;
		}
           | '(' NUMBER dim_info ')'
		{
		  xmlf_arrayspec* as = (xmlf_arrayspec*) $<ptype>3;
		  if (as) assert(as->rank == $<itype>2);
		  $<ptype>$ = as;
		}
           ;

generic_interfaces : names	{ $<ptype>$ = $<ptype>1; }
                   ;

common_members : names	{ $<ptype>$ = $<ptype>1; }
               ;

components : component
           | components component
           ;

component : '(' name
		{
		  $<ptype>$ = xml_new_component($<stype>2);
		}
             type_spec pointer dimension array_spec ')'
		{
		  xmlf_symbol* sym = xml_current_symbol();
		  xmlf_component* comp = $<ptype>3;
		  comp->pointer = $<itype>5;
		  comp->as = $<ptype>7;
		  comp->sym = sym;
		  xml_add_component(sym, comp);
		}
          ;

formal_arglist : names		{ $<ptype>$ = $<ptype>1; }
               ;

/* this next version of formal_namespace should work, minus some of
 * the nested interfaces.  --Rickett, 09.14.05
 */
/* formal_namespace : SYM_INDENT_INCR NAMESPACE namespace_name */
/* { is_formal_namespace = 1; } */
/*                    symtrees {fprintf(stderr, "\n\nlooking for sym_indent_decr\n\n");} SYM_INDENT_DECR */
/*                      { is_formal_namespace = 0; } */
/* 		  { $<ptype>$ = 0; } */
/*                  ; */
formal_namespace : SYM_INDENT_INCR NAMESPACE namespace_name
                   { is_formal_namespace = 1; }
                   symtrees SYM_INDENT_DECR
                     { is_formal_namespace = 0; }
		  { $<ptype>$ = 0; }
                 ;

pointer : /* empty */	{ $<itype>$ = 0; }
        | POINTER	{ $<itype>$ = 1; }
        ;

dimension : /* empty */	{ $<itype>$ = 0; }
          | DIMENSION	{ $<itype>$ = 1; }
          ;

dim_info : /* empty */
		{
		  $<ptype>$ = 0;
		}
         | array_type array_extents
		{
		  xmlf_arrayspec* as = (xmlf_arrayspec*) $<ptype>2;
		  as->type = $<itype>1;
		  $<ptype>$ = as;
		}
         ;

array_type : AS_EXPLICIT
           | AS_DEFERRED
           | AS_ASSUMED_SIZE
           | AS_ASSUMED_SHAPE
		{ $<itype>$ = $<itype>1; }
           ;

array_extents : array_expr
		{
		  xmlf_arrayspec* as = xml_new_arrayspec();
		  as->rank = 0;
		  as->lb[as->rank] = $<itype>1;
		  $<ptype>$ = as;
		}
                array_expr
		{
		  xmlf_arrayspec* as = $<ptype>2;
		  as->ub[as->rank] = $<itype>3;
		  as->rank += 1;
		  $<ptype>$ = as;
		}
              | array_extents array_expr
		{
		  xmlf_arrayspec* as = (xmlf_arrayspec*) $<ptype>1;
		  as->lb[as->rank] = $<itype>2;
		  $<ptype>$ = as;
		}
                array_expr
		{
		  xmlf_arrayspec* as = (xmlf_arrayspec*) $<ptype>1;
		  as->ub[as->rank] = $<itype>4;
		  as->rank += 1;
		  $<ptype>$ = as;
		}
              ;

array_expr : NUMBER	{ $<itype>$ = $<itype>1; }
           | ID
		{
		  /* FIXME (variable name would be useful) */
		  $<itype>$ = XMLF_ARRAY_VARDEF;
		}
           | '('
		{
		  /* FIXME, ignore expression for now */
		  ignore_until(')');
		}
             ')'
		{
		  $<itype>$ = XMLF_ARRAY_NODEF;
		}
           ;

type_spec : '(' basic_typename
		{
		  /* get typespec memory for type to use */
		  xmlf_typespec* ts = xml_typespec_from_ptr($<ptype>0);
		  ts->typename = $<itype>2;
		  $<ptype>$ = ts;
		}
            type ')'
		{
		  $<ptype>$ = $<ptype>4;
		}
          ;

basic_typename :  INTEGER	{ $<itype>$ = $<itype>1; }
               |  REAL		{ $<itype>$ = $<itype>1; }
               |  COMPLEX	{ $<itype>$ = $<itype>1; }
               |  LOGICAL	{ $<itype>$ = $<itype>1; }
               |  CHARACTER	{ $<itype>$ = $<itype>1; }
               |  DERIVED	{ $<itype>$ = $<itype>1; }
               |  PROCEDURE	{ $<itype>$ = $<itype>1; }
	       |  UNKNOWN	{ $<itype>$ = $<itype>1; }
               ;

type :  name
		{
		  xmlf_typespec* ts = $<ptype>0;
		  strcpy(ts->name, $<stype>1);
		  ts->kind_or_len = 0;
		  $<ptype>$ = ts;
		}
     |	len_kind
		{
		  xmlf_typespec* ts = $<ptype>0;
		  strcpy(ts->name, "");
		  ts->kind_or_len = $<itype>1;
		  $<ptype>$ = ts;
		}
     ;

len_kind : NUMBER
		{ $<itype>$ = $<itype>1; }
         | '(' ')'
		{ $<itype>$ = 0; }
         ;


%%      /*  start  of  programs  */

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
