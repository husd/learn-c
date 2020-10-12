#include <stdio.h>

/**
* 这个本来是要模拟数组越界的 arr[3]是越界，正好存储的是i的值
* 所以当执行到arr[3]=0的时候，就把i的值修改为0，等同于执行了
* i = 0; 所以会无限循环
* 
* 在MAC系统上编译之后，居然没有越界，有可能是编译器字节对齐了？
*
**/
int main(int argc, char* argv[]){
    int i = 0;
    int arr[3] = {0};
    for(; i<=3; i++){
        arr[i] = 0;
        printf("hello world\n");
    }
    return 0;
}
