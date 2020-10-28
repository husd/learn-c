#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//io操作，这个要熟悉系统的IO调用，理解unix的流的概念
//读写有缓冲区

int main()
{


    //perror错误报告
    perror("this is an error msg! \n");

    //大多数的流是fully buffered,这意味着你操作的都是buffer
    //输出流只有在buffer满的时候，才会刷盘，这样效率更高
    //立即刷盘
    //fflush(stdout);

    //stdio stdout stderr

    //文件指针 FILE fd，注意，linux所有的东西，都是文件
    FILE *fd;
    fd = fopen("io_demo.c", "r"); //打开自己
    if (fd == NULL) {
        perror("file not exist \n");
        exit(EXIT_FAILURE);
    }

    //把非数字的字符，返回到流里，重新读取
    //ungetc(ch, stdin);

    //关闭
    fclose(fd);

    printf("value is %5d \n", 100);

    printf("请输入1个字符串 利用scanf \n");
    char s1[10];
    scanf("%s", s1);
    printf("scanf name is %s\n", s1);

    printf("请输入1个字符串 利用gets() 特别是不安全，容易溢出 \n");
    char s2[10];
    gets(s2);
    printf("gets name is %s\n", s2);

    printf("请输入1个字符串 利用fgets() 推荐，前3个参数分别是 数据地址，长度（包含结尾的杠零，stdin \n");
    char s3[10];
    fgets(s3, 10, stdin);
    printf("fgets name is %s\n", s3);

    exit(EXIT_SUCCESS);
    return 0;
}