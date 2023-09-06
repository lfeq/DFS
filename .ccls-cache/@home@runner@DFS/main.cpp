#include "Grafo.hpp"

int main() {
  // Crear un grafo de ejemplo con 6 vértices y 7 aristas
  Grafo g(6);
  g.añadir_arista(0, 1);
  g.añadir_arista(0, 2);
  g.añadir_arista(0, 3);
  g.añadir_arista(1, 3);
  g.añadir_arista(2, 4);
  g.añadir_arista(3, 5);
  g.añadir_arista(4, 5);
  g.añadir_arista(5, 0);

  // Ejecutar el algoritmo DFS no recursivo desde el vértice 0
  cout << "DFS desde el vértice 0:" << endl;
  g.dfs_no_recursivo(0);
  cout << endl;

  return 0;
  
}
