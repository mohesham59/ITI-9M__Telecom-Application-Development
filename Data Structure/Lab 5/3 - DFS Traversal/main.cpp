#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Total number of vertices in the graph
int v = 11;

// Adjacency matrix to represent the graph (v x v) initialized with 0
vector<vector<int>> matrix(v, vector<int>(v, 0));

// Visited array to keep track of visited vertices
vector<bool> vis(v, false);

// Function to create the graph by filling the adjacency matrix
void creatgraph(const vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0]; // first vertex of the edge
        int m = edges[i][1]; // second vertex of the edge

        // Mark the edge in the adjacency matrix (undirected graph)
        matrix[u][m] = 1;
        matrix[m][u] = 1;
    }
}

// Function to get an adjacent vertex of 'ver' that has not been visited yet
int GetAdjuVis(int ver) {
    for (int i = 0; i < v; i++) {
        if (matrix[ver][i] && !vis[i])
            return i; // return the first unvisited neighbor
    }
    return -1; // no unvisited neighbor found
}

// DFS traversal starting from vertex 1
vector<int> DFS() {
    stack<int> s;
    vector<int> res;     // store the DFS traversal

    int start = 1;
    vis[start] = true;   // mark start vertex as visited
    s.push(start);

    while(!s.empty()) {
        int v1 = s.top();
        int v2 = GetAdjuVis(v1);

        if(v2 == -1) {           // if no unvisited neighbors
            res.push_back(s.top());
            s.pop();
        } else {                  // visit the unvisited neighbor
            vis[v2] = true;
            s.push(v2);
        }
    }
    return res;
}

int main() {
    // Define the edges of the graph
    vector<vector<int>> edges = {
        {1,2},{1,4},{2,3},{3,4},{3,9},{3,10},{2,5},
        {2,7},{2,8},{5,7},{5,8},{5,6},{7,8}
    };

    // Create the adjacency matrix for the graph
    creatgraph(edges);

    // Reset visited array before performing DFS
    for(int i = 0; i < v; i++)
        vis[i] = false;

    // Perform DFS traversal
    vector<int> dfs = DFS();

    // Print DFS result
    for (int x : dfs)
        cout << x << " ";

    return 0;
}
