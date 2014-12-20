#if (!defined(MESS_STACK_H))
#define MESS_STACK_H

void pop();
void push(MessObject * object);
void swap();
MessObject * topobj();
MessObject * lastobj();

#endif
