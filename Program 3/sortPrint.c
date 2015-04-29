/* Programmers : Alex Vincent (avincent@ucsc.edu), Nader Sleem (nsleem@ucsc.edu)
 * This is a test/ "driver" program to test the implementation of the
 * insertionSort and the heapSort functions. Feel free to experiment 
 * with this to see how the implementation works
  * Last Edited by Alex (4/30/14)*/

#include "insertionSort.h"
#include "heapSort.h"
#include "heap.h"
#include "myinclude.h"

int main(int argc, char **argv)
{
	char buffer[10000];
	FILE *file;
	argc = argc;

	int arraySize = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	file = fopen(argv[1], "r");

	/*File getting error handling*/
	if (file == NULL)
	{
		printf("Error, no file found \n");
		exit(1);
	}
	/*Get the array size*/
	for(k = 0; k < 1 && fgets(buffer, sizeof buffer, file); k++)
	{
		arraySize = atoi(buffer);
	}

    	printf("Array size:  %d\n",arraySize);
	int insertionArray[arraySize];
	int heapArray[arraySize];

	/*read in data and put it in the array*/
	for (k = 0; k < arraySize && fgets(buffer, sizeof buffer, file); k++)
	{
		insertionArray[k] = atoi(buffer);
		heapArray[k] = atoi(buffer);
	}
	

	/* INSERTION SORT TEST */	
	/*Print array size before insertionSort call */
	printf("Print the array before insertionSort: \n");
	for(i = 0; i < arraySize; i++)
	{
		printf("%d ", insertionArray[i]);
	}
	printf("\n\n");

	insertionSort(insertionArray, arraySize);

	/*Print array size after insertionSort call */
	printf("Print the array AFTER insertionSort: \n");
	for (j = 0; j < arraySize; j++)
	{
		printf("%d ", insertionArray[j]);
	}
	printf("\n\n");



	/* HEAPSORT TEST */
	/* Print array size before heapSort call */
	printf("Print the array before heapSort: \n");
	for(i = 0; i < arraySize; i++)
	{
		printf("%d ", heapArray[i]);
	}
	printf("\n\n");
	
	heapSort(heapArray, arraySize);

	/*Print array size after heapSort call */
 	printf("Print the array after heapSort: \n");
	for(j = 0; j < arraySize; j++)
	{
		printf("%d ", heapArray[j]);
	}
	printf("\n\n");

	fclose(file);
	return(0);
} 
