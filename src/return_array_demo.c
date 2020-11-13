#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

//paf是1个函数，返回1个指针，这个指针指向了1个包含20个元素的数组
int (*paf())[20];

typedef struct a_tag {
    int arr[20];
    int age;
} x, y;

y my_function();

jmp_buf err;

int main()
{


    //严格来说，函数是不能返回数组的
    //但是，可以返回1个指针，指针可以指向任何东西，也包括指针
    int (*resu)[20];
    resu = paf();
    //访问数组
    (*resu)[0] = 100;
    printf("(*resu)[0] is %d \n", (*resu)[0]);

    free(resu);

    //使用结构体来做
    y y1 = my_function();
    printf("y1 age is %d\n",y1.age);
    printf("y1 arr is %d\n",y1.arr[10]);

    return 0;
}

int (*paf())[20]
{

    int (*arr)[20];
    arr = calloc(20, sizeof(int));
    if (!arr) {
        longjmp(err, 1);
    }
    return arr;
}

y my_function() {

    y y1;
    y1.age = 20;
    y1.arr[10] = 1000;
    return y1;
}