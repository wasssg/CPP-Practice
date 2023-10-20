#include "RingBuffer.h"
RingBuffer::RingBuffer(int Length)
{
	buffer = new char[Length];
	size = Length;
	front = 0;
	rear = 0;
}

RingBuffer::RingBuffer()
{
	buffer = new char[1];
	size = 1;
	front = 0;
	rear = 0;
}

RingBuffer::~RingBuffer()
{
	delete buffer;
}

bool RingBuffer :: isEmpty() {
	if ((usedLength==0) && rear==front)
	{
		return true;
	}
	return false;
}

char  RingBuffer::at(int index) {
	return  buffer[index];
}

int RingBuffer::getUsedLength() {
	return usedLength;
}
int RingBuffer::getSize() {
	return size;
}
bool RingBuffer::isFull() { //判断是否满了
	if (usedLength==size && rear==size )
	{
		return true;
	}
	return false;
}

bool RingBuffer::needLessen() { //判断是否需要减少容量
	if ((usedLength <= size * 0.7) && ( !isEmpty() ) ) {
		return true;
	}
	return false;
}


void  RingBuffer::push(char item) { //添加元素
	if (isFull()) {
		expand();
	}
	buffer[rear] = item;
	rear++;
	usedLength++;
}
	
void RingBuffer::pop(){  //删除元素
	rear--;
	usedLength--;
	if (needLessen())
	{
		lessen();
	}
}

void  RingBuffer::expand() {   //扩容
	size = size * 1.5;
	char* temp = new char[size];
	for (int i=0;i<usedLength;i++)
	{
		temp[i] = buffer[i];
	}
	this->buffer = temp;
}

void  RingBuffer::lessen(){    //缩小大小
	size = size * 0.8;
	char* temp = new char[size];
	for (int i = 0; i < usedLength; i++)
	{
		temp[i] = buffer[i];
	}
	this->buffer = temp;
}