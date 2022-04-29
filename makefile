all:
	gcc -o affichage affichage.c chiffrementMessage.c

affichage: affichage.o chiffrementMessage.o
	gcc -o affichage affichage.o chiffrementMessage.o

chiffrementMessage.o: chiffrementMessage.c chiffrementMessage.h
	gcc -c chiffrementMessage.c

clean:
	rm affichage && clear
	

