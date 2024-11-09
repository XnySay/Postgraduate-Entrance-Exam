#include <iostream>
#include <queue>
#include <vector>

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
	// 返回从右侧所能看到的节点值
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result; // 存储右侧视图节点值的结果数组
		if (root == NULL) {
			return result; // 如果根节点为空，返回空结果
		}

		queue<TreeNode*> q; // 创建一个队列用于广度优先搜索
		q.push(root);       // 将根节点入队

		while (!q.empty()) {
			int size = q.size(); // 当前层的节点数
			for (int i = 0; i < size; ++i) {
				TreeNode* node = q.front(); // 获取当前层的节点
				q.pop();                    // 将节点出队

				// 如果是当前层的最后一个节点，加入结果数组
				if (i == size - 1) {
					result.push_back(node->val);
				}

				// 将左子节点和右子节点依次入队
				if (node->left != NULL) {
					q.push(node->left);
				}
				if (node->right != NULL) {
					q.push(node->right);
				}
			}
		}

		return result; // 返回右侧视图节点值的结果数组
	}
};

int main() {
	// 创建一个示例二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(4);

	Solution2 solution;
	vector<int> result = solution.rightSideView(root);

	// 输出结果
	cout << "Right side view of the binary tree: ";
	for (int val : result) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
