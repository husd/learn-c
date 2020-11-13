#include <stdio.h>

void f1(char arr[]);
void f2(char *arr);

int main()
{

    char arr[2] = {'a', 'b'};
    printf("&arr 这个是实际的参数 is %x \n", &arr);
    f1(arr);
    f2(arr);
    return 0;
}

void f1(char arr[])
{

    printf("&arr is %x \n", &arr);
    // &(arr[0]) 这个值，就是实际的数组的地址
    printf("&arr[0] is %x \n", &(arr[0]));
    printf("&arr[1] is %x \n", &(arr[1]));
}

void f2(char *arr)
{

    printf("&arr is %x \n", &arr);
    printf("&arr[0] is %x \n", &(arr[0]));
    printf("&arr[1] is %x \n", &(arr[1]));
    printf("++arr is %x \n", ++arr);
}