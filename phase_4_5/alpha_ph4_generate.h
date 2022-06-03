#pragma once
#include "quads.h"

void generate_ASSIGN(quad*);
void generate_ADD(quad*);
void generate_SUB(quad*);
void generate_MUL(quad*);
void generate_DIV(quad*);
void generate_MOD(quad*);
void generate_NOP(quad*);// UMINUS i-code is handled with MUL -1 
void generate_AND(quad*);
void generate_OR(quad*);
void generate_NOT(quad*);
void generate_IF_EQ(quad*);
void generate_IF_NOTEQ(quad*);
void generate_IF_LESSEQ(quad*);
void generate_IF_GREATEREQ(quad*);
void generate_IF_LESS(quad*);
void generate_IF_GREATER(quad*);
void generate_IF_CALL(quad*);
void generate_IF_PARAM(quad*);
void generate_IF_RET(quad*);
void generate_IF_GETRETVAL(quad*);
void generate_IF_FUNCSTART(quad*);
void generate_IF_FUNCEND(quad*);
void generate_IF_TABLECREATE(quad*);
void generate_IF_TABLEGETELEM(quad*);
void generate_IF_TABLESETELEM(quad*);
void generate_IF_JUMP(quad*);

typedef void (*generator_func_t) (quad*);// generator_func_p is a pointer to func with param quad* ret/ing void

void generate();
