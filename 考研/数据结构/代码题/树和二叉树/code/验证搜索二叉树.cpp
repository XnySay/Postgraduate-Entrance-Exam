#include <iostream>
#include <stack>

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
	// 中序遍历法验证BST
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* prev = nullptr;

		while (!stk.empty() || root != nullptr) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();

			if (prev != nullptr && prev->val >= root->val) {
				return false;
			}

			prev = root;
			root = root->right;
		}

		return true;
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	Solution2 solution;
	bool result = solution.isValidBST(root);

	// 输出结果
	if (result) {
		cout << "The tree is a valid BST." << endl;
	} else {
		cout << "The tree is not a valid BST." << endl;
	}

	return 0;
}
