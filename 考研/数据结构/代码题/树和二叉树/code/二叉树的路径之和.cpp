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
	// 判断是否存在从根节点到叶子节点的路径，路径上所有节点值的和等于目标和
	bool hasPathSum(TreeNode* root, int targetSum) {
		// 如果当前节点为空，则不存在这样的路径
		if (root == NULL) {
			return false;
		}
		// 计算当前的剩余目标和
		targetSum -= root->val;
		// 如果当前节点是叶子节点，检查路径和是否等于目标和
		if (root->left == NULL && root->right == NULL) {
			return targetSum == 0;
		}
		// 递归检查左子树和右子树是否存在这样的路径
		return hasPathSum(root->left, targetSum) ||
		       hasPathSum(root->right, targetSum);
	}
};

int main() {
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	Solution2 solution;
	int targetSum = 22;
	bool result = solution.hasPathSum(root, targetSum);

	// 输出结果
	cout << (result ? "true" : "false") << endl;

	return 0;
}
