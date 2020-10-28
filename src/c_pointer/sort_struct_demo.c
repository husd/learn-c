#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b);

int comp2(const void *a, const void *b);

typedef struct OBJ {

    char *str;
    int age;
} OBJ;

/**
 * 模版方法，方便复制
 * @return
 */
int main()
{

    //这种方式是不是太丑陋了，正常应该怎么写呢？
    char str_arr[10][4] = {"abc\0", "dbc\0", "cbc\0", "dbc\0", "ebc\0", "fbc\0", "gbc\0", "hbc\0", "ibc\0", "dbc\0"};
    OBJ arr[10];
    for (int i = 0; i < 10; i++) {
        OBJ tmp;
        tmp.str = &(str_arr[i][0]);
        tmp.age = 100 - i;
        arr[i] = tmp;
    }
    qsort(arr, 10, sizeof(struct OBJ), comp);
    for (int i = 0; i < 10; i++) {
        printf("name :%s age :%d \n", (arr[i]).str, arr[i].age);
    }
    return 0;
}

//按结构进行排序 这个按字符串
int comp(const void *a, const void *b)
{

    return strcmp(((OBJ *) a)->str, ((OBJ *) b)->str);
}

//按结构进行排序 这个按字符串
int comp2(const void *a, const void *b)
{

    return ((OBJ *) a)->age - ((OBJ *) b)->age;
}