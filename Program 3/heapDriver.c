/* This file will test the heap.c module. See below for specifics */
/* Written by Nader Sleem (nsleem@ucsc.edu) and Alex Vincent (avincent@ucsc.edu) */
/* Last Edited by: Nader Sleem 4/29/14 */

#include "myinclude.h"
#include "heapSort.h"
#include "heap.h"

int main(void){
   int tester;
   
   int A[] = {10,20,30,40,50,60,70,90,90,100};
   heapHndl H = NULL;
   H = newHeap(5);

   tester = isFull(H);
   printf("The initial isFull should be 0: %d\n",tester);
   
   tester = isEmpty(H);
   printf("The initial isEmpty should be 1: %d\n",tester);

   insert(H,1);
   printf("The max value is: %d\n",maxValue(H));
   insert(H,2);
   printf("The max value is: %d\n",maxValue(H));
   insert(H,3);
   printf("The max value is: %d\n",maxValue(H));
   insert(H,4);
   printf("The max value is: %d\n",maxValue(H));
   insert(H,5);
   printf("The max value is: %d\n",maxValue(H));

   tester = maxValue(H);
   printf("The max value should be 5: %d\n",tester);
   
   tester = isFull(H);
   printf("The initial isFull should be 1: %d\n",tester);
   
   
   deleteMax(H);
   tester = maxValue(H);
   printf("The max value after deleing should be 4: %d\n",tester); 
   
   deleteMax(H);
   tester = maxValue(H);
   printf("The max value after deleing should be 3: %d\n",tester); 
   
   deleteMax(H);
   tester = maxValue(H);
   printf("The max value after deleing should be 2: %d\n",tester); 

   deleteMax(H);
   tester = maxValue(H);
   printf("The max value after deleing should be 1: %d\n",tester); 
   
   deleteMax(H);
   tester = isEmpty(H);
   printf("The final isEmpty should be 1: %d\n",tester);
   
   
   /* Test for heapSort */ 
   
   heapSort(A,10);
   for(tester = 0; tester <= 9; tester++){
      printf(" %d ",A[tester]);
   }
   printf("\n");
   
   freeHeap(&H);
   return 0;
   
}
