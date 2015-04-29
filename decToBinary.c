#include "myinclude.h"
#include "intstack.h"

/* Author: Alex Vincent, email: avincent@ucsc.edu
 * 
 * This short program uses the intstack ADT given by David Helmbold to create binary representations
 * of decimal numbers. I, the author, only recieved help from cplusplus.com on the correct
 * use of scanf to read integers from the standard input. Everything else was created, tested and debugged 
 * myself using the files provided. Enjoy!
 *
 * */
	

int main()
{
	/*Create an empty stack and variable placeholder*/
	int numberRead;
	StackHndl TheStack;
	TheStack = NULL;
	TheStack = NewStack();
	
	printf("Input a non-negative integer to be converted into binary: \n");
	while(scanf("%d", &numberRead) == 1)
	{
		/*Negative numbers are alerted as errors and not converted*/
		if(numberRead < 0) 
		{
			printf("%d is a negative integer! Try again.\n", numberRead);
			continue;
		}
		
		/*Zero cases are handled separately*/
		if(numberRead == 0) Push(TheStack, 0);
		
		/*Loop that iterates down the number*/
		while(numberRead > 0)
		{
			if(numberRead%2 != 0) Push(TheStack, 1);
			else Push(TheStack, 0);
			numberRead = numberRead/2;
		}
		
		/*PRINTING SECTION*/
		printf("The binary representation of that is: ");
		while(!IsEmpty(TheStack))
		{
			printf("%d",Top(TheStack));
			Pop(TheStack);
		}
		printf("\n");
	}

	FreeStack(&TheStack);
	return 0;
}
