# Makefile for Asg 3 - by Alex Vincent (avincent@ucsc.edu)
# NOTE HERE: "make [file]" command will create the respective file
# "make clean" will remove unneeded executables and .o files created by this Makefile

sortPrint : heap.o sortPrint.o insertionSort.o heapSort.o
	gcc -std=gnu99 -Wall -Wextra -pedantic -o sortPrint sortPrint.o insertionSort.o heapSort.o heap.o

sortComp : heap.o sortComp.o insertionSort.o heapSort.o
	gcc -std=gnu99 -Wall -Wextra -pedantic -o sortComp sortComp.o insertionSort.o heapSort.o heap.o
    
heapDriver : heapDriver.o heap.o heapSort.o
	 gcc -std=gnu99 -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o heapSort.o
	
sortPrint.o : heapSort.h insertionSort.h sortPrint.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic sortPrint.c

sortComp.o : heapSort.h insertionSort.h sortComp.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic sortComp.c

insertionSort.o : insertionSort.h insertionSort.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic insertionSort.c

heapSort.o : heapSort.h heapSort.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic heapSort.c
    
heapDriver.o : heap.h heapDriver.c
	 gcc -c -std=gnu99 -Wall -Wextra -pedantic heapDriver.c
    
heap.o : heap.h heap.c
	 gcc -c -std=gnu99 -Wall -Wextra -pedantic heap.c

clean :
	rm sortPrint.o sortPrint insertionSort.o sortComp.o sortComp heap.o heapDriver.o heapDriver heapSort.o
