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
	// 寻找二叉树中两个节点的最近公共祖先
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 如果当前节点为空，或当前节点是p或q，直接返回当前节点
		if (root == NULL || root == p || root == q) {
			return root;
		}

		// 在左子树中递归寻找p和q的最近公共祖先
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// 在右子树中递归寻找p和q的最近公共祖先
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// 如果左子树和右子树都找到了p或q，说明当前节点是最近公共祖先
		if (left != NULL && right != NULL) {
			return root;
		}

		// 如果左子树和右子树都没有找到p或q，返回空
		if (left == NULL && right == NULL) {
			return NULL;
		}

		// 左子树和右子树只有一个找到了p或q，返回不为空的那个
		return left != NULL ? left : right;
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	Solution2 solution;
	TreeNode* p = root->left;               // Node with value 5
	TreeNode* q = root->left->right->right; // Node with value 4

	TreeNode* ancestor = solution.lowestCommonAncestor(root, p, q);

	// 输出结果
	if (ancestor != NULL) {
		cout << "Lowest Common Ancestor: " << ancestor->val << endl;
	} else {
		cout << "No Common Ancestor Found" << endl;
	}

	return 0;
}
