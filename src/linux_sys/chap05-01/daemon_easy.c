#include <unistd.h>
#include <stdio.h>

int main() {

    int fd;
    fd = daemon(0,0);
    if(fd != 0) {
        perror("daemon error \n");
        return 1;
    }
    printf("daemon success fd is :%d \n",fd);
    return 0;
}