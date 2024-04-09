#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj;

public:
    // Constructor to initialize the graph with 'vertices' number of vertices
    Graph(int vertices) : V(vertices) {
        adj.resize(V); // Initialize adjacency list with V empty vectors
    }

    // Method to add an undirected edge between vertices u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u's adjacency list
        adj[v].push_back(u); // Add u to v's adjacency list (for undirected graph)
    }


    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor (optional in this case since the class doesn't manage dynamic memory)
    ~Graph() {
        // No explicit cleanup needed here for vector adj
    }
};

int main() {
    // Usage example of the Graph class
    Graph g(5); // Create a graph with 5 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Display the adjacency list of the graph
    g.display();

    return 0;
}
