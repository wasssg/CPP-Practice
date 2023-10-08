#pragma once
#include "KList.h"


template <class T>
KList<T>::KList() {
	this->_HeadNode = new KListNode<T>();
}

template <class T>
void KList<T>::push(T data) {

	KListNode<T>* NewNode = new KListNode<T>(data);
	KListNode<T>* CurrentNode = this->_HeadNode;
	while (CurrentNode->nextNode != nullptr)
	{
		CurrentNode = CurrentNode->nextNode;
	}

	CurrentNode->nextNode = NewNode;
	NewNode->prevNode = CurrentNode;
}

template <class T>
void KList<T>::foreach() {
	KListNode<T>* CurrentNode = this->_HeadNode;
	while (CurrentNode->nextNode != nullptr)
	{
		CurrentNode = CurrentNode->nextNode;
		if (CurrentNode->data != NULL) {
			cout << CurrentNode->data << "  ";
		}
	}
	cout << endl;
}

template <class T>
void KList<T>::insert(KListNode<T>* node, int index) {
	KListNode<T>* currentNode = this->_HeadNode;
	for (int i = 0; i < index; i++) {
		currentNode = currentNode->nextNode;
	}
	KListNode<T>* tailNode = currentNode->nextNode;
	currentNode->nextNode = node;
	node->nextNode = tailNode;
	tailNode->prevNode = node;
	node->prevNode = currentNode;
}

template <class T>
KListNode<T>* KList<T>::find(int index) {
	KListNode<T>* currentNode = this->_HeadNode;
	while (currentNode != nullptr && index >= 0)
	{
		currentNode = currentNode->nextNode;
		index--;
	}
	return currentNode;
}

template <class T>
void KList<T> ::popAll() {
	if (this->_HeadNode == nullptr)
	{
		return;
	}
	KListNode<T>* CurrentNode = this->_HeadNode->nextNode;
	while (CurrentNode != nullptr)
	{
		delete CurrentNode->prevNode;
		CurrentNode = CurrentNode->nextNode;
	};
	delete CurrentNode;
}

template <class T>
void KList<T> ::removeByIndex(int index) {

	KListNode<T>* removeNode = this->find(index);
	removeNode->prevNode->nextNode = removeNode->nextNode;
	delete removeNode;
}

template <class T>
void KList<T> ::removeByNode(KListNode<T>* node) {
	KListNode<T>* removeNode = this->_HeadNode;
	while (removeNode->data != node->data) {
		removeNode = removeNode->nextNode;
	}
	removeNode->prevNode->nextNode = removeNode->nextNode;
	delete removeNode;
}