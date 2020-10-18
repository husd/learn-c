
#include <stdio.h>
#include <stdlib.h>

int reverse_bits(int n);

int main() {

    int n = 5;
    unsigned int n1 = reverse_bits(n);
    char *a1,*a2;
    //itoa(reverse_bits(n),a1,2);
    //itoa(n,a2,2);
    printf("n is:%d reverse is :%d",n,n1);
    return 0;
}

//写1个方法，反转一个整数的bit位置，例如25 = 00011001
// 反转之后，应该是 10011000
int reverse_bits(int n) {

    int res = 0;
    for (int i = 0; i < 32; i++) {
        res ^= (n & (1 << i)) == 0 ? 0 : 1 << (31 - i);
    }
    return res;
}