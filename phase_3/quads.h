#include <iostream>
#include "symtable.h"

enum iopcode {
	ASSIGN,			ADD,			SUB,
	MUL,			DIV,			MOD,
	UMINUS,			AND,			OR,
	NOT,			IF_EQ,			IF_NOTEQ,
	IF_LESSEQ,		IF_GREATEREQ,	IF_LESS,
	IF_GREATER,		CALL,			PARAM,
	RET,			GETRETVAL,		FUNCSTART,
	FUNCEND,		TABLECREATE,	TABLEGETELEM,
	TABLESETELEM
};

enum expr_t {
	VAR_E,			TABLEITEM_E,	PROGRAMFUNC_E,
	LIBRARYFUNC_E,	ARITHEXPR_E,	BOOLEXPR_E,
	ASSIGNEXPR_E,	NEWTABLE_E,		CONSTNUM_E,
	CONSTBOOL_E,	CONSTSTRING_E,	NIL_E
};

union values {
	int intConst;
	double doubleConst;
	std::string *strConst;
	union values (*f)();
};

struct expr {
	expr_t type;
	st_entry *sym;
	expr *index;
	union values value;
	expr *next;
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

void emit(iopcode op, expr *arg1, expr *arg2, expr *result, unsigned label,
		unsigned line);
