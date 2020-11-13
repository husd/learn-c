#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUMPCOPY for(i=0;i<65536;i++) \
    dest[i] = src[i]

#define SMARTCOPY memcpy(dest,src,65536)

/**
 * cc -O mem_demo_cache.c
 * time a.out
 *
 * 这段代码主要是演示CPU的cache
 *
 * @return
 */
int main()
{

    char dest[65536], src[65536];
    int i, j;
    for (j = 0; j < 10000; j++) {
        DUMPCOPY;
    }

    return 0;
}
