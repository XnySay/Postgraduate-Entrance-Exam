#include <iostream>

// 定义链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	    : val(x)
	    , next(nullptr) {}
};

// 添加两个链表
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode dummy(0); // 使用哑节点简化代码
	ListNode* current = &dummy;
	int carry = 0;

	// 遍历两个链表，直到所有节点都处理完毕
	while (l1 != nullptr || l2 != nullptr || carry != 0) {
		int sum = carry;
		if (l1 != nullptr) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != nullptr) {
			sum += l2->val;
			l2 = l2->next;
		}

		carry = sum / 10;
		current->next = new ListNode(sum % 10);
		current = current->next;
	}

	return dummy.next;
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
	// 创建链表 l1= [2,4,3]
	ListNode* l1 = createNode(2);
	l1->next = createNode(4);
	l1->next->next = createNode(3);

	// 创建链表 l2 = [5,6,4]
	ListNode* l2 = createNode(5);
	l2->next = createNode(6);
	l2->next->next = createNode(4);

	std::cout << "链表 l1: ";
	printList(l1);

	std::cout << "链表 l2: ";
	printList(l2);

	ListNode* result = addTwoNumbers(l1, l2);

	std::cout << "结果链表: ";
	printList(result);

	// 释放链表内存
	freeList(l1);
	freeList(l2);
	freeList(result);

	return 0;
}
