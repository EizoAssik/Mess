#include "common.h"
#include "object.h"
#include "typelist.h"

#if(!defined(MESS_TYPE_H))
#define MESS_TYPE_H

struct _MessObject {
    COMMON_HEADER;
};

/*
 * 通过此结构向Mess注册类型信息
 */

typedef void (*type_init_func_t)(void *);
typedef void (*type_del_func_t )(void *);

typedef struct {
    const char * const name;
    ui64   id;
    ui64   fixsize;
    type_init_func_t init;
    type_del_func_t  del;
} MessTypeConstructor;

extern MessTypeConstructor * TYPE_CONS[];

/*
 * MESS_TYPE_CONS宏用于在运行时注册类型构造子
 * P.S. 编这个名字真费劲
 */

#define MESS_TYPE_CONS(id, cons) static __attribute__((constructor))     \
void reg_cons_ ## id() {                \
    cons.fixsize += sizeof(MessObject); \
    TYPE_CONS[id] = &(cons);            \
} \

MessObject * newobj(MessType type);

#endif
