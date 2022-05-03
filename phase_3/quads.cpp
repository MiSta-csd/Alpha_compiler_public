#include "quads.h"
#include "symtable.h"
#include <assert.h>
#include <vector>

std::vector<quad> quad_vec;

unsigned tmp_var_count = 0;

void emit(iopcode op, expr *result, expr *arg1, expr *arg2, unsigned label,
		unsigned line) {
	quad_vec.push_back({.op = op,
			.result = result,
			.arg1 = arg1,
			.arg2 = arg2,
			.label = label,
			.line = line});
}

/* auxil vector for storing voithitikes metavlhtes */
std::vector<expr*> expr_vec;

expr::expr(expr_t type, st_entry *sym, expr *index, union values value, expr *next) {
	this->type = type;
	this->sym = sym;
	this->index = index;
	this->value = value;
	this->next = next;
}

void print_quads() {
	std::string opcodes[] = {"ASSIGN_O", "ADD_O", "SUB_O", "MUL_O", "DIV_O", "MOD_O", "UMINUS_O", "AND_O",
	"OR_O", "NOT_O", "IF_EQ_O", "IF_NOTEQ_O", "IF_LESSEQ_O", "IF_GREATEREQ_O", "IF_LESS_O", "IF_GREATER_O",
	"CALL_O", "PARAM_O", "RET_O", "GETRETVAL_O", "FUNCSTART_O", "FUNCEND_O", "TABLECREATE_O", "TABLEGETELEM_O",
	"TABLESETELEM_O", "JUMP_O"};
	std::cout << " -------------------------------------------\n\n";
	int i = 1;
    for (auto v : quad_vec){
		std::cout << i << ": " << opcodes[v.op] << " ";
		if (v.result != NULL){
			std::cout << v.result->sym->name << " ";
		}
		if(v.arg1) {
			switch (v.arg1->type) {
				case CONSTINT_E:
					std::cout << v.arg1->value.intConst << " ";
					break;
				case CONSTSTRING_E:
					std::cout << v.arg1->value.strConst << " ";
					break;
				case BOOLEXPR_E:
					std::cout << (v.arg1->value.boolConst == true? "true" : "false") << " ";
					break;
				case NIL_E:
					std::cout << "NIL ";
					break;
				default:
					std::cout << v.arg1->sym->name << " ";
					break;
			}
		}
		if(v.arg2) {
			switch (v.arg2->type) {
				case CONSTINT_E:
					std::cout << v.arg2->value.intConst << " ";
					break;
				case CONSTSTRING_E:
					std::cout << v.arg2->value.strConst << " ";
					break;
				case BOOLEXPR_E:
					std::cout << (v.arg2->value.boolConst == true? "true" : "false") << " ";
					break;
				case NIL_E:
					std::cout << "NIL ";
					break;
				default:
					std::cout << v.arg2->sym->name << " ";
					break;
			}
		}
		if (v.label != 0){
			std::cout << v.label << " ";
		}
		std::cout << "[line " << v.line << "]\n";
		i++;
    }
    std::cout << " ------------------------------------------- \n";
}

int get_current_quad() {
	return quad_vec.size() + 1;
}

expr* insert_expr(expr_t expr_t, st_entry *sym, expr *index, union values val, expr *next) {
	expr *out = new expr(expr_t, sym, index, val, next);
	expr_vec.push_back(out);
	return out;
}

void erase_expressions() {
	// for (unsigned i = 0; i < expr_vec.size(); ++i) {
	// 	free(expr_vec[i]);
	// } // den kanoume free giati trwme skato sto print
	expr_vec.clear();
	tmp_var_count = 0;
}

std::string tmp_expr_name() {
	std::string out = "^" + std::to_string(tmp_var_count++);
	return out;
}
