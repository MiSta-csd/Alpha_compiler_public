#include "quads.h"
#include "symtable.h"
#include <assert.h>
#include <vector>

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

/* auxil vector for storing voithitikes metavlhtes */
std::vector<expr*> expr_vec;

expr::expr(expr *ex) {
	this->type = ex->type;
	this->sym = ex->sym;
	this->index = ex;
	this->value = ex->value;
}

expr::expr(expr_t type, st_entry *sym, expr *index, union values value) {
	this->type = type;
	this->sym = sym;
	this->index = index;
	this->value = value;
}

void print_quads() {
	std::string opcodes[] = {"ASSIGN_O", "ADD_O", "SUB_O", "MUL_O", "DIV_O", "MOD_O", "UMINUS_O", "AND_O",
	"OR_O", "NOT_O", "IF_EQ_O", "IF_NOTEQ_O", "IF_LESSEQ_O", "IF_GREATEREQ_O", "IF_LESS_O", "IF_GREATER_O",
	"CALL_O", "PARAM_O", "RET_O", "GETRETVAL_O", "FUNCSTART_O", "FUNCEND_O", "TABLECREATE_O", "TABLEGETELEM_O",
	"TABLESETELEM_O", "JUMP_O"};
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

int get_current_quad() {
	return quad_vec.size() + 1;
}

expr* insert_expr(expr_t expr_t, st_entry *sym, expr *index, union values val) {
	expr *out = new expr(expr_t, sym, index, val);
	// expr_vec.push_back(out);
	return out;
}

void erase_expressions() {
	// for (unsigned i = 0; i < expr_vec.size(); ++i) {
	// 	free(expr_vec[i]);
	// } // den kanoume free giati trwme skato sto print
	// expr_vec.clear();
	tmp_var_count = 0;
}

std::string new_tmp_name() {
	std::string out = "^" + std::to_string(tmp_var_count++);
	return out;
}
