
#include <stdio.h>

void scan_arr(const char *arr);

// array_demo.c
int main() {

    //简单的初始化
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++) {
        //下标访问 和 指针访问
        printf("this is %d %d \n", arr[i], *(arr + i));
    }

    char arr2[4] = {'a','b','c','d'};
    for (int i = 0; i < 4; i++) {
        //指针访问
        printf("this is %c \n", *(arr2 + i));
    }

    scan_arr(arr2);
    return 0;
}

void scan_arr(const char *arr) {


    for (int i = 0; i < 4; i++) {
        //指针访问
        printf("func seen this is %c \n", *(arr + i));
    }
}
