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
	std::string opcodes[] = {"ASSIGN_O", "ADD_O", "SUB_O", "MUL_O", "DIV_O", "MOD_O", "UMINUS_O", "AND_O",
	"OR_O", "NOT_O", "IF_EQ_O", "IF_NOTEQ_O", "IF_LESSEQ_O", "IF_GREATEREQ_O", "IF_LESS_O", "IF_GREATER_O",
	"CALL_O", "PARAM_O", "RET_O", "GETRETVAL_O", "FUNCSTART_O", "FUNCEND_O", "TABLECREATE_O", "TABLEGETELEM_O",
	"TABLESETELEM_O", "JUMP_O"};
	std::cout << " ------------------------------------------- \n";
    std::cout << "\n";
	int i = 1;
    for (auto v : quad_vec){
		std::cout << i << ": " << opcodes[v.op] << " ";
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
