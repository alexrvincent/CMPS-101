# Makefile for intstack module - by DPH, modified Spring 2014, further modified by Alex Vincent
# This further modification compiles the decToBinary program using the intstack module

decToBinary : decToBinary.o intstack.o
	gcc -ansi -Wall -Wextra -pedantic -o decToBinary decToBinary.o intstack.o

intstack.o : intstack.h intstack.c
	gcc -c -ansi -Wall -Wextra -pedantic intstack.c

decToBinary.o : intstack.h decToBinary.c
	gcc -c -ansi -Wall -Wextra -pedantic decToBinary.c

clean :
	rm decToBinary decToBinary.o intstack.o

