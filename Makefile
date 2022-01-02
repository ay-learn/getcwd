CC = cc
LIBS += -lm

all: main

test: moy.o incert.o ecart.o mesure.o affiche1d.o affiche2d.o remplir.o test.o
	$(CC)  moy.o incert.o ecart.o mesure.o affiche1d.c affiche2d.c remplir.o test.o -o test $(LIBS)

main: moy.o incert.o ecart.o mesure.o affiche1d.o affiche2d.o remplir.o main.o
	$(CC)  moy.o incert.o ecart.o mesure.o affiche1d.c affiche2d.c remplir.o main.o -o main $(LIBS)

moy.o: moy.c  util.h
	$(CC) -c moy.c $(LIBS)

incert.o: incert.c  util.h
	$(CC) -c incert.c $(LIBS)

ecart.o: ecart.c  util.h
	$(CC) -c ecart.c $(LIBS)

mesure.o: mesure.c  util.h
	$(CC) -c mesure.c $(LIBS)

affiche1d.o: affiche1d.c  util.h
	$(CC) -c affiche1d.c $(LIBS)

affiche2d.o: affiche2d.c  util.h
	$(CC) -c affiche2d.c $(LIBS)

remplir.o: remplir.c  util.h
	$(CC) -c remplir.c $(LIBS)


main.o: main.c util.h
	$(CC) -c main.c $(LIBS)

clean:
	rm -f *.o
	rm -f main
