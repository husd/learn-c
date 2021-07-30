#include <setjmp.h>
#include <stdio.h>

/* setjmp 函数的功能是将函数在此处的上下文保存在 jmp_buf 结构体中，以供 longjmp 从此结构体中恢复。 */
/* 如果你读过 Linux 操作系统进程切换的源码，你会很明白 Linux 会把进程的上下文保存在 task_struct 结构体中，切换时直接恢复。 */
/* goto 可以实现函数内部的跳转 对于函数之外的，就没办法跳转了，这个时候，就需要使用setjmp longjmp */
int divide(int a, int b);

static jmp_buf exception;

int main()
{

    /* 先模拟下java的异常 */
    if (setjmp(exception) == 0) {
        /* 模拟的时候，把除数修改为0就可以了 */
        int c = divide(10, 10);
        printf("10/0 is %d \n", c);
    } else {
        printf("some thing exception happens return \n");
        return 1;
    }


    jmp_buf env;
    int i;

    i = setjmp(env);
    printf("i is %d \n", i);
    if (i != 0) {
        /* program will exit from this */
        return 0;
    }
    longjmp(env, 2);
    printf("this line will never got printed ! \n");
    return 0;
}

/* 使用 setjmp/longjmp 来模拟java的异常 */

int divide(int a, int b)
{

    if (b == 0) {
        int n = 1;
        /* longjmp 会把代码跳转到上一次执行 setjmp的代码的地方，而且，会把返回值设置为n */
        longjmp(exception, n);
    } else {
        return a / b;
    }
}

