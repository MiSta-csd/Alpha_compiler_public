#pragma once
#include <iostream>
#include <cstring>
#define AVM_STACKSIZE   4096
#define AVM_WIPEOUT(m)  memset(&(m), 0, sizeof(m))

enum avm_memcell_t {
        NUMBER_M    =0,
        STRING_M    =1,
        BOOL_M,
        TABLE_M,
        USERFUNC_M,
        LIBFUNC_M,
        NIL_M,
        UNDEF_M
};

struct avm_table; // defined in avm_table.h
typedef struct avm_memcell {
    avm_memcell_t   type;
    union data{
        double              numVal;
        std::string        *strVal;
        bool                boolVal;
        struct avm_table   *tableVal;
        unsigned            funcVal;
        std::string        *libfuncVal;     
    }data;
} avm_memcell;

static void avm_initstack (void);
