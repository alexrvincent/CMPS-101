/* This file will test the hashTable.c module. See below for specifics */
/* Written by Alex Vincent (avincent@ucsc.edu) */

#include "myinclude.h"
#include "IDList.h"

int main(void)
{

   IDListHndl theList = NULL;
   theList = NewIDList();
   
   /*The items are inserted onto the front of the list,
    *so they will be printed backwards in a Stack-like fashion*/ 
   insertAtFrontID(theList, 1);
   insertAtFrontID(theList, 2);
   insertAtFrontID(theList, 3);
   insertAtFrontID(theList, 4);
   insertAtFrontID(theList, 5);
   insertAtFrontID(theList, 6);
   insertAtFrontID(theList, 7);
   insertAtFrontID(theList, 8);
   insertAtFrontID(theList, 9);
   insertAtFrontID(theList, 10);

   printIDList(theList);
   printf("\n");
   printf("Should print 10 9 8 7 6 5 4 3 2 1\n");
   return 0;
}

