#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <limits.h>

using std :: string;
using std :: vector;
using namespace std;

//i went with making my nodes ints because i do not like strings in c/c++ sorry lol

/*struct edge {
	int destination;
	int weight;
};*/

class Graph {
	private:
	vector <vector <pair <int, int>>> adjList;  //i chose to use a vector with a vector of pairs for a adjacency list
	int numofNodes; //this just stores the number of nodes in the graph

	public:
	Graph(int nodes) { //this take nodes as the argument and sets the numofNodes (from above) with whatever is inputed, 
		numofNodes = nodes;
		adjList.resize(numofNodes); //this 'resizes; the adjList to have the number of things that numofnode has
	}

	void addNode(int nodeName) { //takes an int that's the nodeName of the int and adds it to the graph
		numofNodes ++; //increases the numodNodes by 1
		adjList.resize(numofNodes); //then resizes the vector
	}

	//undirected edge
	void addEdge(int source, int destination, int weight) { //takes three ints as arguments, a source(what node does it start at), destination(where does the edge of this node go to?), and the weight of the edge that connects them
		adjList[source].push_back(make_pair(destination, weight)); //adds a the pair that has the source and destination and weight to the adjlist 
		adjList[destination].push_back(make_pair(source, weight)); //same as above, but opposite
	}

	vector <int> shortestPathDijk (int source, int destination) { //2 arguments, the source and destination, finds the shortest path between 2 nodes
		vector <int> dist(numofNodes, INT_MAX);
		vector <bool> visited(numofNodes, false); //3 vectors that rep the distance from the source to the other nodes, visit (keeps track of what's been visited), and last which stores the ;ast node in the shortest path
		vector <int> last(numofNodes, -1);

		dist[source] = 0;

		//dijkstra algorithm
		for (int i = 0; i <numofNodes - 1; i++) {  //this goes through the numOfNodes (-1) and 
			int u = getminDistance (dist, visited); //chooses the nodee that's smallest. Then it says it's been 'visited'
			visited[u] = true;

			//this check if for the neighbors to see if it can find a shorter path 
			for (const auto& neighbor :adjList[u]) { 
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
					last[v] = u;
				}
			}
		}

		//finds the shortest path from above steps
		vector <int> path; //empty vectore called path made so it can store the nodes that make up the shortest path
		int current = destination; //set the current to destination node
		while (current != -1) {
			path.insert(path.begin(), current); //loop to go trhough the above steps above 
			current = last[current];
		}
		return path;

	}

	int getminDistance (const vector <int>& dist, const vector <bool>& visited) { //method to find the indec of the node that has the minimum distence between nodes that havent been seen. two vectors, 1 tracks visited nodes and the other hold distance
		int minDist = INT_MAX; //checks over all nodes to se if theyve been visited. 
		int minIndex = -1;

		for (int i = 0; i < numofNodes; i++) { // if the distance is less than the current smallest distance it updates it
			if (!visited[i] && dist[i] < minDist) {
				minDist = dist[i];
				minIndex = i;
			}
		}
		return minIndex;

	}
	vector <pair<int, int>> MSTPrim() { //prims algorithm to find the mst of my graph
		vector <pair<int, int>> MST; //3 vectos, one for the empty mst, key(stores the minimum weigth of each edge), mstset(tracks if the node gets to be in the mst, sets all nodes to false to start with)
		vector <int> key(numofNodes, INT_MAX);
		vector <bool> mstSet(numofNodes, false);

		key[0] = 0;

		for (int i = 0; i < numofNodes - 1; i++) { //uses getminkey function to go over each numofnode-1 times 
			int u = getminKey(key, mstSet); //starting node [u], minimum key, bascially where it starts
			mstSet[u] = true;

			for (const auto& neighbor : adjList[u]) { //loopsp for looking at the nieghbors of [u], and updates the key values if the weight is smaller than the current key
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!mstSet[v] && weight < key[v]) {
					key[v] = weight;
				}
			}
		}
		for (int i = 1; i < numofNodes; i++) {
			MST.push_back(make_pair(i, key[i])); //makes the mst and adds the edges to the vector 'mst' from above (the empty one)
		}
		return MST;

	}

	//find the index of the node with the smallest key value in the nodes that wern't in the mst
	int getminKey (const vector<int>& key, const vector<bool>& mstSet) { //key holds the min weight that connects the edges that connect the nodes and mstset tracks what node has been put in the mst
		int minKey = INT_MAX;
		int minIndex = -1;

		for (int i = 0; i < numofNodes; i++) {
			if (!mstSet[i] && key[i] < minKey) { //goes over all nodes to see if they've been put in the mst and if their value is less than the current min, if it is, it updates mminindex
				minKey = key[i];
				minIndex = i;
			}
		}
		return minIndex;

	}

	//function tpprint out the grpah just so I could see and make sure the graph was made right
	void printOut () {
		for (int i = 0; i < numofNodes; i++) {
			cout << "The nodes are: " << i;
			for (const auto& neighbor : adjList[i]) {
				cout << "(" << neighbor.first << " - " << neighbor.second <<")" <<endl;
			}
		}
	}

};

int main() {

	//simple small graph testing to make sure i can add nodes and edges
	//and that it gives me the right shortest path and mst
	//graph w 8 nodes
	Graph graph(8); 

	graph.addEdge(0, 1, 3);
	graph.addEdge(0, 2, 8);
	graph.addEdge(1, 2, 2);
	graph.addEdge(1, 3, 5);
	graph.addEdge(2, 5, 7);
	graph.addEdge(3, 4, 4); //i included a picture of what this would theoretically look like in the google doc :)
	graph.addEdge(4, 5, 2);
	graph.addEdge(4, 7, 6);
	graph.addEdge(5, 6, 5);
	graph.addEdge(6, 7, 1);

	graph.printOut();  //prints out the grpah

	/*cout << "The Shortest Path using Dijkstra's Algorithm is: ";
	vector <int> shortestPathDijk = graph.shortestPathDijk(0, 4);
	for (int vertex : shortestPathDijk) {
		cout << vertex << " ";
	}
	cout << endl;*/

	cout << "The Minimal Spanning tree using Prim's Algorithm is: "; //calls the mstprim on the graph
	vector <pair< int, int>> MSTPrim = graph.MSTPrim();  //loop to go over all the edges in the mstprim vector
	for (const auto& edge : MSTPrim) {  
		cout << edge.first << " " << edge.second << endl; //prints first (destination node) and second (weight of edge that conncects them)
	}
	cout << endl;

	//just seeing if it was a fluke that it was right ealier
	cout << "The Shortest Path using Dijkstra's Algorithm is: ";
	vector <int> shortestPathDijk = graph.shortestPathDijk(2,7); //calls dijkstra on the graph and 2 parameters (where it's going to start and end)
	for (int vertex : shortestPathDijk) {  //loop to go over each value
		cout << vertex << " ";
	}
	cout << endl;

	return 0;

}

