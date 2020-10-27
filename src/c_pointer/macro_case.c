//宏的例子
//宏可以用来做一些简单的计算，很好用
//加括号是个好的经验
//不要写特别复杂的宏
//

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((b) > (a) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))

int main() {

    int a = 10;
    //这条会报警，产生了副作用
    int c = MAX(a++,a++);
    printf("c is %d \n",c);
    return 0;
}