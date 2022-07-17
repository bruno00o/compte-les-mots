CC=gcc
CFLAGS=-ansi -pedantic -Wall
OBJ=Main.o Mots.o Affichage.o Arguments.o Fichier.o Chaine.o Occurences.o Tri.o Test.o

clm: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Main.o: Main.c Test.h

Mots.o: Mots.c

Affichage.o: Affichage.c Mots.h Occurences.h

Fichier.o: Fichier.c 

Arguments.o: Arguments.c Chaine.h

Chaine.o: Chaine.c

Occurences.o: Occurences.c Mots.h Chaine.h

Tri.o: Tri.c Occurences.h Chaine.h

Test.o: Test.c Mots.h Fichier.h Chaine.h Occurences.h Arguments.h Tri.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f clm