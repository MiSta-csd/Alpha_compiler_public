#include "avm_mem_structs.h"

#define AVM_STACKSIZE   4096


avm_memcell stack[AVM_STACKSIZE];

static void avm_initstack (void) {
    for (size_t i = 0; i < AVM_STACKSIZE; ++i)
    {
        AVM_WIPEOUT(stack[i]); stack[i].type = UNDEF_M;
    }  
}