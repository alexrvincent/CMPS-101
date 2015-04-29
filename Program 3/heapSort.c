/* Implementation for the heapSort function using the heap ADT
 * Created by Alex Vincent (avincent@ucsc.edu) and Nader Sleem (nsleem@ucsc.edu) 
 * Last edited --- by Alex Vincent 5/1/14*/

#include "myinclude.h"
#include "heapSort.h"
#include "heap.h"

void heapSort(int keys[], int numKeys)
{
	/* Initialize variables, create empty sorted array */
	int i, j;

	/* Create new heap handle */
	heapHndl H = NULL;
	H = newHeap(numKeys);

	/* Copy all array data into the heap */
	for (i = 0; i < numKeys; i++)
	{
		insert(H,keys[i]);
	}
	
	/* Continuously put the top value in the heap in the array */
	for (j = 0; j < numKeys; j++)
	{
		keys[j] = maxValue(H); 
		deleteMax(H); 
	}
    
    freeHeap(&H);
}
