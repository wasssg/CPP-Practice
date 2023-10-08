#pragma once
#include <iostream>
using namespace std;

template<class T>
class kArray {
public:
	kArray();

	kArray(T capacity);
	~kArray();

	int length();
	int capacity();

	void kReserve(int capacity);

	int& operator [](int index);

	void push(T data);

	void insert(int index, T data);

	void show();

	void remove(int index);

	void pop();

	void clear();

	int findeIndex(T data);

public:
	int m_capacity;
	int* m_data;
	int m_length;


};


