#include "mtype.h"
#include "typelist.h"

DEFINE_METHODS_TABLE(float_methods);

static void init(MessFloat * raw) {
    raw->value = 42.0;
}

static MessTypeConstructor int_cons = {
    .id      = Float,
    .name    = "MessFloat",
    .init    = (type_init_func_t)init,
    .fixsize = sizeof(f64),
};

MESS_TYPE_CONS(Float, int_cons, float_methods);
