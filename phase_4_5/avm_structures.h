#pragma once
#include <iostream>
#include "quads.h"

enum vmopcode {
    ASSIGN_V,       ADD_V,          SUB_V,
    MUL_V,          DIV_V,          MOD_V,
    UMINUS_V,       AND_V,          OR_V,
    NOT_V,          JEQ_V,          JNE_V,
    JLE_V,          JGE_V,          JLT_V,
    JGT_V,          CALL_V,         PUSHARG_V,
    FUNCENTER_V,    FUNCEXIT_V,     NEWTABLE_V,
    TABLEGETELEM_V, TABLESETELEM_V, NOP_V
};
enum vmarg_t {
    LABEL_A,
    GLOBAL_A,
    FORMAL_A,
    LOCAL_A,
    NUMBER_A,
    STRING_A,
    BOOL_A,
    NIL_A,
    USERFUNC_A,
    LIBFUNC_A,
    RETVAL_A/* ,    UNDEF_A */
};

typedef struct vmarg {
    vmarg_t     type;
    unsigned val;
}vmarg;

struct vminstruction {
    vmopcode    opcode;
    vmarg       result;
    vmarg       arg1;
    vmarg       arg2;
    unsigned    srcLine;
};

struct userfunc {
    unsigned    address;
    unsigned    localSize;
    std::string       id;
};

void make_operand(expr* e, vmarg *arg);
