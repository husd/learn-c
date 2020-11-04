#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

int main()
{

    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    char *buf[] = {
            "first line \n",
            "second line \n",
            "third line \n"
    };
    fd = open("buccaneer.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == 1) {
        perror("open error");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }
    // fd iov 数组的长度
    nr = writev(fd, iov, 3);
    if (nr == -1) {
        perror("writev error \n");
        return 1;
    }
    printf("wrote %d bytes \n ", (int)nr);
    if (close(fd)) {
        perror("close fd error");
        return 1;
    }
    return 0;
}
