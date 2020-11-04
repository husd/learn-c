#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main() {

    printf("uid is %d \n",getuid());
    printf("gid is %d \n",getgid());

    //非root用户，无效，只能设置自己的有效UID或者保留UID
    setuid(12);
    seteuid(12);

    printf("uid is %d \n",getuid());
    printf("gid is %d \n",getgid());
    return 0;
}