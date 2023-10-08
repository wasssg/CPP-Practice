#pragma once
#pragma once
#include <iostream>
using namespace std;

// node
template <typename T>
struct klistNode {
	T data;
	klistNode<T>* nextNode = nullptr;
	klistNode<T>* prevNode = nullptr;
	klistNode() {};
	klistNode(int val) :data(val) {};
};


// list
template <typename T>
class klist {
public:
	klist();

	void push(T data);
	void foreach();
	void insert(klistNode<T>* node, int index);
	klistNode<T>* find(int data);
	void popAll();


	void removeByIndex(int index);
	void removeByNode(klistNode<T>* node);

private:
	klistNode<T>* _HeadNode;
};


