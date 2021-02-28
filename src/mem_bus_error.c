#include <stdio.h>

union {
    char a[10];
    int i;
} u;

int main() {

    printf("sizeof u is %lu \n", sizeof(u)); // 12 因为要字节对齐，int是4字节，所以至少需要12个字节，才能对齐
    printf("sizeof char is %lu \n", sizeof(char));
    //演示bus error
    int *p = (int *) & (u.a[1]);
    *p = 17; // p中未对齐的地址会引起一个bus error
    
    /* the misaligned addr in p causes a bus error! */

    /*
     * This causes a bus error because the array/int union ensures that character
     * array "a" is also at a reasonably aligned address for an integer,
     * so "a+1" is definitely not. We then try to store 4 bytes
     * into an address that is aligned only for single-byte access.
     *
     * */
    //mac下没有显示出应有的效果来
    return 0;
}
