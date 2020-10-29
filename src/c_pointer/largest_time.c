#include <stdio.h>
#include <time.h>

int main() {

    //时间什么时候到了尽头？
    //time_t的最大值是多少
    time_t biggest = 0x7FFFFFFF;
    //这个错误是没有考虑时区
    printf("wrong :biggest is %s \n",ctime(&biggest));
    //这个要稍微好点
    printf("right :biggest is %s \n",asctime(gmtime(&biggest)));
    return 0;
}
