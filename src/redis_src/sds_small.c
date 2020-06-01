//
// Created by 胡胜冬 on 2020/4/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "sds.h"
#include "testhelp.h"

int sdsTest(void) {

    long s1 = 10;
    printf(" x length is : %lu \n",sizeof(s1));
    sds x = sdsnew("foo"), y;

    memcmp(x,"foo\0",4);

    test_cond("Create a string and obtain the length",
              sdslen(x) == 3 && memcmp(x,"foo\0",4) == 0)

    sdsfree(x);
    x = sdsnewlen("foo",2);
    test_cond("Create a string with specified length",
              sdslen(x) == 2 && memcmp(x,"fo\0",3) == 0)

    x = sdscat(x,"bar");
    test_cond("Strings concatenation",
              sdslen(x) == 5 && memcmp(x,"fobar\0",6) == 0);

    x = sdscpy(x,"a");
    test_cond("sdscpy() against an originally longer string",
              sdslen(x) == 1 && memcmp(x,"a\0",2) == 0)

    x = sdscpy(x,"xyzxxxxxxxxxxyyyyyyyyyykkkkkkkkkk");
    test_cond("sdscpy() against an originally shorter string",
              sdslen(x) == 33 &&
              memcmp(x,"xyzxxxxxxxxxxyyyyyyyyyykkkkkkkkkk\0",33) == 0)

    sdsfree(x);
    x = sdscatprintf(sdsempty(),"%d",123);
    test_cond("sdscatprintf() seems working in the base case",
              sdslen(x) == 3 && memcmp(x,"123\0",4) == 0)

    sdsfree(x);
    x = sdsnew("--");
    x = sdscatfmt(x, "Hello %s World %I,%I--", "Hi!", LLONG_MIN,LLONG_MAX);
    test_cond("sdscatfmt() seems working in the base case",
              sdslen(x) == 60 &&
              memcmp(x,"--Hello Hi! World -9223372036854775808,"
                       "9223372036854775807--",60) == 0)
    printf("[%s]\n",x);

    sdsfree(x);
    x = sdsnew("--");
    x = sdscatfmt(x, "%u,%U--", UINT_MAX, ULLONG_MAX);
    test_cond("sdscatfmt() seems working with unsigned numbers",
              sdslen(x) == 35 &&
              memcmp(x,"--4294967295,18446744073709551615--",35) == 0)

    sdsfree(x);
    x = sdsnew(" x ");
    sdstrim(x," x");
    test_cond("sdstrim() works when all chars match",
              sdslen(x) == 0)

    sdsfree(x);
    x = sdsnew(" x ");
    sdstrim(x," ");
    test_cond("sdstrim() works when a single char remains",
              sdslen(x) == 1 && x[0] == 'x')

    sdsfree(x);
    x = sdsnew("xxciaoyyy");
    sdstrim(x,"xy");
    test_cond("sdstrim() correctly trims characters",
              sdslen(x) == 4 && memcmp(x,"ciao\0",5) == 0)

    y = sdsdup(x);
    sdsrange(y,1,1);
    test_cond("sdsrange(...,1,1)",
              sdslen(y) == 1 && memcmp(y,"i\0",2) == 0)

    sdsfree(y);
    y = sdsdup(x);
    sdsrange(y,1,-1);
    test_cond("sdsrange(...,1,-1)",
              sdslen(y) == 3 && memcmp(y,"iao\0",4) == 0)

    sdsfree(y);
    y = sdsdup(x);
    sdsrange(y,-2,-1);
    test_cond("sdsrange(...,-2,-1)",
              sdslen(y) == 2 && memcmp(y,"ao\0",3) == 0)

    sdsfree(y);
    y = sdsdup(x);
    sdsrange(y,2,1);
    test_cond("sdsrange(...,2,1)",
              sdslen(y) == 0 && memcmp(y,"\0",1) == 0)

    sdsfree(y);
    y = sdsdup(x);
    sdsrange(y,1,100);
    test_cond("sdsrange(...,1,100)",
              sdslen(y) == 3 && memcmp(y,"iao\0",4) == 0)

    sdsfree(y);
    y = sdsdup(x);
    sdsrange(y,100,100);
    test_cond("sdsrange(...,100,100)",
              sdslen(y) == 0 && memcmp(y,"\0",1) == 0)

    sdsfree(y);
    sdsfree(x);
    x = sdsnew("foo");
    y = sdsnew("foa");
    test_cond("sdscmp(foo,foa)", sdscmp(x,y) > 0)

    sdsfree(y);
    sdsfree(x);
    x = sdsnew("bar");
    y = sdsnew("bar");
    test_cond("sdscmp(bar,bar)", sdscmp(x,y) == 0)

    sdsfree(y);
    sdsfree(x);
    x = sdsnew("aar");
    y = sdsnew("bar");
    test_cond("sdscmp(bar,bar)", sdscmp(x,y) < 0)

    sdsfree(y);
    sdsfree(x);
    x = sdsnewlen("\a\n\0foo\r",7);
    y = sdscatrepr(sdsempty(),x,sdslen(x));
    test_cond("sdscatrepr(...data...)",
              memcmp(y,"\"\\a\\n\\x00foo\\r\"",15) == 0)


    test_report()


    return 0;
}

int sdsTest2() {

    sds x = sdsnew("A..A..hello A.. worldA.....12345678901111111111111111111111111111111");
    sdstrim(x,"A.");
    printf("x is :%s",x);

    char flag = x[-1] & 7;
    printf("flag is %d \n",flag);

    uint8_t dict_hash_function_seed[16];
    dict_hash_function_seed[0] = 123;
    dict_hash_function_seed[1] = 123;
    dict_hash_function_seed[2] = 123;
    dict_hash_function_seed[3] = 123;
    dict_hash_function_seed[4] = 123;
    printf("size of uint8_t is %d \n", sizeof(uint8_t));
    printf("size of seed is: %d",sizeof(dict_hash_function_seed) * sizeof(uint8_t));
    int a = 1;
    int b = 0;
    int c = -1;
    if(c) {
        printf("2 is true \n");
    }
    if(a) {
        printf("1 is true \n");
    }
    if(b) {
        printf("0 is true \n");
    }
    bool d = true;
    if(d) {
        printf("d is true \n");
    }
    sdsfree(x);
    return 0;
}

int main() {
    return sdsTest2();
}
