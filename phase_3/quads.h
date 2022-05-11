#pragma once
#include "symtable.h"

enum iopcode {
	ASSIGN_OP,		ADD_OP,			SUB_OP,
	MUL_OP,			DIV_OP,			MOD_OP,
	UMINUS_OP,		AND_OP,			OR_OP,
	NOT_OP,			IF_EQ_OP,		IF_NOTEQ_OP,
	IF_LESSEQ_OP,	IF_GREATEREQ_OP,IF_LESS_OP,
	IF_GREATER_OP,	CALL_OP,		PARAM_OP,
	RET_OP,			GETRETVAL_OP,	FUNCSTART_OP,
	FUNCEND_OP,		TABLECREATE_OP,	TABLEGETELEM_OP,
	TABLESETELEM_OP,JUMP_OP
};

enum expr_t {
	VAR_E,			TABLEITEM_E,	PROGRAMFUNC_E,
	LIBRARYFUNC_E,	ARITHEXPR_E,	BOOLEXPR_E,
	ASSIGNEXPR_E,	NEWTABLE_E,		CONSTINT_E,
	CONSTSTRING_E,	CONSTDOUBLE_E,	CONSTBOOL_E,
	NIL_E
};

union values {
	int intConst;
	double doubleConst;
	std::string *strConst;
	bool boolConst;
	union values (*f)();
};

struct quad;
struct expr {
	expr_t type;
	st_entry *sym;
	expr *index;
	union values value;
	std::vector<quad*> *truelist;
	std::vector<quad*> *falselist;
	expr(expr *ex);
	expr(expr_t type, st_entry *sym, expr *index, union values value);
}typedef expr;

typedef struct quad {
	iopcode op;
	expr *result;
	expr *arg1;
 	expr *arg2;
	unsigned label;
	unsigned line;
}quad;

std::string new_tmp_name();

void emit(iopcode op, expr *result, expr *arg1, expr *arg2, unsigned label,
		unsigned line);

void print_quads();

unsigned int get_current_quad();

unsigned int get_next_quad();

