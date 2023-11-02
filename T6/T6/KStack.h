#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//struct KStackInfo {
//public:
//	~KStackInfo()
//	{
//		if (next != nullptr)
//		{
//			delete next;
//			next = nullptr;
//		}
//	}
//public:
//	void* m_data = nullptr;
//	KStackInfo* next = nullptr;
//};


class KStack
{
public:	
	template<class T>
	void push(T& data); 
	template<class T>
	void pop(T& data);
private:
	vector<void*> datas;
	int currIndex = -1;
};

template<class T>
void KStack::push(T& data) {
	datas.push_back(& data);
	currIndex++;
}

template <class T>
void  KStack::pop(T& data) {
	data = *(T*)datas[currIndex];
	currIndex--;
}


//template<class T>
//void KStack::push(T& data) {
//	KStackInfo* temp = new KStackInfo;
//	temp->m_data = &data;
//	tail->next = temp;
//	tail = tail->next;
//}
//
//template<class T>
//void KStack::pop(T& data) {
//	if (head->next == nullptr) {
//		cout << "the stack is empty! " << endl;
//		return;
//	}
//	delete tail->m_data;
//}







