#include "mtype.h"
#include "typelist.h"

#define BUCKET_SIZE 16

SET_MESS_TYPE(List);

static void init(MessList * raw) {
    raw->length = 0;
    raw->list   = (MessObject*)
        calloc(BUCKET_SIZE, sizeof(MessObject*));
}

static MessTypeConstructor cons = {
    .name    = "MessList",
    .init    = (type_init_func_t)init,
    .fixsize = sizeof(i64),
};

SETUP_TYPE_CONS(cons);
