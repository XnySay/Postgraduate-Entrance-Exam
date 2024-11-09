#include <iostream>

// 定义链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int value)
	    : val(value)
	    , next(nullptr) {}
};

// 链表反转函数
void reverse(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return; // 处理空链表或只有一个节点的链表

	ListNode* prev = nullptr;    // 用于存储前一个节点
	ListNode* curr = head->next; // 当前节点
	ListNode* next = nullptr;    // 用于存储下一个节点

	while (curr != nullptr) {
		next = curr->next; // 保存下一个节点
		curr->next = prev; // 当前节点指向前一个节点，反转
		prev = curr;       // 更新前一个节点为当前节点
		curr = next;       // 移动到下一个节点
	}

	head->next = prev; // 更新头节点的下一个节点为新的首节点
}

// 创建新节点
ListNode* createNode(int value) { return new ListNode(value); }

// 打印链表
void printList(ListNode* head) {
	ListNode* current = head->next; // 跳过头节点
	while (current != nullptr) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

// 释放链表内存
void freeList(ListNode* head) {
	ListNode* current = head;
	while (current != nullptr) {
		ListNode* next = current->next;
		delete current;
		current = next;
	}
}

int main() {
	// 创建链表 L -> 1-> 2 -> 3 -> 4 -> NULL
	ListNode* head = createNode(0); // 创建头节点
	head->next = createNode(1);
	head->next->next = createNode(2);
	head->next->next->next = createNode(3);
	head->next->next->next->next = createNode(4);

	std::cout << "原始链表: ";
	printList(head);

	// 反转链表
	reverse(head);

	std::cout << "反转后的链表: ";
	printList(head);

	// 释放链表内存
	freeList(head);

	return 0;
}
