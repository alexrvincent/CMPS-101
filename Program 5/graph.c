/* Programmer: Alex Vincent (avincent@ucsc.edu)
 * Implementation for the Graph ADT module, which makes use of the list ADT.
 * For an explicit breakdown of the functions and their uses, check the
 * header file for this program. Functions have been commented extensively
 * for use of readability and understandability. */

#include "myinclude.h"
#include "list.h"
#include <limits.h>

typedef struct graph
{
	ListHndl* vertices;
	int* parentPtr;
	int* colorPtr;
	int* distancePtr;
	
	int edgeNums;
	int vertNums;
} *GraphHndl;

GraphHndl newGraph(int n)
{
	/*Allocate graph size with it's corresponding fields*/
	GraphHndl g = malloc(sizeof(struct graph));
	g->vertices = calloc(n, sizeof(ListHndl));
	g->parentPtr = calloc(n, sizeof(ListHndl));
	g->colorPtr = calloc(n, sizeof(int));
	g->distancePtr = calloc(n, sizeof(int));

	/* Initialize the status variables to 0 */
	g->vertNums = 0;
	g->edgeNums = 0;
	
	
	/*Give every vertex a new list to hold, initialize colors*/
	for (int i = 0; i < n; i++)
	{
		g->vertices[i] = NewList(); // New empty list pointer
		g->colorPtr[i] = 0;       // 0 indicates "white/unseen" color  
		g->parentPtr[i] = -1;     // -1 indicates no parent
		g->distancePtr[i] = INT_MAX; //"infinity" length
		g->vertNums = g->vertNums + 1; //increment vertNums through loop
	}
	return g;
}

void addEdge(GraphHndl g, int from, int to)
{
	/* Put the newest edge path at the end of the list */
	insertAtBack(g->vertices[from], to);
	g->edgeNums = g->edgeNums + 1; //increment edge numbers after adding one in.
}

void freeGraph(GraphHndl g)
{
	/*Free the fields of the graph structure*/
	free(g->parentPtr);
	free(g->colorPtr);
	free(g->distancePtr);
	/* For every list in the graph, free them */
	for(int i = 1; i < g->vertNums-1; i++)
	{
		if(g->vertices[i] != NULL)
		{
			makeEmpty(g->vertices[i]);
			free(g->vertices[i]);
		}
	}
	free(g);
}

void doBFS(GraphHndl g, int source)
{
	ListHndl tempList = NewList();

	/*Make the lists white, reset distances and parents*/
	for(int i = 0; i < g->vertNums; i++)
	{
		g->parentPtr[i] = -1;
		g->distancePtr[i] = INT_MAX;
		g->colorPtr[i] = 0;
	}

	/*Temporary list holds paths from source*/
	insertAtBack(tempList, source);
	g->colorPtr[source] = 1;
	g->distancePtr[source] = 0;

	/*For every node in the source's adjacency list..*/
	while(!isEmpty(tempList))
	{
		int currNode = getFirst(tempList);

		/*Handle case where we're passed a bigger node*/
		if(currNode > g->vertNums)
		{
			deleteFirst(tempList);
			break;
		}

		/*Second temporary list holds edge path*/
		ListHndl tempList2 = g->vertices[currNode];
		moveFirst(tempList2);

		/* For each of the next node's adjacent nodes .. */
		while(!offEnd(tempList2))
		{
			int tempEdge = getCurrent(tempList2);
			/* If the node was white, increase the distance,
 			 * color it grey and set it's parent to be currnode
 			 * and enqueue this node into the path list */
			if(g->colorPtr[tempEdge] == 0)
			{
				g->distancePtr[tempEdge] = g->distancePtr[currNode]+1;
				g->colorPtr[tempEdge] = 1;
				g->parentPtr[tempEdge] = currNode;
				insertAtBack(tempList, tempEdge);
			}
			moveNext(tempList2);
		}
		/*Dequeue the first element and set black to show we're done.*/
		deleteFirst(tempList);
		g->colorPtr[currNode] = 2;
	}
	makeEmpty(tempList);
	//freeList(tempList);
}

int getDistance(GraphHndl g, int destination)
{
	/*Simply get and return that node's distance from destination*/
	int tempDistance = 0;
	tempDistance = g->distancePtr[destination];
	return tempDistance;
}

ListHndl getPathTo(GraphHndl g, int destination)
{
	/* Temporary list will accumulate the data we request*/
	ListHndl thePath = NewList();
	int currNode = destination;

	/*Follow the parent pointers and insert them into the list*/
	/*Stop at -1, where that node has no parent*/
	while(currNode != -1)
	{
		insertAtFront(thePath,currNode);
		currNode = g->parentPtr[currNode];
	}
	/* Return the list that accumulated the path */
	return thePath;
}

/* Debug print loop. Used in debug but not needed here. */
void printGraph(GraphHndl g)
{
	for(int i = 1; i < g->vertNums-1; i++)
	{
		printf(" For node %d: \n", i);
		if ( i != 0)
		{
			printf("It's parent is ");
			printList((ListHndl)g->parentPtr[i]);
		}
		printf("\tColor %d, Dist %d", g->colorPtr[i], g->distancePtr[i]);
		printf("\tEdges:");
		ListHndl tempList = g->vertices[i];
		moveFirst(tempList);
		while(!offEnd(tempList))
		{
			printf("%d, ", getCurrent(index));
			moveNext(tempList);
		}
	}
}
	
	
