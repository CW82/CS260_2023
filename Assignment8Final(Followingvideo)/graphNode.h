//we will add the pragma once in a few minutes, so we can see the issue that it prevents!
#pragma once

#include <string>
#include <vector>
#include <utility>

#include "edge.h"

using std::string;
using std::vector;
using std :: pair;

class GraphNode {
    public:
    // constructor
    GraphNode(const string & newName) : value (newName) {

	}

    ~GraphNode();

    // add edge
    void addEdge(GraphNode *destination, int weight) {
		neighbors.push_back({destination, weight});
	}
    // get value of this node
    string getValue() const {
		return value;
	}

    // get neighbors as a list of pointers
   const vector<pair<GraphNode *, int >> & getNeighbors() const {
	return neighbors;
   }

    private:
    // stored value
    string value;

    // reference to neighbors
    vector<pair <GraphNode *, int>> neighbors;
};