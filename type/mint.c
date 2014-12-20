#include "common.h"
#include "mtype.h"
#include "typelist.h"
#include "stack.h"


static void int_init(MessInt * raw) {
    raw->value = 42;
}

static MessTypeConstructor int_cons = {
    .id      = Int,
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

DEFINE_METHODS_TABLE(int_methods) = {add};
MESS_TYPE_CONS(Int, int_cons, int_methods);
