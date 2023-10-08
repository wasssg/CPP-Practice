#pragma once
#include <iostream>
#include <vector>
using namespace std;
class kString {
public:	
	kString():m_data(nullptr), m_size(0) {};
	kString(const char* str);
	kString(const kString& str);
	kString(int size);
	int len();
	friend ostream& operator<< (ostream& cout, const kString& obj);
	kString sub(int start, int length);
	char* append(const char* str);
	int find(const char* str);
	bool operator==(const kString& other);
	//vector<kString> split(const char* str);
	kString* split(const char* str);
	
private:
	char* m_data;
	int m_size;
	int getLength(const char* str) {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		return len;
	}

};