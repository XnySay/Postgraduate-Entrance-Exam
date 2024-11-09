#include <vector>
using namespace std;

class Solution2 {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		// 如果只有一个人且没有信任关系，他就是法官
		if (n == 1 && trust.empty())
			return 1;

		vector<int> inDegree(n + 1, 0);
		vector<int> outDegree(n + 1, 0);

		// 遍历 trust 数组，更新 inDegree 和 outDegree
		for (const auto& t : trust) {
			int a = t[0], b = t[1];
			outDegree[a]++;
			inDegree[b]++;
		}

		// 找到满足条件的法官
		for (int i = 1; i <= n; ++i) {
			if (inDegree[i] == n - 1 && outDegree[i] == 0) {
				return i;
			}
		}

		return -1; // 没有找到满足条件的法官
	}
};
