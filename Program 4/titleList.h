/* Programmers: Alex Vincent (avincent@ucsc.edu)
 *              revised implementation from CS101 asg2 with Chris Dilday
	
	This module implements the linked list ADT holding as it's data fields
	a string and a list handle to a linked list of integers. This is a 
	custom made linked list module for this assignment.

	NOTE, explicit Post/Pre-conditions are listed above the group of functions
	to which it applies as to avoid needless descriptions.*/

#include <stdio.h>
/*Declaration of the ListHandle empty pointer. Set it to null
 *when you first use it! */
typedef struct ListStruct * ListHndl;

/* This function will allocate memory for a new list, returning
 *a POINTER to the thing allocated */
ListHndl NewList ();

/* NOTE HERE: All methods below require the Pre-condition that L is NOT null, either through
	!offEnd() or that L has been created with NewList(). This is made noted here as to avoid
	repetition of the same saying.*/

/* This function ACCEPTS a pointer to a ListHandle and will free
 * every Node in the list, as well as the list itself. */
void freeTitleList (ListHndl L); /*Pre condition -> L was made with NewList*/

/* This checks to see whether the ListStruct points to any struct nodes. 
 * If it points to anything NOT null, it will return 1. 
 * If it all it points to are NULL things, it will return 0. */
int isEmpty (ListHndl L);

/* Inserts a node into the beginning of the list, current pointer stays the same! Post-condition: Longer list */
void insertAtFront(ListHndl L, char * string, int libraryNumber);

/* Prints out the entire list to STDOUT, 
 * make sure to change it to print to a file - special case when list is empty*/
void printList(ListHndl L);

/*Pre-Condition: List handle is not null
 * Post-Condition: nothing
 * Description: will print the libraryId's associated with the title if found
 * otherwise will print and error message.*/
void lookUpTitle(ListHndl L, char * title);
