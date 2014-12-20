#include "mtype.h"
#include "typelist.h"


static void int_init(MessInt * raw) {
    raw->value = 42;
}

static MessTypeConstructor int_cons = {
    .id      = Int,
    .name    = "MessInt",
    .init    = (type_init_func_t)int_init,
    .fixsize = sizeof(i64),
};

MESS_TYPE_CONS(Int, int_cons);
