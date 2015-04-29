/* Programmers: Alex Vincent (avincent@ucsc.edu), Nader Sleem (nsleem@ucsc.edu)
 * this is a program to compare the running times of the insertionSort
 * and heapSort algorithms.
 * Lasted edited by -- Nader ( 5/1/14 )*/
 
 #include "myinclude.h"
 #include "insertionSort.h"
 #include "heapSort.h"
 #include <time.h>
 
 int main (int argc, char **argv)
 {
	clock_t startTime, duration;
	
	/*read in data, initialize array of unsorted keys*/
	char buffer[10000];
	FILE *file;
	argc = argc;
	int arraySize = 0;
	int k = 0;

	/*File getting error handling*/
	file = fopen(argv[1], "r");
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
	/* Print size of input */
    printf("Total # of inputs: %d \n",arraySize);
	
    int theArray[arraySize];
	int secondArray[arraySize];
	
	/*read in data and put it in the array*/
	for (k = 0; k < arraySize && fgets(buffer, sizeof buffer, file); k++)
	{
		theArray[k] = atoi(buffer);
		secondArray[k] = atoi(buffer);
	}
	
	/*Begin clock counting*/
	startTime = clock();
	
	/*run insertionSort*/
	insertionSort(theArray, arraySize);
	/*Get the duration of insertionSort */
	duration = clock() - startTime;
	printf("insertionSort took %f seconds. \n", (float) (duration) / CLOCKS_PER_SEC);
    
    /* Begin clock again */
    startTime = clock();
    /*This time run heapSort */
    heapSort(secondArray, arraySize);
	/*Get the duration of heapSort */
    duration = clock() - startTime;
	printf("heapSort took %f seconds. \n", (float) (duration) / CLOCKS_PER_SEC);
    
    fclose(file);
	return (0);
}
