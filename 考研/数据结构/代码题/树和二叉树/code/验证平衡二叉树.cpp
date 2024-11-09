#include <cmath>
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
	// 判断二叉树是否平衡的主函数
	bool isBalanced(TreeNode* root) { return height(root) != -1; }

private:
	// 计算节点高度的辅助函数
	int height(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}

		// 递归计算左子树高度
		int leftHeight = height(node->left);
		if (leftHeight == -1) {
			return -1;
		}

		// 递归计算右子树高度
		int rightHeight = height(node->right);
		if (rightHeight == -1) {
			return -1;
		}

		// 如果左右子树高度差超过1，返回-1表示不平衡
		if (abs(leftHeight - rightHeight) > 1) {
			return -1;
		}

		// 返回当前节点的高度
		return max(leftHeight, rightHeight) + 1;
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
	bool result = solution.isBalanced(root);

	// 输出结果
	if (result) {
		cout << "The tree is balanced." << endl;
	} else {
		cout << "The tree is not balanced." << endl;
	}

	return 0;
}
