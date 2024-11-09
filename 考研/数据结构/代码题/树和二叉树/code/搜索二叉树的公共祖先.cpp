#include <iostream>

using namespace std;

// 定义二叉搜索树的节点类
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
	// 在二叉搜索树中寻找两个节点的最近公共祖先
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root != nullptr) {
			// 如果当前节点的值大于p和q的值，说明p和q都在当前节点的左子树
			if (root->val > p->val && root->val > q->val) {
				root = root->left;
			}
			// 如果当前节点的值小于p和q的值，说明p和q都在当前节点的右子树
			else if (root->val < p->val && root->val < q->val) {
				root = root->right;
			}
			// 当前节点在p和q之间，或等于p或q，说明当前节点就是最近公共祖先
			else {
				return root;
			}
		}
		return nullptr; // 这种情况一般不会发生，除非输入的节点不在树中
	}
};

int main() {
	// 创建一个示例二叉搜索树
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);

	Solution2 solution;
	TreeNode* p = root->left;  // Node with value 2
	TreeNode* q = root->right; // Node with value 8

	TreeNode* ancestor = solution.lowestCommonAncestor(root, p, q);

	// 输出结果
	if (ancestor != NULL) {
		cout << "Lowest Common Ancestor: " << ancestor->val << endl;
	} else {
		cout << "No Common Ancestor Found" << endl;
	}

	return 0;
}
