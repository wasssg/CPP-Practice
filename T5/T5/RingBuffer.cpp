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
bool RingBuffer::isFull() { //�ж��Ƿ�����
	if (usedLength==size && rear==size )
	{
		return true;
	}
	return false;
}

bool RingBuffer::needLessen() { //�ж��Ƿ���Ҫ��������
	if ((usedLength <= size * 0.7) && ( !isEmpty() ) ) {
		return true;
	}
	return false;
}


void  RingBuffer::push(char item) { //���Ԫ��
	if (isFull()) {
		expand();
	}
	buffer[rear] = item;
	rear++;
	usedLength++;
}
	
void RingBuffer::pop(){  //ɾ��Ԫ��
	rear--;
	usedLength--;
	if (needLessen())
	{
		lessen();
	}
}

void  RingBuffer::expand() {   //����
	size = size * 1.5;
	char* temp = new char[size];
	for (int i=0;i<usedLength;i++)
	{
		temp[i] = buffer[i];
	}
	this->buffer = temp;
}

void  RingBuffer::lessen(){    //��С��С
	size = size * 0.8;
	char* temp = new char[size];
	for (int i = 0; i < usedLength; i++)
	{
		temp[i] = buffer[i];
	}
	this->buffer = temp;
}