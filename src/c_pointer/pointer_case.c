
#include <stdio.h>
#include <string.h>
//指针强制转换

int compare_int(void const *A,void const *B) {

    //这1步，是1个强制转换
    if( *(int *)A == *(int *)B ) {
        return 0;
    } else {
        return 1;
    }
}

int main() {

    int a = 10;
    int b = 11;

    int c = compare_int(&a,&b);
    printf("c is %d \n",c);
    a = 10;
    b = 10;
    printf("c is %d \n",compare_int(&a,&b));
    return 0;
}

