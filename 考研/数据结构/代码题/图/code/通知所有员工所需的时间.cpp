#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	// 递归函数计算通知所有员工所需时间
	int dfs(int manager, vector<vector<int>>& subordinates,
	        vector<int>& informTime) {
		int maxTime = 0;
		// 遍历所有下属
		for (int sub : subordinates[manager]) {
			// 递归计算下属的通知时间
			maxTime = max(maxTime, dfs(sub, subordinates, informTime));
		}
		// 返回当前经理通知所有下属所需时间
		return maxTime + informTime[manager];
	}

	int numOfMinutes(int n, int headID, vector<int>& manager,
	                 vector<int>& informTime) {
		// 创建下属列表
		vector<vector<int>> subordinates(n);
		for (int i = 0; i < n; ++i) {
			if (manager[i] != -1) {
				subordinates[manager[i]].push_back(i);
			}
		}
		// 从总负责人开始计算
		return dfs(headID, subordinates, informTime);
	}
};
