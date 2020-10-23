
#include <stdio.h>
#include <string.h>

//演示了strcmp的正确用法
int main() {

    char *s0 = "123456";
    char *s1 = "abcdef";

    size_t len1 = strlen(s0);
    printf("char len is :%d sizeof is %d \n",(int)len1, (int)sizeof(s0));

    //注意区分 strlen() 和 sizeof() 的区别
    char *str1 = "http://see.xidian.edu.cn/cpp/u/shipin/";
    char str2[100] = "http://see.xidian.edu.cn/cpp/u/shipin_liming/";
    char str3[5] = "12345";
    //编译器有警告 size_t 和 int 有区别
    printf("strlen(str1)=%d, sizeof(str1)=%d\n", (int)strlen(str1), (int)sizeof(str1));
    printf("strlen(str2)=%d, sizeof(str2)=%d\n", (int)strlen(str2), (int)sizeof(str2));
    printf("strlen(str3)=%d, sizeof(str3)=%d\n", (int)strlen(str3), (int)sizeof(str3));

    char *index = strchr("1u2u3u",'u');
    char *index_l = strrchr("1u2u3u",'u');
    char *index_s = strstr("1u2u3u","2u");
    printf("index of see is %s index_l is %s strstr is %s \n",index,index_l,index_s);

    //有空 研究下，为什么char *str 这种方式，不能分割
//     char *split_s = "this is some text";
//     const char *sep = " ";
    char split_s[40] = "this is some text";
    const char sep[2] = " ";

    char *token;
    token = strtok(split_s,sep);

    while(token != NULL) {
        printf(" split s is %s \n",token);
        token = strtok(NULL,sep);
    }

    printf("split_s is : %s \n" ,split_s);

    printf("size of int is %d \n",(int) sizeof(int));
    printf("size32 of int is %d \n",(int) sizeof(int32_t));
    printf("size16 of int is %d \n",(int) sizeof(int16_t));
    printf("size8 of int is %d \n",(int) sizeof(int8_t));

    size_t len = strlen(s0) + strlen(s1) + 1;
    char dest[len];
    memset(dest,'\0', sizeof(dest));
    strcpy(dest,s0);
    strcat(dest,s1);
    //所以可以看出sizeof(指针) sizeof(数组) 的区别
    //这里也正好可以说明指针和数组的区别
    printf("strcpy is : %s len is %d sizeof is %d\n",dest, (int)strlen(dest), (int)sizeof(dest));

    if(strcmp(s0,s1) == 0) {
        printf("this eqs \n");
    } else {
        printf("this not eqs \n");
    }

    char *str_up = "this is lower";
    char *str_down = "THIS IS UP";
   // toupper(str_up);
   // tolower(str_down);

    //memset(str_up,'0',0,strlen(str_up));
    printf("%s %s \n",str_up,str_down);

    return 0;
}