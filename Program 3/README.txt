Name: Alex Vincent, Nader Sleem

Emails: avincent@ucsc.edu, nsleem@ucsc.edu

This is the README file for ASG3.

This directory contains the following 12 files:

README.txt	-The documentation file
heap.c		-the implementation of the heap ADT
heapDriver.c	-the "test" program that verifies the correctness of
 the heap implementation

heap.h		-the header file the the heap implementation	
heapSort.c	-the implementation file for the heapSort algorithm

heapSort.h	-the header file for the heapSort function

insertionSort.h	-the header file for the insertionSort function

insertionSort.c	-the implementation file for the insertionSort function

Makefile	-the Makefile to create sortPrint, sortComp and heapDriver

myinclude.h	-David Helmbold's header file that includes commonly used libraries

sortComp.c	-short program that tests the two sorting algorithms, displaying proper output.

sortPrint.c	-short program that tests the two sorting algorthm speeds, displaying their difference	

NOTE: You must type "make [file]" on the command line to create the executable. These are the 3 you can make:
		-"make heapDriver"
		-"make sortPrint"
		-"make sortComp"


   Experimental Procedure

For our experimental procedure, we tested our sortComp program (implementing both insertionSort and heapSort) on the ucsc unix timeshare using exponential powers of ten for input sizes. We ran each input size 3 times and here's what we came up with (note
the following times are in seconds):

	
	INPUT SIZE	INSERTIONSORT TIME	HEAPSORT TIME
		
	10		0.000000		0.000000
		
	100		0.000000		0.000000
		
	1,000		0.000000		0.000000
		
	10,000		0.130000		0.000000
		
	100,000		10.720000		0.030000


Before the experiment, we hypothesized that heapSort would run slightly faster, but didn't know exactly how much faster. By our experiment, however, we've found that heapSort, for much larger input size, has a significantly faster sorting time than insertionSort. This is proven by the fact that insertionSort has a worst case running time of O(n^2) whereas heapSort has a worst case running time O(nlogn).

	
	
We also tested on two different machines; one in the BE105 computer lab (hooked directly to the UCSC server) and a laptop using Putty wirelessly through the unix timeshare. We found that the lab PC ran FASTER with insertionSort over the laptop, but SLOWER with heapSort. While there's no clear answer as to why, we think this might be due to network connections giving a slightly delayed signal. These tests were done 5 times to guarantee our results. The results above are the ones made running the program on the lab PC's in BE105. 
In conclusion, for larger sizes of input, heapSort has the clear advantage over insertionsort and for smaller inputs (around 1,000), they're virtually identical.