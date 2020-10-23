#include <stdio.h>
#include <string.h>

int main() {

    //指针的基本用法
    int a = 20;
    printf("a is %d \n",*&a);

    int *b = 21;
    printf("b is %d \n",b);
//printf("*a is %d \n",*a);

    return 0;
}