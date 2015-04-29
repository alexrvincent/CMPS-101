/* Programmers: Alex Vincent (avincent@ucsc.edu)
				Chris Dilday (cdilday@ucsc.edu)
		This is a test/ "driver" program to test the implementation of the
		List ADT created. Feel free to experiment with this file to understand
		how the implementation works.*/

#include "List.h"
#include "myinclude.h"

int main ()
{
	long testData = 98;
	long testData2 = 97;
	long testData3 = 99;

	/* List creation */
	ListHndl TheList;
	TheList = NULL;
	TheList = NewList();
	
	if(isEmpty(TheList)) printf("The list is empty \n");

	insertAtFront(TheList, testData);
	insertAtBack(TheList, testData2);
	insertAtBack(TheList, testData3);
	insertAtBack(TheList, testData2);
	insertAtFront(TheList, testData);
	insertAtBack(TheList, testData2);
	insertAtFront(TheList, testData);
	insertAtFront(TheList, testData3);
	
	printf("Current is %lu\n", getCurrent(TheList));
	moveLast(TheList);
	printf("Current is %lu\n", getCurrent(TheList));
	moveFirst(TheList);
	printf("Current is %lu\n", getCurrent(TheList));
	moveNext(TheList);
	printf("Current is %lu\n", getCurrent(TheList));
	movePrev(TheList);
	printf("Current is %lu\n", getCurrent(TheList));

	insertBeforeCurrent(TheList, testData2);
	printf("Inserted %lu before %lu, which means %lu is before %lu\n", testData2, testData3, getFirst(TheList), getCurrent(TheList));
	
	printf("Printing the entire list.. ");
	printList(TheList);
	
	deleteFirst(TheList);
	deleteLast(TheList);
	printf("Printing the entire list after deleting first & last.. ");
	printList(TheList);
	moveNext(TheList);
	moveNext(TheList);
	moveNext(TheList);
	movePrev(TheList);
	printf("Printing the entire list after deleting current: %lu.. ", getCurrent(TheList));
	deleteCurrent(TheList);
	printList(TheList);
	
	moveFirst(TheList);
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	printf("Printing FIRST, CURRENT, LAST... ");
	printf("%lu, %lu, %lu \n", getFirst(TheList), getCurrent(TheList), getLast(TheList));
	
	
	printf("Printing the entire list.. ");
	printList(TheList);
	
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	makeEmpty(TheList);
	
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 

	freeList(&TheList);
	
	return(0);
}
