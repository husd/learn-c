#include <stdio.h>
#include <stdlib.h>

int main()
{

#if 0
    int *p = 0;
    *p = 17; /* segmentation fault 指针有非法的值，不能使用 */

#endif

#if 0
    int *p;
    *p = 100; /* 空指针不能解除引用 */
#endif

#if 1
    int b = 100;
    int *p = &b;
    printf(" p is %d\n",*p);
    free(p);
    *p = 200; /* use pointer after free it 可能会发生未知的错误，也可能不会 */
    printf(" p is %d\n",*p);
#endif

    return 0;
}