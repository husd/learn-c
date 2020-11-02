#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * 模版方法，方便复制
 * @return
 */
int main()
{

    // 0表示stdin  STDIN_FILENO
    // 1表示stdout STDOUT_FILENO
    // 2表示stderr STDERR_FILENO
    // 不要把文件局限于文件，所有的东西都可以用文件来访问

    FILE *file;
    file = fopen("linux_io.c", "rw");
    if (file == NULL) {
        perror("error happens \n");
    }

    //注意指针和fd的不同
    int fd;
    fd = open("linux_io.c", O_CREAT | O_ASYNC, 0600);
    if (fd == -1) {
        printf("fd error \n");
    } else {
        printf("fd is %d \n", fd);
    }

    //典型的creat 历史遗留问题
    fd = creat("linux_id_creat.c", 0644);
    //等效于 open("linux_id_creat.c", O_WRONLY | O_CREAT | O_TRUNC,0644);
    int f;
    f = open("linux_id_creat.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("2fd error \n");
    } else {
        printf("2fd is %d \n", fd);
        if (close(f) == -1) perror("close file error %d \n", f);
    }

    //errno的值
    extern int errno;
    printf("before errno is %d \n", errno);
    f = open("linux_id_creat2.c", O_WRONLY | O_TRUNC, 0644);
    if (f != -1) {
        if (close(f) == -1) perror("close file error %d \n", f);
    }
    printf("after errno is %d f is %d \n", errno, f);
    return 0;
}