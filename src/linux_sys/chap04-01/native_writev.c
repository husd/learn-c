#include <unistd.h>
#include <sys/uio.h>

ssize_t naive_writev(int fd, const struct iovec *iov, int count)
{
    ssize_t
    int i;
    for (
            i
                    ret = 0;
    = 0;
    i < count;
    i++) {
        ssize_t nr;
        nr = write(fd, iov[i].iov_base, iov[i].iov_len);
        if (nr == -1) {
            ret = -1;
            break;
        }
        ret +=
                nr;
    }
    return
            ret;
}

