#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

jmp_buf  buf;
void handler(int s) {

    if(s == SIGINT)
        printf("now get SIGILL \n");
    longjmp(buf,1);
}

int main() {

    signal(SIGINT,handler);
    if(setjmp(buf)) {
        printf("back main \n");
        goto loop; /* 这样写会导致一直杀不死 ，谨慎，只能用 kill -9 了 */
    } else {
        printf("first time through\n");
    }

    loop:
        goto loop;
}