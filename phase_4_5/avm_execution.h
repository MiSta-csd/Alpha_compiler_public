#pragma once
#include "avm_mem_structs.h"
#include "avm_structures.h"
#include "avm_table.h"


#define AVM_STACKENV_SIZE   4
avm_memcell reg_AX, reg_BX, reg_CX;
avm_memcell reg_RETVAL;
unsigned    top,topsp;

double  consts_getnumber (unsigned index);
std::string consts_getstring (unsigned index);
std::string libfuncs_getused (unsigned index);

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg);

typedef void (execute_func_t) (instruction*);

#define AVM_MAX_INSTRUCTIONS (unsigned) NOP_V;

void execute_assign (instruction*);
void execute_add (instruction*);
void execute_sub (instruction*);
void execute_mul (instruction*);
void execute_div (instruction*);
void execute_mod (instruction*);
/*  */
void execute_uminus (instruction*);
void execute_and (instruction*);
void execute_or (instruction*);
void execute_not (instruction*);
/* Minw pushare to na treksw test locally :) */
void execute_jeq (instruction*);
void execute_jne (instruction*);
void execute_jle (instruction*);
void execute_jge (instruction*);
void execute_jlt (instruction*);
void execute_jgt (instruction*);
void execute_call (instruction*);
void execute_pusharg (instruction*);
void execute_funcenter (instruction*);
void execute_funcexit (instruction*);
void execute_newtable (instruction*);
void execute_tablegetelem (instruction*);
void execute_tablesetelem (instruction*);
void execute_nop (instruction*);







