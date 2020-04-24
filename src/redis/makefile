target=sds.o sds_small.o zmalloc.o
sds:${target}
	gcc -o sds ${target}
sds.o: sds.h sdsalloc.h
sds_small.o: sds.h testhelp.h
zmalloc.o: zmalloc.h atomicvar.h
clean:
	rm sds *.o
