#include <vector>
using namespace std;

class Solution2 {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		vector<int> inDegree(n, 0);

		// 更新每个节点的入度
		for (const auto& edge : edges) {
			int to = edge[1];
			inDegree[to]++;
		}

		vector<int> result;
		// 找到所有入度为 0 的节点
		for (int i = 0; i < n; ++i) {
			if (inDegree[i] == 0) {
				result.push_back(i);
			}
		}

		return result;
	}
};
