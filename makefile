all: isort txtfind

isort: isort.o
	gcc -o isort.o

isort.o: isort.c
	gcc -Wall -g -c isort.c


txtfind: txtfind.o
	gcc -o txtfind.o

txtfind.o: txtfind.c
	gcc -Wall -g -c txtfind.c

.PHONY: clean all

clean:
	rm *.o isort txtfind
