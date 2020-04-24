#include <stdio.h>
/**
  * ip
  *
  **/
int main() {

    int a_ip = (1 << 7) - 1;
    int b_ip = a_ip + (1 << 6);
    int c_ip = b_ip + (1 << 5);
    int d_ip = c_ip + (1 << 4);
    printf("ip type a %d \n", a_ip);
    printf("ip type b %d \n", b_ip);
    printf("ip type c %d \n", c_ip);
    printf("ip type d %d \n", d_ip);
}