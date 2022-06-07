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

    memccpy(lv, rv, sizeof(avm_memcell));   /* In C++ dispatch instead */

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

    assert(lv && (&stack[N-1] >= lv > &stack[top] || lv == &reg_RETVAL));
    assert(rv)/* should do similar assertion test here */

    avm_assign(lv, rv);
}

unsigned avm_totalactuals(void){
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i){
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}