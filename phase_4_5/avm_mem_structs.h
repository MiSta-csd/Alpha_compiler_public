#pragma once
#include <iostream>
#include <cstring>



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
        userfunc            funcVal;    /* changed from unsigned */
        std::string        *libfuncVal;     
    }data;
} avm_memcell;

#define AVM_STACKSIZE   4096
#define AVM_WIPEOUT(m)  memset(&(m), 0, sizeof(m))
avm_memcell stack[AVM_STACKSIZE];

#define AVM_STACKENV_SIZE   4
avm_memcell reg_AX, reg_BX, reg_CX;
avm_memcell reg_RETVAL;
unsigned    top,topsp;

static void avm_initstack (void);

unsigned totalActuals = 0;

void avm_dec_top (void);
void avm_push_envvalue (unsigned val);
void avm_callsaveenvironment (void);