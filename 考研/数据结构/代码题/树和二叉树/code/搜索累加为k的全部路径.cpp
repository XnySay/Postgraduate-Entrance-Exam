#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树的节点类
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
	// 寻找所有根节点到叶子节点路径和等于给定值的路径
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			vector<int> path;
			dfs(root, sum, 0, path, ans);
		}
		return ans;
	}

private:
	// 深度优先搜索递归函数
	void dfs(TreeNode* node, int aim, int currentSum, vector<int>& path,
	         vector<vector<int>>& ans) {
		if (node == nullptr) {
			return;
		}

		path.push_back(node->val);
		currentSum += node->val;

		// 如果是叶节点并且路径和等于目标值，则记录当前路径
		if (node->left == nullptr && node->right == nullptr) {
			if (currentSum == aim) {
				ans.push_back(path);
			}
		} else {
			// 继续搜索左子树和右子树
			if (node->left != nullptr) {
				dfs(node->left, aim, currentSum, path, ans);
			}
			if (node->right != nullptr) {
				dfs(node->right, aim, currentSum, path, ans);
			}
		}

		// 回溯到父节点前，移除当前节点
		path.pop_back();
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	Solution2 solution;
	int targetSum = 22;

	vector<vector<int>> result = solution.pathSum(root, targetSum);

	// 输出结果
	for (const auto& path : result) {
		for (int val : path) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}
