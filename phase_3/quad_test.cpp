#include "quads.h"
#include <vector>

extern std::vector<quad> quad_vec;

void print_quads(){
	for(auto q : quad_vec){
		std::cout << q.op << " " << q.arg1->type << " " << q.arg2->type << " " << q.label  << " " << q.line << std::endl;
	}
}

void print_expr(expr *exp) {
	std::cout << "val = " << exp->value.intConst << std::endl;
}

int main(){
	union values val;
	val.intConst = 25;
	expr *tmp_expr = new expr(CONSTNUM_E, NULL, NULL, val, NULL);
	print_expr(tmp_expr);
	/* print_quads(); */
	return 0;
}
