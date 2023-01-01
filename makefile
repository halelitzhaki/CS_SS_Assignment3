all: isort txtfind

isort: isort.o
	gcc -Wall -g -o isort isort.o
	
txtfind: txtfind.o
	gcc -Wall -g -o txtfind txtfind.o

isort.o: isort.c
	gcc -Wall -g -c isort.c

txtfind.o: txtfind.c
	gcc -Wall -g -c txtfind.c

.PHONY: clean all

clean:
	rm *.o isort txtfind
