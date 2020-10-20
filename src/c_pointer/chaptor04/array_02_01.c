
#include <stdio.h>

// 这个文件和array_02.c 联合编译
// gcc array_02.c array_02_01.c 这样用
// 本意是测试数组和指针的不同之处
extern int a[];
extern int *b;

// 如果修改为以下的引用，就会报错
//extern int b[];
//extern int *a;

//意思就是数组和指针虽然看起来像，但是不能任意转换，指针只分配了指针的空间
//数组则是分配了整个数组的空

int main() {

int x,y;
x= a[0];
y= b[1];

printf("this x is %d y is %d \n",x,y);
return 0;
}
