//多维数据的传参数
#include <stdio.h>
#include <stdlib.h>


#define MAX 8

const int MAX_SIZE = 100;
// int error_arr[MAX_SIZE]; //会编译错误

//动态扩容
static int CURRENT_ELE = 0;
static const int INIT_SIZE = 5;
static int TOTAL_ELE = 5;

char *dynamic_arr;

void arr_add_new(char c)
{
    if (CURRENT_ELE == 0) {
        dynamic_arr = malloc(INIT_SIZE * sizeof(char));
    }
    if (CURRENT_ELE > 0 && TOTAL_ELE > 0 && CURRENT_ELE == TOTAL_ELE - 1) {
        /* 计算新数组的大小 需要注意的是 + 号的优先级要高于 >> ，所以需要加括号 */
        TOTAL_ELE = TOTAL_ELE + (TOTAL_ELE >> 1);
        //分配内存
        char *tmp;
        tmp = (char *) realloc(dynamic_arr, TOTAL_ELE);
        if (tmp == NULL) {
            printf("out of mem \n");
            exit(1);
        }
        dynamic_arr = tmp;
        dynamic_arr[CURRENT_ELE++] = c;
        printf("resize success now num:%d total:%d \n", CURRENT_ELE, TOTAL_ELE);
    } else {
        dynamic_arr[CURRENT_ELE++] = c;
        //printf("add success now num:%d total:%d \n", CURRENT_ELE, TOTAL_ELE);
    }
}


int main()
{

    for (int i = 0; i < 100; i++) {
        arr_add_new((char) i);
    }
    return 0;
}