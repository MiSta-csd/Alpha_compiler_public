#pragma once
#include "quads.h"

std::string exp_type_to_string(expr*);

bool check_arith (expr* e, std::string context);

expr* expr_compare_expr(expr *arg1, enum iopcode opcode, expr *arg2);

expr* expr_action_expr(expr *arg1, enum iopcode opcode, expr *arg2, std::string context);

void backpatch(std::vector<quad*>*, unsigned label);

void patchlabel(quad*, unsigned label);

std::vector<quad*>* merge(std::vector<quad*>* list1, std::vector<quad*>* list2);

expr* true_test(expr*);

expr * lvalue_expr (st_entry *sym);

expr * newexpr (expr_t t);

expr * newexpr_conststring (std::string *s);

expr * newexpr_constbool (bool);

expr * newexpr_constint (int);

expr *newexpr_constdouble(double);

expr * emit_iftableitem (expr *e);

expr * emit_ifbool(expr *operand);

expr * member_item (expr* lv, std::string *name);

expr * make_call (expr* lv, std::vector<expr*> exp_vec);

void resettemp();

std::string newtempname();

st_entry* newtemp();

bool istempname (std::string s);

bool istempexpr (expr* e);
