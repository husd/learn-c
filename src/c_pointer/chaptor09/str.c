
#include <stdio.h>
#include <string.h>

//演示了strcmp的正确用法
int main() {

    char *s0 = "abcdef";
    char *s1 = "abcdef";

    if(strcmp(s0,s1) == 0) {
        printf("this eqs \n");
    } else {
        printf("this not eqs \n");
    }

    return 0;
}