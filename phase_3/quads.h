#include <iostream>
#include "symtable.h"

enum iopcode {
	ASSIGN_O,			ADD_O,			SUB_O,
	MUL_O,				DIV_O,			MOD_O,
	UMINUS_O,			AND_O,			OR_O,
	NOT_O,				IF_EQ_O,		IF_NOTEQ_O,
	IF_LESSEQ_O,		IF_GREATEREQ_O,	IF_LESS_O,
	IF_GREATER_O,		CALL_O,			PARAM_O,
	RET_O,				GETRETVAL_O,	FUNCSTART_O,
	FUNCEND_O,			TABLECREATE_O,	TABLEGETELEM_O,
	TABLESETELEM_O,		JUMP_O
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

struct expr {
	expr_t type;
	st_entry *sym;
	expr *index;
	union values value;
	expr *next;
	// constructor
	expr(expr_t type, st_entry *sym, expr *index, union values value, expr *next);
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

void emit(iopcode op, expr *arg1, expr *arg2, expr *result, unsigned label,
		unsigned line);

void print_quads();

int get_current_quad();

expr* insert_expr(expr_t expr_t, st_entry *sym, expr *index, union values val, expr *next);

/* after we read a stmt the expr_vec is no longer needed and we truncate it */
void erase_expressions();
