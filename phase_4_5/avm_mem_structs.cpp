#include "avm_mem_structs.h"
#include <cstring>

#define AVM_STACKSIZE   4096
#define AVM_WIPEOUT(m)  memset(&(m), 0, sizeof(m))

avm_memcell stack[AVM_STACKSIZE];

static void avm_initstack (void) {
    for (size_t i = 0; i < AVM_STACKSIZE; ++i)
    {
        AVM_WIPEOUT(stack[i]);
		stack[i].type = UNDEF_M;
    }  
}
