#include "common.h"
#include "mtype.h"
#include "typelist.h"
#include "stack.h"

SET_MESS_TYPE(Int);

static void int_init(MessInt * raw) {
    raw->value = 42;
}

static MessTypeConstructor int_cons = {
    .name    = "MessInt",
    .init    = (type_init_func_t)int_init,
    .fixsize = sizeof(i64),
};

static void add() {
    MessObject * obj = topobj();
    if (typeof(obj) == Int) {
        i64 value = typecast(MessInt, obj)->value;
        pop();
        typecast(MessInt, topobj())->value += value;
    } else {
        errprintf("Int adding with other instance");
    }
}

SETUP_METHOD_TABLE( SET_METHOD(Add, add) );
SETUP_TYPE_CONS(int_cons);
