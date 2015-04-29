/* Implementation of the HEAP ADT, see header file for function details */
/* Written by Nader Sleem (nsleem@ucsc.edu) */
/* and Alex Vincent (avincent@ucsc.edu) */
/* Last Edited by --- Nader Sleem 4/29/14 */

#include "heap.h"
#include "myinclude.h"
#include <assert.h>

/* HeapStruct struct implementation */
struct HeapStruct {
   int maxSize;
   int currSize;
   int (*array);
};

heapHndl newHeap(int maxSize){
   heapHndl H;
 
   H = malloc(sizeof(HeapStruct));
   H->maxSize = maxSize;
   H->currSize = 0;
   H->array = (int*)malloc((H->maxSize+1) * sizeof(int));
   
   return H;
}

int isFull (heapHndl H){
   assert( H != NULL );
   
   if( H->maxSize == H->currSize) return 1;
   else return 0;
}

int isEmpty (heapHndl H){
   assert(H != NULL);
   
   if(H->currSize == 0) return 1;
   else return 0;
}

int maxValue (heapHndl H){ 
   assert(H != NULL);
   assert(!isEmpty(H));
   
   /*Max element is always at index 1 */
   return H->array[1]; 
}

void deleteMax(heapHndl H){
   int i, temp;
   assert(H != NULL);
   assert(!isEmpty(H));
   
   i = 1;
   H->array[i] = H->array[H->currSize];
   H->currSize = H->currSize - 1; 
   /* while i has a child. 
      Atleast 1 child means it must be a lchild */
   while( 2*i <= H->currSize ){     
      /* if i has 2 children in heap */
      if( (2*i) <= H->currSize && (2*i)+1 <= H->currSize ){ 
         /* if the lchild is bigger than rchild */
         if(H->array[2*i] >= H->array[(2*i)+1]){ 
            /* and if lchild is bigger than its parent */
            if( H->array[i] <= H->array[2*i] ){ 
               temp = H->array[i];  
               H->array[i] = H->array[2*i]; /*swap them */
               H->array[2*i] = temp;
               i = 2*i;
            }else break;
         /* else if rchild is bigger than lchild */
         }else if( H->array[2*i] < H->array[(2*i)+1] ){ 
            /* and if rchild is bigger than its parent */
            if( H->array[i] <= H->array[(2*i)+1] ){ 
               temp = H->array[i];
               H->array[i] = H->array[(2*i)+1];/*swap them */
               H->array[(2*i)+1] = temp;
               i = (2*i)+1;
            }else break;
         }
      /* else if i has only a single child in the heap 
         Single child is always a lchild */
      }else if( (2*i) <= H->currSize ){
         /* and if the child is bigger than the parent */
         if( H->array[i] <= H->array[2*i] ){
            temp = H->array[i];  
            H->array[i] = H->array[2*i]; /*swap them */
            H->array[2*i] = temp;
            i = 2*i; 
         }else break;
      }
   }
}

void insert (heapHndl H, int priority){
   int i, temp;
   assert( H != NULL );
   assert(H->currSize <= H->maxSize);
   
   H->currSize = H->currSize + 1;
   i = H->currSize;
   H->array[i] = priority;
   if (i == 1) return;
   else{
      while( i > 1 && H->array[i] > H->array[i/2] ){
         temp = H->array[i/2];
         H->array[i/2] = H->array[i];
         H->array[i] = temp;
         i = i/2;
      }
   }
} 

void freeHeap(heapHndl * H){
   assert( *H != NULL );
   
   free((*H)->array);
   free(*H);
   H = NULL;
}
