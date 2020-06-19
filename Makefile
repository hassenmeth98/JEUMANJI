prog: main.o fonction.o stage1.o 
	gcc main.o stage1.o fonction.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c
stage1.o: stage1.c
	gcc -c stage1.c
fonction.o: fonction.c
	gcc -c fonction.c
clean:
	rm -fr *.o


