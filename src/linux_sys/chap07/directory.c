
#include <unistd.h>
#include <stdio.h>

int main() {

    int BUF_LEN = 256;
    char cwd[BUF_LEN];
    //返回的是当前目录
    if (!getcwd (cwd, BUF_LEN)) {
        perror("getcwd error \n");
        return 1;
    }
    printf ("cwd = %s\n", cwd);

    //用指针来 让系统自动计算这个BUF_LEN的长度
    char *path;
    path = getcwd(NULL,0);
    printf ("cwd = %s\n", path);
    return 0;
}