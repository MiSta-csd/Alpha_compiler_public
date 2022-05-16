#include "quads.h"
#include "symtable.h"
#include <assert.h>
#include <vector>
#include <string>

std::vector<quad*> quad_vec;

unsigned tmp_var_count = 0;

void emit(iopcode op, expr *result, expr *arg1, expr *arg2, unsigned label,
		unsigned line) {
	quad_vec.push_back(new quad{.op = op,
			.result = result,
			.arg1 = arg1,
			.arg2 = arg2,
			.label = label,
			.line = line});
}

expr::expr() {

}

expr::expr(expr_t type, st_entry *sym, expr *index, union values value) {
	this->type = type;
	this->sym = sym;
	this->index = index;
	this->value = value;
}

void print_quads() {
	std::string opcodes[] = {"ASSIGN_OP", "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP", "MOD_OP", "UMINUS_OP", "AND_OP",
	"OR_OP", "NOT_OP", "IF_EQ_OP", "IF_NOTEQ_OP", "IF_LESSEQ_OP", "IF_GREATEREQ_OP", "IF_LESS_OP", "IF_GREATER_OP",
	"CALL_OP", "PARAM_OP", "RET_OP", "GETRETVAL_OP", "FUNCSTART_OP", "FUNCEND_OP", "TABLECREATE_OP", "TABLEGETELEM_OP",
	"TABLESETELEM_OP", "JUMP_OP"};
	std::cout << " -------------------------------------------\n\n";
	int i = 1;
    for (auto quad : quad_vec){
		std::cout << i << ": " << opcodes[quad->op] << " ";
		if (quad->result != NULL){
			std::cout << quad->result->sym->name << " ";
		}
		if(quad->arg1) {
			if(quad->arg1->sym && quad->arg1->type != CONSTBOOL_E) {
				std::cout << quad->arg1->sym->name << " ";
			}else {
				switch (quad->arg1->type) {
					case CONSTINT_E:
						std::cout << quad->arg1->value.intConst << " ";
						break;
					case CONSTDOUBLE_E:
						std::cout << quad->arg1->value.doubleConst << " ";
						break;
					case CONSTSTRING_E:
						std::cout << "\"" << quad->arg1->value.strConst << "\" ";
						break;
					case CONSTBOOL_E:
						// std::cout << (quad->arg1->value.boolConst == true? "'true'" : "'false'") << " ";
					// 	break;
					case BOOLEXPR_E:
						std::cout << (quad->arg1->value.boolConst == true? "'true'" : "'false'") << " ";
						break;
					case NIL_E:
						std::cout << "NIL";
						break;
					default:
						assert(NULL);
				}
			}
		}
		if(quad->arg2) {
			if(quad->arg2->sym && quad->arg2->type != CONSTBOOL_E) {
				std::cout << quad->arg2->sym->name << " ";
			}else {
				switch (quad->arg2->type) {
					case CONSTINT_E:
						std::cout << quad->arg2->value.intConst << " ";
						break;
					case CONSTDOUBLE_E:
						std::cout << quad->arg2->value.doubleConst << " ";
						break;
					case CONSTSTRING_E:
						std::cout << quad->arg2->value.strConst << " ";
						break;
					case CONSTBOOL_E:
						std::cout << (quad->arg2->value.boolConst == true? "'true'" : "'false'") << " ";
						break;
					case NIL_E:
						std::cout << "NIL";
						break;
					default:
						assert(NULL);
				}
			}
		}
		if (quad->label){
			std::cout << quad->label << " ";
		}
		std::cout << "[line " << quad->line << "]\n";
		i++;
    }
    std::cout << " ------------------------------------------- \n";
}

unsigned int get_current_quad() {
	return quad_vec.size();
}

unsigned int get_next_quad() {
	return quad_vec.size() + 1;
}

void erase_expressions() {
	// for (unsigned i = 0; i < expr_vec.size(); ++i) {
	// 	free(expr_vec[i]);
	// } // den kanoume free giati trwme skato sto print
	tmp_var_count = 0;
}
