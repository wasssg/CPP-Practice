#include "KArray.h"
template<class T>
KArray<T>::KArray() {
	m_data = nullptr;
	m_capacity = 0;
	m_length = 0;
}

template<class T>
KArray<T>::KArray(T capacity) {
	m_data = new T[capacity];
	m_capacity = capacity;
	m_length = 0;
}

template<class T>
KArray<T>::~KArray() {
	if (m_data != nullptr) {
		delete[]m_data;
		this->m_capacity = 0;
		m_capacity = 0;
		m_length = 0;
	}
}

template<class T>
int KArray<T>::length() {
	return m_length;
}

template<class T>
int KArray<T>::capacity() {
	return m_capacity;
}

template<class T>
void KArray<T>::kReserve(int capacity) {
	if (m_capacity >= capacity) return;
	int* newData = new T[m_capacity * capacity];
	for (int i = 0; i < m_capacity; i++) {
		newData[i] = m_data[i];
	}
	m_data = newData;
	m_capacity = capacity;
}

template<class T>
int& KArray<T>::operator [](int index) {
	return m_data[index];
}

template<class T>
void KArray<T>::push(T data) {
	if (m_length > m_capacity) {
		this->kReserve(2);
	}
	m_data[m_length] = data;
	m_length++;
}

template<class T>
void KArray<T>::insert(int index, T data) {
	if (m_length + 1 > m_capacity) this->kReserve(2);
	if (index > m_length) index = m_length;

	for (int i = m_length; i > index; i--) {
		m_data[i] = m_data[i - 1];
	}
	m_data[index] = data;
	m_length++;
}

template<class T>
void KArray<T>::show() {
	for (int i = 0; i < m_length; i++) {
		cout << m_data[i] << "   ";
	}
	cout << endl;
}

template<class T>
void KArray<T>::remove(int index) {
	if (index > m_length) index = m_length;
	for (int i = index; i < m_length; i++)
	{
		m_data[i] = m_data[i + 1];
	}
	m_length--;
}

template<class T>
void KArray<T>::pop() {
	if (m_length <= 0) return;
	m_length--;
}

template<class T>
void KArray<T>::clear() {
	delete[]m_data;
}

template<class T>
int KArray<T>::findeIndex(T data) {
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i] == data)  return i;
	}
	return -1;
}

