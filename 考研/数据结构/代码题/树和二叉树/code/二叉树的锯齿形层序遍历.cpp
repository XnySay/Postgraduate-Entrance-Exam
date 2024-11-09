#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// 二叉树的锯齿形层序遍历
// 测试链接 :
// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
	    : val(x)
	    , left(NULL)
	    , right(NULL) {}
};

class Solution2 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans; // 存储结果的二维向量
		if (!root)
			return ans; // 如果根节点为空，直接返回空结果

		deque<TreeNode*> dq; // 使用双端队列实现BFS
		dq.push_back(root);
		bool reverse =
		    false; // 用于指示当前层的遍历方向，false表示从左到右，true表示从右到左

		while (!dq.empty()) {
			int size = dq.size();
			vector<int> level; // 存储当前层节点值的向量

			for (int i = 0; i < size; ++i) {
				if (reverse) {
					// 如果是从右到左，使用双端队列从后面弹出节点
					TreeNode* node = dq.back();
					dq.pop_back();
					level.push_back(node->val);
					// 下一层节点按照左子节点、右子节点的顺序放入双端队列前端
					if (node->right)
						dq.push_front(node->right);
					if (node->left)
						dq.push_front(node->left);
				} else {
					// 如果是从左到右，使用双端队列从前面弹出节点
					TreeNode* node = dq.front();
					dq.pop_front();
					level.push_back(node->val);
					// 下一层节点按照左子节点、右子节点的顺序放入双端队列后端
					if (node->left)
						dq.push_back(node->left);
					if (node->right)
						dq.push_back(node->right);
				}
			}
			ans.push_back(level); // 将当前层结果加入最终结果中
			reverse = !reverse;   // 反转遍历方向
		}

		return ans;
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution2 solution;
	vector<vector<int>> result = solution.zigzagLevelOrder(root);

	// 输出结果
	for (const auto& level : result) {
		for (int val : level) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}
