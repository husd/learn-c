//
// Created by doubleKing on 2020/10/18.
//

//编译的方法 多文件编译 链接 入门可以这么写，但是最好使用头文件
// gcc chapter1_ans.c increment.c nagete.c
//
#include <stdio.h>

int plus(int c);

int minus(int c);

int main() {

    // 表达式的返回值
//    int b= \40;
//    int a = \100;
//    printf("a is %d b is %d \n",a,b);
    int a = plus(10);
    int b = minus(-10);
    printf("a is %d b is %d \n", a, b);
    return 0;
}