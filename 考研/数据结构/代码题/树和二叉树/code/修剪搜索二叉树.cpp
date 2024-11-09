#include <iostream>

using namespace std;

// 定义二叉树节点类
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
	// 修剪二叉搜索树，保留值在[low, high]范围内的节点
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return nullptr;
		}

		// 如果当前节点的值小于low，修剪右子树
		if (root->val < low) {
			return trimBST(root->right, low, high);
		}

		// 如果当前节点的值大于high，修剪左子树
		if (root->val > high) {
			return trimBST(root->left, low, high);
		}

		// 当前节点的值在[low, high]范围内，继续修剪左右子树
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};

void printTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
}

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(1);

	Solution2 solution;
	int low = 1, high = 3;
	TreeNode* trimmedRoot = solution.trimBST(root, low, high);

	// 输出修剪后的二叉树
	printTree(trimmedRoot);

	return 0;
}
