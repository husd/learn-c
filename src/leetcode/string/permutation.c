/*
面试题 08.08. 有重复字符串的排列组合
有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

示例1:

 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tmp[10] = {0};

void Dfs(char **res, char *S, int depth, int len, int *used, int *returnSize)
{
    // len = 9 这本题中，这个值是固定的
    // 所以当回溯到第9层的时候，表示已经找到了1个正确的答案
    // 此时就记录结果 增加returnSize的值就行了
    if (depth == len) {
        tmp[len] = '\0';
        res[*returnSize] = (char *) malloc(sizeof(char) * (len + 1));
        printf("%c%c%c%c%c%c%c%c%c%c\n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7], tmp[8],
               tmp[9]);
        strcpy(res[(*returnSize)++], tmp);
        return;
    }
    for (int i = 0; i < len; i++) {
        if ((i > 0 && S[i] == S[i - 1] && used[i - 1] == 1) || used[i] == 1) {
            printf("i= %d S[i] %c S[i-1] %c used[i-1] %d used[i] %d \n", i, S[i], S[i - 1], used[i - 1], used[i]);
            continue;
        }
        used[i] = 1;
        //这行代码是最关键的，每次都在计算tmp的值该是多少
        //i的值一定能计算到
        tmp[depth] = S[i];
        Dfs(res, S, depth + 1, len, used, returnSize);
        used[i] = 0;
    }
}

//这里是自定义的排序函数
int Cmp(const void *a, const void *b)
{
    return (*(char *) a - *(char *) b);
}

//思路就是排序、DFS、回溯
char **permutation(char *str, int *returnSize)
{

    int len = strlen(str);
    //首先是排序，排序的原因就是需要降低计算的难度
    //让相同的字母，排列到一起，例如字符是abac DFS的时候，需要判断现在的字符串和
    //之前的字符串是否有重复的，势必要写一个set来做判断，是否重复，但是排序之后就不一样了
    //不需要判断是否重复了，因为有顺序，不可能会重复
    qsort(str, len, sizeof(char), Cmp);
    //最长只有9，所以1000足够了
    char **res = (char **) malloc(sizeof(char *) * 1000);
    //设置1个动态长度的数组
    int *used = (int *) calloc(len, sizeof(int));
    *returnSize = 0;
    //dfs算法来计算所有的可能
    Dfs(res, str, 0, len, used, returnSize);
    return res;
}


int main()
{
    char *str = "abc";
    int returnSize = 0;
    permutation(str, &returnSize);
    printf("return size is %d\n", returnSize);
    return 0;
}




