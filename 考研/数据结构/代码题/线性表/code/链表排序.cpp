#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	    : val(x)
	    , next(nullptr) {}
};

ListNode* split(ListNode* head, int n);
ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev);

ListNode* sortList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	// 获取链表长度
	int n = 0;
	for (ListNode* node = head; node != nullptr; node = node->next) {
		++n;
	}
	// 创建一个虚拟头节点，方便操作
	ListNode dummy(0);
	dummy.next = head;
	// 自底向上的归并排序
	for (int step = 1; step < n; step <<= 1) {
		ListNode* prev = &dummy;
		ListNode* cur = dummy.next;
		while (cur != nullptr) {
			ListNode* left = cur;
			ListNode* right = split(left, step);
			cur = split(right, step);
			prev = merge(left, right, prev);
		}
	}
	return dummy.next;
}

// 将链表分割为两部分，第一部分包含n个节点
// 返回第二部分的头节点
ListNode* split(ListNode* head, int n) {
	for (int i = 1; head != nullptr && i < n; ++i) {
		head = head->next;
	}
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* second = head->next;
	head->next = nullptr;
	return second;
}

// 合并两个已排序的链表，将结果附加到节点prevNode
// 返回合并链表的尾节点
ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
	ListNode* cur = prev;
	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		} else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = (l1 != nullptr ? l1 : l2);
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	return cur;
}

void solve() {
	int n;
	std::cin >> n;

	// 创建链表
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	for (int i = 0; i < n; ++i) {
		int val;
		std::cin >> val;
		if (head == nullptr) {
			head = new ListNode(val);
			tail = head;
		} else {
			tail->next = new ListNode(val);
			tail = tail->next;
		}
	}

	// 排序链表
	head = sortList(head);

	// 打印排序后的链表
	ListNode* cur = head;
	while (cur != nullptr) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << "\n";

	// 释放链表内存
	cur = head;
	while (cur != nullptr) {
		ListNode* next = cur->next;
		delete cur;
		cur = next;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}