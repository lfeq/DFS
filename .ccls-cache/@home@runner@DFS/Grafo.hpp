#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Grafo {
private:
    int n; // Número de vértices
    vector<vector<int>> lista; // Lista de adyacencia


public:
    Grafo(int n) : n(n), lista(n) {}

    // Añadir una arista dirigida de u a v
    void añadir_arista(int u, int v) {
        lista[u].push_back(v);
    }

    // Imprimir las aristas de un vértice
    void imprimir_aristas_de_vertice(int u) {
        cout << "Aristas del vértice " << u << ": ";
        for (int v : lista[u]) {
            cout << v << " ";
        }
        cout << endl;
    }

    // Implementar el algoritmo DFS no recursivo
    void dfs_no_recursivo(int s) {
        vector<bool> visitado(n, false); // Crear un vector para marcar los vértices visitados
        stack<int> pila; // Crear una pila
        pila.push(s); // Poner el vértice inicial en la pila
        while (!pila.empty()) { // Mientras la pila no esté vacía
            int u = pila.top(); // Obtener un vértice de la pila
            pila.pop();
            if (!visitado[u]) { // Si el vértice no ha sido visitado
                visitado[u] = true; // Marcarlo como visitado
                cout << u << " "; // Imprimir el vértice
                for (int v : lista[u]) { // Recorrer los vértices adyacentes a u
                    pila.push(v); // Ponerlos en la pila
                }
            }
        }
    }

    // Función para verificar si el grafo contiene ciclos utilizando DFS
    bool tiene_ciclos() {
        vector<bool> visitado(n, false); // Crear un vector para marcar los vértices visitados
        vector<bool> en_pila(n, false); // Crear un vector para marcar los vértices en la pila de recursión

        for (int i = 0; i < n; ++i) {
            if (!visitado[i]) {
                if (dfs_recursivo(i, visitado, en_pila)) {
                    return true; // Si se encuentra un ciclo, retornar true
                }
            }
        }

        return false; // Si no se encontraron ciclos, retornar false
    }

// Implementar el algoritmo DFS recursivo
    bool dfs_recursivo(int u, vector<bool>& visitado, vector<bool>& en_pila) {
        visitado[u] = true; // Marcar el vértice actual como visitado
        en_pila[u] = true; // Marcar el vértice actual como parte de la pila de recursión

        for (int v : lista[u]) { // Recorrer los vértices adyacentes a u
            if (!visitado[v]) { // Si el vértice no ha sido visitado, llamar recursivamente a la función
                if (dfs_recursivo(v, visitado, en_pila)) {
                    return true; // Si se encuentra un ciclo, retornar true
                }
            } else if (en_pila[v]) { // Si el vértice ya está en la pila y también se visita en el camino actual, hay un ciclo
                return true;
            }
        }

        en_pila[u] = false; // Marcar el vértice actual como fuera de la pila de recursión
        return false;
    }
};