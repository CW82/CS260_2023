#include <string>
#include <vector>
#include <iostream>

#include "graph.h"
#include "graphNode.cpp"


using std :: string;
using std :: vector;
using namespace std;

int main () {
	//edge to test
	edge *newEdge = new edge{nullptr, nullptr, 42};
	cout << "new Edge->source: " << newEdge->source << "\nnewEdge->destination: " << newEdge->destination << "\nnewEdge->weight: " << newEdge->weight << endl;

	//simple nodes to test
	GraphNode *newNode = new GraphNode("Corvallis");
	cout << "newNode->value: " << newNode->getValue() <<"\nnewNode->getNeighbors(): " << newNode->getNeighbors().size() << endl;

	//add edge to a node
	newNode->addEdge(newNode, 1);
	cout << "newNode->getNeighbor().size(): " << newNode->getNeighbors().size() << endl;
	cout << "newNode->getNeighbor().at(0): " << newNode->getNeighbors().at(0)->destination->getValue() << endl;

	//delete node
	delete newNode;

	cout << "The end" << endl;

	return 0;
}