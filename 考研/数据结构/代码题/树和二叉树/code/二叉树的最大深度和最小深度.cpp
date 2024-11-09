#include <algorithm>
#include <climits>
#include <iostream>

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
	// 求二叉树的最大深度
	int maxDepth(TreeNode* root) {
		// 如果当前节点为空，则深度为0
		if (root == NULL) {
			return 0;
		}
		// 递归计算左子树和右子树的最大深度，取较大值加1
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	// 求二叉树的最小深度
	int minDepth(TreeNode* root) {
		// 如果当前节点为空，则深度为0
		if (root == NULL) {
			return 0;
		}
		// 如果当前节点是叶节点，则深度为1
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		// 初始化左右子树的深度为最大值
		int ldeep = INT_MAX;
		int rdeep = INT_MAX;
		// 计算左子树的最小深度
		if (root->left != NULL) {
			ldeep = minDepth(root->left);
		}
		// 计算右子树的最小深度
		if (root->right != NULL) {
			rdeep = minDepth(root->right);
		}
		// 返回左右子树深度较小值加1
		return min(ldeep, rdeep) + 1;
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
	int max_depth = solution.maxDepth(root);
	int min_depth = solution.minDepth(root);

	// 输出最大深度和最小深度
	cout << "Max Depth: " << max_depth << endl;
	cout << "Min Depth: " << min_depth << endl;

	return 0;
}
