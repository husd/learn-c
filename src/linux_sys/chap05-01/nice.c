#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    extern int errno;
    errno = 0;
    int ret;
    //nice的参数，表示要增加多少个优先级，nice(0)就表示当前的优先级
    ret = nice(0);
    printf("current nice %d \n", ret);
    ret = nice(10);
    //nice()的返回值可能是-1，所以不能简单判断ret == -1 表示程序出错了
    if (ret == -1 && errno != 0) {
        perror("nice error \n");
        return 1;
    }
    printf("current nice %d \n", ret);
    //如果想设置绝对值，可以如下操作
    int val;
    val = nice(0);
    //我们想把nice的值设置为18 ，就需要把增加值，设置为 18 - val
    //这样 val + 18 - val = 18
    val = 18 - val;
    ret = nice(val);
    printf("current nice %d \n", ret);

    //优先级
    ret = getpriority (PRIO_PROCESS, 0);
    printf ("nice value is %d\n", ret);

    ret = setpriority(PRIO_PGRP, 0, 10);
    if (ret == -1)
        perror ("setpriority");


    return 0;
}