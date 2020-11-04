#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    //mmap内存映射
    // /dev/zero是一段全是0的内存
    void *p;
    int fd;
    //书中的例子是 /dev/zero 但是似乎mac下不支持这么做，所以一直报不支持
    //就修改成了另外的1个文件
    fd = open("mem.c", O_RDONLY);
    if (fd < 0) {
        perror("open error \n");
        return 1;
    }
    int page_size = getpagesize();
    printf("page size is :%d \n",page_size);
    p = mmap(NULL,   /* do not care where */
             page_size, /* map one page */
             PROT_READ | PROT_WRITE, /* map read/write */
             MAP_PRIVATE, /* private mapping */
             fd,  /* map /dev/zero */
             0);  /* no offset */
    if (p == MAP_FAILED) {
        perror("mmap fail \n");
        if (close(fd)) {
            perror("close fd error \n");
        }
        return 1;
    }
    if (close(fd)) {
        perror("close fd error \n");
    }
    /* 'p' points at one page of memory, use it... */
    p = (char *) p;
    printf("p is %s \n",p);

    //使用完了，要还回去
    int ret;
    ret = munmap(p, page_size);
    if (ret) {
        perror("munmap error \n");
        return 1;
    }
    return 0;
}