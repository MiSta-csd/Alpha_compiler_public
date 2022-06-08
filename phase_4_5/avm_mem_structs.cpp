#include "avm_mem_structs.h"
#include "avm_auxiliary.h"



static void avm_initstack (void) {
    for (size_t i = 0; i < AVM_STACKSIZE; ++i)
    {
        AVM_WIPEOUT(stack[i]);
		stack[i].type = UNDEF_M;
    }  
}

void avm_dec_top (void)
{
    if (!top) {
        avm_error("stack overflow");
        executionFinished = 1;
    }
    else
        --top;
}

void avm_push_envvalue (unsigned val)
{
    stack[top].type         = NUMBER_M;
    stack[top].data.numVal  = val;
    avm_dec_top();
}

void avm_callsaveenvironment (void)
{
    avm_push_envvalue(totalActuals);
    avm_push_envvalue(pc + 1);
    avm_push_envvalue(top + totalActuals + 2);
    avm_push_envvalue(topsp);
}
