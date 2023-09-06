#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define directions for moving (up, down, left, right)
const int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class MazeGenerator {
private:
    int rows, cols;
    vector<vector<bool>> visited;
    vector<vector<bool>> walls;

public:
    MazeGenerator(int r, int c) : rows(r), cols(c) {
        visited.assign(rows, vector<bool>(cols, false));
        walls.assign(rows, vector<bool>(cols, true));
        srand(static_cast<unsigned>(time(0))); // Seed for random number generator
    }

    // Check if a cell is within the maze boundaries
    bool isValid(int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    // Perform a Depth-First Search to generate the maze
    void generateMaze(int r, int c) {
        visited[r][c] = true;

        // Randomly shuffle the directions
        int dirOrder[4] = {0, 1, 2, 3};
        for (int i = 3; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(dirOrder[i], dirOrder[j]);
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[dirOrder[i]][0];
            int nc = c + dirs[dirOrder[i]][1];

            if (isValid(nr, nc) && !visited[nr][nc]) {
                walls[r][c] = false; // Remove wall between current cell and neighbor
                generateMaze(nr, nc); // Recursively visit the neighbor
            }
        }
    }

    // Print the generated maze
    void printMaze() {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (r == 0 && c == 0) {
                    cout << "S "; // Start cell
                } else if (r == rows - 1 && c == cols - 1) {
                    cout << "E "; // End cell
                } else if (walls[r][c]) {
                    cout << "# "; // Wall
                } else {
                    cout << "-"; // Path
                }
            }
            cout << endl;
        }
    }
};
