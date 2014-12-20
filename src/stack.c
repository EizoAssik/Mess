#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "mtype.h"
#include "gc.h"

static ui64 length = 0;
static MessObject * top  = NULL;
static MessObject * last = NULL;

void pop() {
    if (top == NULL) {
        errprintf("Pop from empty stack.");
    } else {
        length -= 1;
        gc_add(top);
        top = top->last_in_stack;
        if (top) {
            top->next_in_stack = NULL;
            last = top->last_in_stack;
        } else {
            last = NULL;
        }
    }
}

void push(MessObject * object) {
    length += 1;
    if (top == NULL) {
        top = object;
    } else {
        object->last_in_stack = top;
        top->next_in_stack = object;
        last = top;
        top = object;
    }
}

void swap() {
    if (length == 1) {
        return;
    } else if (length >= 2) {
        MessObject * first = top;
        MessObject * second = top->last_in_stack;
        first->next_in_stack = second;
        first->last_in_stack = second->last_in_stack;
        second->next_in_stack = NULL;
        second->last_in_stack = first;
        last = first;
        top = second;
    } else {
        errprintf("Swapping a stack of length %ld.\n", length);
    }
}

MessObject * topobj() {
    return top;
}

MessObject * lastobj() {
    return last;
}
