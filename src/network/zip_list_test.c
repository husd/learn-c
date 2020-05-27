//
// Created by 胡胜冬 on 2020/5/27.
//
#include <stdio.h>

#define ZIP_STR_MASK 0xc0 // 11000000
#define ZIP_INT_MASK 0x30 // 11000000
#define ZIP_STR_06B (0 << 6) // 00000000
#define ZIP_STR_14B (1 << 6) // 1000000
#define ZIP_STR_32B (2 << 6) // 10000000

#define ZIP_INT_16B (0xc0 | 0<<4) //11000000
#define ZIP_INT_32B (0xc0 | 1<<4) //11010000
#define ZIP_INT_64B (0xc0 | 2<<4) //11100000
#define ZIP_INT_24B (0xc0 | 3<<4) //11110000
#define ZIP_INT_8B 0xfe     //11111110

int main() {

    printf("%d is: %x \n", ZIP_STR_MASK,ZIP_STR_MASK);
    printf("%d is: %x \n", ZIP_INT_MASK,ZIP_INT_MASK);
    printf("%d is: %x \n", ZIP_STR_06B,ZIP_STR_06B);
    printf("%d is: %x \n", ZIP_STR_14B,ZIP_STR_14B);
    printf("%d is: %x \n", ZIP_STR_32B,ZIP_STR_32B);
    printf("%d is: %x \n", ZIP_INT_16B,ZIP_INT_16B);
    printf("%d is: %x \n", ZIP_INT_32B,ZIP_INT_32B);
    printf("%d is: %x \n", ZIP_INT_64B,ZIP_INT_64B);
    printf("%d is: %x \n", ZIP_INT_24B,ZIP_INT_24B);
    printf("%d is: %x \n", ZIP_INT_8B,ZIP_INT_8B);
    return 0;
}



