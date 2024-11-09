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
	// 检查两个子树是否是镜像对称的
	bool isMirror(TreeNode* t1, TreeNode* t2) {
		// 如果两个子树都为空，则它们是镜像对称的
		if (t1 == NULL && t2 == NULL) {
			return true;
		}
		// 如果其中一个子树为空，另一个不为空，则它们不是镜像对称的
		if (t1 == NULL || t2 == NULL) {
			return false;
		}
		// 检查当前节点的值是否相等，且对应的子树是否镜像对称
		return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
		       isMirror(t1->left, t2->right);
	}

	// 检查二叉树是否轴对称
	bool isSymmetric(TreeNode* root) {
		// 检查根节点的左子树和右子树是否是镜像对称的
		return isMirror(root, root);
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);

	Solution2 solution;
	bool result = solution.isSymmetric(root);

	// 输出结果
	cout << "Is the binary tree symmetric? " << (result ? "Yes" : "No") << endl;

	return 0;
}
