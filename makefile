prog: main.o struct.o fonction.o
	gcc main.o struct.o fonction.o -o prog -lSDL2 -lSDL2_image -lSDL2_ttf
main.o : main.c struct.c struct.h
	gcc -c main.c
struct.o : struct.c struct.h
	gcc -c struct.c
fonction.o : fonction.c
	gcc -c fonction.c
