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

void avm_memcellclear (avm_memcell* m);

void avm_warning (std::string s);
void avm_error (std::string s);

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

