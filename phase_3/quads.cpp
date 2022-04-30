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

void print_quads(){
	std::cout << " ------------------------------------------- \n";
    std::cout << "\n";
	int i = 1;
    for (auto v : quad_vec){
		std::cout << i << ": " << v.op << " ";
		if (v.result != NULL){
			std::cout << v.result << " ";
		}
		if (v.arg1 != NULL){
			std::cout << v.arg1->value.intConst << " ";
		}
		if (v.arg2 != NULL){
			std::cout << v.arg2->value.intConst << " ";
		}
		if (v.label != 0){
			std::cout << v.label << " ";
		}
		std::cout << "[line " << v.line << "]\n";
		i++;
    }
    std::cout << " ------------------------------------------- \n";
}

int get_current_quad(){
	return quad_vec.size() + 1;
}