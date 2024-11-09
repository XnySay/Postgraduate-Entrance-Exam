#include <algorithm>
#include <vector>

using namespace std;

class Solution2 {
public:
	// DFS函数，用于计算从起点(r, c)出发的岛屿面积
	int dfs(vector<vector<char>>& grid, int r, int c) {
		int rows = grid.size();
		int cols = grid[0].size();

		// 检查当前单元格是否越界或为水
		if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
			return 0;
		}

		// 将当前单元格标记为水，避免重复访问
		grid[r][c] = '0';

		// 递归地计算当前岛屿的面积(上下左右)
		int area = 1;
		area += dfs(grid, r - 1, c); // 上
		area += dfs(grid, r + 1, c); // 下
		area += dfs(grid, r, c - 1); // 左
		area += dfs(grid, r, c + 1); // 右

		return area;
	}

	// 主函数，计算最大的岛屿面积
	int maxAreaOfIsland(vector<vector<char>>& grid) {
		if (grid.empty()) {
			return 0;
		}

		int rows = grid.size();
		int cols = grid[0].size();
		int maxArea = 0;

		// 遍历整个网格
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				// 如果当前单元格是陆地，计算其岛屿面积
				if (grid[r][c] == '1') {
					maxArea = max(maxArea, dfs(grid, r, c));
				}
			}
		}

		return maxArea;
	}
};
