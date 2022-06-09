#pragma once
#include "avm_mem_structs.h"
#include "avm_structures.h"
#include "avm_table.h"
#include "avm_execution.h"

typedef void (*memclear_func_t) (avm_memcell*);

void memclear_string (avm_memcell* m);
void memclear_table (avm_memcell* m);

memclear_func_t memclearFuncs[] = {
    0, /*  number */
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};

std::string typeStrings[] = {"number", "string", "bool", "table", "userfunc", "libfunc", "nil", "undef"};

void avm_memcellclear (avm_memcell* m);

void avm_warning (std::string s, ...);
void avm_error (std::string s, ...);

double avm_get_numVal(avm_memcell* m);
std::string avm_get_stringVal(avm_memcell* m);
bool avm_get_boolVal(avm_memcell* m);
userfunc avm_get_funcVal(avm_memcell* m);

std::string avm_tostring (avm_memcell* m);

typedef std::string (*tostring_func_t) (avm_memcell*);

std::string number_tostring (avm_memcell* m);
std::string string_tostring (avm_memcell* m);
std::string bool_tostring (avm_memcell* m);
std::string table_tostring (avm_memcell* m);
std::string userfunc_tostring (avm_memcell* m);
std::string libfunc_tostring (avm_memcell* m);
std::string nil_tostring (avm_memcell* m);
std::string undef_tostring (avm_memcell* m);

tostring_func_t tostringFuncs[] = {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring, 
    nil_tostring,
    undef_tostring
};

userfunc* avm_get_funcinfo (unsigned address);

/* bool convertors */
typedef bool (*tobool_func_t) (avm_memcell*);


bool number_tobool (avm_memcell* m) { return m->data.numVal != 0; }
bool string_tobool (avm_memcell* m) { return !(m->data.strVal->empty()); }
bool bool_tobool (avm_memcell* m) { return m->data.boolVal; }
bool table_tobool (avm_memcell* m) { return true; }
bool userfunc_tobool (avm_memcell* m) { return true; }
bool libfunc_tobool (avm_memcell* m) { return true; }
bool nil_tobool (avm_memcell* m) { return false; }
bool undef_tobool (avm_memcell* m) { assert(0); return false; }

tobool_func_t toboolFuncs[] = {
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool, 
    nil_tobool,
    undef_tobool
};

bool avm_tobool (avm_memcell* m);