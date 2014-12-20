#include <stdio.h>
#include <stdlib.h>

#if(!defined(MESS_COMMON_H))
#define MESS_COMMON_H

typedef unsigned short     i16;
typedef          long int  i64;
typedef unsigned long int ui64;
typedef          double    f64;

#define errprintf(format, ...) \
    fprintf(stderr, \
            "MessError at %s:%d, reporting:\n" \
            format, __FILE__, __LINE__, ## __VA_ARGS__)

#define typeof(object) \
    ((MessObject*)object->type)

#define typecast(type, object) \
    ((type *)(object))

#endif
