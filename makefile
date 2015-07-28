CC = gcc
OPTIONS = -Wall
EXE = gestionProduct
OBJS = fichier.o list.o main.o inventaire.o gestionnaire.o

.SUFFIXES: .c .o

all: link

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) *.c -c

link: compile
	$(CC) $(OBJS) -o $(EXE)
	
clean:
	rm $(EXE)
	rm $(OBJS)


