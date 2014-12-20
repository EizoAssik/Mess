#include "mtype.h"
#include "typelist.h"

#define BUCKET_SIZE 16

static void init(MessList * raw) {
    raw->length = 0;
    raw->list = (MessObject*)
        calloc(BUCKET_SIZE, sizeof(MessObject*));
}

static MessTypeConstructor cons = {
    .id      = Int,
    .name    = "MessList",
    .init    = (type_init_func_t)init,
    .fixsize = sizeof(i64),
};

MESS_TYPE_CONS(List, cons);
