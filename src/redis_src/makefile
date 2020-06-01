target=dict.o dict_main.o zmalloc.o
sds:${target}
	gcc -o dict.out ${target}
dict.o:dict.h fmacros.h zmalloc.h
dict_main.o: dict.h
clean:
	rm dict.out *.o