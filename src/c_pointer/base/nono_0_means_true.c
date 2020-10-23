//
// Created by doubleKing on 2020/10/18.
//

#include <stdio.h>

int main() {

    //这个代码，仅仅表示 在C语言种，非0表示true 0表示false
    if(-1) {
        printf("-1 means true \n");
    } else {
        printf("-1 means false \n");
    }

    int b = 10;
    int c = b + --b;
    //目前在windows机器上，使用cygwin的gcc编译 gcc version 10.2.0 (GCC)
    //结果是 18
    printf("c is %d \n",c);
    return 0;
}