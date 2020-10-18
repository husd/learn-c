//
// Created by doubleKing on 2020/10/18.
//

//展示了注释的另外一个写法

#include <stdio.h>

int main() {

    printf("this is main \n");
#if 0
    这里是注释的内容
#endif

    // 表达式的返回值
    int b=0;
    int a = (b = 10);
    printf("a is %d b is %d \n",a,b);
    return 0;
}

