all:
	gcc -c main main.c chiffrementMessage.c

main: main.o chiffrementMessage.o
	gcc -o main main.o chiffrementMessage.o

chiffrementMessage.o: chiffrementMessage.c chiffrementMessage.h
	gcc -c chiffrementMessage.c

clean:
	rm *.o && rm main
	

