#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "mtype.h"
#include "stack.h"

int main() {
    push(newobj(Int));
    push(newobj(Float));
    swap();
    push(newobj(Int));
    method_call(Add);
    printf("Excepted 84, get %ld.\n",
           ((MessInt*)topobj())->value);
    pop();
    printf("Excepted 42.0, get %lf.\n",
           ((MessFloat*)topobj())->value);
    return 0;
}
