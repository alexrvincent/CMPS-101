/* Header file for the list module ADT, describing the list ADT functions
   for the use of a client */
   
 /* Programmers: Alex Vincent (avincent@ucsc.edu)
		 first implementation with help of Chris Dilday (cdilday@ucsc.edu)
	This is the header file for the List ADT. Here you will find
	descriptive prototypes for the functions implemented in the
	List.c files. To make proper use of this ADT
	
		-Create a ListHndl pointer
		-Assign the pointer to a ListStruct using NewList()
		-Use the methods here on the pointer as seen
	
	The explicit implementation of this ADT can be seen in the List.c file. 
	NOTE, explicit Post/Pre-conditions are listed above the group of functions
	to which it applies as to avoid needless descriptions. Also, this header
	was modified from assignment 2 to hold integer values*/

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
void freeList (ListHndl* L); /*Pre condition -> L was made with NewList*/

/* This checks to see whether the ListStruct points to any struct nodes. 
 * If it points to anything NOT null, it will return 1. 
 * If it all it points to are NULL things, it will return 0. */
int isEmpty (ListHndl L);

/*Returns 0 if the current pointer is not on the list (aka pointing to null) */
int offEnd (ListHndl L);

/* Returns 0 if the curr pointer is pointing to first, with !offEnd() pre-condition */
int atFirst(ListHndl L);

/* Return 0 if the curr pointer is pointing to last, with !offEnd() pre-condition */
int atLast (ListHndl L);

/* Returns the data (number) from the node without altering the function */
int getFirst(ListHndl L);
int getLast(ListHndl L);
int getCurrent(ListHndl L);

/* Inserts a node into the beginning of the list, current pointer stays the same! Post-condition: inter list */
void insertAtFront(ListHndl L, int data);

/*Inserts a node into the end of the list, current pointer stays the same! Post-condition: inter list*/
void insertAtBack(ListHndl L, int data);

/* Prints out the entire list to STDOUT, 
 * make sure to change it to print to a file - special case when list is empty*/
void printList(ListHndl L);

/* Prints entire list to A FILE*/
void printListFile(ListHndl L, FILE *file);

/*Makes the list empty by going through and freeing nodes. Sets first, current, and last pointers to null. 
	Post-condition: the list will be empty*/
void makeEmpty(ListHndl L);

/*Post condition for the following functions are that the current pointer will be moved. 
	See below for specific place current will be moved to. */

/*points the current pointer to the first element*/
void moveFirst(ListHndl L);

/*points the current pointer to the last element*/
void moveLast(ListHndl L);

/*Moves the current marker to the previous element*/
void movePrev(ListHndl L);

/*Moves the current marker to the next element*/
void moveNext(ListHndl L);

/*Inserts a new node before the current node*/
void insertBeforeCurrent(ListHndl L, int data);

/* Post condition for the following functions is that the ADT is guaranteed to have fewer nodes. */

/*Deletes the first element in the list*/
void deleteFirst(ListHndl L);

/*Deletes the last element in the list*/
void deleteLast(ListHndl L);

/*Deletes the current element in the list and leaves curr = NULL*/
void deleteCurrent(ListHndl L);
