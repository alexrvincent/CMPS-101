/* Programmer: Alex Vincent (avincent@ucsc.edu)
 * Implementation of hashTable ADT.
 * See header file for function descriptions (as most of the 
 * comments are there)! */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "myinclude.h"
#include "hashTable.h"
#include "titleList.h"
#include "hashFunction.h"

/* Struct holds data fields */
struct HashStruct {
   int maxSize;
   ListHndl (*table);
};

HashHndl newHashTable(int maxSize)
{
   HashHndl H;
   H = malloc(sizeof(HashStruct));
   H->maxSize = maxSize;
   H->table = malloc(maxSize * sizeof(ListHndl));

   /* Give every entry in the hash table an empty list handle */
   for( int i = 0; i < maxSize; i++)
   {
	H->table[i] = NewList();
   }
   return H;
}

void insert(HashHndl h, char * title, int libraryID)
{
        char * passedTitle = title;
	assert(h != NULL);
	int hashedIndex = 0;
	/*Hash the title*/
	hashedIndex = hashFunction(h, title);
	/* Insert it (this function handles collisions) */
	insertAtFront(h->table[hashedIndex], passedTitle, libraryID);
}
	
int getHashSize(HashHndl h)
{
	assert(h != NULL);
	return h->maxSize;
}

void printHash(HashHndl h)
{
	assert(h != NULL);
        /* For usefulness, print out the index of the hash table
	 * as well as all the contents in it's lists*/
	for(int i = 0; i < h->maxSize; i++)
	{
		assert(h->table[i] != NULL);
		printf("[%d]: ", i);
		printList(h->table[i]);
	}
}

void lookUp(HashHndl h, char * title)
{
	assert (h != NULL);
	int hashedIndex = 0;
	/* Hash the title and see if it's in the hash table*/
	hashedIndex = hashFunction (h, title);
	lookUpTitle(h->table[hashedIndex], title);
}

void freeHashTable(HashHndl  h)
{
	assert(h != NULL);
	for(int i = 0; i < h->maxSize; i++){
	freeTitleList(h->table[i]);
	}
	/*Will need to free lists too!*/
	free(h);
	h = NULL;
	
}		
