#pragma once
#include <iostream>
using namespace std;
class RingBuffer
{
public:
	RingBuffer(int length);
	RingBuffer();
	~RingBuffer();
	bool isEmpty();//�ж��Ƿ�Ϊ��
	bool isFull();//�ж��Ƿ�����
	bool needLessen(); //�ж��Ƿ���Ҫ
	void push(char item);//���Ԫ��
	void pop();//ɾ��Ԫ��
	void expand();//����
	void lessen();//��С��С
	char at(int index); // ��ȡָ���±��ֵ
	int getUsedLength();//��ȡ��ʹ�� �ĳ���
	int getSize();//��ȡ����buffer�ĳ���
private:	
	int size=0; // ringBuffer�ĳ���
	int usedLength = 0; // ʹ���˵ĳ���
	int front; //�׵�ַ
	int rear; //β��ַ
	char* buffer; // RingBuffer�������
};


