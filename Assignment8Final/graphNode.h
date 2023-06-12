#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std :: string;
using std :: vector;

class graphNode {
	public:
	//constructor
	graphNode();

	//add edge
	void addEdge(graphNode *destination, int weight);

	string getValue();

	//get neighbor as a list of pointer 
	vector <edge *> getNeighbor();

	private:
	//store value
	string values;

	//reference to neighbors
	vector <edge *> neighbors;

};