#if (!defined(MESS_INNER_TYPELIST_H))
#define MESS_INNER_TYPELIST_H

#define TYPE_REGISTER(names...) \
    typedef enum { names, MESS_TYPE_COUNT } MessType; \

#endif

