//dynamic memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //动态内存分配 malloc
    //calloc 可以初始化内存 所需元素的数量和每个元素的字节数，这样就可以自动算出来需要多少 而且可以初始化为0
    //realloc 可以使原来的内存扩大或者缩小

    int *pi2;
    pi2 = calloc(10, sizeof(int));
    if(pi2 == NULL) {
        printf("out of mem \n");
        exit(1);
    }
    printf("pi2 is %d \n" ,pi2[9]);
    free(pi2);

    //free 之后就不能再访问了 也不一定会报错
    printf("pi2 is %d \n" ,pi2[11]);

    //int *pi 一般使数组的用法 如果你使用int pi; 表示这是个整型
    //int *pi 表示指向1个整型的指针，两者完全不同
    int *pi;
    //申请可以存储100个字节的空间，数组长度 25
    // 还可以写 malloc(25 * sizeof(int)); 这样可能含义更明确
    //并且是可移植的，所以建议这么写
//    pi = malloc(100);
    pi = malloc(25 * sizeof(int));
    if (pi == NULL) {
        printf("out of memory \n");
        exit(1);
    }
    //初始化为0
    for (int i = 0; i < 5; i++) {
        pi[i] = 10;
    }
    for (int i = 0; i < 5; i++) {
        printf(" pi is %d \n", pi[i]);
    }
    // 内存释放，只能全部释放，不能只释放一部分
    // 释放之后，也就不能使用了
    // 假设你复制了多个指针，指向这个动态内存，释放的时候,注意此类问题
    free(pi);


    // 下面演示了复制字符串
    const char *s1 = "this is a test";
    char *str;
    //注意要多申请1个
    str = malloc(strlen(s1) + 1);
    if(str == NULL) {
        printf("out of memory \n");
        exit(1);
    }
    strcpy(str,s1);
    printf("new str is :%s \n",str);

    free(str);
    return 0;
}
