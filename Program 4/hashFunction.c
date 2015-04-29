/* Programmer: Alex Vincent (avincent@ucsc.edu)
 * Implementation of hash function using a loose version Horners Method */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
int hashFunction (HashHndl h, char * string)
{
	int hashCode = 0;
	unsigned int i;
	/* Iterate through the string, adding it's binary value to a
 	*  recursive sum of the product of itself and 33. */
	for (i = 0; i < strlen(string); i++)
	{
		hashCode = (33 * hashCode + (*string))%getHashSize(h);
		string++;
	}
	/*Modulo hash table to get desired range*/
	hashCode = hashCode%getHashSize(h);
	return hashCode;
}
