
这个文件夹主要是学习linux系统编程

按不同的标准编译

gcc writev.c -std=c99
gcc writev.c -std=gnu99
gcc writev.c -std=c89


编译的时候指定参数
gcc writev.c -DDEBUG=1
