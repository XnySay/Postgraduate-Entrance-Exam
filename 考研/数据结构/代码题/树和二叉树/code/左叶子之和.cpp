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
	// 计算二叉树所有左叶子之和
	int sumOfLeftLeaves(TreeNode* root) {
		// 如果当前节点为空，返回0
		if (root == NULL) {
			return 0;
		}

		// 初始化左叶子节点和
		int leftLeavesSum = 0;

		// 检查左子节点是否存在并是叶子节点
		if (root->left != NULL) {
			if (root->left->left == NULL && root->left->right == NULL) {
				leftLeavesSum +=
				    root->left->val; // 左子节点是叶子节点，累加其值
			} else {
				leftLeavesSum +=
				    sumOfLeftLeaves(root->left); // 递归计算左子树的左叶子节点和
			}
		}

		// 递归计算右子树的左叶子节点和
		leftLeavesSum += sumOfLeftLeaves(root->right);

		// 返回左叶子节点和
		return leftLeavesSum;
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
	int result = solution.sumOfLeftLeaves(root);

	// 输出结果
	cout << "Sum of all left leaves: " << result << endl;

	return 0;
}
