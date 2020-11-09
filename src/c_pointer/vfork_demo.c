#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void) {
    int var;
    var = 0;
    //主要讲vfork的问题
    //fork 是 创建一个子进程，并把父进程的内存数据copy到子进程中。
    //vfork是 创建一个子进程，并和父进程的内存数据share一起用。
    pid_t pid;
    pid = getpid();
    if ((pid = vfork()) < 0) {
        printf("vfork error");
        exit(-1);
    } else if (pid == 0) { /* 子进程 */
        var++;
        //注意因为函数栈父子进程共享，所以整个程序的栈就跪了，在子进程中return 相当于
        //把父进程也return了
        return 0;
    }
    printf("pid=%d, glob=%d, var=%d\n", getpid(), 123, var);
    return 0;
}

#if 0
    /** https://coolshell.cn/articles/12103.html **/
#endif