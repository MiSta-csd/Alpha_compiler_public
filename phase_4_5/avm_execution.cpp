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