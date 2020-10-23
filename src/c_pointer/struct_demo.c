#include <stdio.h>
#include <string.h>

//基本用法
struct person {
    int age;
    int sex;
    char *name;
    char *address;
};

//提高版本
typedef struct {
    int age;
    int sex;
    char *name;
    char *address;
} _person;

void print_person(_person *p) {

    printf(" p is %s \n",p->address);
}

int main() {

    struct person p1;
    p1.address = "向阳街20号";
    p1.sex = 1;
    p1.name = "测试名字";
    p1.age = 20;
    printf(" p1 is %s %s %d %d \n",p1.address,p1.name,p1.age,p1.sex);

    _person p2;
    p2.address = "向阳街20号";
    p2.sex = 1;
    p2.name = "测试名字";
    p2.age = 20;
    printf(" p2 is %s %s %d %d \n",p2.address,p2.name,p2.age,p2.sex);

    print_person(&p2);

    //_person *p3; 这样写是不行的，指针就是指针，没有初始化，不知道需要多大内存，所以只能分配1个指针的地址
    //不能分配_person的内存地址
    _person *p3 = &p2;
    p3->address = "向阳街21号";
    printf(" p3 is %s \n",p3->address);
    printf(" p2 is %s %s %d %d \n",p2.address,p2.name,p2.age,p2.sex);

    return 0;
}
