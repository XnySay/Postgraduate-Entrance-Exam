#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义树节点类
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
	    : val(v)
	    , left(nullptr)
	    , right(nullptr) {}
};

// 辅助递归函数，用于构建二叉树
TreeNode* build(const vector<int>& pre, int pre_start, int pre_end,
                const vector<int>& in, int in_start, int in_end,
                const unordered_map<int, int>& in_map);

// 主函数，构建二叉树
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
	// 检查输入数组是否有效
	if (pre.empty() || in.empty() || pre.size() != in.size()) {
		return nullptr;
	}
	// 使用哈希表存储中序遍历的值及其索引
	unordered_map<int, int> in_map;
	for (int i = 0; i < in.size(); i++) {
		in_map[in[i]] = i;
	}
	// 调用递归函数构建二叉树
	return build(pre, 0, pre.size() - 1, in, 0, in.size() - 1, in_map);
}

// 辅助递归函数，用于构建二叉树
TreeNode* build(const vector<int>& pre, int pre_start, int pre_end,
                const vector<int>& in, int in_start, int in_end,
                const unordered_map<int, int>& in_map) {
	// 如果先序遍历的起始索引大于结束索引，返回空节点
	if (pre_start > pre_end) {
		return nullptr;
	}
	// 创建当前子树的根节点，根节点值为当前先序遍历的第一个元素
	TreeNode* root = new TreeNode(pre[pre_start]);
	// 如果只有一个节点，直接返回根节点
	if (pre_start == pre_end) {
		return root;
	}
	// 在中序遍历中找到当前根节点的位置
	int in_root_index = in_map.at(pre[pre_start]);
	// 计算左子树的节点数目
	int left_tree_size = in_root_index - in_start;

	// pre : l1(........)[.......r1]
	// in  : (l2......)k[........r2]
	// (...)是左树对应，[...]是右树的对应
	root->left = build(pre, pre_start + 1, pre_start + left_tree_size, in,
	                   in_start, in_root_index - 1, in_map);
	root->right = build(pre, pre_start + left_tree_size + 1, pre_end, in,
	                    in_root_index + 1, in_end, in_map);

	// 返回根节点
	return root;
}

// 测试函数
void test() {
	// 创建先序遍历和中序遍历的数组
	vector<int> pre = {3, 9, 20, 15, 7};
	vector<int> in = {9, 3, 15, 20, 7};

	// 构建二叉树
	TreeNode* root = buildTree(pre, in);

	// 验证结果
	assert(root->val == 3);
	assert(root->left->val == 9);
	assert(root->right->val == 20);
	assert(root->right->left->val == 15);
	assert(root->right->right->val == 7);

	cout << "All tests passed." << endl;
}

int main() {
	test();
	return 0;
}
