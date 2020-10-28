#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//普通版本的排序
int comp(const void *a, const void *b)
{

    return (*(int *) a) - (*(int *) b);
}

/**
 * 模版方法，方便复制
 * @return
 */
int main()
{

    int arr[10] = {1, 29, 38, 12, 210, 23, 13, 2, 3, 4};
    qsort(arr, 10, sizeof(int), comp);
    for (int i = 0; i < 10; i++) {
        printf("%d \n", arr[i]);
    }
    return 0;
}