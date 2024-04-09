#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
class graph {
    private:
    int V; 
    vector<vector<int>> adj;
    public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }
}