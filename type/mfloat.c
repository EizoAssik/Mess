#include "mtype.h"
#include "typelist.h"

SET_MESS_TYPE(Float);

static void init(MessFloat * raw) {
    raw->value = 42.0;
}

static MessTypeConstructor cons = {
    .name    = "MessFloat",
    .init    = (type_init_func_t)init,
    .fixsize = sizeof(f64),
};

SETUP_TYPE_CONS(cons);
