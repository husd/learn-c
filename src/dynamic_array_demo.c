#include <stdlib.h>
#include <stdio.h>

int main()
{

    const int a = 10;
    /* gcc -std=c89 dynamic_array_demo.c 如果按c89的标准来编译，会报错 */
    /* gcc -std=c99 dynamic_array_demo.c 如果按c89的标准来编译，会报错 */
    int arr[a] = {0}; /* 这里会报错，因为a必须是1个常量 */
    // 实际测试，这种可能不会报错，但是数据内容可能是随机内容
    arr[0] = 100;
    for (int i = 0; i < 10; ++i) {
        printf("arr[%d] is %d \n", i, arr[i]);
    }

    int size = 10;
    printf("size is %d \n",size);
    size = size + (size >> 1);
    printf("size is %d \n",size);
    return 0;
}