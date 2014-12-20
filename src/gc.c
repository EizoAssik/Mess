#include "common.h"
#include "mtype.h"

void gc_add(MessObject * object) {
    free(object);
}
