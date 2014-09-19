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
#include <assert.h>
#include "gfortran2xml.h"
/* #include "ptd-parser.yacc.tab.h" */
#include "ptd-parser.tab.h"

xmlf_list* namespaces = 0x0;

xmlf_namespace* current_ns  = 0x0;
xmlf_symbol*    current_sym = 0x0;

static void xml_dump_symbol(FILE* fp, xmlf_symbol* sym);
static void xml_dump_component(FILE* fp, xmlf_component* comp);
static void xml_dump_arg(FILE* fp, xmlf_symbol* sym);
static void xml_dump_return(FILE* fp, xmlf_symbol* sym);
static void xml_dump_type(FILE* fp, xmlf_symbol* sym);
static void xml_dump_typespec(FILE* fp, xmlf_typespec* ts, xmlf_symbol* sym);

static xmlf_symbol*
xml_get_ns_symbol(xmlf_namespace* ns, char* sym_name);

static xmlf_symbol*
xml_get_contained_ns_symbol(xmlf_namespace* ns, char* ns_name, char* sym_name);

static char* xml_intent(xmlf_symbol* sym);

#define MAX_INDENT_LEVELS 9

int xml_level = 0;
int xml_max_level = MAX_INDENT_LEVELS - 1;
char* xml_levels[MAX_INDENT_LEVELS] =
{ "", "  ", "    ", "      ", "        ", "          "
    , "            ", "              ", "                " };

char* ws = "";

static int xml_increase_level()
{
  assert(xml_level < xml_max_level);
  xml_level += 1;
  ws = xml_levels[xml_level];
}

static int xml_decrease_level()
{
  assert(xml_level > 0);
  xml_level -= 1;
  ws = xml_levels[xml_level];
}

void xml_open_file(FILE* fp)
{
   fprintf(fp, "<?xml version=\"1.0\"?>\n");
   /* commented the next line out because I don't think
    * it's necessary.  --Rickett, 07.13.05
    */
/*   fprintf(fp, "<!DOCTYPE library SYSTEM \"mapping.dtd\">\n"); */
  fprintf(fp, "\n");
}

void xml_close_file(FILE* fp)
{
}

void xml_open_library(FILE* fp, char* filename, char* language)
{
  fprintf(fp, "<library lang=\"%s\" version=\"2\" name=\"%s\">\n",
	  language, filename);
  fprintf(fp, "\n");
  xml_increase_level();
}

void xml_close_library(FILE* fp)
{
  xml_decrease_level();
  fprintf(fp, "</library>\n");
}

void xml_open_includes(FILE* fp)
{
  fprintf(fp, "<!-- include files that the topmost file includes -->\n");
}

void xml_close_includes(FILE* fp)
{
}

void xml_open_modules(FILE* fp)
{
  fprintf(fp, "<!-- fortran module scopes -->\n");
  fprintf(fp, "\n");
}

void xml_close_modules(FILE* fp)
{
}

void xml_open_module(FILE* fp, char* name)
{
  fprintf(fp, "%s<!--\n", ws);
  fprintf(fp, "%s  - MODULE: %s\n", ws, name);
  fprintf(fp, "%s  -->\n", ws);
  fprintf(fp, "%s<scope name=\"%s\" kind=\"module\">\n", ws, name);
  fprintf(fp, "\n");
  xml_increase_level();
}

void xml_close_module(FILE* fp)
{
  xml_decrease_level();
  fprintf(fp, "%s</scope>\n", ws);
  fprintf(fp, "\n");
}

void xml_open_derived_type(FILE* fp, char* name)
{
  fprintf(fp, "%s<!--\n", ws);
  fprintf(fp, "%s  - User defined type : %s\n", ws, name);
  fprintf(fp, "%s  -->\n", ws);
  fprintf(fp, "%s<structure name=\"%s\" kind=\"ftype\">\n", ws, name);
  fprintf(fp, "\n");
  xml_increase_level();
}

void xml_close_derived_type(FILE* fp)
{
  xml_decrease_level();
  fprintf(fp, "%s</structure>\n", ws);
  fprintf(fp, "\n");
}

void xml_open_method(FILE* fp, char* name, char* ns_name)
{
  fprintf(fp, "%s<!--\n", ws);
  if (ns_name) {
    fprintf(fp, "%s  - METHOD: %s::%s\n", ws, ns_name, name);
  } else {
    fprintf(fp, "%s  - METHOD: %s\n", ws, name);
  }
  fprintf(fp, "%s  -->\n", ws);
  fprintf(fp, "%s<method name=\"%s\" kind=\"static\">\n", ws, name);
  fprintf(fp, "\n");
  xml_increase_level();
}

void xml_close_method(FILE* fp)
{
  xml_decrease_level();
  fprintf(fp, "%s</method>\n", ws);
  fprintf(fp, "\n");
}


xmlf_namespace* xml_current_namespace()
{
  return current_ns;
}

void xml_set_current_namespace(xmlf_namespace* ns)
{
  current_ns = ns;
}

xmlf_symbol* xml_current_symbol()
{
  return current_sym;
}

void xml_set_current_symbol(xmlf_symbol* sym)
{
  current_sym = sym;
}


xmlf_namespace* xml_new_namespace(char* name, xmlf_namespace* pre)
{
  xmlf_namespace* ns = (xmlf_namespace*) malloc(sizeof(xmlf_namespace));
  assert(ns);
  strcpy(ns->name, name);
  ns->previous = pre;
  ns->next = 0;
  ns->proc_sym = 0;
  ns->sym_head = ns->sym_tail = 0;
  if (pre) {
    assert(pre->next == 0);
    pre->next = ns;
  }
  return ns;
}

void xml_free_namespace(xmlf_namespace* ns)
{
  xmlf_symbol* sym = ns->proc_sym;
  if (sym != 0) {
    xml_free_symbol(sym);
  }
  sym = ns->sym_head;
  while(sym != 0) {
    xmlf_symbol* next = sym->next;
    xml_free_symbol(sym);
    sym = next;
  }
  if (ns->next) {
    xml_free_namespace(ns->next);
  }
  free(ns);
}

void xml_add_namespace(xmlf_namespace* ns)
{
  if (namespaces == 0x0) {
    namespaces = xml_new_list();
  }
  xml_append_item(namespaces, ns);
}

void xml_dump_global_namespace(FILE* fp, xmlf_namespace* ns)
{
  if (ns->sym_head != 0) {
    fprintf(fp, "<!-- types and functions NOT contained in a scope -->\n");
    fprintf(fp, "\n");
    xml_dump_namespace(fpxml, ns);
  }
}

void xml_dump_namespace(FILE* fp, xmlf_namespace* ns)
{
  xmlf_symbol* sym = ns->sym_head;

  xml_open_module(fp, ns->name);

  while(sym != 0) {
    if (sym->attr.flavor == DERIVED) {
      xml_dump_symbol(fp, sym);
    }
    sym = sym->next;
  }

  sym = ns->proc_sym;
  if (sym != 0) {
     if (sym->attr.flavor == PROCEDURE) {
/*         if(strcmp(sym->name, "zoo") == 0) */
/*            fprintf(stderr, "\n\ngoing to dump symbol zoo\n\n"); */
      xml_dump_symbol(fp, sym);
    }
  }

  sym = ns->sym_head;
/*   if(sym->attr.flavor == PROCEDURE && sym->formal == NULL) */
/*      xml_dump_symbol(fp, sym); */
/*   sym = sym->next; */
  while (sym != 0) {
     if (sym->attr.flavor == PROCEDURE) {
/*         if(sym->formal != NULL) */
/*         { */
/*            fprintf(stderr, "\n\ngoing to dump a symbol %s w/ formal " */
/*                    "list in namespace %s\n\n", sym->name, ns); */
/*         } */
/*         if(strcmp(sym->name, "foo") == 0) */
/*            fprintf(stderr, "\n\ngoing to dump symbol foo\n\n"); */
/*         if(strcmp(sym->name, "zoo") == 0) */
/*            fprintf(stderr, "\n\ngoing to dump symbol zoo\n\n"); */
        /* i put the call under the if.  --Rickett, 09.08.05 */
/*         if(sym->formal == NULL) */
           xml_dump_symbol(fp, sym);
    }
    sym = sym->next;
  }

  xml_close_module(fp);
}

void xml_add_symbol(xmlf_namespace* ns, xmlf_symbol* sym)
{
  if (strcmp(ns->name, sym->name) == 0) {
    assert(ns->proc_sym == 0);
    ns->proc_sym = sym;
    return;
  }

  if (ns->sym_head == 0) {
    ns->sym_head = ns->sym_tail = sym;
  } else {
    ns->sym_tail->next = sym;
    ns->sym_tail = sym;
  }
  sym->next = 0;
}

int xml_is_global_procedure(xmlf_namespace* ns)
{
  xmlf_symbol* sym = ns->proc_sym;

  if (sym && sym->attr.flavor == PROCEDURE) {
    assert (ns->previous == 0);
    return 1;
  }
  return 0;
}

void xml_add_global_procedure(xmlf_namespace* ns)
{
  xmlf_namespace* tmp;
  xmlf_namespace* global = namespaces->items[0];

  assert(namespaces->len > 0);

  /* I don't think global procedures should have links */

  assert(ns->previous == 0);
  assert(ns->next == 0);

  /* insert namespace at end of globals list */

  tmp = global;
  while (tmp) {
    if (tmp->next == 0) break;
    tmp = tmp->next;
  }
  tmp->next = ns;
  ns->previous = tmp;

  assert(ns->proc_sym);

  if (global->sym_head == 0) global->sym_head = ns->proc_sym;
  if (global->sym_tail == 0) {
    global->sym_tail = ns->proc_sym;
  } else {
    assert(global->sym_tail->next == 0);
    global->sym_tail->next = ns->proc_sym;
    global->sym_tail = ns->proc_sym;
  }
}

xmlf_symbol* xml_get_symbol(char* name)
{
  int i;
  xmlf_list* l = namespaces;

  if (name  == '\0') return 0;

  for (i = 0; i < l->len; i++) {
    xmlf_namespace* ns = (xmlf_namespace*) l->items[i];
    xmlf_symbol* sym = xml_get_ns_symbol(ns, name);
    if (sym) return sym;
  }    
  return 0;
}

static xmlf_symbol* xml_get_ns_symbol(xmlf_namespace* ns, char* name)
{
  xmlf_symbol* sym = ns->proc_sym;

  if (name  == '\0') return 0;

  if (sym && strcmp(sym->name, name) == 0) {
    return sym;
  }

  sym = ns->sym_head;
  while (sym) {
    if (strcmp(sym->name, name) == 0) {
      return sym;
    } else {
      sym = sym->next;
    }
  }
  return 0;
}

static xmlf_symbol*
xml_get_contained_ns_symbol(xmlf_namespace* ns, char* ns_name, char* sym_name)
{
  xmlf_namespace* contained = ns->next;

  if (ns_name  == '\0') return 0;
  if (sym_name == '\0') return 0;

  while (contained) {
    if (strcmp(contained->name, ns_name) == 0) {
      xmlf_symbol* sym = xml_get_ns_symbol(contained, sym_name);
      /* need to check from namespace == ns->name ? */
      if (sym) return sym;
      else     return 0;
    } else {
      contained = contained->next;
    }
  }
  return 0;
}

xmlf_symbol* xml_new_symbol(char* name, xmlf_namespace* ns)
{
  xmlf_symbol* sym = (xmlf_symbol*) malloc(sizeof(xmlf_symbol));
  assert(sym);
  strcpy(sym->name, name);

  sym->value       = 0;
  sym->as          = 0;
  sym->generic     = 0;
  sym->common_head = 0;
  sym->result      = 0;
  sym->formal      = 0;
  sym->formal_ns   = 0;

  sym->ns = ns;
  sym->next = 0;
  sym->comp_head = 0;
  sym->comp_tail = 0;
  sym->attr.n_bit_attributes = 0;
  return sym;
}

void xml_free_symbol(xmlf_symbol* sym)
{
  xmlf_component *next;

  if (sym->value) free(sym->value);
  if (sym->as) xml_free_arrayspec(sym->as);
  if (sym->generic) xml_free_list(sym->generic);
  if (sym->common_head) xml_free_list(sym->common_head);
  if (sym->result) free(sym->result);
  if (sym->formal) xml_free_list(sym->formal);
  if (sym->formal_ns) xml_free_namespace(sym->formal_ns);

  next = sym->comp_head;
  while (next) {
    xmlf_component* tmp = next->next;
    xml_free_component(next);
    next = tmp;
  }

  free(sym);
}

static void xml_dump_symbol(FILE* fp, xmlf_symbol* sym)
{
  if (sym->attr.flavor == DERIVED) {
    xmlf_component* comp = sym->comp_head;
    xml_open_derived_type(fp, sym->name);
    while (comp) {
      xml_dump_component(fp, comp);
      comp = comp->next;
    }
    xml_close_derived_type(fp);
  }

  if (sym->attr.flavor == PROCEDURE) {
    int i;
    xmlf_symbol* proc_sym;

    /* ignore implicit procedures */
    for(i = 0; i < sym->attr.n_bit_attributes; i++) {
      if (sym->attr.bit_attributes[i] == IMPLICIT_TYPE) return;
    }

    if (sym->attr.procedures == PROC_MODULE ||
        sym->attr.procedures == PROC_UNKNOWN) {
      if (sym->attr.procedures == PROC_MODULE) {
	xml_open_method(fp, sym->name, sym->ns->name);
      } else {
	xml_open_method(fp, sym->name, 0);
      }
      if (sym->formal) {
	char** names = (char**) ((xmlf_list*) sym->formal)->items;
	char* name = *names;
	while (name) {
	  if (sym->attr.procedures == PROC_MODULE) {
	    proc_sym = xml_get_contained_ns_symbol(sym->ns, sym->name, name);
	  } else {
	    proc_sym = xml_get_ns_symbol(sym->ns, name);
	  }
	  assert(proc_sym);
	  xml_dump_arg(fp, proc_sym);
	  name = *(++names);
	}
      }
      xml_dump_return(fp, sym);
      xml_close_method(fp);
    }
  }
}

static void xml_dump_arg(FILE* fp, xmlf_symbol* sym)
{
  int i, isPtr = 0;

  for (i = 0; i < sym->attr.n_bit_attributes; i++) {
    if (sym->attr.bit_attributes[i] == POINTER) {
      isPtr = 1;
      break;
    }
  }

  fprintf(fp, "%s<!-- ARGUMENT : %s -->\n", ws, sym->name);
  fprintf(fp, "%s<arg name=\"%s\" intent=\"%s\">\n", ws, sym->name
	    , xml_intent(sym));

  if (isPtr) {
    xml_increase_level();
    fprintf(fp, "%s<type kind=\"fptr\">\n", ws);
    xml_increase_level();
    fprintf(fp, "%s<indirect depth=\"1\" kind=\"pointer\">\n", ws);
  }

  if (sym->as) {
    int i;
    int rank = sym->as->rank;

    xml_increase_level();
    fprintf(fp, "%s<type kind=\"farray\">\n", ws);
    xml_increase_level();
    fprintf(fp, "%s<array lang=\"fortran\" rank=\"%d\">\n", ws, rank);
    
    xml_increase_level();
    xml_dump_typespec(fp, &sym->ts, sym);
    for (i = 0; i < rank; i++) {
      if (sym->as->lb[i] == XMLF_ARRAY_NODEF  ||
          sym->as->lb[i] == XMLF_ARRAY_VARDEF ||
          sym->as->ub[i] == XMLF_ARRAY_NODEF  ||
          sym->as->ub[i] == XMLF_ARRAY_VARDEF   ) {
	fprintf(fp, "%s<dimension extent=\"*\"/>\n", ws);
      } else {
	int extent = 1 + sym->as->ub[i] - sym->as->lb[i];
	fprintf(fp, "%s<dimension extent=\"%d\"/>\n", ws, extent);
      }
    }
    xml_decrease_level();
  } else {
    xml_increase_level();
    xml_dump_type(fp, sym);
    /*    xml_dump_typespec(fp, &comp->ts, comp->sym); */
    xml_decrease_level();
  }

  if (sym->as) {
    fprintf(fp, "%s</array>\n", ws);
    xml_decrease_level();
    fprintf(fp, "%s</type>\n", ws);
    xml_decrease_level();
  }

  if (isPtr) {
    fprintf(fp, "%s</indirect>\n", ws);
    xml_decrease_level();
    fprintf(fp, "%s</type>\n", ws);
    xml_decrease_level();
  }

  fprintf(fp, "%s</arg>\n", ws);
  fprintf(fp, "\n");
}

static void xml_dump_return(FILE* fp, xmlf_symbol* sym)
{
  int i, is_function = 0;

  fprintf(fp, "%s<!-- return value -->\n", ws);
  for (i = 0; i < sym->attr.n_bit_attributes; i++) {
    if (sym->attr.bit_attributes[i] == FUNCTION) {
      is_function = 1;
      break;
    }
  }
  if (is_function) {
    fprintf(fp, "%s<return>\n", ws);
    xml_increase_level();
    xml_dump_type(fp, sym);
    xml_decrease_level();
    fprintf(fp, "%s</return>\n", ws);
  } else {
    fprintf(fp, "%s<return>\n", ws);
    xml_increase_level();
    fprintf(fp, "%s<type kind=\"fvoid\"/>\n", ws);
    xml_decrease_level();
    fprintf(fp, "%s</return>\n", ws);
  }
}

static void xml_dump_type(FILE* fp, xmlf_symbol* sym)
{
  xml_dump_typespec(fp, &sym->ts, sym);
}

static char* xml_intent(xmlf_symbol* sym)
{
  switch(sym->attr.intent) {
    case INTENT_IN:		return "in";
    case INTENT_OUT:		return "out";
    case INTENT_INOUT:		return "inout";
    case INTENT_UNKNOWN:	return "inout";
  }
  return "ERROR: INTENT incorrect";
}


void xml_add_component(xmlf_symbol* sym, xmlf_component* comp)
{
  if (sym->comp_head == 0) {
    sym->comp_head = sym->comp_tail = comp;
  } else {
    sym->comp_tail->next = comp;
    sym->comp_tail = comp;
  }
  comp->next = 0;
}

xmlf_component* xml_new_component(char* name)
{
  xmlf_component* comp = (xmlf_component*) malloc(sizeof(xmlf_component));
  assert(comp);
  strcpy(comp->name, name);
  comp->next = 0;
  comp->pointer = 0;
  comp->as = 0;
  return comp;
}

void xml_free_component(xmlf_component* comp)
{
  if (comp->as) xml_free_arrayspec(comp->as);
  free(comp);
}

static void xml_dump_component(FILE* fp, xmlf_component* comp)
{
  fprintf(fp, "%s<!--FIELD: %s -->\n", ws, comp->name);
  fprintf(fp, "%s<field name=\"%s\">\n", ws, comp->name);

  if (comp->pointer) {
    xml_increase_level();
    fprintf(fp, "%s<type kind=\"fptr\">\n", ws);
    xml_increase_level();
    fprintf(fp, "%s<indirect depth=\"1\" kind=\"pointer\">\n", ws);
  }

  if (comp->as) {
    int i;
    int rank = comp->as->rank;

    xml_increase_level();
    fprintf(fp, "%s<type kind=\"farray\">\n", ws);
    xml_increase_level();
    fprintf(fp, "%s<array lang=\"fortran\" rank=\"%d\">\n", ws, rank);
    
    xml_increase_level();
    xml_dump_typespec(fp, &comp->ts, comp->sym);
    for (i = 0; i < rank; i++) {
      if (comp->as->lb[i] == XMLF_ARRAY_NODEF ||
          comp->as->ub[i] == XMLF_ARRAY_NODEF) {
	fprintf(fp, "%s<dimension extent=\"*\"/>\n", ws);
      } else {
	int extent = 1 + comp->as->ub[i] - comp->as->lb[i];
	fprintf(fp, "%s<dimension extent=\"%d\"/>\n", ws, extent);
      }
    }
    xml_decrease_level();
  } else {
    xml_increase_level();
    xml_dump_typespec(fp, &comp->ts, comp->sym);
    xml_decrease_level();
  }

  if (comp->as) {
    fprintf(fp, "%s</array>\n", ws);
    xml_decrease_level();
    fprintf(fp, "%s</type>\n", ws);
    xml_decrease_level();
  }

  if (comp->pointer) {
    fprintf(fp, "%s</indirect>\n", ws);
    xml_decrease_level();
    fprintf(fp, "%s</type>\n", ws);
    xml_decrease_level();
  }

  fprintf(fp, "%s</field>\n", ws);
  fprintf(fp, "\n");
}

xmlf_typespec* xml_typespec_from_ptr(void* ptr)
{
  /* HACK WARNING */
  /* this must work for both xmlf_symbol and xmlf_component */
  /* and requires that location of ts is the same in each type */

  return &((xmlf_symbol*) ptr)->ts;
}


static void
xml_dump_typespec(FILE* fp, xmlf_typespec* ts, xmlf_symbol* sym)
{
  fprintf(fp, "%s<type kind=", ws);
  switch (ts->typename) {
    case INTEGER:
      fprintf(fp, "\"fint\" ikind=");
      switch (ts->kind_or_len) {
        case 1: fprintf(fp, "\"char\"/>\n");  break;
        case 2: fprintf(fp, "\"short\"/>\n");  break;
        case 4: fprintf(fp, "\"int\"/>\n");  break;
        case 8: fprintf(fp, "\"long\"/>\n");  break;
        default: assert("NOT IMPLEMENTED" == 0);
      }
      break;
    case REAL:
      fprintf(fp, "\"ffloat\" fkind=");
      switch (ts->kind_or_len) {
        case 4: fprintf(fp, "\"float\"/>\n");  break;
        case 8: fprintf(fp, "\"dbl\"/>\n");  break;
        default: assert("NOT IMPLEMENTED" == 0);
      }
      break;
    case COMPLEX:
      fprintf(fp, "\"fcmplx\" fkind=");
      switch (ts->kind_or_len) {
        case 4: fprintf(fp, "\"float\"/>\n");  break;
        case 8: fprintf(fp, "\"dbl\"/>\n");  break;
        default: assert("NOT IMPLEMENTED" == 0);
      }
      break;
    case LOGICAL:
      fprintf(fp, "\"flogic\" ikind=");
      switch (ts->kind_or_len) {
        case 1: fprintf(fp, "\"char\"/>\n");  break;
        case 2: fprintf(fp, "\"short\"/>\n");  break;
        case 4: fprintf(fp, "\"int\"/>\n");  break;
        case 8: fprintf(fp, "\"long\"/>\n");  break;
        default: assert("NOT IMPLEMENTED" == 0);
      }
      break;
    case CHARACTER:
      fprintf(fp, "\"fchar\" ikind=\"char\" clen=");
      if (ts->kind_or_len == 0) {
        fprintf(fp, "\"*\"/>\n");
      } else if (ts->kind_or_len > 0) {
        fprintf(fp, "\"%d\"/>\n", ts->kind_or_len);
      } else {
	printf("kind_or_len = %d\n", ts->kind_or_len);
	assert("NOT IMPLEMENTED" == 0);
      }
      break;
    case DERIVED: {
      xmlf_symbol* ts_sym = xml_get_symbol(ts->name);
      fprintf(fp, "\"usertype\" usertype=\"%s\" context=\"%s\"/>\n"
                , ts->name, ts_sym->ns);
      break;
    }
    case PROCEDURE:
    case UNKNOWN:
    default: assert("NOT IMPLEMENTED" == 0);
  }
}

xmlf_arrayspec* xml_new_arrayspec()
{
  xmlf_arrayspec* as = (xmlf_arrayspec*) malloc(sizeof(xmlf_arrayspec));
  assert(as);
  return as;
}

void xml_free_arrayspec(xmlf_arrayspec* as)
{
  free(as);
}

xmlf_list* xml_new_list()
{
  xmlf_list* l = (xmlf_list*) malloc(sizeof(xmlf_list));
  assert(l);
  l->n_max = XMLF_INITIAL_LIST_LEN;
  l->items = (void**) malloc(l->n_max*sizeof(void*));
  assert(l->items);
  l->items[0] = '\0';
  l->len = 0;
  return l;
}

void xml_free_list(xmlf_list* l)
{
  /* free contained items? */
  free(l->items);
  free(l);
}

void xml_append_item(xmlf_list* l, void* item)
{
  if (l->len > l->n_max - 2) {
    /* must save for '\0' element at end */
    l->n_max *= 2;
    l->items = (void**) realloc(l->items, l->n_max*sizeof(void*));
    assert(l->items);
  }
  l->items[l->len] = item;
  l->len += 1;
  l->items[l->len] = '\0';	/* must work for name list as well */
}
