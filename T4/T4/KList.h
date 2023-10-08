#pragma once
#pragma once
#include <iostream>
using namespace std;

// node
template <typename T>
struct KListNode {
	T data;
	KListNode<T>* nextNode = nullptr;
	KListNode<T>* prevNode = nullptr;
	KListNode() {};
	KListNode(int val) :data(val) {};
};


// list
template <typename T>
class KList {
public:
	KList();

	void push(T data);
	void foreach();
	void insert(KListNode<T>* node, int index);
	KListNode<T>* find(int data);
	void popAll();


	void removeByIndex(int index);
	void removeByNode(KListNode<T>* node);

private:
	KListNode<T>* _HeadNode;
};


