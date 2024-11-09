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
	// 计算完全二叉树的节点个数
	int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int h = getDepth(root);
		return countNodesHelper(root, 1, h);
	}

private:
	// 获取二叉树的深度(树的高度)
	int getDepth(TreeNode* node) {
		int depth = 0;
		while (node != NULL) {
			depth++;
			node = node->left;
		}
		return depth;
	}

	// 辅助方法:计算以当前节点为根的子树的节点数
	int countNodesHelper(TreeNode* node, int level, int height) {
		if (level == height) {
			return 1;
		}
		if (getDepth(node->right) + level == height) {
			return (1 << (height - level)) +
			       countNodesHelper(node->right, level + 1, height);
		} else {
			return (1 << (height - level - 1)) +
			       countNodesHelper(node->left, level + 1, height);
		}
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);

	Solution2 solution;
	int result = solution.countNodes(root);

	// 输出结果
	cout << "Number of nodes in the complete binary tree: " << result << endl;

	return 0;
}
