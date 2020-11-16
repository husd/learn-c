//
// Created by 胡胜冬 on 2020/6/5.
//

#include <unistd.h>
#include <stdio.h>

/**
 *
 * 这段代码，假设编译之后，形成的目标文件是a.out
 * 执行 ./a.out time_demo(time_demo是可执行文件)之后
 * 可以正确输出结果 问题是:
 * 绝对路径和相对路径
 *
 * 说明程序执行的环境，就是当前环境
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{

    char *p1 = argv[1];
    char *p2 = "/Users/hushengdong/hushengdong/github-source/learn-c/src/network/time_demo";
    int res;
    if ((res = access(p1, 2)) == -1) {
        printf("no permissions to execute %s", p1);
        return -1;
    }
    printf("access of %s is %d",p1,res);
    printf(" p1 is :%s \n", p1);
    printf(" p2 is :%s\n", p2);
    execve(p1, NULL, NULL);
    return 0;
}
