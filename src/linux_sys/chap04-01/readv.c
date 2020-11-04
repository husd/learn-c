#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main()
{
    //todo husd 这个程序运行不是预期结果
    char foo[20], bar[20], baz[20];
    struct iovec iov[3];
    ssize_t nr;
    int fd;
    fd = open("buccaneer.txt", O_RDONLY);
    if (fd == -1) {
        perror("open error");
        return 1;
    }
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof(foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[2].iov_len = sizeof(baz);

    nr = readv(fd, iov, 3);
    if (nr == -1) {
        perror("readv error \n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d : %s \n", i, (char *) (iov[i].iov_base));
    }

    if (close(fd)) {
        perror("close fd error");
        return 1;
    }

    return 0;
}
