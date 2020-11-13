#include <stdio.h>

/**
 *
 * 详细的说明了printf函数的常见用法
 *
 * @return
 */
int main()
{

    //基础知识要夯实，不能学个半盆子晃荡，虽然printf很基础，但是
    //更要夯实基础，编程中，遇到不会的，先写TODO，然后找时间一一学会
    //推土机方式样学习，不漏过一丝细节
    unsigned long long nums = 1000L;
    char *name = "hash";
    unsigned long long fields = 1000L;
    double percent = 12.0;
    double p2 = 12.2345;
    //%5.2f 表示一共输出5位，小数点后有2位
    //5f 即一共5位
    //.2f 小数点后2位
    //05.2f 补0的化，不写前面的0也会补
    // %%表示输入一个%号 前面的那个%表示强引用的意思，类似反斜杠
    // \\ 表示输出1个反斜杠     这个是传统的反斜杠用法
    // \" 表示输出1个引号       这个是传统的反斜杠用法
    printf("%llu %ss with %llu (%5.2f%% of keys, avg size %.2f)\n", nums, name, fields, percent, p2);
    printf("输出引号使用反斜杠  \" \n");
    printf("输出反斜杠使用反斜杠 \\ \n");
    printf("输出\\n也使用反斜杠 \n");
    printf("输出%% 使用两个%%就可以了，和反斜杠稍有不同 %%x \n");

    int i = 47;
    printf("%%x、%%X、%%#x、%%#X 的用法很简单，需要注意的是加了#号就以标准的16进制输出数字 \n");
    printf("演示 %%x 的用法(小写) %x\n", i);
    printf("演示 %%X 的用法(大写) %X\n", i);
    printf("演示 %%#x 的用法(小写) %#x\n", i); /* #号就是加1个0X的前缀 */
    printf("演示 %%#X 的用法(大写) %#X\n", i);
    return 0;
}