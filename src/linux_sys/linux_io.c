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
 //如果要开启debug 需要在编译的时候执行 gcc -DDEBUG=1 linux_io.c
 //这样就能执行debug的语句了
int main()
{

    // 0表示stdin  STDIN_FILENO
    // 1表示stdout STDOUT_FILENO
    // 2表示stderr STDERR_FILENO
    // 不要把文件局限于文件，所有的东西都可以用文件来访问

    FILE *file;
    file = fopen("test.txt", "a");
    if (file == NULL) {
        perror("error happens \n");
        return 0;
    }

    //lock and unlock
    printf("lock file : \n");
    flockfile(file);
    //写入字符
    fputc('a', file);
    //write line
    int count = fputs("\n this appended by fputs ", file);
    printf("fputs result :%d \n",count);

    fflush(file);

    funlockfile(file);
    printf("unlock file : \n");
    fclose(file);

    //重新以只读的模式打开 因为刚才的文件，是a模式打开的，只能写，不能读
    file = fopen("test.txt", "r");

    //fflush()是C标准库，fsync()是系统调用，通常不建议混用
    //最好都用C标准库
    //int f_fd = fileno(file);
    //立即刷新到磁盘
    //fsync(f_fd);

    // 拿到FILE对象之后，有3种方法可以读取数据
    //每次读取1个字符
    //每次读取1行
    //读取2进制数据

    //挨个演示代码

    //1个字符
    char c;
    printf("---------------读取单个字符--------------\n");
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    printf("\n");

    //先把文件指针复位
    //SEEK_SET： 文件开头
    //SEEK_CUR： 当前位置
    //SEEK_END： 文件结尾

    //fseek(file, 0, SEEK_SET);
    rewind(file);
    printf("---------------读取行--------------\n");
    int LINE_MAX = 256;
    char buf[LINE_MAX];
    while (fgets(buf, LINE_MAX, file)) {
#if DEBUG
        long int cur = ftell(file);
        printf("cur is %ld \n",cur);
#endif
        printf("%s", buf);
    }
    printf("\n");

    fseek(file, SEEK_SET, 0);
    //2进制模式 todo husd 2进制模式没有成功
    //fread 有1个对应的fwrite
    //之后再补齐用法
    printf("---------------2进制模式--------------\n");
    size_t nr;
    while ((nr = fread(buf, sizeof(buf), 1, file)) != 0) {
        printf("%s", buf);
    }
    printf("\n");

    //主要要关闭流 注意fclose的返回值是0，表示关闭成功
    //一般意义上 0在C语言中表示false
    if (fclose(file) != 0) {
        perror("close file error \n");
    }

    //注意指针和fd的不同
    int fd;
    fd = open("linux_io.c", O_CREAT | O_ASYNC, 0600);
    if (fd == -1) {
        printf("fd error \n");
    } else {
        printf("fd is %d \n", fd);
    }
    if (close(fd) == -1) printf("close file error %d \n", fd);

    //典型的creat 历史遗留问题
    fd = creat("linux_id_creat.c", 0644);
    //等效于 open("linux_id_creat.c", O_WRONLY | O_CREAT | O_TRUNC,0644);
    int f;
    f = open("linux_id_creat.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("2fd error \n");
    } else {
        printf("2fd is %d \n", fd);
        if (close(f) == -1) printf("close file error %d \n", f);
    }

    //errno的值
    extern int errno;
    printf("before errno is %d \n", errno);
    f = open("linux_id_creat2.c", O_WRONLY | O_TRUNC, 0644);
    if (f != -1) {
        if (close(f) == -1) printf("close file error %d \n", f);
    }
    printf("after errno is %d f is %d \n", errno, f);
    return 0;
}