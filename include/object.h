#include "common.h"

#if(!defined(MESS_OBJECT_H))
#define MESS_OBJECT_H

/*
 * 所有的Mess类型必须以此开始
 */

#define COMMON_HEADER \
    MessType     type;          \
    ui64         fixsize;       \
    ui64         refconut;      \
    MessObject * next_in_stack; \
    MessObject * last_in_stack  \

typedef struct _MessObject MessObject;

#define DEFINE_MESS_OBJECT( name, ... ) \
    typedef struct { COMMON_HEADER; __VA_ARGS__; } name;

#endif
