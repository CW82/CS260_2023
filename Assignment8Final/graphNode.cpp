#include <vector>

#include "graphNode.h"

using std :: vector;

//empty string
graphNode :: graphNode () {
	values = " ";
	//vector<graphNode *> neighbors is a direct object, not a pointer to one, so when this graphNode gets constructed, that direct objects gets contructed

}

void graphNode :: addEdge (graphNode *destination, int weight) {
	edge *newEdge = new edge{this, destination, weight};
	neighbors.push_back(newEdge);
}

string graphNode :: getValue() {
	return values;
}

vector <edge *> graphNode :: getNeighbor() {
	return neighbors;
}