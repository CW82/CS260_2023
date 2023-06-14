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
	vector <vector <pair <int, int>>> adjList;
	int numofNodes;

	public:
	Graph(int nodes) {
		numofNodes = nodes;
		adjList.resize(numofNodes);
	}

	void addNode(string nodeName) {
		numofNodes ++;
		adjList.resize(numofNodes);
	}

	void addEdge(int source, int destination, int weight) {
		adjList[source].push_back(make_pair(destination, weight));
		adjList[destination].push_back(make_pair(source, weight));
	}

	vector <int> shortestPathDijk (int source, int destination) {
		vector <int> dist(numofNodes, INT_MAX);
		vector <bool> visited(numofNodes, false);
		vector <int> last(numofNodes, -1);

		dist[source] = 0;

		for (int i = 0; i <numofNodes - 1; i++) {
			int u = getminDistance (dist, visited);
			visited[u] = true;

			for (const auto& neighbor :adjList[u]) {
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
					last[v] = u;
				}
			}
		}

		vector <int> path;
		int current = destination;
		while (current != -1) {
			path.insert(path.begin(), current);
			current = last[current];
		}
		return path;

	}

	int getminDistance (const vector <int>& dist, const vector <bool>& visited) {
		int minDist = INT_MAX;
		int minIndex = -1;

		for (int i = 0; i < numofNodes; i++) {
			if (!visited[i] && dist[i] < minDist) {
				minDist = dist[i];
				minIndex = i;
			}
		}
		return minIndex;

	}
	vector <pair<int, int>> MSTPrim() {
		vector <pair<int, int>> MST;
		vector <int> key(numofNodes, INT_MAX);
		vector <bool> mstSet(numofNodes, false);

		key[0] = 0;

		for (int i = 0; i < numofNodes - 1; i++) {
			int u = getminKey(key, mstSet);
			mstSet[u] = true;

			for (const auto& neighbor : adjList[u]) {
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!mstSet[v] && weight < key[v]) {
					key[v] = weight;
				}
			}
		}
		for (int i = 1; i < numofNodes; i++) {
			MST.push_back(make_pair(i, key[i]));
		}
		return MST;

	}
	int getminKey (const vector<int>& key, const vector<bool>& mstSet) {
		int minKey = INT_MAX;
		int minIndex = -1;

		for (int i = 0; i < numofNodes; i++) {
			if (!mstSet[i] && key[i] < minKey) {
				minKey = key[i];
				minIndex = i;
			}
		}
		return minIndex;

	}

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
	/*Graph graph(8);

	graph.addEdge(0, 1, 3);
	graph.addEdge(0, 2, 8);
	graph.addEdge(1, 2, 2);
	graph.addEdge(1, 3, 5);
	graph.addEdge(2, 5, 7);
	graph.addEdge(3, 4, 4);
	graph.addEdge(4, 5, 2);
	graph.addEdge(4, 7, 6);
	graph.addEdge(5, 6, 5);
	graph.addEdge(6, 7, 1);

	graph.printOut();

	cout << "The Shortest Path using Dijkstra's Algorithm is: ";
	vector <int> shortestPathDijk = graph.shortestPathDijk(0, 4);
	for (int vertex : shortestPathDijk) {
		cout << vertex << " ";
	}
	cout << endl;

	cout << "The Minimal Spanning tree using Prim's Algorithm is: ";
	vector <pair< int, int>> MSTPrim = graph.MSTPrim();
	for (const auto& edge : MSTPrim) {
		cout << edge.first << " " << edge.second << endl;
	}
	cout << endl;*/

	Graph graph();

	
	return 0;

}

