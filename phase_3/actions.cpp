#include "actions.h"
#include "quads.h"
#include <assert.h>
#include <string>

extern unsigned tmp_var_count;
extern std::vector<quad*> quad_vec;
extern int yylineno;

std::string exp_type_to_string(expr *ex){
	switch(ex->type) {
		case BOOLEXPR_E:
		case CONSTBOOL_E:
			return (ex->value.boolConst == true? "'true'" : "'false'");
		case CONSTDOUBLE_E:
			return std::to_string(ex->value.doubleConst);
		case VAR_E:
			return std::to_string(ex->index->value.intConst);
		case CONSTINT_E:
			return std::to_string(ex->value.intConst);
		case CONSTSTRING_E:
			return *ex->value.strConst;
		case NIL_E:
			return "NIL";
		case NEWTABLE_E:
			return "NEWTABLE_E: " + ex->sym->name;
		case PROGRAMFUNC_E:
		case LIBRARYFUNC_E:
			return "function " + ex->sym->name;
		default:
			assert(NULL);
	}
}

bool check_arith (expr* e, std::string context) {
	assert(e);
	if (e->type == CONSTBOOL_E ||
		e->type == CONSTSTRING_E ||
		e->type == NIL_E ||
		e->type == NEWTABLE_E ||
		e->type == PROGRAMFUNC_E ||
		e->type == LIBRARYFUNC_E ||
		e->type == BOOLEXPR_E ) {
		std::cout << "\033[31m" << "ERROR " << "\033[37m" <<
		"Illegal expr " << exp_type_to_string(e) << " used in " << context << " line " << yylineno << std::endl;
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
	emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
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
		
		// if(opcode == MOD_OP){
		// 	if(type == CONSTDOUBLE_E) {
		// 		val.doubleConst = (double)(val_1 % val_2);
		// 	}else {
		// 		val.intConst = val_1 % val_2;
		// 	}
		// 	if(prev_op == SUB_OP || prev_op == ADD_OP) {
		// 		tmp_name = new_tmp_name();
		// 		if( !(st_tmp_entry = st_lookup(tmp_name) )) {
		// 			st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
		// 		}
		// 	}
		// }else {// OLOI OI ELEGXOI ME DOUBLE INT EINAI KYRIWS GIA NA PROSDIORISW TON TELIKO TYPO sto union ALLA KAI GIA NA EPITREPSW MOD ME FLOAT
		// 	switch(opcode){
		// 		case ADD_OP:
		// 			if(type == CONSTINT_E){
		// 				val.intConst = val_1 + val_2;
		// 			}else {
		// 				if(arg1->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_1 + arg2->value.doubleConst;
		// 				else if(arg2->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_2 + arg1->value.doubleConst;
		// 				else
		// 					val.doubleConst = arg1->value.doubleConst + arg2->value.doubleConst;
		// 			}
		// 			break;
		// 		case SUB_OP:
		// 			if(type == CONSTINT_E){
		// 				val.intConst = val_1 - val_2;
		// 			}else {
		// 				if(arg1->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_1 - arg2->value.doubleConst;
		// 				else if(arg2->type == CONSTINT_E)
		// 					val.doubleConst = arg1->value.doubleConst - (double)val_2;
		// 				else
		// 					val.doubleConst = arg1->value.doubleConst - arg2->value.doubleConst;
		// 			}
		// 			break;
		// 		case MUL_OP:
		// 			if(type == CONSTINT_E) {
		// 				val.intConst = val_1 * val_2;
		// 			}else {
		// 				if(arg1->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_1 * arg2->value.doubleConst;
		// 				else if(arg2->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_2 * arg1->value.doubleConst;
		// 				else
		// 					val.doubleConst = arg1->value.doubleConst * arg2->value.doubleConst;
		// 			}
		// 			if(prev_op == SUB_OP || prev_op == ADD_OP) {
		// 				tmp_name = new_tmp_name();
		// 				if( !(st_tmp_entry = st_lookup(tmp_name) )) {
		// 					st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
		// 				}
		// 			}
		// 			break;
		// 		case DIV_OP:
		// 			if(type == CONSTINT_E){
		// 				val.intConst = val_1 / val_2;
		// 			}else {
		// 				if(arg1->type == CONSTINT_E)
		// 					val.doubleConst = (double)val_1 / arg2->value.doubleConst;
		// 				else if(arg2->type == CONSTINT_E)
		// 					val.doubleConst = arg1->value.doubleConst / (double)val_2;
		// 				else
		// 					val.doubleConst = arg1->value.doubleConst / arg2->value.doubleConst;
		// 			}
		// 			if(prev_op == SUB_OP || prev_op == ADD_OP) {
		// 				tmp_name = new_tmp_name();
		// 				if( !(st_tmp_entry = st_lookup(tmp_name) )) {
		// 					st_tmp_entry = st_insert(tmp_name, LOCAL_VAR);
		// 				}
		// 			}
		// 			break;
		// 		default :
		// 			std::cout << "\033[31mError\033[37m:\tCannot work with this opcode : " << opcode << std::endl;
		// 			assert(NULL);// better assert
		// 			return NULL;
		// 	}
		// }
		res = new expr(type, st_tmp_entry, NULL, val);
		emit(opcode, res, arg1, arg2, 0, yylineno);
		return res;
	}
	return NULL;
}

void emit_branch_quads(){
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
	emit(ASSIGN_OP, expr_pt, expr_pt, NULL, 0, yylineno);
	emit(JUMP_OP, NULL, NULL, NULL, get_next_quad() + 2, yylineno);
	val.boolConst = false;
	expr_pt = new expr(CONSTBOOL_E, st_tmp_entry, NULL, val);
	emit(ASSIGN_OP, expr_pt, expr_pt, NULL, 0, yylineno);
}

void patchlabel (unsigned quadNo, unsigned label) {
	assert(quadNo < get_current_quad() && !quad_vec[quadNo]->label);
	quad_vec[quadNo]->label = label;
}

void backpatch(std::vector<quad*> *vq, unsigned label){  
	for(int i = 0; i < vq->size(); ++i){
		(*vq)[i]->label = label;
	}
}

// expr* newexpr_const (unsigned int b) {
// 	expr* e = new_expr()
// 	return e;
// }

std::vector<quad*>* merge(std::vector<quad*>* list1, std::vector<quad*>* list2){
	for(int i = 0; i < list2->size(); ++i){
		list1->push_back((*list2)[i]);
	}
	return list1;
}


/*  */
expr* true_test(expr* ex) {
	if(ex->type != BOOLEXPR_E) {
		union values val;
		unsigned char const_flag = 0;
		switch(ex->type) {
			case ARITHEXPR_E:
			case ASSIGNEXPR_E:
			case VAR_E:
				if(ex->index)
					val.boolConst = true;
				else {
					val.boolConst = false;
				}
				break;
			case CONSTBOOL_E:
				const_flag = 1;
				break;
			case TABLEITEM_E:
			case NEWTABLE_E:
			case LIBRARYFUNC_E:
			case PROGRAMFUNC_E:
				val.boolConst = true;
				break;
			case CONSTINT_E:
				// ex->value.boolConst = !!ex->value.intConst;
				const_flag = 1;
				break;
			case CONSTSTRING_E:
				// ex->value.boolConst = true;
				const_flag = 1;
				break;
			case CONSTDOUBLE_E:
				// if(ex->value.doubleConst == 0.0)
				// 	ex->value.boolConst = false;
				// else
				// 	ex->value.boolConst = true;
				const_flag = 1;
				break;
			case NIL_E:
				val.boolConst = false;
				break;
			default:
				std::cout << "invalid expr type : " << ex->type << std::endl;
				assert(false);
		}
		expr *expr_pt;
		if(!const_flag)// for printing the desired output as quad in case of constant check
			expr_pt = new expr(BOOLEXPR_E, ex->sym, ex, val);
		else {
			expr_pt = ex;
		}
		expr_pt->truelist = new std::vector<quad*>();
		expr_pt->falselist = new std::vector<quad*>();
		union values t_val;
		t_val.boolConst = true;
		expr *true_exp = new expr(CONSTBOOL_E, NULL, expr_pt, t_val);
		emit(IF_EQ_OP, NULL, expr_pt, true_exp, 0, yylineno);
		expr_pt->truelist->push_back(quad_vec[quad_vec.size()-1]);
		emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
		expr_pt->falselist->push_back(quad_vec[quad_vec.size()-1]);
		return expr_pt;
	}
	return ex;
}
