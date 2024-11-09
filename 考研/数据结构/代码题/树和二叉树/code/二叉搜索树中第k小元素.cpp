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

// 查找二叉搜索树中第 k 小的元素
int kthSmallest(TreeNode* root, int k) {
	// 使用栈进行迭代中序遍历
	stack<TreeNode*> stk;
	TreeNode* current = root;

	while (current != nullptr || !stk.empty()) {
		// 一直走到左子树的最下方
		while (current != nullptr) {
			stk.push(current);
			current = current->left;
		}

		// 处理当前节点
		current = stk.top();
		stk.pop();
		k--; // 访问一个节点，k减1

		// 如果k变成0，说明当前节点是第k小的元素
		if (k == 0) {
			return current->val;
		}

		// 进入右子树
		current = current->right;
	}

	return -1; // 这个return只是为了满足编译器，理论上不会走到这里
}

void solve() {
	int k;
	cin >> k;
	// 创建一个示例二叉搜索树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);

	int result = kthSmallest(root, k);

	cout << "The " << k << "th smallest element in the BST is: " << result
	     << endl;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	// int t;
	// cin >> t;

	// while (t--) {
	// 	solve();
	// }
	solve();

	return 0;
}