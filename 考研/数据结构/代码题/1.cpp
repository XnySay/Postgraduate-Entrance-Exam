#include <iostream>
using namespace std;

// 定义链表结点结构
struct ListNode {
  int data;                                   // 数据域
  ListNode *next;                             // 指针域
  ListNode(int x) : data(x), next(nullptr) {} // 构造函数
};

// 查找倒数第 k 个结点的函数
int findKthFromEnd(ListNode *head, int k) {
  if (k <= 0 || !head)
    return 0;
  ListNode *fast = head;
  ListNode *slow = head;

  // 先让 fast 指针移动 k 步
  for (int i = 0; i < k; ++i) {
    if (fast == nullptr) {
      return 0; // 如果链表长度不足 k，直接返回 false
    }
    fast = fast->next;
  }

  // 同时移动 fast 和 slow 指针，直到 fast 到达链表末尾
  while (fast != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  // 此时 slow 指向倒数第 k 个结点
  if (slow != nullptr)
    return slow->data;

  return 0; // 没有找到，返回 0
}