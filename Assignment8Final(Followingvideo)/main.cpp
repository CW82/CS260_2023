#include <string>
#include <vector>
#include <iostream>

using std :: string;
using std :: vector;
using namespace std;

class graphNode;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct edge {
	graphNode *source;
	graphNode *destination;
	int weight;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class graphNode {
	public:
	//constructor
	graphNode(string newNode);
	~graphNode();

	//add edge
	void addEdge(graphNode *destination, int weight);

	//get name
	string getValue();

	//get neighbor as a list of pointer 
	vector <edge *> getNeighbor();

	private:
	//store value
	string value;

	//reference to neighbors
	vector <edge *> neighbors;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Graph {
	public:
	//constructor
	Graph();
	~Graph();

	//add node
	void addNode(string newName);

	//add edge
	void addEdge(string sourceName, string destinationName, int weight);
	
	//get size of grpah nodes list
	int getSize();

	//short path (dijkstra)
	string shortestPath (string sourceName);

	//mst
	string MST ();

	private:
	vector <graphNode *> nodes;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Graph :: Graph () {

};

Graph :: ~Graph () {

}

void Graph :: addNode (string newName) {
	//make a node
	graphNode *newNode = new graphNode(newName);
	nodes.push_back(newNode);
}

void Graph :: addEdge (string sourceName, string destinationName, int weight) {
	//find source node reference
	graphNode *sourceNode = nullptr;
	graphNode *destinationNode = nullptr;

	for (auto node : nodes) {
		if (sourceName == node->getValue()) {
			sourceNode = node;
		}

		if (destinationName == node->getValue()) {
			destinationNode = node;
		}

	}

	if (sourceNode != nullptr && destinationNode != nullptr) {
		sourceNode->addEdge(destinationNode, weight);
		destinationNode->addEdge(sourceNode, weight);
	}

	//ask source nodes to make edge toward destination nodes


	//undirected graph?
}

int Graph :: getSize () {
	return nodes.size ();
}

/*string Graph :: shortestPath (string sourceName) {

}*/

/*string Graph :: MST () {

}*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//empty string
graphNode :: graphNode (string newName) {
	value = newName;
	//vector<graphNode *> neighbors is a direct object, not a pointer to one, so when this graphNode gets constructed, that direct objects gets contructed

}

//destructor
graphNode :: ~graphNode () {
	for (auto neighbor : neighbors) {
		delete neighbor;
	}
	neighbors.clear();
}

void graphNode :: addEdge (graphNode *destination, int weight) {
	edge *newEdge = new edge{this, destination, weight};
	neighbors.push_back(newEdge);
}

string graphNode :: getValue() {
	return value;
}

vector <edge *> graphNode :: getNeighbor() {
	return neighbors;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main () {
	//edge to test
	edge *newEdge = new edge{nullptr, nullptr, 42};
	cout << "new Edge->source: " << newEdge->source << "\nnewEdge->destination: " << newEdge->destination << "\nnewEdge->weight: " << newEdge->weight << endl;

	//simple nodes to test
	graphNode *newNode = new graphNode("Corvallis");
	cout << "newNode->value: " << newNode->getValue() <<"\nnewNode->getNeighbors(): " << newNode->getNeighbor().size() << endl;

	//add edge to a node
	newNode->addEdge(newNode, 1);
	cout << "newNode->getNeighbor().size(): " << newNode->getNeighbor().size() << endl;
	cout << "newNode->getNeighbor().at(0): " << newNode->getNeighbor().at(0)->destination->getValue() << endl;

	//delete node
	delete newNode;

	cout << "The end" << endl;

	return 0;
}