#include <iostream>

class SeqList {
private:
	static const int Maxsize = 100; // 定义线性表的最大长度
	int data[Maxsize];              // 存储线性表元素的数组
	int length;                     // 线性表当前长度

public:
	// 构造函数，用于初始化线性表
	SeqList()
	    : length(0) {}

	// 判断线性表是否为空
	bool isEmpty() const { return length == 0; }

	// 插入元素到线性表
	bool insertList(int index, int element) {
		if (index < 1 || index > length + 1 || length >= Maxsize) {
			return false; // 插入位置不合法或表已满
		}
		for (int i = length; i >= index; i--) {
			data[i] = data[i - 1]; // 元素后移
		}
		data[index - 1] = element; // 插入新元素
		length++;
		return true;
	}

	// 删除线性表中的元素
	bool deleteList(int index) {
		if (index < 1 || index > length) {
			return false; // 删除位置不合法
		}
		for (int i = index; i < length; i++) {
			data[i - 1] = data[i]; // 元素前移
		}
		length--;
		return true;
	}

	// 查找元素的位置
	int locateElement(int element) const {
		for (int i = 0; i < length; i++) {
			if (data[i] == element) {
				return i + 1; // 返回元素的位置(位置从1开始计数)
			}
		}
		return -1; // 没找到元素
	}

	// 检查元素是否存在
	bool contains(int element) const { return locateElement(element) != -1; }

	// 遍历打印线性表
	void printList() const {
		for (int i = 0; i < length; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};