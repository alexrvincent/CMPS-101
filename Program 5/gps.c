/* Programmer: Alex Vincent (avincent@ucsc.edu)
	This short program will read and insert nodes into a graph, calling
	queries to find the shortest paths to nodes. This program will
	make use of the graph and list ADTS
*/
#include "myinclude.h"
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "list.h"
#include "graph.h"

int main(int argc, char **argv)
{
   	char buffer[1000];
   	int vertNums = 0;
   	int queryNums = 0;
  
   	/* Open and begin reading the first file */
   	FILE *file;
   	argc = argc;
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
		sscanf(buffer, "%d %d", &vertNums, &queryNums);
	}
	/* Create the new graph with the information we just read */
	  GraphHndl theGraph = NULL;
	  theGraph = newGraph(vertNums);
	  
	 /* Begin to make the graph with information given */
	 for(int i = 0; i < vertNums && fgets(buffer, sizeof buffer, file); i++)
	 {
		int tempVertex;
		sscanf(buffer, "%d", &tempVertex);
		char *tempPtr = strtok(buffer, " \n");

		while(tempPtr != NULL)
		{
			addEdge(theGraph, tempVertex, atoi(tempPtr));
			tempPtr = strtok(NULL, " \n");
		}
		
	}
	
	/* Start finding the path */
	int source, destination;
	for( int i = 0; i < queryNums && fgets(buffer, sizeof buffer, file); i++)
	{
		sscanf(buffer, "%d %d", &source, &destination);
		doBFS(theGraph,source);
		int distance = getDistance(theGraph, destination);
		/* Case 1: The distance is still infinity, so no path */
		if(distance == INT_MAX)
		{
			printf("Sorry, there's no path from %d to %d in this graph.\n", source, destination);
		}
		/* Case 2: A path exists. Get it using getPathto and print it out */
		else
		{
			printf("The shortest path from %d to %d requires %d edges, it is the following : \n\t", source, destination, distance);
			ListHndl thePath = getPathTo(theGraph, destination);
			printList(thePath);
			printf("\n");
		}
	}
	fclose(file);
	freeGraph(theGraph);	
}
