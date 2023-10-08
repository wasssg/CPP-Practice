#include "Kstring.h"
using namespace std;


KString::KString(const char* str) {
	if (str)
	{
		int len = getLength(str);
		m_data = new char[len + 1];
		for (int i = 0; i < len; i++) {
			m_data[i] = str[i];
		}
		m_data[len] = '\0';
		m_size = len;
	}
	else
	{
		m_size = 0;
	}
}
KString::KString(int size) {
	int len = size;
	m_data = new char[len + 1];

	m_data[len] = '\0';
	m_size = len;
}


KString::KString(const KString& str) {
	int len = str.m_size;
	m_data = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		m_data[i] = str.m_data[i];
	}
	m_size = str.m_size;
	m_data[len] = '\0';
}

int KString:: len() {
	return this->m_size;
}

 ostream& operator<< (ostream& cout, const KString& obj)
{
	int len = obj.m_size;
	for (int i = 0; i < len; i++) {
		cout << obj.m_data[i];
	}
	return cout;
}

 KString KString::sub(int start, int length) {
	 char* res = new char[length+1];
	 int i = 0;
	 int temp = length;
	 while (length != 0)
	 {
		 res[i] = m_data[start];
		 i++;
		 start++;
		 length--;
	 }
	 res[temp] = '\0';
	 return res;
 }

 char* KString::append(const char* str) {
	 int strLength = getLength(str);
	 int newSize = m_size + strLength;
	 char* newChar = new char[newSize+1];
	 for (int i = 0; i < m_size; i++) {
		 newChar[i] = m_data[i];
	 }
	 delete[] this->m_data;
	 for (int i = 0; i < strLength; i++)
	 {
		 if (m_size + i<= newSize + 1) {
			 newChar[m_size + i] = str[i];
		 }
	 }
	 newChar[newSize] = '\0';
	 m_size = m_size + strLength;
	 m_data = new char[m_size + 1];
	 for (int i = 0; i < m_size; i++)
	 {
		 m_data[i] = newChar[i];
	 }
	 m_data[m_size] = '\0';
	 delete[] newChar;
	 m_size = m_size + strlen(str);
	 newChar = nullptr;
	 return m_data;
 }

 int KString::find(const char* str) {
	 for (int i = 0; i < m_size; i++)
	 {
		 bool isMatch = true;
		 for (int j = 0; j < getLength(str); j++)
		 {
			 if (m_data[j + i] != str[j]) {
				 isMatch = false;
				 break;
			 }
		 }
		 if (isMatch)
		 {
			 return i;
		 }
	 }
	 return -1;
 }

 bool KString::operator==(const KString& other) {
	 if (other.m_size != this->m_size)
	 {
		 return false;
	 }
	 if (this->m_data == nullptr)
	 {
		 return true;
	 }
	 for (int i = 0; i < m_size; i++)
	 {
		 if (m_data[i] != other.m_data[i]) {
			 return false;
		 }
		 return true;
	 }
 }

 

 KString* KString::split(const char* str) {
	 KString newStr = KString(m_data);// 创建newStr存放原来的数据
	 newStr.append(str);//追加被分割字符
	 KString* res = new KString[newStr.m_size];// 定义字符串数组	
	 int index = newStr.find(str);
	 int i = 0;
	 while (index != -1) {
		 auto temp = newStr.sub(0, index);//
		 res[i].append(temp.m_data);
		
		 newStr = newStr.sub(index + 1, newStr.m_size);
		 index = newStr.find(str);
		 i++;
	 }
	 return res;
 }