#include "avm_execution.h"

extern avm_memcell                  stack[AVM_STACKSIZE];

extern std::vector<double>          numConsts;
extern std::vector<std::string> 	stringConsts;
extern std::vector<std::string> 	namedLibFuncs;
extern std::vector<userfunc*> 		userFuncs;


avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg)
{
    switch (arg->type) {

        /* Variables */
        case GLOBAL_A:  return &stack[AVM_STACKSIZE - 1 - arg->val];
        case LOCAL_A:   return &stack[topsp - arg->val];
        case FORMAL_A:  return &stack[topsp + AVM_STACKENV_SIZE + 1 + arg->val];

        case RETVAL_A: return &reg_RETVAL;

        case NUMBER_A: {
            reg->type = NUMBER_M;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }

        case STRING_A: {
            reg->type = STRING_M;
            reg->data.strVal = new std::string(consts_getstring(arg->val));
            return reg;
        }

        case BOOL_A: {
            reg->type = BOOL_M;
            reg->data.boolVal = arg->val;
            return reg;
        }

        case NIL_A: reg->type = NIL_M; return reg;

        case USERFUNC_A: {
            reg->type = USERFUNC_M;
            reg->data.funcVal = arg->val; /* Address already stored */
            return reg;
        }

        case LIBFUNC_A: {
            reg->type = LIBFUNC_M;
            reg->data.libfuncVal = &(libfuncs_getused(arg->val));
            return reg;
        }

        default: assert(0);
    }
}


double  consts_getnumber (unsigned index)
{
    return numConsts[index];
}

std::string consts_getstring (unsigned index)
{
    return stringConsts[index];
}

std::string libfuncs_getused (unsigned index)
{
    return namedLibFuncs[index];
}

void execute_cycle (void)
{
    if (executionFinished)
        return;
    else 
    if (pc == AVM_ENDING_PC)
    {
        executionFinished = 1;
        return;
    }
    else {
        assert(pc < AVM_ENDING_PC);
        instruction* instr = code + pc;
        assert(
            instr->opcode >= 0 &&
            instr->opcode <= AVM_MAX_INSTRUCTIONS
        );
        if (instr->srcLine)
            currLine = instr->srcLine;
        unsigned oldPC = pc;
        (*executeFuncs[instr->opcode]) (instr);
        if (pc == oldPC)
            ++pc;
    }
}

void avm_assign (avm_memcell* lv, avm_memcell* rv)
{
    if (lv == rv)       /* Same cells? destructive tro assign! */
        return;

    if (lv->type == TABLE_M &&  /* Same tables? no need to assign. */
        rv->type == TABLE_M &&
        lv->data.tableVal == rv->data.tableVal)
        return;

    if (rv->type == UNDEF_M)    /* From undefined r-value? warn! */
        avm_warning("assigning from 'undef' content!");

    avm_memcellclear(lv);   /* Clear old cell contents */

    //memccpy(lv, rv, sizeof(avm_memcell));   /* In C++ dispatch instead */
    *lv = *rv;

    /* Now take care of copied values or reference counting */
    if (lv->type == STRING_M)
        lv->data.strVal = new std::string(*(rv->data.strVal));
    else
    if (lv->type == TABLE_M)
        avm_tableincrefcounter(lv->data.tableVal);

}

void execute_assign (instruction* instr)
{
    avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
    avm_memcell* rv = avm_translate_operand(&instr->arg1, &reg_AX);

    assert(lv && (&stack[N-1] >= lv && &stack[top] || lv == &reg_RETVAL)); // care - changed!
    assert(rv);/* should do similar assertion test here */ // added semicolon

    avm_assign(lv, rv);
}

unsigned avm_totalactuals(void){
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i){
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

unsigned avm_get_envvalue(unsigned i){
    assert(stack[i].type == NUMBER_M);
    unsigned val = (unsigned)stack[i].data.numVal;
    assert(stack[i].data.numVal == val);
    return val;
}

void execute_call (instruction* instr)
{
    avm_memcell* func = avm_translate_operand(&instr->result, &reg_AX);
    assert(func);
    avm_callsaveenvironment();

    switch (func->type)
    {
        case USERFUNC_M: 
        {
            pc = func->data.funcVal;
            assert(pc < AVM_ENDING_PC);
            assert(code[pc].opcode == FUNCENTER_V);
            break;
        }
        
        case STRING_M:
        {
            char* cstr = new char[(*(func->data.strVal)).length() + 1];
            strcpy(cstr, (*(func->data.strVal)).c_str());
            avm_calllibfunc(cstr);//wraia des aftes tis grammes // 2 me8doi h .length() k h .c_str(). H 2h paragei apo std::string 
            //ena const char* , to opoio isws sou kanei omorfa!
            /* Des file ti anagkazomai na kanw epeidh o mhtsos 
            den phre xabari oti den xrhsimopoioume char* */
            delete [] cstr;
        }

        case LIBFUNC_M:
        {
            char* cstr = new char[(*(func->data.libfuncVal)).length() + 1];
            strcpy(cstr, (*(func->data.libfuncVal)).c_str());
            avm_calllibfunc(cstr);
            /* Des file ti anagkazomai na kanw epeidh o mhtsos 
            den phre xabari oti den xrhsimopoioume char* */
            delete [] cstr;
        } 
        
        default:
        {
            std::string* s = new std::string(avm_tostring(func));
            avm_error("call: cannot bind "+ *s +" to function!");
            delete s;
            executionFinished = 1;
        }
        
    }
}

void execute_funcenter (instruction* instr)
{
    avm_memcell* func = avm_translate_operand(&instr->result, &reg_AX);
    assert(func);
    assert(pc == func->data.funcVal); /* Func addr should match PC */

    /* Callee actions here. */
    totalActuals = 0;
    userfunc* funcInfo = avm_get_funcinfo(pc);
    topsp =top;
    top = top - funcInfo->localSize;

}

void execute_funcexit (instruction* unused)
{
    unsigned oldTop = top;
    top     = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc      = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp   = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    
    while (++oldTop <= top) /* Intentionally ignering first. */
        avm_memcellclear(&stack[oldTop]);
}

void execute_pusharg (instruction* instr)
{
    avm_memcell* arg = avm_translate_operand(&instr->arg1, &reg_AX);
    assert(arg);

    /*  This is actually stack[top] = arg, but we have to
        use avm_assign
     */

    avm_assign(&stack[top], arg);
    ++totalActuals;
    avm_dec_top();
}

double add_impl (double x, double y) { return x + y; }
double sub_impl (double x, double y) { return x - y; }
double mul_impl (double x, double y) { return x * y; }
double div_impl (double x, double y) 
{
    assert(y != 0);
    return x / y; 
}
double mod_impl (double x, double y) 
{ 
    return ((int) x) % ((int) y);   /* no further error checking */ 
}

void execute_arithmetic (instruction* instr)
{
    avm_memcell* lv  = avm_translate_operand(&instr->result, (avm_memcell*) 0);
    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &reg_AX); 
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &reg_BX);

    assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&reg_RETVAL));
    assert(rv1 && rv2);

    if (rv1->type != NUMBER_M || rv2->type != NUMBER_M) {
        avm_error("not a number in arithmetic!");
        executionFinished = 1;
    }
    else {
        arithmetic_func_t op = arithmeticFuncs[instr->opcode - ADD_V];
        avm_memcellclear(lv);
        lv->type           = NUMBER_M;
        lv->data.numVal = (*op) (rv1->data.numVal, rv2->data.numVal);
    }
}

