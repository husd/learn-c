
# 这里是不同的项目
fft = fft.o
pointer_demo = pointer_demo.o

# 修改target变量就可以了，编译不同的文件
target = ${pointer_demo}

sds:${target}
	gcc -o a.out ${target}
fft.o: fft.c
pointer_demo.o: pointer_demo.c
clean:
	rm *.out *.o
