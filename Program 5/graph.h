/*  Programmer: Alex Vincent (avincent@ucsc.edu) 
    Header file for the graph ADT module, describing function uses
    for a client's use 
	
    Note: Post-conditions include the descriptions of the function*/
   
#include "list.h"

/*Typedef'd reference of a pointer to a graph struct for clarity
 *Client creates this and assigns it using the newGraph function*/
typedef struct graph *GraphHndl;

/*Pre-condition: None.
  Post-condition: will return pointer to new empty graph*/
GraphHndl newGraph(int n);

/*Pre-condition: Graph g was made using newGraph()
  Post-condition: creates a link between "from" integer and "to" integer*/
void addEdge(GraphHndl g, int from, int to);

/*Pre-condition: Graph g was made using newGraph()
  Post-condition: The graph passed will have all it's contents freed*/
void freeGraph(GraphHndl g);

/*Pre-condition: Graph g was made using newGraph()
  Post-condition: Updates the distance path to any node path.*/
void doBFS(GraphHndl g, int source);

/*Pre-condition: The function doBFS was called (for accurate results)
  Post-condition: None. Returns maximum length from source to destination*/
int getDistance(GraphHndl g, int destination);

/*Pre-condition: The function doBFS was called
  Post-condition: None. Returns list pointer that contains path to destination*/
ListHndl getPathTo(GraphHndl g, int destination);

/*Pre-condition: Graph g was made using newGraph()
  Post-condition: None. This will print the contents of the graph*/
void printGraph(GraphHndl g);  
