#include <vector>
using namespace std;

class Solution2 {
public:
	void dfs(vector<vector<char>>& grid, int r, int c) {
		int rows = grid.size();
		int cols = grid[0].size();

		// Check if the current cell is out of bounds or is water
		if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
			return;
		}

		// Mark the current cell as water to avoid revisiting
		grid[r][c] = '0';

		// Visit all four adjacent cells (up, down, left, right)
		dfs(grid, r - 1, c); // Up
		dfs(grid, r + 1, c); // Down
		dfs(grid, r, c - 1); // Left
		dfs(grid, r, c + 1); // Right
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) {
			return 0;
		}

		int rows = grid.size();
		int cols = grid[0].size();
		int islandCount = 0;

		// Traverse the entire grid
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				// If a land cell is found, perform DFS to mark the entire
				// island
				if (grid[r][c] == '1') {
					++islandCount;   // Increment island count
					dfs(grid, r, c); // Perform DFS to mark the island
				}
			}
		}

		return islandCount;
	}
};
