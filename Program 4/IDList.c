/* Programmers: Alex Vincent (avincent@ucsc.edu)
	This program is the implementation file for the IDList ADT
	file. See the header file for a breakdown of the capabilities
	and list of all the methods for this of the ADT. 
	
	Modified to hold INTS
*/

#include "IDList.h"
#include "myinclude.h"
#include <assert.h>

typedef struct IDNodeStruct * IDNodePtr;

typedef struct IDNodeStruct 
{
	int libraryNumber;
	struct IDNodeStruct* next;
	struct IDNodeStruct* prev;
} IDNodeStruct;

typedef struct IDListStruct 
{
	IDNodePtr first;
	IDNodePtr last;
	IDNodePtr curr;
} IDListStruct;

IDListHndl NewIDList () 
{
	IDListHndl tempList;
	tempList = malloc ( sizeof(IDListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	return tempList;
}

void freeIDList (IDListHndl L)
{
	IDNodePtr tempCurr;
	assert(L != NULL);
	tempCurr = L->first;
	L->curr = L->first;
	while(L->curr != NULL)
	{
		tempCurr = L->curr->next;
		free(L->curr); 
		L->curr = tempCurr;
	}
	L->first = NULL;
	L->curr = NULL;
	L->last = NULL;
	free(L);
	L = NULL;
}

int isEmptyID(IDListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

void insertAtFrontID(IDListHndl L, int libraryNumber)
{
	IDNodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(IDNodeStruct) );

	/* Unconditionlly insert a new libraryNumber into the list*/
	tempNode->libraryNumber = libraryNumber;
	tempNode->next = L->first;
	tempNode->prev = NULL;

	/* Handle special case: first insertion */
	if(L->first == NULL)
	{ 
		L->first = tempNode;
		L->last = tempNode;
		L->curr = tempNode;
	}
	else
	{
		L->first->prev = tempNode;
		L->first = tempNode;
	}

}
void printIDList(IDListHndl L)
{
	IDNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	/* Every node, unconditionally print every integer there */
	while(tempCurr != NULL)
	{
		printf("%d ", tempCurr->libraryNumber);
		tempCurr = tempCurr->next;
	}
}
