//
// Created by 胡胜冬 on 2020/11/29.
//
//callback is A "callback" is any function that is called
// by another function which takes the first function as a parameter。

//from https://www.cnblogs.com/jiangzhaowei/p/9129105.html

//

#include <stdio.h>

// callback func define
int Handle(int (*Callback)());

int Callback_1() // Callback Function 1
{
    printf("Hello, this is Callback_1 \n");
    return 0;
}

int Callback_2() // Callback Function 2
{
    printf("Hello, this is Callback_2 \n");
    return 0;
}

int Callback_3() // Callback Function 3

{
    printf("Hello, this is Callback_3 \n");
    return 0;
}

int Handle(int (*Callback)())
{
    printf("Entering Handle Function. \n");
    Callback();
    printf("------ Leaving Handle Function. \n");
}

int main()
{
    printf("Entering Main Function. \n");
    Handle(Callback_1);
    Handle(Callback_2);
    Handle(Callback_3);
    printf("Leaving Main Function. \n");
    return 0;
}
