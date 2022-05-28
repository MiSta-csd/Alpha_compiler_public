#include <iostream>
#include <cstring>

enum avm_memcell_t {
        NUMBER_M    =0,
        STRING_M    =1,
        BOOL_M,
        TABLE_M,
        USERFUNC_M,
        LIBFUNC_M,
        NIL_M,
        UNDEF_M
};

struct avm_table;
typedef struct avm_memcell {
    avm_memcell_t   type;
    union data{
        double              numVal;
        std::string        strVal;
        bool                boolVal;
        struct avm_table*   tableVal;
        unsigned            funcVal;
        std::string        libfuncVal;     
    }data;
};

#define AVM_WIPEOUT(m)  memset(&(m), 0, sizeof(m))

static void avm_initstack (void);