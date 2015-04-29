/* This file will test the titleList.c module. See below for specifics */
/* Written by Alex Vincent (avincent@ucsc.edu) */

#include "myinclude.h"
#include "titleList.h"

int main(void)
{

   ListHndl theList = NULL;
   theList = NewList();
   
   char test1[] = "The Sun Also Rises";
   char test2[] = "To Kill A MockingBird";
   char test3[] = "Catcher in the Rye";
   char test4[] = "Hamlet";
   char test5[] = "Hamlet";
   
   /*Load the pointers with the arrays, put them into the list*/
   char *testPtr;
   testPtr = test1;
   insertAtFront(theList, testPtr, 35);
   testPtr = test2;
   insertAtFront(theList,testPtr, 53);
   testPtr = test3;
   insertAtFront(theList, testPtr, 289);

   /*Load in a same string, with different ID. Shouldn't make a new node, but rather
    * Add the ID to the node with the same book title*/
   testPtr = test2;
   insertAtFront(theList,testPtr,1000);
   testPtr = test4;
   insertAtFront(theList,testPtr,53);
   testPtr = test5;
   insertAtFront(theList,testPtr,35);
   
   printf("\t###### PRINT THE TITLE LIST WITH LIBRARY NUMBERS ######");
   printList(theList);
   /*The list above should print:
    * Hamlet 35 53
    * Catcher in the Rye 289
    * To Kill A Mockingbird 1000 53
    * The Sun Also Rises 35 */ 
   
}
