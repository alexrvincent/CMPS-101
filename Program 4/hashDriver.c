/* This file will test the hashTable.c module. See below for specifics */
/* Written by Alex Vincent (avincent@ucsc.edu) */

#include "myinclude.h"
#include "hashTable.h"

int main(void)
{
   HashHndl theHashTable = NULL;
   theHashTable = newHashTable(10);
   
   char *stringPtr;
   char title1[] = "Frankenstein";
   char title2[] = "Don Quixote";
   char title3[] = "Pilgrim's Progress";
   char title5[] = "Gulliver's Travels";
   char title6[] = "Tom Jones";
   char title7[] = "Clarissa";
   char title8[] = "Tristram Shandy";
   char title9[] = "Dangerous Liaisons";
   char title12[] = "Nightmare Abbey";
   char title14[] = "The Charterhouse of Parma";


   stringPtr = title1;
   insert(theHashTable, stringPtr, 91);
   stringPtr = title2;
   insert(theHashTable, stringPtr, 47);
   stringPtr = title8;
   insert(theHashTable, stringPtr, 21);
   stringPtr = title5;
   insert(theHashTable, stringPtr, 42);
   stringPtr = title9;
   insert(theHashTable, stringPtr, 58);
   stringPtr = title14;
   insert(theHashTable, stringPtr, 17);
   stringPtr = title3;
   insert(theHashTable, stringPtr, 45);
   stringPtr = title7;
   insert(theHashTable, stringPtr, 36);
   stringPtr = title5;
   insert(theHashTable, stringPtr, 20);
   stringPtr = title12;
   insert(theHashTable, stringPtr, 81);
   stringPtr = title6;
   insert(theHashTable, stringPtr, 74);
   stringPtr = title5;
   insert(theHashTable, stringPtr, 2);
   
   printf("\t######## PRINT THE HASH TABLE #######\n");
   printHash(theHashTable);
   printf("\n");

   printf("\t#######  LOOK UP IN THE HASH TABLE #######\n");	
   lookUp(theHashTable, "Gulliver's Travels"); // Should print 2, 20, 42
   lookUp(theHashTable, "The Stranger"); // Prints error message not in the table
   lookUp(theHashTable, "Tom Jones"); // Should print 74
   
}
