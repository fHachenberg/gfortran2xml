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

#include <stdio.h>

extern FILE* fpxml;

#define XMLF_MAX_SYMBOL_LEN 63
#define XMLF_MAX_BIT_ATTRIBUTES 8
#define XMLF_INITIAL_LIST_LEN 8
#define XMLF_ARRAY_NODEF  -98765
#define XMLF_ARRAY_VARDEF -98764

typedef struct xmlf_list
{
  void** items;
  int len;
  int n_max;
}
xmlf_list;

typedef struct
{
  char name[XMLF_MAX_SYMBOL_LEN + 1];	/* name of derived type */
  int typename;				/* INTEGER, REAL, ... */
  int kind_or_len;
}
xmlf_typespec;

typedef struct
{
  int flavor;
  int intent;
  int access_types;
  int procedures;
  int bit_attributes[XMLF_MAX_BIT_ATTRIBUTES];
  int n_bit_attributes;
}
xmlf_sym_attribute;

typedef struct
{
  int rank;
  int type;			/* AS_EXPLICIT, AS_DEFERRED, ... */
  int lb[7];			/* none for AS_DEFERRED */
  int ub[7];
}
xmlf_arrayspec;

typedef struct
{
  int kind;
  void* ptr;
}
xmlf_sym_info;

typedef struct xmlf_component
{
  char name[XMLF_MAX_SYMBOL_LEN + 1];
  xmlf_typespec ts;
  /* HACK ATTACK, MUST be same as xmlf_symbol to here*/

  int pointer;				/* POINTER */
  xmlf_arrayspec* as;			/* DIMENSION attributes */

  struct xmlf_symbol* sym;		/* containing symbol */

  struct xmlf_component* next;
}
xmlf_component;


typedef struct xmlf_symbol
{
  char name[XMLF_MAX_SYMBOL_LEN + 1];
  xmlf_typespec ts;
  /* HACK ATTACK, MUST be same as xmlf_component to here*/

  xmlf_sym_attribute attr;

  int*  value;				/* TODO works(?) only for ints */
  xmlf_arrayspec* as;
  xmlf_list*      generic;
  xmlf_list*      common_head;
  char*           result;
  xmlf_list*      formal;

  struct xmlf_namespace* formal_ns;	/* TODO usage not implemented yet */

  xmlf_component* comp_head;
  xmlf_component* comp_tail;

  struct xmlf_namespace *ns;

  struct xmlf_symbol* next;
}
xmlf_symbol;


typedef struct xmlf_namespace
{
  char name[XMLF_MAX_SYMBOL_LEN + 1];
  struct xmlf_namespace* previous;
  struct xmlf_namespace* next;
  xmlf_symbol* proc_sym;
  xmlf_symbol* sym_head;
  xmlf_symbol* sym_tail;
}
xmlf_namespace;


xmlf_namespace* xml_current_namespace();
void xml_set_current_namespace(xmlf_namespace* ns);

xmlf_symbol* xml_current_symbol();
void xml_set_current_symbol(xmlf_symbol* ns);

xmlf_namespace* xml_new_namespace(char* name, xmlf_namespace* p);
void xml_free_namespace(xmlf_namespace* ns);
void xml_dump_namespace(FILE* fp, xmlf_namespace* ns);
void xml_dump_global_namespace(FILE* fp, xmlf_namespace* ns);
void xml_add_symbol(xmlf_namespace* ns, xmlf_symbol* sym);
int  xml_is_global_procedure(xmlf_namespace* ns);
void xml_add_global_procedure(xmlf_namespace* ns);

xmlf_symbol* xml_new_symbol(char* name, xmlf_namespace* ns);
void xml_free_symbol(xmlf_symbol* sym);
void xml_add_component(xmlf_symbol* sym, xmlf_component* comp);

xmlf_component* xml_new_component(char* name);
void xml_free_component(xmlf_component* comp);

xmlf_typespec* xml_typespec_from_ptr(void* ptr);

xmlf_arrayspec* xml_new_arrayspec();
void xml_free_arrayspec(xmlf_arrayspec* as);

xmlf_list* xml_new_list();
void xml_free_list(xmlf_list* l);
void xml_append_item(xmlf_list* l, void* data);
