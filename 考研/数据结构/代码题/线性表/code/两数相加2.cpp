#include <iostream>
#include <stack>

// 定义链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	    : val(x)
	    , next(nullptr) {}
};

// 反转链表
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

// 添加两个链表
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	l1 = reverseList(l1);
	l2 = reverseList(l2);

	ListNode* dummy = new ListNode(0);
	ListNode* current = dummy;
	int carry = 0;

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

	ListNode* result = reverseList(dummy->next);
	delete dummy; // 清除dummy节点
	return result;
}
// 添加两个链表
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	std::stack<int> stack1, stack2;

	// 将链表 l1的节点值存入栈中
	while (l1 != nullptr) {
		stack1.push(l1->val);
		l1 = l1->next;
	}

	// 将链表 l2 的节点值存入栈中
	while (l2 != nullptr) {
		stack2.push(l2->val);
		l2 = l2->next;
	}

	ListNode* result = nullptr;
	int carry = 0;

	// 逐位相加处理进位
	while (!stack1.empty() || !stack2.empty() || carry != 0) {
		int sum = carry;
		if (!stack1.empty()) {
			sum += stack1.top();
			stack1.pop();
		}
		if (!stack2.empty()) {
			sum += stack2.top();
			stack2.pop();
		}
		carry = sum / 10;
		ListNode* newNode = new ListNode(sum % 10);
		newNode->next = result;
		result = newNode;
	}

	return result;
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
	// 创建链表 l1= [7,2,4,3]
	ListNode* l1 = createNode(7);
	l1->next = createNode(2);
	l1->next->next = createNode(4);
	l1->next->next->next = createNode(3);

	// 创建链表 l2 = [5,6,4]
	ListNode* l2 = createNode(5);
	l2->next = createNode(6);
	l2->next->next = createNode(4);

	std::cout << "链表 l1: ";
	printList(l1);

	std::cout << "链表 l2: ";
	printList(l2);

	ListNode* result = addTwoNumbers(l1, l2);

	std::cout << "翻转法 结果链表: ";
	printList(result);
	std::cout << "链表 l1: ";
	printList(l1);

	std::cout << "链表 l2: ";
	printList(l2);
	std::cout << "使用栈 结果链表: ";
	result = addTwoNumbers2(l1, l2);
	printList(result);

	// 释放链表内存
	freeList(l1);
	freeList(l2);
	freeList(result);

	return 0;
}
