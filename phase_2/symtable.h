#ifndef SYMTABLE_H
#define SYMTABLE_H


#include <iostream>
#include <ostream>
#include <assert.h>
#include <vector>
#include <cassert>



enum st_entry_type {
	GLOBAL_VAR = 0,
	FORMAL_ARG,
	LOCAL_VAR,
	LIB_FUNC,
	USER_FUNC
};


struct st_entry {
	bool active;
	std::string name;
	enum st_entry_type type;
	std::vector<st_entry*> *argList;	// Formal Arguments list
										// in case of function
	unsigned int scope;
	int line;
} typedef st_entry;



/* TODO */ // insert, lookup, hide

st_entry* st_insert(std::string name_input, enum st_entry_type type_input);

std::string st_godfather();

/* increases scope */
void st_increase_scope();

/* decreases scope */
void st_decrease_scope();

/* self explainatory */
unsigned int st_get_scope();

/* 	performs search in order:
	- through locals
	- through argList buffer
	- high to low every scope (only non formals)*/
st_entry* st_lookup(std::string);


st_entry* st_lookup(std::string name_input, unsigned int scope_input);

int st_hide(unsigned int scope_input);

int load_2_arglist(struct st_entry* arg);

int offload_arglist(st_entry* func);

void st_set_in_funcdef(bool b);

bool st_get_in_funcdef();

void st_initialize();

void st_print_table();

void st_freeAll();


#endif


