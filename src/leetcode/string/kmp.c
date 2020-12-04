//
// Created by 胡胜冬 on 2020/12/3.
//
//
// Created by 胡胜冬 on 2020/12/3.
//
//简称 KMP 算法，是在 BF 算法基础上改进得到的算法

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//T是初始化的模式串
//next是数组，是KMP算法的核心，记录每个字符串的前缀字符串
//例如
void gen_next(char *T, int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmp(char *long_str, char *short_str)
{

    int len_short = strlen(short_str);
    int len_long = strlen(long_str);
    int *next = (int *) malloc(sizeof(int) * len_short);
    gen_next(short_str, next);
    int i = 1, j = 1;
    while (i <= len_long && j <= len_short) {

        //j==0:代表模式串的第一个字符就和当前测试的字符不相等；
        //S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j == 0 || long_str[i - 1] == short_str[j - 1]) {
            i++;
            j++;
        } else {
            // 如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
            j = next[j];
        }
    }

    if(j > len_short) {
        return i - (int)strlen(short_str) - 1;
    }

    return -1;
}

int main()
{

    char *s1 = "1z1234djiwesdjixnisjdfiejifxncijinfeijrlsejivnjidfjseifnkch8eijfisdkjf823isdjuf93ksjdkfjskdjfksdjfz1235";
    //char *s1 = "z1234";
    char *s2 = "z1234";

    int real = kmp(s1, s2);
    printf("real is %d \n", real);
    return 0;
}

