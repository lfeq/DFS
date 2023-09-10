# Búsqueda en Profundidad No Recursiva (DFS) en C++
### Introducción

En teoría de grafos, la Búsqueda en Profundidad (DFS, por sus siglas en inglés) es un algoritmo utilizado para recorrer un grafo. Comienza en un vértice dado y explora todos sus vértices adyacentes, luego todos los vértices adyacentes de esos vértices, y así sucesivamente. Este proceso se repite hasta que se hayan visitado todos los vértices en el grafo.

DFS se puede implementar de forma recursiva o no recursiva. En este artículo, discutiremos la implementación no recursiva de DFS en C++.

### Explicación del Código

El código para el algoritmo DFS no recursivo se muestra a continuación:

```cpp
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
```

### Pasos para Ejecutar

Compile el código C++ utilizando su compilador preferido. Puede usar el siguiente comando en la línea de comandos si tiene g++ instalado:
```bash
g++ main.cpp Demonstrations.cpp -o nombre_del_ejecutable
```

Ejecute el programa compilado:
```bash
nombre_del_ejecutable
```

Ejecutar en Replit
https://replit.com/@LorenzEquihua/DFS#main.cpp