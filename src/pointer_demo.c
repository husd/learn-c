#include <stdio.h>

int main()
{

    int a = 10;
    int *p = &a;
    printf("p is %d \n",*p);
    a = 20;
    printf("p is %d \n",*p);

    int *m = 10; /* 编译器会给出警告 ，且m初始化是失败的 这个时候的指针具有非法的值，不能正常使用 */

    printf("m is %x \n",&m);

    int *n = &a;
    *n = 100;
    printf("n is %d \n",*n);
    return 0;
}