#include <iostream>
#include "avm_table.h"

typedef void (*library_func_t)(void);

// typedef struct libPair
// {
//     char* name;
//     void (*lib_function)(void);
//     struct libPair* next;
// } libPair;

// typedef struct libFuncHashTable
// {
//     libPair** pairs;
//     unsigned int size;
// }libFuncHashTable;

void libfunc_print (void);

void avm_calllibfunc(char *id);

void libfunc_typeof(void);

void libfunc_input(void);

void libfunc_objectmemberkeys(avm_table t);
