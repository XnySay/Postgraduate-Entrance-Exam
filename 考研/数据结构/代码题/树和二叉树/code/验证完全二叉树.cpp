#include <iostream>
#include <queue>

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
	// 验证二叉树是否为完全二叉树
	bool isCompleteTree(TreeNode* root) {
		if (root == NULL) {
			return true; // 空树是完全二叉树
		}

		queue<TreeNode*> q;
		q.push(root);
		bool leaf = false; // 是否遇到过左右两个孩子不双全的节点

		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();

			// 如果左子节点为空但右子节点不为空，或者已经遇到过左右两个孩子不双全的节点，且当前节点还有孩子节点，则不满足完全二叉树
			if ((node->left == NULL && node->right != NULL) ||
			    (leaf && (node->left != NULL || node->right != NULL))) {
				return false;
			}

			if (node->left != NULL) {
				q.push(node->left);
			}
			if (node->right != NULL) {
				q.push(node->right);
			}

			// 如果当前节点的左子节点或右子节点为空，则后续节点必须是叶子节点
			if (node->left == NULL || node->right == NULL) {
				leaf = true;
			}
		}
		return true;
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
	bool result = solution.isCompleteTree(root);

	// 输出结果
	cout << "Is the binary tree complete? " << (result ? "Yes" : "No") << endl;

	return 0;
}
