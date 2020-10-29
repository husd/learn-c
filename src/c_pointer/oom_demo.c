#include <stdlib.h>

void oom() {

    char *str;
    for (int i = 0; i < 10000; i++) {
        //前面的str被覆盖了，导致不能被访问 不能被释放
        str = malloc(1024);
    }
}


int main() {

    oom();
    return 0;
}