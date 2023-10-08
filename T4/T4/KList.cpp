#pragma once
#include "KList.h"


template <class T>
klist<T>::klist() {
	this->_HeadNode = new klistNode<T>();
}

template <class T>
void klist<T>::push(T data) {

	klistNode<T>* NewNode = new klistNode<T>(data);
	klistNode<T>* CurrentNode = this->_HeadNode;
	while (CurrentNode->nextNode != nullptr)
	{
		CurrentNode = CurrentNode->nextNode;
	}

	CurrentNode->nextNode = NewNode;
	NewNode->prevNode = CurrentNode;
}

template <class T>
void klist<T>::foreach() {
	klistNode<T>* CurrentNode = this->_HeadNode;
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
void klist<T>::insert(klistNode<T>* node, int index) {
	klistNode<T>* currentNode = this->_HeadNode;
	for (int i = 0; i < index; i++) {
		currentNode = currentNode->nextNode;
	}
	klistNode<T>* tailNode = currentNode->nextNode;
	currentNode->nextNode = node;
	node->nextNode = tailNode;
	tailNode->prevNode = node;
	node->prevNode = currentNode;
}

template <class T>
klistNode<T>* klist<T>::find(int index) {
	klistNode<T>* currentNode = this->_HeadNode;
	while (currentNode != nullptr && index >= 0)
	{
		currentNode = currentNode->nextNode;
		index--;
	}
	return currentNode;
}

template <class T>
void klist<T> ::popAll() {
	if (this->_HeadNode == nullptr)
	{
		return;
	}
	klistNode<T>* CurrentNode = this->_HeadNode->nextNode;
	while (CurrentNode != nullptr)
	{
		delete CurrentNode->prevNode;
		CurrentNode = CurrentNode->nextNode;
	};
	delete CurrentNode;
}

template <class T>
void klist<T> ::removeByIndex(int index) {

	klistNode<T>* removeNode = this->find(index);
	removeNode->prevNode->nextNode = removeNode->nextNode;
	delete removeNode;
}

template <class T>
void klist<T> ::removeByNode(klistNode<T>* node) {
	klistNode<T>* removeNode = this->_HeadNode;
	while (removeNode->data != node->data) {
		removeNode = removeNode->nextNode;
	}
	removeNode->prevNode->nextNode = removeNode->nextNode;
	delete removeNode;
}