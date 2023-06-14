#pragma once

#include <utility>
#include "graphNode.h"

class Graph {
    public:
    // constructor and destructor
    Graph();
    ~Graph();

    // add node
    void addNode(const string& newName) {
		nodes.push_back(new GraphNode(newName));
	}

    // add edge
    void addEdge(const string& sourceName, const string& destinationName, int weight) {
		GraphNode *sourceNode = nullptr;
		GraphNode *destinationNode = nullptr;

		for (auto node : nodes) {
			if (node->getValue() == sourceName) {
				sourceNode = node;
			}

			if (node->getValue() == destinationName) {
				destinationNode = node;
			}
		}

		if (sourceNode && destinationNode) {
			sourceNode->addEdge(destinationNode, weight);
			destinationNode->addEdge(sourceNode, weight);
		}
	}

    //get size of graph nodes list
    int getSize();

    // shortest path, take source and return string representing the shortest paths from the source node to each destination node
    string shortestPathDij(const string& sourceName) {
		string result;
		GraphNode *sourceNode = nullptr;

		for (auto node : nodes) {
			if (node->getValue() == sourceName) {
				sourceNode = node;
				break;
			}
		}

		if (!sourceNode) {
			return result;
		}

		vector <int> dist(nodes.size(), )
	}

    // minimum spanning tree
    string MSTKrus() {

	}

    private:
    // some way of storing my data...
    vector<GraphNode *> nodes;
};