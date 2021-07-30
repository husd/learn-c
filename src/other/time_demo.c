//
// Created by 胡胜冬 on 2020/6/5.
//

#include <time.h>
#include <stdio.h>
#include <sys/time.h>

//微妙 microseconds
long long ustime(void) {
    struct timeval tv;
    long long ust;

    gettimeofday(&tv, NULL);
    ust = ((long long)tv.tv_sec)*1000000;
    ust += tv.tv_usec;
    return ust;
}

//毫秒 millisecond
long long mstime(void) {
    return ustime()/1000;
}

int main() {

    long long t1,t2;

    t1 = ustime();
    t2 = mstime();
    printf(" us time is :%lld \n",t1);
    printf(" ms time is :%lld \n",t2);
    return 0;
}

