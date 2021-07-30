#include <stdio.h>

int main()
{

    int ap[2][3][5];

    int (*r)[5] = ap[0];
    int *t = ap[0][0];

    printf("(*r)[5] r is %x\n", r);
    printf("t is %x\n", t);
    printf("---------------------\n");
    printf("(*r)[5] r is %x\n", ++r);
    printf("t is %x\n", ++t);

    //演示多维数据的初始化

    //字符串常量数组，可以这么做
    char *arr[] = {
            "abdc",
            "adder",
            "this is some thing!"
    };
    for (int i = 0; i < 3; i++) {
        printf("str is %s \n", arr[i]);
    }

    //数字类型的可以这么做
    int r1[] = {1,2,3,4};
    int r2[] = {1,2,3,4};
    int r3[] = {1,2,3,4};

    int * arr2[] = {
            r1,
            r2,
            r3
    };
    for (int j = 0; j < 3; ++j) {
        printf("str is %d \n", arr2[j][1]);
    }

    //但是下面的这种是错误的
    int * arr3[] = {
            {1,2,3,4},
            {1,2,3,4},
            {1,2,3,4}
    };
    //编译会有警告
    //执行会报错 segmentation fault
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; ++j) {
            printf("str is %d ", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}