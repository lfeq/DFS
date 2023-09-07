#include "Demonstration.h"
#include "Graph.hpp"
#include <cstdlib>
#include <ctime>
#include <set>
#include <chrono>

namespace Demonstrations {
	void RunGraphDemo() {
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
		g.dfs_non_recursive(0, true);
		cout << endl;
	}

	void RunTreeDemo() {
		Graph tree(8);
		tree.add_edge(0, 1);
		tree.add_edge(0, 2);
		tree.add_edge(1, 3);
		tree.add_edge(1, 4);
		tree.add_edge(3, 6);
		tree.add_edge(3, 7);
		tree.add_edge(2, 5);

		cout << "DFS desde el vértice 0:" << endl;
		tree.dfs_non_recursive(0, true);
		cout << endl;
	}

	void RunBigGraphDemo() {
		// Create a graph with 100 nodes
		int num_nodes = 100000;
		Graph g(num_nodes);

		// Generate random edges
		srand(static_cast<unsigned int>(time(nullptr)));
		int num_edges = 200000; // Adjust the number of edges as needed

		for (int i = 0; i < num_edges; ++i) {
			int u = rand() % num_nodes;
			int v = rand() % num_nodes;

			if (u != v) { // Avoid self-loops
				g.add_edge(u, v);
			}
		}
		// Start measuring time
		auto start_time = chrono::high_resolution_clock::now();

		// Perform DFS
		cout << "DFS from vertex 66:" << endl;
		g.dfs_non_recursive(66, false);

		// End measuring time
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

		// Print execution time
		cout << "Time taken by DFS non recursive: " << duration.count() << " milliseconds" << endl;

		auto start_time_recursive = chrono::high_resolution_clock::now();
		g.dfs(66);

		auto end_time_recursive = chrono::high_resolution_clock::now();
		auto duration_recursive = chrono::duration_cast<chrono::milliseconds>(end_time_recursive - start_time_recursive);

		// Print execution time for recursive DFS
		cout << "Time taken by DFS recursive: " << duration_recursive.count() << " milliseconds" << endl;

	}
}
