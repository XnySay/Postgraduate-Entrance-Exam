#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	// 创建一个图的邻接表表示法
	vector<vector<int>> adj(numCourses);
	// 创建一个数组来存储每个节点的入度
	vector<int> indegree(numCourses, 0);

	// 填充邻接表和入度数组
	for (auto& pre : prerequisites) {
		adj[pre[1]].push_back(pre[0]);
		indegree[pre[0]]++;
	}

	// 创建一个队列来处理入度为0的节点
	queue<int> q;
	// 将所有入度为0的节点入队
	for (int i = 0; i < numCourses; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	// 存储课程的学习顺序
	vector<int> order;

	// 开始处理队列中的节点
	while (!q.empty()) {
		int course = q.front();
		q.pop();
		order.push_back(course);

		// 遍历当前节点的所有邻接节点
		for (int next : adj[course]) {
			indegree[next]--;
			// 如果邻接节点的入度变为0，则将其入队
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	// 如果处理过的节点数量等于课程总数，则返回学习顺序
	if (order.size() == numCourses) {
		return order;
	} else {
		// 否则返回空数组，表示存在环，无法完成所有课程
		return {};
	}
}

int main() {
	int numCourses = 4;
	vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
	vector<int> order = findOrder(numCourses, prerequisites);

	if (!order.empty()) {
		cout << "可以完成所有课程，学习顺序为:";
		for (int course : order) {
			cout << course << " ";
		}
		cout << endl;
	} else {
		cout << "无法完成所有课程" << endl;
	}

	return 0;
}
