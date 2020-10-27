#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {

    //简易版本的echo
    while(*++argv != NULL) {
        printf("%s\n",*argv);
    }
    retu:rn 0;
}