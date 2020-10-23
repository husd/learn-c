//
// Created by doubleKing on 2020/10/18.
//

#include <stdio.h>

int main() {

    // 表达式的返回值
//    int b= \40;
//    int a = \100;
//    printf("a is %d b is %d \n",a,b);
    int a = 0,b=10;
    printf("a is %d b is %d \n", a, b);

    // 等同于
     char *c;
     c = "abcde";
    //char *c = "abcd";

    printf("address is %x %d %s \n",&c,c,c); //  address is ffffcc20 4206610 abcd
    // 至于为什么按数字显示，是 4206610 呢，就需要研究下

    int a2 = 45;
    // a1的值，就是1个地址，1个指针
    // *a1的值，就是指针指向的值
    int *a1 = &a2,b1=2,c1=3;
    printf("a2 is %d ",a2);
    printf("a1 is %x b1 is %d c1 is %d \n",a1,b1,c1);
    printf("a1 is %d  \n",*a1);

    // 修改a2的值，会同时修改a1的值
    a2 = 40;
    printf("a1 is %d a2 is %d \n",*a1,a2);

    // long类型赋值给short 会怎么样？
    //结果就是如果在short范围内，就没有啥问题，编译器自动处理了
    //如果不在，会有一个警告，然后结果不可预知
    long a3 = 10L;
    short a4 = 100L;

    double a5 = 1.0;
    float a6 = a5;
    printf("a4 is :%d a6 is: %2f \n",a4, a6);

    enum {COIN,CENT};
    printf("COIN is :%d CENT is: %d \n",COIN,CENT);


    return 0;
}