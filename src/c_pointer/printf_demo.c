#include <stdio.h>

int main()
{

    unsigned long long nums = 1000L;
    char *name = "hash";
    unsigned long long fields = 1000L;
    double percent = 12.2345;
    double p2 = 12.2345;
    printf("%llu %ss with %llu (%05.2f%% of keys, avg size %.2f)\n", nums, name, fields, percent, p2);
    return 0;
}