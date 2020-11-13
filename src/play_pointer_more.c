#include <stdio.h>

void func1(arr[1][2][3])
{
    printf("func1 arr addr is %#p \n", arr);
}

void func2(arr[][2][3])
{
    printf("func2 arr addr is %#p \n", arr);
}

void func3(char (*ptr)[2][3])
{
    printf("func3 arr addr is %#p \n", ptr);
}

int main()
{

    //这个代码，充分说明了 数组和指针之间 是怎么转换的 尤其是作为函数的参数的时候
    printf("char arr[1][2][3] start -----------\n");
    char arr[1][2][3];
    func1(arr);
    func2(arr);
    func3(arr);

    printf("char (*ptr)[2][3] start -----------\n");
    char (*ptr)[2][3] = arr;
    func1(ptr);
    func2(ptr);
    func3(ptr);
    printf("char (*ptr)[1][2][3] start -----------\n");
    char (*ptr2)[1][2][3] = &arr;
    func1(*ptr2);
    func2(*ptr2);
    func3(*ptr2);

    return 0;
}