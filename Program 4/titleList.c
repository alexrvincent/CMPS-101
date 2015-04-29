/* Programmer: Alex Vincent (avincent@ucsc.edu)
	This program is the implementation file for the titleList ADT
	file. See the header file for a breakdown of the capabilities
	and list of all the methods for this of the ADT. 
	
	Modified to hold STRINGS and LISTHNDLS
*/

#include "titleList.h"
#include "IDList.h"
#include "myinclude.h"
#include <string.h>
#include <assert.h>

typedef struct NodeStruct * NodePtr;

typedef struct NodeStruct 
{
	char (*title);
	IDListHndl libraryList;
	
	struct NodeStruct* next;
	struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct 
{
	NodePtr first;
	NodePtr last;
	NodePtr curr;
} ListStruct;


ListHndl NewList () 
{
	ListHndl tempList;
	tempList = malloc ( sizeof(ListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	return tempList;
}

void freeList (ListHndl * L)
{
	NodePtr tempCurr;
	assert((*L) != NULL);
	tempCurr = (*(L))->first;
	(*(L))->curr = (*(L))->first;
	while((*(L))->curr != NULL)
	{
		tempCurr = (*(L))->curr->next;
		free((*(L))->curr); 
		(*(L))->curr = tempCurr;
	}
	(*(L))->first = NULL;
	(*(L))->curr = NULL;
	(*(L))->last = NULL;
	free((*L));
	(*L) = NULL;
}

int isEmpty(ListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

void insertAtFront(ListHndl L, char * string, int libraryNumber)
{
	assert( L != NULL);
        L->curr = L->first;

	/* CHECK: If the string is the same as any other in the list, insert just the ID*/
	while(L->curr != NULL)
	{
		if(strcmp(string, L->curr->title) == 0)
		{
			insertAtFrontID(L->curr->libraryList, libraryNumber);
                	L->curr = L->first;
			return;
		}
		L->curr = L->curr->next;
	}
	
	L->curr = L->first;

	/* If this check fails, the title is not in the list!
 	*  This means we'll just make a new titleList node with it's ID */
	L->curr = L->first;

	NodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(NodeStruct) );

	tempNode->title = string;
	tempNode->libraryList = NewIDList();
	insertAtFrontID(tempNode->libraryList, libraryNumber);
	tempNode->next = L->first;
	tempNode->prev = NULL;

	/*Handle special case for first-in-list*/
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

void printList(ListHndl L)
{
	int i = 0;
	NodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	printf("\n");
	/* Print every title at every node */
	while(tempCurr != NULL)
	{
		/* Print every letter of evert title*/
		for (i = 0; tempCurr->title[i] != '\0'; i++)
		{
		printf("%c", tempCurr->title[i]);
		}
		printf(" ");
		/* Then print the title's libraryID's */
		printIDList(tempCurr->libraryList);
		printf("\n");
		tempCurr = tempCurr->next;
	}
}

void lookUpTitle(ListHndl L, char * title)
{
	assert ( L != NULL);
	L->curr = L->first;
	/* For every node in the titleList */
	while (L->curr != NULL)
	{
		/* Compare the passed title and the title at that node
 		*  If they're the same, print the libraryID's associated
 		*  with that node */
		if(strcmp(title, L->curr->title) == 0)
		{
			printIDList(L->curr->libraryList);
			printf("\n");
			L->curr = L->first;
			return;
		}
		L->curr = L->curr->next;
	}
	L->curr = L->first;
	/* Otherwise it failed! Print an error message */
	printf("Sorry, %s isn't currently at any library.\n", title);
}

void freeTitleList(ListHndl L)
{
	NodePtr tempCurr;
	assert( L != NULL);
	tempCurr = L->first;
	while(L->curr != NULL)
	{
		tempCurr = L->curr->next;

		free(L->curr->title);
		freeIDList(L->curr->libraryList);
		free(L->curr);

		L->curr = tempCurr;
	}
	L->first = NULL;
	L->curr = NULL;
	L->last = NULL;
	free(L);
	L = NULL;
}
