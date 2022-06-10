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

avm_memcell::avm_memcell()
{
   memset( this, 0, sizeof( avm_memcell) );
   this->type = UNDEF_M;
}
avm_memcell::~avm_memcell()
{
   memset( this, 0, sizeof( avm_memcell) );
}

avm_memcell::avm_memcell(avm_memcell_t type, void* data)
{
    switch (type)
    {
        case NUMBER_M:
        {
            this->type = type;
            this->data.numVal = *(double*) data;
            break;
        }
        case STRING_M:
        {
            this->type = type;
            this->data.strVal = (std::string*) data;
            break;
        }
        case BOOL_M:
        {
            this->type = type;
            this->data.boolVal = *(bool*) data;
            break;
        }
        case TABLE_M:
        {
            this->type = type;
            this->data.tableVal = (avm_table*) data;
            break;
        }
        case USERFUNC_M:
        {
            this->type = type;
            this->data.funcVal = *(userfunc*) data;
            break;
        }
        case LIBFUNC_M:
        {
            this->type = type;
            this->data.libfuncVal = (std::string*) data;
            break;
        }
        case NIL_M:
        {
            this->type = type;
            /*this->~data();*/ // Maycause problems
            break;
        }
        case UNDEF_M:
        {
            this->type = type;
            /*this->~data();*/ // Maycause problems
            break;
        }
        default:
        {
            assert(0);
            break;
        }
    }
}