/**
* 对信号进行相应
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <assert.h>

//信号相应程序

int main()
{

    int a = 10;
    //gcc -DNDEBUG=0 signal_demo.c 这样就消除了断言了
    assert(a > 10);
    return 0;
}