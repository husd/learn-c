#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_stack.h"

/**
 * 模版方法，方便复制
 * @return
 */
int main() {

    stack_push(10);
    stack_push(9);
    stack_push(8);
    stack_push(7);
    stack_push(6);

    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    printf("top is %d \n",stack_pop());
    stack_pop();
    return 0;
}