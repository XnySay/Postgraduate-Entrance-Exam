#include <vector>
using namespace std;

class Solution1 {
public:
	// 深度优先搜索函数，用于遍历城市
	void dfs(vector<vector<int>>& isConnected, vector<bool>& visited,
	         int city) {
		// 标记当前城市为已访问
		visited[city] = true;
		// 遍历所有城市，找出与当前城市直接相连的城市
		for (int i = 0; i < isConnected.size(); ++i) {
			if (isConnected[city][i] == 1 && !visited[i]) {
				dfs(isConnected, visited, i);
			}
		}
	}

	// 主函数，计算省份的数量
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		vector<bool> visited(n, false);
		int count = 0;

		// 遍历每个城市
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				// 如果当前城市未被访问，进行DFS遍历，并计数加1
				dfs(isConnected, visited, i);
				++count;
			}
		}

		return count;
	}
};

class Solution2 {
public:
	// 查找并查集根节点
	int find(vector<int>& parent, int i) {
		if (parent[i] != i) {
			parent[i] = find(parent, parent[i]);
		}
		return parent[i];
	}

	// 合并两个集合
	void unionSet(vector<int>& parent, vector<int>& rank, int i, int j) {
		int rootI = find(parent, i);
		int rootJ = find(parent, j);
		if (rootI != rootJ) {
			if (rank[rootI] > rank[rootJ]) {
				parent[rootJ] = rootI;
			} else if (rank[rootI] < rank[rootJ]) {
				parent[rootI] = rootJ;
			} else {
				parent[rootJ] = rootI;
				rank[rootI]++;
			}
		}
	}

	// 主函数，计算省份的数量
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		vector<int> parent(n);
		vector<int> rank(n, 0);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}

		// 合并直接相连的城市
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isConnected[i][j] == 1) {
					unionSet(parent, rank, i, j);
				}
			}
		}

		// 计算独立集合的数量
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (parent[i] == i) {
				count++;
			}
		}

		return count;
	}
};