//
// Created by 胡胜冬 on 2020/12/3.
//
//Brute Force 暴力匹配算法
//长的是m，短的是n，这种方法最差，需要m*n的时间复杂度
//就是挨个匹配 这个的效率最低了

#include <stdio.h>
#include <string.h>

int bf(char *long_str, char *short_str)
{

    int max_len = strlen(long_str);
    int min_len = strlen(short_str);

    int i = 0, j = max_len, s1;
    while (i < j) {
        s1 = 0;
        while (s1 < min_len) {
            if (i + s1 < max_len && long_str[i + s1] != short_str[s1]) {
                break;
            }
            s1++;
        }
        if (s1 == min_len) {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{

    char *s1 = "1234567890z1234djiwesdjixnisjdfiejifxncijinfeijrlsejivnjidfjseifnkch8eijfisdkjf823isdjuf93ksjdkfjskdjfksdjfz1235";
    //char *s1 = "z1234";
    char *s2 = "z1234";

    int real = bf(s1, s2);
    printf("real is %d \n", real);
    return 0;
}
