/* Programmer: Alex Vincent (avincent@ucsc.edu)
	This program has been created using the Hashtable ADT.
	This program accepts two files at the command line: 1) A file to read in from and stores
	the information there and 2) requests that ask for information stored. For a breakdown of 
	the creation of this file, see the attached README, as well as the other files in this directory. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashTable.h"

int main(int argc, char **argv)
{
   char buffer[100];
   char buffer2[100];
   
   /* These are to be changed by the first file */
   int inputLineSize = 0;
   int hashTableSize = 0;
   
   FILE *file;
   argc = argc;
   
   /* Open and begin reading the first file */
   file = fopen(argv[1], "r");
   
   /* Check for the case where the file does not exist */
   if(file == NULL)
	{
		printf("ERROR: Could not find file in directory. Closing program.\n");
		exit(1);
	}
	
	/* Grab the first line with fgets, put it into the buffer */
	for(int i = 0; i < 1 && fgets(buffer, sizeof buffer, file); i++) 
	{
		/*Now use sscanf to chop up the line into the parts we need*/
		sscanf(buffer, "%d %d", &inputLineSize, &hashTableSize);
		//printf("%d %d\n", inputLineSize, hashTableSize); //Debug print
	}

	/* Create the new hash table with the information we got */
	HashHndl theHashTable = NULL;
	theHashTable = newHashTable(hashTableSize);
	/*char *stringPtrs[]; */
		
	/* Now begin grabbing the lines one by one */
	for (int i = 0; i <= inputLineSize && fgets(buffer, sizeof buffer, file); i++)
	{
		 int tempLibraryID = 0;
		 char* tempPtr = NULL;
		 sscanf(buffer, "%d", &tempLibraryID);
		/*Get the ID Number */
		 tempPtr = strtok(buffer, " "); // Use 'space' as delimiter
		 tempLibraryID = atoi(tempPtr); //the current LibraryID given by input number

		/* Get the string and save it*/
		 tempPtr = strtok(NULL, "\n");
		 if(tempPtr == NULL) break;
		 assert(tempPtr != NULL);	
		 char *saveString = (char*) malloc(100*sizeof(char));
		 strcpy(saveString, tempPtr);
		 
		/*Now store the string if it's not null */
		 if(saveString == NULL) break;
		 else insert(theHashTable, saveString, tempLibraryID);
	}

	/* We're done with the input file, close it and move on */	
	fclose(file);


	/* Now open the second file and begin taking requests */
	int inputLineSize2 = 0;
	file = fopen(argv[2], "r");

        /* Handle case where the second file is invalid */
	if(file == NULL)
	{
	  printf("Error: Could not find second file. Closing program");
	  exit(1);
	}
	
	/*Grab the input size from the first line */
	for (int i = 0; i < 1 && fgets(buffer2, sizeof buffer2, file); i++)
	{
		sscanf(buffer, "%d", &inputLineSize2);
	}
	
	/* Now just read each line and call a look up on the string you read */
	for (int i = 0; i <= inputLineSize2 && fgets(buffer2, sizeof buffer2, file); i++)
	{
		char * tempPtr = strtok(buffer2, "\n");
		lookUp(theHashTable,tempPtr);
	}

   freeHashTable(theHashTable);		
   return 0;
}
