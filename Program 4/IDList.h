/* Programmers: Alex Vincent (avincent@ucsc.edu)
 * 	        previous version implemented with help of Chris Dilday.
	
	NOTE, explicit Post/Pre-conditions are listed above the group of functions
	to which it applies as to avoid needless descriptions.*/

#include <stdio.h>

/*Declaration of the ListHandle empty pointer. Set it to null
 *when you first use it! */
typedef struct IDListStruct * IDListHndl;

/* This function will allocate memory for a new list, returning
 *a POINTER to the thing allocated */
IDListHndl NewIDList();

/* NOTE HERE: All methods below require the Pre-condition that L is NOT null, either through
	!offEnd() or that L has been created with NewList(). This is made noted here as to avoid
	repetition of the same saying.*/

/* This function ACCEPTS a pointer to a ListHandle and will free
 * every Node in the list, as well as the list itself. */
void freeIDList (IDListHndl L); /*Pre condition -> L was made with NewList*/

/* This checks to see whether the ListStruct points to any struct nodes. 
 * If it points to anything NOT null, it will return 1. 
 * If it all it points to are NULL things, it will return 0. */
int isEmptyID (IDListHndl L);

/* Inserts a node into the beginning of the list, current pointer stays the same! Post-condition: Longer list */
void insertAtFrontID(IDListHndl L, int libraryNumber);

/* Prints out the entire list to STDOUT, 
 * make sure to change it to print to a file - special case when list is empty*/
void printIDList(IDListHndl L);

