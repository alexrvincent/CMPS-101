Name: Alex Vincent

Email: avincent@ucsc.edu

This is the README file for ASG4.

This directory contains the following 15 files:

README.txt	   -The documentation file
catalog.c	   -main program that interprets the library titles/IDs	
hashDriver.c	   -a test program to ensure the correctness of the hashTable
hashFunction.c     -a one-function implementation of a hash function
hashFunction.h     -header file for the use hash function explaining its use
hashTable.c        -implementation of the hash table ADT
hashTable.h        -header for hash table ADT explaining its functions and use
IDList.c           -implementation for the integer linked list ADT
IDListDriver.c     -test program that verifies correctness of integer list ADT.
IDList.h           -header file for integer linked list adt explaining its functions
Makefile           -Makefile used to compile programs into executeables
myinclude.h	   -David Helmbold's commonly used header files (used with permission)
titleList.c        -implementation of the string/ListHndl linked list ADT
titleListDriver.c  -test program that verifies correctness of title/ListHndl list ADT
titleList.h        -header file for titleList ADT, showing its uses and functions


COMPILING: You must type "make [file]" on the command line to create the executable. These are the 4 you can make:
		-"make" - makes catalog.c, the main program
		-"make hashDriver"
		-"make titleListDriver"
                -"make IDListDriver"

 To run the main program, compile and type catalog [test.in] [test.req]

IMPORTANT NOTE: My list program inserts libraryID's into the FRONT of the IDList. As a result, the
output is the same as the test files, but just in reverse order in a stack-like fashion. 
The guidelines in the assignment specify that this is fine.
 
HOW IT WORKS/ Extra Notes:
I decided to implement the program using two seperate linked lists, one controling only the libraryID's
(IDList) and the other controlling the title/ListHndl to IDList (titleList). They are functionally the same,
but hold/parse their fields differently. I've isolated my hashFunction into a hashFunction.c file so it's easy
to see how exactly the strings are hashed as well as easy to modify the hash function. In fact, I played around
with some of the implementations and found this (Horner's Method) to be the best. I've also implemented a
debugging "printHash" function that prints the indexes of the hashTable and it's contents (and content's
contents); see the printHash in action in the hashDriver. I've placed most of the comments for this program
in the header files, so check there first! A lot of work went into this program, so make sure to read the comments
to understand how everything works. Thanks, and enjoy! 