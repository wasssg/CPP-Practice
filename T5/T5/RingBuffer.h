#pragma once
#include <iostream>
using namespace std;
class RingBuffer
{
public:
	RingBuffer(int length);
	RingBuffer();
	~RingBuffer();
	bool isEmpty();//判断是否为空
	bool isFull();//判断是否满了
	bool needLessen(); //判断是否需要
	void push(char item);//添加元素
	void pop();//删除元素
	void expand();//扩容
	void lessen();//缩小大小
	char at(int index); // 获取指定下标的值
	int getUsedLength();//获取已使用 的长度
	int getSize();//获取整个buffer的长度
private:	
	int size=0; // ringBuffer的长度
	int usedLength = 0; // 使用了的长度
	int front; //首地址
	int rear; //尾地址
	char* buffer; // RingBuffer存的数据
};


