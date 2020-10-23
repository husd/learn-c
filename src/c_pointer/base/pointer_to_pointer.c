
#include <stdio.h>

int main() {

    int a = 10;
    int *b = &a;
    int **c = &b;
    printf("a is %d,b is %d c is %d \n", a, *b, **c);
    return 0;
}