#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    int c = 0;
    //printf("start to run\n");
    for (i = 0; i < 2; i++) {
        //fork()系统调用是Unix下以自身进程创建子进程的系统调用，一次调用，两次返回，如果返回是0，
        // 则是子进程，如果返回值>0，则是父进程（返回值是子进程的pid），这是众为周知的。
        //在fork()的调用处，整个父进程空间会原模原样地复制到子进程中，包括指令，变量值，程序调用栈，环境变量，缓冲区，等等。
        fork();
        //因为程序遇到“\n”，或是EOF，或是缓中区满，或是文件描述符关闭，或是主动flush
        //所以如果没有 \n 缓冲区就不会flush 被子进程复制了过去
        printf("A");
        //printf("pid is %d -\n",getpid());
        c++;
    }
    //printf("c is %d \n",c);

    //标准输出是行缓冲，所以遇到“\n”的时候会刷出缓冲区

    wait(NULL);
    wait(NULL);

    return 0;
}