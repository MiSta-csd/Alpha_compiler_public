#include "avm_structures.h"

std::vector<double>			numConsts;
unsigned        			totalNumConsts = 0;
std::vector<std::string*> 	stringConsts;
unsigned        			totalStringConsts = 0;
std::vector<std::string> 	namedLibfuncs;
unsigned        			totalNamedLibfuncs = 0;
std::vector<userfunc*> 		userFuncs;
unsigned        			totalUserFuncs = 0;

unsigned consts_newstring(std::string *str) {
	stringConsts.push_back(str);
	return totalStringConsts++;
}

unsigned consts_newnumber(double n) {
	numConsts.push_back(n);
	return totalNumConsts++;
}

unsigned consts_newused(std::string str) {
	namedLibfuncs.push_back(str);
	return totalNamedLibfuncs++;
}

void make_operand(expr* e, vmarg *arg) {
	switch (e->type) {
		case VAR_E:
		case TABLEITEM_E:
		case ARITHEXPR_E:
		case BOOLEXPR_E:
		case NEWTABLE_E:
			arg->val = e->sym->offset;
			switch (e->sym->space) {
				case programvar:	arg->type = GLOBAL_A; break;
				case functionlocal:	arg->type = LOCAL_A; break;
				case formalarg: 	arg->type = FORMAL_A; break;
				default:
					assert(0);
			}
			break;
		/* CONSTANTS */
		case CONSTBOOL_E:
			arg->val = e->value.boolConst;
			arg->type = BOOL_A;
			break;
		case CONSTDOUBLE_E:
			arg->val = consts_newnumber(e->value.doubleConst);
			arg->type = NUMBER_A;
			break;
		case CONSTINT_E:
			arg->val = consts_newnumber((double)e->value.intConst);
			arg->type = NUMBER_A;
			break;
		case CONSTSTRING_E:
			arg->val = consts_newstring(e->value.strConst);
			arg->type = STRING_A;
			break;
		case NIL_E:
			arg->type = NIL_A;
			break;
		case PROGRAMFUNC_E:
			arg->type = USERFUNC_A;
			arg->val = e->sym->taddress;// TODO
		case LIBRARYFUNC_E:
			arg->type = LIBFUNC_A;
			arg->val = consts_newused(e->sym->name);
		default:
			assert(0);
	}
}
