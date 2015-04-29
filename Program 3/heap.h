/* Header file for the heap implementation */
/* Written by Alex Vincent (avincent@ucsc.edu)
   and Nader Sleem (nsleem@ucsc.edu) 
   Last edited by Nader (4/29/14)*/ 

/* HeapStruct struct initialization 
The HeapStruct will contain information about the maximum size of the heap,
the current size of the heap, and a pointer to the heap itself */
typedef struct HeapStruct HeapStruct;

/*Handle definition. The client will need to declare this as an empty pointer,
 *then use "newHeap" to assign it to a usable structure.*/
typedef struct HeapStruct * heapHndl;

/*Creates an empty newHeap structure, returning a pointer to that structure*/
heapHndl newHeap (int maxSize);

/*Pre-Condition: H was made with newHeap.
 *Post-Condition: None. 
 *Description: returns a 0 (false) if H is not full. Returns a 1 otherwise.*/
int isFull (heapHndl H);

/*Pre-Condition: H was made with newHeap.
 *Post-Condition: None. 
 *Description: returns a 1 (true) in the case that H is empty. Returns a 0 otherwise */
int isEmpty (heapHndl H);

/*Pre-Condition: H was made with newHeap, !isEmpty
 *Post-Condition: None. 
 *Description: Returns the maximum integer value in the heap*/
int maxValue (heapHndl H);

/*Pre-Condition: H was made with newHeap, !isEmpty 
 *Post-Condition: The heap will have one less element. 
 *Description: Deletes the node with the largest integer value .*/
void deleteMax(heapHndl H);

/*Pre-Condition: H was made with newHeap, currSize <= MaxSize
 *Post-Condition: The heap will have one more element 
 *Description: Insert, in sorted order, an element into the heap.*/
void insert (heapHndl H, int priority);

/*Pre-Condition: H was made with newHeap.
 *Post-Condition: All heap elements freed. 
 *Description: Frees all heap elements and the heap*/
void freeHeap(heapHndl * H);
