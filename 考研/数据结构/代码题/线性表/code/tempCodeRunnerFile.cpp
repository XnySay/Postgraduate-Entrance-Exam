bool findKthToTail(ListNode* head, int k) {
	if (head == nullptr || k <= 0) {
		return false; // 处理无效输入
	}

	ListNode* fast = head;
	ListNode* slow = head;

	// 第一个指针先向前移动k步
	for (int i = 0; i < k; ++i) {
		if (fast == nullptr) { // 如果链表长度小于k，直接返回false
			return false;
		}
		fast = fast->next;
	}

	// 两个指针同时向前移动，直到第一个指针到达链表的末尾
	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	// 此时，第二个指针指向的就是倒数第k个节点
	std::cout << slow->val << std::endl; // 输出该节点的值
	return true;
}