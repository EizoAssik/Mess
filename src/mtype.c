/*
 * Lang.Mess的对象系统框架
 */

#include <stdlib.h>
#include "mtype.h"
#include "common.h"

MessTypeConstructor * TYPE_CONS[MESS_TYPE_COUNT];

MessObject * newobj(MessType type) {
    ui64 fixsize     = TYPE_CONS[type]->fixsize;
    MessObject * obj = calloc(1, fixsize);
    obj->type        = type;
    obj->fixsize     = fixsize;
    obj->refconut    = 1;
    if (TYPE_CONS[type]->init)
        TYPE_CONS[type]->init(obj);
    return obj;
}



