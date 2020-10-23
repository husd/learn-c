
#include <stdio.h>
#include "../../c_pointer/_util_.h"

int reverse_bits(int n);

// gcc reverse_bits.c ../_util_.c
int main() {

    int n1 = 25;
    int n2 = reverse_bits(n1);
    char a1[33],a2[33];
    itoa_online(n1,a1,2);
    itoa_online(n2,a2,2);
    printf("n  is: %d reverse is : %d \n",n1,n2);
    printf("a1 is: %s reverse is : %s \n",a1,a2);
    return 0;
}

//写1个方法，反转一个整数的bit位置，例如25 = 00011001
// 反转之后，应该是 10011000
int reverse_bits(int n) {

    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

