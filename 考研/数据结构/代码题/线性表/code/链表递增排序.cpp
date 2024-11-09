#include <iostream>

// 定义链表节点结构
struct ListNode {
	int data;
	ListNode* next;
	ListNode(int x)
	    : data(x)
	    , next(nullptr) {}
};

// 插入排序函数
void InsertSort(ListNode* head) {
	// 如果链表为空或者只有一个元素，直接返回
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	// 初始化一个新的链表，头节点为nullptr
	ListNode* new_head = new ListNode(0); // 临时的头节点
	ListNode* p = head->next;

	while (p != nullptr) {
		// 保存下一个节点
		ListNode* next = p->next;

		// 从新链表的头节点开始遍历
		ListNode* q = new_head;
		while (q->next != nullptr && q->next->data < p->data) {
			q = q->next;
		}

		// 将p插入到q后面
		p->next = q->next;
		q->next = p;

		// 继续处理下一个节点
		p = next;
	}

	// 将新链表的头节点赋值给原链表
	head->next = new_head->next;

	// 释放临时头节点的内存
	delete new_head;
}
ListNode* merge(ListNode* l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode* tail = &dummy;
	while (l1 && l2) {
		if (l1->data < l2->data) {
			tail->next = l1;
			l1 = l1->next;
		} else {
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	tail->next = l1 ? l1 : l2;
	return dummy.next;
}

ListNode* mergeSort(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* mid = slow->next;
	slow->next = nullptr;
	return merge(mergeSort(head), mergeSort(mid));
}

void ListInsertSort(ListNode* head) {
	if (!head || !head->next)
		return;
	head->next = mergeSort(head->next);
}
// 创建新节点
ListNode* createNode(int value) { return new ListNode(value); }

// 打印链表
void printList(ListNode* head) {
	ListNode* current = head->next; // 跳过头节点
	while (current != nullptr) {
		std::cout << current->data << " -> ";
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
	// 创建链表 L -> 4 -> 2 -> 1-> 3 -> NULL
	ListNode* head = createNode(0); // 创建头节点
	head->next = createNode(4);
	head->next->next = createNode(2);
	head->next->next->next = createNode(1);
	head->next->next->next->next = createNode(3);

	std::cout << "原始链表: ";
	printList(head);

	// 插入排序链表
	ListInsertSort(head);

	std::cout << "排序后的链表: ";
	printList(head);

	// 释放链表内存
	freeList(head);

	return 0;
}
