
-- signed char unsigned char

signed char unsigned char 会存在兼容性问题，如果显示的声明
，有些编译器不行，所以最佳方案就是把char声明的值，限定在
signed char 和 unsigned char的交集，这样就不存在兼容问题

char a = 'a';

