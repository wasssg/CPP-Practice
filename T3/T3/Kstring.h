#pragma once
#include <iostream>
#include <vector>
using namespace std;
class KString {
public:	
	KString():m_data(nullptr), m_size(0) {};
	KString(const char* str);
	KString(const KString& str);
	KString(int size);
	int len();
	friend ostream& operator<< (ostream& cout, const KString& obj);
	KString sub(int start, int length);
	char* append(const char* str);
	int find(const char* str);
	bool operator==(const KString& other);
	KString* split(const char* str);
	
private:
	char* m_data=nullptr;
	int m_size;
	int getLength(const char* str) {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		return len;
	}

};