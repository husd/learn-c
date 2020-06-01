//
// Created by 胡胜冬 on 2020/4/30.
//

#include <limits.h>
#include <stdio.h>

int main(void) {

    unsigned long a = LONG_MAX + 1LU;
    printf("long is :%ld \n",a);
    printf("long2 is :%ld \n",LONG_MAX);
    if(1) {
        printf("1 is true\n");
    }
    if(3) {
        printf("3 is true\n");
    }
    if(0) {
        printf("0 is true\n");
    }
    return 0;
}

