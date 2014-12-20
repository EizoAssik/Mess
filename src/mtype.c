/*
 * Lang.Mess的对象系统框架
 */

#include <stdlib.h>
#include "common.h"
#include "mtype.h"
#include "stack.h"

MessTypeConstructor * TYPE_CONS[MESS_TYPE_COUNT];
mess_type_method_t  * TYPE_METHOD[MESS_TYPE_COUNT];

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

void method_call(MessTypeMethodID methodid) {
    mess_type_method_t method = TYPE_METHOD[lastobj()->type][methodid];
    if (method)
        method();
    else
        errprintf("Method not implemented");
}


