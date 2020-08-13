
libmygmp.dll : mygmp.o
		gcc -shared -o libmygmp.dll mygmp.o -lmpfr -lgmp

mygmp.o : mygmp.c mygmp.h
		gcc -c -Wall -Werror mygmp.c -lmpfr -lgmp

.PHONY : clean
clean :
		del libmygmp.dll mygmp.o

.PHONY : main
main :
		g++ -L. -Wall -o a.exe main.cpp -lmygmp
