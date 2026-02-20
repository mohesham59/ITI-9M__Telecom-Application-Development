// Project 1: Represent Graph in Adjacency Matrix
// This program creates an adjacency matrix for an undirected graph
// with 10 nodes and a predefined list of edges using vector<vector<int>>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10; // Number of nodes in the graph

    // Define the edges of the graph as vectors of two integers
    // Each inner vector represents an edge between node u and node v
    vector<vector<int>> edges =
    {
        {1, 2}, {1, 4}, {2, 3}, {3, 4}, {3, 9}, {3, 10},
        {2, 5}, {2, 7}, {2, 8}, {5, 7}, {5, 8}, {5, 6}, {7, 8}
    };

    // Create an adjacency matrix initialized to 0
    // Matrix size is (n+1) x (n+1) to use 1-based indexing for nodes
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));  // 1 : 10

    // Fill the adjacency matrix based on the edges
    // Since the graph is undirected, mark both adj[u][v] and adj[v][u] as 1
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i][0]; // First element of inner vector
        int v = edges[i][1]; // Second element of inner vector
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
