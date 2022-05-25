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

struct avm table;
typedef struct avm_memcell {
    avm_memcell_t   type;
    union {
        double              numVal;
        std::string*        strVal;
        bool                boolVal;
        struct avm_table*   tableVal;
        unsigned            funcVal;
        std::string*        libfuncVal;      
    } data;
};


static void avm_initstack (void);