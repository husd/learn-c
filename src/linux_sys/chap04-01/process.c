#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    printf("pid is %d ppid is %d \n",getpid(),getppid());
    pid_t  pid = fork();
    if(pid == -1) {
        perror("fork error \n");
        return 1;
    }
    printf("pid is %d ppid is %d \n",getpid(),getppid());

    //输出结果是3行，好好理解fork()的作用

    //pid is 84054 ppid is 81431
    //pid is 84054 ppid is 81431
    //pid is 84058 ppid is 1
    return 0;
}