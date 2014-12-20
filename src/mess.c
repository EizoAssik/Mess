#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "mtype.h"

MessObject * stack[4096];

int main() {
    stack[0] = newobj(Int);
    stack[1] = newobj(Float);
    printf("Excepted 42, get %ld.\n",
           *(i64*)((char*)stack[0]+sizeof(MessObject)));
    printf("Excepted 42.0, get %lf.\n",
           *(f64*)((char*)stack[1]+sizeof(MessObject)));
    return 0;
}
