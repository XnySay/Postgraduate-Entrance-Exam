#include <iostream>

// 定义链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	    : val(x)
	    , next(nullptr) {}
};

// 查找当前组的结束节点
ListNode* teamEnd(ListNode* s, int k) {
	while (--k != 0 && s != nullptr) {
		s = s->next;
	}
	return s;
}

// 翻转链表从s到e的部分
void reverse(ListNode* s, ListNode* e) {
	e = e->next;
	ListNode* pre = nullptr;
	ListNode* cur = s;
	while (cur != e) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	s->next = e;
}

// 翻转每个k组链表
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* groupStart = head;
	ListNode* groupEnd = teamEnd(groupStart, k);
	if (groupEnd == nullptr) {
		return head;
	}

	// 第一组需要特别处理，因为会涉及到头节点的改变
	head = groupEnd;
	reverse(groupStart, groupEnd);

	// 翻转后，groupStart变成了上一组的结尾节点
	ListNode* prevGroupEnd = groupStart;
	while (prevGroupEnd->next != nullptr) {
		groupStart = prevGroupEnd->next;
		groupEnd = teamEnd(groupStart, k);
		if (groupEnd == nullptr) {
			return head;
		}
		reverse(groupStart, groupEnd);
		prevGroupEnd->next = groupEnd;
		prevGroupEnd = groupStart;
	}
	return head;
}

// 创建新节点
ListNode* createNode(int value) { return new ListNode(value); }

// 打印链表
void printList(ListNode* head) {
	ListNode* current = head;
	while (current != nullptr) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

// 释放链表内存
void freeList(ListNode* head) {
	while (head != nullptr) {
		ListNode* next = head->next;
		delete head;
		head = next;
	}
}

int main() {
	// 创建链表 1-> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
	ListNode* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	head->next->next->next->next->next = createNode(6);
	head->next->next->next->next->next->next = createNode(7);
	head->next->next->next->next->next->next->next = createNode(8);

	std::cout << "原始链表: ";
	printList(head);

	int k = 3;
	head = reverseKGroup(head, k);

	std::cout << "翻转后的链表: ";
	printList(head);

	// 释放链表内存
	freeList(head);

	return 0;
}
