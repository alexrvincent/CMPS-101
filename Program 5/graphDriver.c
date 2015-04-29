/* Programmer: Alex Vincent (avincent@ucsc.edu)
   A Short "test driver" program that verifies the correctness of the
   graph ADT that this program uses with a simple creation and 
   breadth-first search call.*/

 #include <stdlib.h>
 #include <stdio.h>
 #include "graph.h"
 #include "list.h"
 
 int main()
 {
	GraphHndl g = newGraph(8);
	addEdge(g, 0, 1);
	addEdge(g, 1, 2);
	addEdge(g, 2, 3);
	addEdge(g, 2, 4);
	addEdge(g, 3, 5);
	addEdge(g, 3, 6);
	addEdge(g, 4, 7);
	addEdge(g, 5, 4);
	
	doBFS(g, 0);

	printf("The shortest path between 7 and 0 has a distance of %d.\n", getDistance(g,7));
	printf("Path distance above should be 4.\n");
	
	ListHndl listPath = getPathTo(g,7);
	printList(listPath);
	printf("Path should be : 0 1 2 4 7\n");
	freeGraph(g);
}
	
