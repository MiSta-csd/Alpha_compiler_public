#pragma once
#include "avm_mem_structs.h"
#include "avm_structures.h"
#include "avm_table.h"
#include "avm_auxiliary.h"


#define AVM_STACKENV_SIZE   4
avm_memcell reg_AX, reg_BX, reg_CX;
avm_memcell reg_RETVAL;
unsigned    top,topsp;

double  consts_getnumber (unsigned index);
std::string consts_getstring (unsigned index);
std::string libfuncs_getused (unsigned index);

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg);

#define N 4096
#define AVM_MAX_INSTRUCTIONS (unsigned) NOP_V
#define AVM_NUMACTUALS_OFFSET   +4
#define AVM_SAVEDPC_OFFSET      +3
#define AVM_SAVEDTOP_OFFSET     +2
#define AVM_SAVEDTOPSP_OFFSET   +1


void execute_assign (instruction*);
void execute_add (instruction*);
void execute_sub (instruction*);
void execute_mul (instruction*);
void execute_div (instruction*);
void execute_mod (instruction*);

/* the following funcs are not needed but exist for possible dispatcher assignments */
void execute_uminus (instruction*);
void execute_and (instruction*);
void execute_or (instruction*);
void execute_not (instruction*);
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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

typedef void (*execute_func_t)(instruction*);

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
	execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
/*     execute_ret,
    execute_getretval, */
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
/*     execute_jump, */
    execute_nop
};

unsigned char   executionFinished = 0;
unsigned        pc = 0;
unsigned        currLine = 0;
unsigned        codeSize = 0;
instruction*    code = (instruction*) 0;

#define AVM_ENDING_PC codeSize

void execute_cycle (void);

void avm_assign (avm_memcell* lv, avm_memcell* rv);

void execute_assign (instruction* instr);

unsigned avm_totalactuals(void);

avm_memcell* avm_getactual (unsigned i);

unsigned avm_get_envvalue(unsigned i);

// void avm_registerlibfunc (char* id, library_func_t addr);




