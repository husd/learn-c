#ifndef _SIMPLE_STACK_H_
#define _SIMPLE_STACK_H_

#define STACK_TYPE int

#define TRUE 1
#define FALSE 0

void stack_push(STACK_TYPE val);
STACK_TYPE stack_pop(void);
STACK_TYPE stack_top(void);
int stack_is_empty(void);
int stack_is_full(void);

#endif