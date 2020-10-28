#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//演示了在linux下的数字和字符串的相互转换
//windows下可以使用atoi() 和 itoa();
int main() {

    //字符串转数字
    int a = 10;
    char str[10];
    sprintf(str,"%3d",a);
    printf("str is %s \n",str);

    //数字转字符串
    int num = -10;
    char *s = "+12345.12";
    sscanf(s,"%d",&num);
    printf("num is %f \n",(float)num);

    return 0;
}