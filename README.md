 ## Non-Recursive Depth First Search (DFS) in C++

### Introduction

In graph theory, Depth First Search (DFS) is an algorithm used to traverse a graph. It starts at a given vertex and explores all of its adjacent vertices, then all of the adjacent vertices of those vertices, and so on. This process is repeated until all of the vertices in the graph have been visited.

DFS can be implemented recursively or non-recursively. In this article, we will discuss the non-recursive implementation of DFS in C++.

### Code Explanation

The code for the non-recursive DFS algorithm is given below:

```c++
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int n; // Number of vertices
    vector<vector<int>> adjacency_list; // Adjacency list

public:
    Graph(int n) : n(n), adjacency_list(n) {}

    // Add an edge from u to v
    void add_edge(int u, int v) {
        adjacency_list[u].push_back(v);
    }

    // Implement the non-recursive DFS algorithm
    void dfs_non_recursive(int s) {
        vector<bool> visited(n, false); // Create a vector to mark visited vertices
        stack<int> stack; // Create a stack
        stack.push(s); // Put the initial vertex into the stack
        while (!stack.empty()) { // While the stack is not empty
            int u = stack.top(); 
            stack.pop();
            if (!visited[u]) {  // If the vertex has not been visited
                visited[u] = true; // Mark it as visited
                cout << u << " "; // Print the vertex
                for (int v : adjacency_list[u]) { // Traverse vertices adjacent to u
                    stack.push(v); // Put them into the stack
                }
            }
        }
    }
};

int main() {
  Graph g(6);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(1, 3);
  g.
}
