#include "quads.h"
#include <assert.h>
#include <vector>

std::vector<quad> quad_vec;

void emit(iopcode op, expr *result, expr *arg1, expr *arg2, unsigned label,
		unsigned line) {
	quad_vec.push_back({.op = op,
			.result = result,
			.arg1 = arg1,
			.arg2 = arg2,
			.label = label,
			.line = line});
}

expr::expr(expr_t type, st_entry *sym, expr *index, union values value, expr *next) {
	this->type = type;
	this->sym = sym;
	this->index = index;
	this->value = value;
	this->next = next;
}

