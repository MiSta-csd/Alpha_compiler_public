#include "actions.h"
#include <assert.h>

extern unsigned tmp_var_count;
extern std::vector<quad*> quad_vec;
extern int yylineno;

bool check_arith (expr* e, std::string context) {
	if (e->type == CONSTBOOL_E ||
		e->type == CONSTSTRING_E ||
		e->type == NIL_E ||
		e->type == NEWTABLE_E ||
		e->type == PROGRAMFUNC_E ||
		e->type == LIBRARYFUNC_E ||
		e->type == BOOLEXPR_E ) {
		std::cout << "\033[31m" << "ERROR " << "\033[37m" <<
		"Illegal expr " << exp_type_to_string(e) << " used in " << context << "!\n";
		return false;
	}
	return true;
}

expr* expr_compare_expr(expr *arg1, enum iopcode opcode, expr *arg2) {
	st_entry *st_tmp_entry;
	std::string tmp_name;
	if(tmp_var_count)
		tmp_name = "^" + std::to_string(tmp_var_count-1);
	else
		tmp_name = new_tmp_name();
	if(!(st_tmp_entry = st_lookup(tmp_name) )) {
		st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
	}
	union values val;
	expr *expr_pt = new expr(BOOLEXPR_E, st_tmp_entry, NULL, val);
	expr_pt->truelist = new std::vector<quad*>();
	expr_pt->falselist = new std::vector<quad*>();
	emit(opcode, NULL, arg1, arg2, 0, yylineno);
	expr_pt->truelist->push_back(quad_vec[quad_vec.size()-1]);
	emit(JUMP_O, NULL, NULL, NULL, 0, yylineno);
	expr_pt->falselist->push_back(quad_vec[quad_vec.size()-1]);
	return expr_pt;
}

expr* expr_action_expr(expr *arg1, enum iopcode opcode, expr *arg2, std::string context) {
	expr *res;
	bool is_arith = check_arith(arg1, context) && check_arith(arg2, context);
	if (is_arith) {
		st_entry *st_tmp_entry;
		std::string tmp_name;
		if(tmp_var_count)
			tmp_name = "^" + std::to_string(tmp_var_count-1);
		else
			tmp_name = new_tmp_name();
		if(!(st_tmp_entry = st_lookup(tmp_name) )) {
			st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
		}
		union values val;
		int val_1, val_2;
		expr_t type = CONSTINT_E;
		if(arg1->type == CONSTDOUBLE_E){
			val_1 = (int)arg1->value.doubleConst;
			type = CONSTDOUBLE_E;
		}else {
			val_1 = arg1->value.intConst;
		}
		if(arg2->type == CONSTDOUBLE_E){
			val_2 = (int)arg2->value.doubleConst;
			type = CONSTDOUBLE_E;
		}else {
			val_2 = arg2->value.intConst;
		}

		enum iopcode prev_op;// gia na borei na douleyei h veltistopoihsh swsta
		if(quad_vec.size()){
			prev_op = quad_vec[quad_vec.size()-1]->op;
		}else { prev_op = opcode;}
		
		if(opcode == MOD_O){
			if(type == CONSTDOUBLE_E) {
				val.doubleConst = (double)(val_1 % val_2);
			}else {
				val.intConst = val_1 % val_2;
			}
			if(prev_op == SUB_O || prev_op == ADD_O) {
				tmp_name = new_tmp_name();
				if( !(st_tmp_entry = st_lookup(tmp_name) )) {
					st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
				}
			}
		}else {// OLOI OI ELEGXOI ME DOUBLE INT EINAI KYRIWS GIA NA PROSDIORISW TON TELIKO TYPO sto union ALLA KAI GIA NA EPITREPSW MOD ME FLOAT
			switch(opcode){
				case ADD_O:
					if(type == CONSTINT_E){
						val.intConst = val_1 + val_2;
					}else {
						if(arg1->type == CONSTINT_E)
							val.doubleConst = (double)val_1 + arg2->value.doubleConst;
						else if(arg2->type == CONSTINT_E)
							val.doubleConst = (double)val_2 + arg1->value.doubleConst;
						else
							val.doubleConst = arg1->value.doubleConst + arg2->value.doubleConst;
					}
					break;
				case SUB_O:
					if(type == CONSTINT_E){
						val.intConst = val_1 - val_2;
					}else {
						if(arg1->type == CONSTINT_E)
							val.doubleConst = (double)val_1 - arg2->value.doubleConst;
						else if(arg2->type == CONSTINT_E)
							val.doubleConst = arg1->value.doubleConst - (double)val_2;
						else
							val.doubleConst = arg1->value.doubleConst - arg2->value.doubleConst;
					}
					break;
				case MUL_O:
					if(type == CONSTINT_E) {
						val.intConst = val_1 * val_2;
					}else {
						if(arg1->type == CONSTINT_E)
							val.doubleConst = (double)val_1 * arg2->value.doubleConst;
						else if(arg2->type == CONSTINT_E)
							val.doubleConst = (double)val_2 * arg1->value.doubleConst;
						else
							val.doubleConst = arg1->value.doubleConst * arg2->value.doubleConst;
					}
					if(prev_op == SUB_O || prev_op == ADD_O) {
						tmp_name = new_tmp_name();
						if( !(st_tmp_entry = st_lookup(tmp_name) )) {
							st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
						}
					}
					break;
				case DIV_O:
					if(type == CONSTINT_E){
						val.intConst = val_1 / val_2;
					}else {
						if(arg1->type == CONSTINT_E)
							val.doubleConst = (double)val_1 / arg2->value.doubleConst;
						else if(arg2->type == CONSTINT_E)
							val.doubleConst = arg1->value.doubleConst / (double)val_2;
						else
							val.doubleConst = arg1->value.doubleConst / arg2->value.doubleConst;
					}
					if(prev_op == SUB_O || prev_op == ADD_O) {
						tmp_name = new_tmp_name();
						if( !(st_tmp_entry = st_lookup(tmp_name) )) {
							st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
						}
					}
					break;
				default :
					std::cout << "\033[31mError\033[37m:\tCannot work with this opcode : " << opcode << std::endl;
					assert(NULL);// better assert
					return NULL;
			}
		}
		res = new expr(type, st_tmp_entry, NULL, val);
		// if(arg1->sym){
		// 	std::cout << "Quad #" << get_current_quad() << " got arg1 with result_name = " << st_tmp_entry->name <<" and sym_T_name = " << arg1->sym->name << std::endl;
		// }
		// if(arg2->sym){
		// 	std::cout << "Quad #" << get_current_quad() << " got arg2 with result_name = " << st_tmp_entry->name <<" and sym_T_name = " << arg2->sym->name << std::endl;
		// }
		emit(opcode, res, arg1, arg2, 0, yylineno);
	}
	else {// WHAT TODO in error case???
		std::cout << "Ma kala...\n";
		return NULL;
	}
	return res;
}

void emit_bool_quads(expr* ex){
	st_entry *st_tmp_entry;
	std::string tmp_name;
	if(tmp_var_count)
		tmp_name = "^" + std::to_string(tmp_var_count-1);
	else
		tmp_name = new_tmp_name();
	if(!(st_tmp_entry = st_lookup(tmp_name) )) {
		st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
	}
	union values val;
	expr *expr_pt;
	val.boolConst = true;
	expr_pt = new expr(CONSTBOOL_E, st_tmp_entry, NULL, val);
	emit(ASSIGN_O, expr_pt, expr_pt, NULL, 0, yylineno);
	emit(JUMP_O, NULL, NULL, NULL, get_current_quad() + 2, yylineno);
	val.boolConst = false;
	expr_pt = new expr(CONSTBOOL_E, st_tmp_entry, NULL, val);
	emit(ASSIGN_O, expr_pt, expr_pt, NULL, 0, yylineno);
}

void backpatch(std::vector<quad*> *vq, unsigned label){
	for(int i = 0; i < vq->size(); ++i){
		(*vq)[i]->label = label;
	}
}

std::vector<quad*>* merge(std::vector<quad*>* list1, std::vector<quad*>* list2){
	for(int i = 0; i < list2->size(); ++i){
		list1->push_back((*list2)[i]);
	}
	return list1;
}
