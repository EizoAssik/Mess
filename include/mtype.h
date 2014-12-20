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

typedef enum {
    Add, Sub, Mul, Div, Mod,
    Index, Append,
    MESS_METHOD_COUNT
} MessTypeMethodID;

typedef void (*type_init_func_t)(void *);
typedef void (*type_del_func_t )(void *);
typedef void (*mess_type_method_t)();

typedef struct {
    const char * const name;
    ui64   type;
    ui64   fixsize;
    type_init_func_t init;
    type_del_func_t  del;
} MessTypeConstructor;

extern MessTypeConstructor * TYPE_CONS[];
extern mess_type_method_t  * TYPE_METHOD[];

/*
 * MESS_TYPE_CONS宏用于在运行时注册类型构造子
 * P.S. 编这个名字真费劲
 */

#define SET_MESS_TYPE(type) \
    static const MessType _THIS_MESS_TYPE = type;

#define SETUP_TYPE_CONS(cons)   \
    static __attribute__((constructor))     \
    void reg_cons() {                \
        cons.type = _THIS_MESS_TYPE; \
        cons.fixsize += sizeof(MessObject); \
        TYPE_CONS[_THIS_MESS_TYPE] = &(cons);            \
    } 

#define SETUP_METHOD_TABLE(...)         \
    static mess_type_method_t MTHOD_TABLE[MESS_METHOD_COUNT]; \
    static __attribute__((constructor)) \
    void init_methods() {               \
        __VA_ARGS__;                    \
        TYPE_METHOD[_THIS_MESS_TYPE] = MTHOD_TABLE; \
    }

#define SET_METHOD(key, func) \
    MTHOD_TABLE[key] = func


MessObject * newobj(MessType type);
void method_call(MessTypeMethodID method);

#endif
