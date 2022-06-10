#include <iostream>

typedef void (*library_func_t)(void);

typedef struct libPair
{
    char* name;
    void (*lib_function)(void);
    struct libPair* next;
} libPair;

typedef struct libFuncHashTable
{
    libPair** pairs;
    unsigned int size;
}libFuncHashTable;

void libfunc_print (void);

void avm_calllibfunc(char *id);

void libfunc_typeof(void);
