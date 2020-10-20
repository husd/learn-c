
#include "_util_.h"

/* 实现itoa函数的源码 */
char *itoa_online(int num, char *str, int radix) {
    /* 索引表 */
    char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned unum; /* 中间变量 */
    int i = 0, j, k;
    /* 确定unum的值 */
    if (radix == 10 && num < 0) /* 十进制负数 */
    {
        unum = (unsigned) -num;
        str[i++] = '-';
    } else unum = (unsigned) num; /* 其它情况 */
    /* 逆序 */
    do {
        str[i++] = index[unum % (unsigned) radix];
        unum /= radix;
    } while (unum);
    str[i] = '\0';
    /* 转换 */
    if (str[0] == '-') k = 1; /* 十进制负数 */
    else k = 0;
    /* 将原来的“/2”改为“/2.0”，保证当num在16~255之间，radix等于16时，也能得到正确结果 */
    char temp;
    for (j = k; j <= (i - k - 1) / 2.0; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return str;
}