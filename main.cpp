#include "Graph.hpp"

int main() {
  Graph g(6);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 5);
  g.add_edge(4, 5);
  g.add_edge(5, 0);

  cout << "DFS desde el vértice 0:" << endl;
  g.dfs_non_recursive(0);
  cout << endl;

  Graph tree(8);
  tree.add_edge(0, 1);
  tree.add_edge(0, 2);
  tree.add_edge(1, 3);
  tree.add_edge(1, 4);
  tree.add_edge(3, 6);
  tree.add_edge(3, 7);
  tree.add_edge(2, 5);

  cout << "DFS desde el vértice 0:" << endl;
  tree.dfs_non_recursive(0);
  cout << endl;

  return 0;
  
}
