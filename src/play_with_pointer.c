#include <stdio.h>

char ga[] = "abcdefghijklm";

/* 记住，对于函数的参数是数组的，编译器内部都会转为指针 */
void my_array_func(char ca[10]) {

    printf("addr of array param = %p \n",&ca); /* 思考下这样的输出，和指针参数版本的第一行，是不是一样的 */
    printf("addr (ca[0) = %p \n",&(ca[0]));
    printf("addr (ca[1) = %p \n",&(ca[1]));
    printf(" ++ca = %p \n\n",++ca);
}

void my_pointer_func(char *pa) {

    printf("addr of pointer param = %p \n",&pa);
    printf("addr (pa[0) = %p \n",&(pa[0]));
    printf("addr (pa[1) = %p \n",&(pa[1]));
    printf(" ++pa = %p \n\n",++pa);
}

int main() {

    printf("addr of global param = %p \n",&ga);
    printf("addr (ga[0) = %p \n",&(ga[0]));
    printf("addr (ga[1) = %p \n",&(ga[1]));
    printf("\n\n");
    my_array_func(ga);
    my_pointer_func(ga);

    return 0;
}