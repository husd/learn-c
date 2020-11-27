//
// Created by 胡胜冬 on 2020/11/27.
//

//想熟悉下C里面的各种类型的占用字节长度

#include <stdio.h>
#include <unistd.h>

int main() {

    uintptr_t a;
    printf("uintptr_t size if is: %ld \n", sizeof(a));
    size_t t;
    printf("size_t size if is: %ld \n", sizeof(t));
    return 0;
}

