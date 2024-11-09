#include <iostream>

// 定义链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	    : val(x)
	    , next(nullptr) {}
};

// 反转链表函数
ListNode* reverseList(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != nullptr) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// 合并两个链表函数
void mergeLists(ListNode* l1, ListNode* l2) {
	while (l1 != nullptr && l2 != nullptr) {
		ListNode* l1_next = l1->next;
		ListNode* l2_next = l2->next;

		l1->next = l2;
		if (l1_next == nullptr)
			break;
		l2->next = l1_next;

		l1 = l1_next;
		l2 = l2_next;
	}
}

// 重新排列链表函数
void reorderList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return;

	// 使用快慢指针找到链表中点
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// 反转链表的后半部分
	ListNode* secondHalf = reverseList(slow->next);
	slow->next = nullptr;

	// 合并前后两个部分
	mergeLists(head, secondHalf);
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
	// 创建链表 1-> 2 -> 3 -> 4 -> 5 -> NULL
	ListNode* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);

	std::cout << "原始链表: ";
	printList(head);

	reorderList(head);

	std::cout << "重新排列后的链表: ";
	printList(head);

	// 释放链表内存
	freeList(head);

	return 0;
}
