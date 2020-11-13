//FILO结构 先进后出
// gcc -DDEBUG=1 stack_demo.c simple_stack.c
#include <assert.h>
#include "simple_stack.h"
#include <stdio.h>

#define STACK_SIZE 100

static STACK_TYPE arr[STACK_SIZE];
static int top_element = -1;

void stack_push(STACK_TYPE val) {

#if DEBUG
    int temp = stack_is_full();
    printf("stack is full: %d \n",temp);
#endif
    assert(!stack_is_full());
    top_element++;
    arr[top_element] = val;
}

STACK_TYPE stack_pop(void) {

    assert(!stack_is_empty());
    return arr[top_element--];
}
STACK_TYPE stack_top(void) {

    assert(!stack_is_empty());
    return arr[top_element];
}
int stack_is_empty(void) {

    if(top_element <= -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}
int stack_is_full(void) {

    if(top_element >= STACK_SIZE - 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}
