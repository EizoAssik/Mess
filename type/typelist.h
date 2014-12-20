#include "common.h"
#include "object.h"
#include "_typelist.h"

#if (!defined(MESS_TYPELIST_H))
#define MESS_TYPELIST_H

TYPE_REGISTER(Int, Float, List);

DEFINE_MESS_OBJECT(MessInt,   i64 value);
DEFINE_MESS_OBJECT(MessFloat, f64 value);
DEFINE_MESS_OBJECT(MessList,
    ui64 length;
    MessObject * list);
DEFINE_MESS_OBJECT(MessString,
    ui64 length;
    i16 * context);

#endif
