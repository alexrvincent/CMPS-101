/* Implementation for the insertionSort function
 * Created by Alex Vincent (avincent@ucsc.edu) and Nader Sleem (nsleem@ucsc.edu)
 * Last Edited by Alex (4/29/14)
 * Description: taking an unsorted array and the array size, sorts the array
 * using the insertion sort algorithm */

#include "myinclude.h"
#include "insertionSort.h"

void insertionSort (int keys[], int numKeys)
{
	int i, k, temp;
	for (i = 1; i < numKeys; i++)
	{
		/*Begin at an increasing spot in the array*/
		k = i;
		/*At each iteration, swap the value if the next term is less than than the first*/
		while (k > 0 && keys[k] < keys[k-1]) 
		{
			temp = keys[k];
			keys[k] = keys[k-1];
			keys[k-1] = temp;
			k--;
		}
	}
}
