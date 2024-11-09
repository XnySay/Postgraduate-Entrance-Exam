#include <iostream>
#include <stack>

using namespace std;

// 定义二叉树的节点类
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
	    : val(x)
	    , left(nullptr)
	    , right(nullptr) {}
};

class Solution {
public:
	// 前序遍历翻转二叉树
	TreeNode* invertTreePreOrder(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}

		// 首先交换当前节点的左右子节点
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		// 然后递归地对子节点进行同样的操作
		invertTreePreOrder(root->left);
		invertTreePreOrder(root->right);

		return root;
	}
	// 后序遍历翻转二叉树
	TreeNode* invertTreePostOrder(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}

		// 先递归地访问左右子节点并翻转它们
		TreeNode* left = invertTreePostOrder(root->left);
		TreeNode* right = invertTreePostOrder(root->right);

		// 然后交换当前节点的左右子节点
		root->left = right;
		root->right = left;

		return root;
	}
	TreeNode* invertTreePreOrderNonRecursive(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		std::stack<TreeNode*> stk;
		stk.push(root);

		while (!stk.empty()) {
			TreeNode* node = stk.top();
			stk.pop();

			// 交换左右子树
			std::swap(node->left, node->right);

			// 先将右子树压栈，再将左子树压栈
			if (node->right)
				stk.push(node->right);
			if (node->left)
				stk.push(node->left);
		}

		return root;
	}
	TreeNode* invertTreePostOrderNonRecursive(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			stk.pop();
			swap(node->left, node->right); // 交换左右子节点
			if (node->left)
				stk.push(node->left); // 先左后右保证右子树先处理
			if (node->right)
				stk.push(node->right);
		}
		return root;
	}
	TreeNode* copyTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* newNode = new TreeNode(root->val);
		newNode->left = copyTree(root->left);
		newNode->right = copyTree(root->right);
		return newNode;
	}
};

void printTree(TreeNode* root) {
	if (root != nullptr) {
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
	}
}

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	Solution solution;
	cout << "Original tree: ";
	printTree(root);
	cout << endl;

	TreeNode* invertedRootByPreOrder =
	    solution.invertTreePreOrder(solution.copyTree(root));
	TreeNode* invertedRootByPostOrder =
	    solution.invertTreePostOrder(solution.copyTree(root));
	TreeNode* invertedRootByPreOrderNonRecursive =
	    solution.invertTreePreOrderNonRecursive(solution.copyTree(root));
	TreeNode* invertedRootByPostOrderNonRecursive =
	    solution.invertTreePostOrderNonRecursive(solution.copyTree(root));

	// 输出翻转后的二叉树
	cout << "Inverted tree: ";
	cout << "\nPreOrder: \n";
	printTree(invertedRootByPreOrder);
	cout << "\nPostOrder: \n";
	printTree(invertedRootByPostOrder);
	cout << "\nPreOrder NonRecursive: \n";
	printTree(invertedRootByPreOrderNonRecursive);
	cout << "\nPostOrder NonRecursive: \n";
	printTree(invertedRootByPostOrderNonRecursive);
	return 0;
}
