#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Total number of vertices in the graph
int v = 11;

// Adjacency matrix to represent the graph (v x v), initialized with 0
vector<vector<int>> matrix(v, vector<int>(v, 0));

// Visited array to keep track of visited vertices during BFS
vector<bool> vis(v, false);

// Function to create the graph by filling the adjacency matrix
void creatgraph(const vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0]; // first vertex of the edge
        int m = edges[i][1]; // second vertex of the edge

        // Update adjacency matrix for an undirected graph
        matrix[u][m] = 1;
        matrix[m][u] = 1;
    }
}

// Function to get an unvisited adjacent vertex of a given vertex
int GetAdjuVis(int ver) {
    for (int i = 0; i < v; i++) {
        if (matrix[ver][i] && !vis[i])
            return i; // return the first unvisited neighbor
    }
    return -1; // no unvisited neighbor found
}

// BFS traversal starting from vertex 1
vector<int> BFS() {
    int start = 1;
    vector<int> res;    // stores the BFS traversal order
    queue<int> q;       // queue for BFS

    vis[start] = true;  // mark starting vertex as visited
    q.push(start);      // enqueue starting vertex

    while (!q.empty()) {
        int v1 = q.front(); // get the vertex at the front of the queue
        q.pop();
        res.push_back(v1);  // add it to the BFS result

        int v2;
        // Check all unvisited neighbors of v1
        while ((v2 = GetAdjuVis(v1)) != -1) {
            vis[v2] = true;  // mark neighbor as visited
            q.push(v2);      // enqueue neighbor
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

    // Create adjacency matrix for the graph
    creatgraph(edges);

    // Perform BFS traversal
    vector<int> bfs = BFS();

    // Print BFS traversal order
    for (int x : bfs)
        cout << x << " ";

    return 0;
}
