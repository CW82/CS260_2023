#include <iostream>

#include "graph.h"
#include "graphNode.h"

using namespace std;

int main () {
	//edge to test
	edge *newEdge = new edge{nullptr, nullptr, 42};
	cout << "new Edge->source: " << newEdge->source << "\nnewEdge->destination: " << newEdge->destination << "\nnewEdge->weight: " << newEdge->weight << endl;

	//simple nodes to test
	graphNode newNode; //default constructor, the one without parameters
	cout << "newNode.value: " << newNode.getValue() << "\nnewNode.getNeighbors(): " << newNode.getNeighbor().size() << endl;

	cout << "The end" << endl;

	return 0;
}