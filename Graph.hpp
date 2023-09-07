#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief A class representing a directed graph and implementing non-recursive DFS traversal.
 * 
 * This class allows you to create a directed graph with a specified number of vertices
 * and add edges between them. It also provides a non-recursive Depth-First Search (DFS) algorithm
 * to traverse the graph, starting from a given source vertex.
 */
class Graph {
private:
    int n; // Number of vertices
    vector<vector<int>> adjacency_list; // Adjacency list

public:
    /**
     * @brief Construct a new Graph object with a given number of vertices.
     * 
     * @param n The number of vertices in the graph.
     */
    Graph(int n) : n(n), adjacency_list(n) {}

    /**
     * @brief Add an edge from one vertex to another in the graph.
     * 
     * @param u The source vertex.
     * @param v The destination vertex.
     */
    void add_edge(int u, int v) {
        adjacency_list[u].push_back(v);
    }

    /**
     * @brief Perform a non-recursive Depth-First Search (DFS) traversal of the graph
     * starting from a specified source vertex.
     * 
     * @param s The source vertex to start the traversal from.
     */
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

    #pragma region extras
    /**
     * @brief Print the graph's adjacency list.
     * 
     * This function displays the adjacency list representation of the graph, 
     * where each vertex is shown along with its adjacent vertices.
     */
    void print_graph() {
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << " -> ";
            for (int v : adjacency_list[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    /**
     * @brief Print the graph's adjacency matrix representation.
     * 
     * This function generates and displays the adjacency matrix representation of the graph,
     * where each cell in the matrix indicates the presence or absence of an edge between
     * vertices. '1' represents an edge, and '0' represents no edge.
     */
    void print_graph_matrix() {
        vector<vector<char>> matrix(n, vector<char>(n, '0'));

        for (int i = 0; i < n; ++i) {
            for (int v : adjacency_list[i]) {
                matrix[i][v] = '1';
            }
        }

        cout << "Adjacency Matrix Representation of the Graph:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    #pragma endregion
};