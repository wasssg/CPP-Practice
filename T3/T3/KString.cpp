#include "Kstring.h"
using namespace std;


kString::kString(const char* str) {
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
		m_data[0] = '\0';
		m_size = 0;
	}
}
kString::kString(int size) {
	int len = size;
	m_data = new char[len + 1];

	m_data[len] = '\0';
	m_size = len;
}


kString::kString(const kString& str) {
	int len = str.m_size;
	m_data = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		m_data[i] = str.m_data[i];
	}
	m_size = str.m_size;
}

int kString:: len() {
	return this->m_size;
}

 ostream& operator<< (ostream& cout, const kString& obj)
{
	int len = obj.m_size;
	for (int i = 0; i < len; i++) {
		cout << obj.m_data[i];
	}
	return cout;
}

 kString kString::sub(int start, int length) {
	 char* res = new char[length+1];
	 int i = 0;
	 int temp = length;
	 while (length != 0)
	 {
		// cout << "1111" << endl;
		 res[i] = m_data[start];
		 i++;
		 start++;
		 length--;
	 }
	 res[temp] = '\0';
	 return res;
 }

 char* kString::append(const char* str) {
	 int strLength = getLength(str);
	 int newSize = m_size + strLength;
	 char* newChar = new char[newSize+1];
	 for (int i = 0; i < m_size; i++) {
		 newChar[i] = m_data[i];
	 }
	 delete[] this->m_data;
	 for (int i = 0; i < strLength; i++)
	 {
		 newChar[m_size +i] = str[i];
	 }
	 newChar[strLength + m_size] = '\0';
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

 int kString::find(const char* str) {
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

 bool kString::operator==(const kString& other) {
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

 /*vector<kString> kString::split(const char* str)
 {
	 vector<int> vIndex=find(str);
	 vector<kString> vString;
	 int i = 0;
	 while (i < m_size)
	 {
		 i = this->find(str);
		 vIndex.push_back(i);
	 }
	 for (int j = 0; j < vIndex.size(); j++) {
		 cout << vIndex[j];
	 }
	 return vString;
 }*/

 kString* kString::split(const char* str) {
	 kString newStr = kString(m_data);// 创建newStr存放原来的数据
	 newStr.append(str);//追加被分割字符
	// newStr.m_size = this->m_size;
	 kString* res = new kString[newStr.m_size];// 定义字符串数组	
	 int index = newStr.find(str);
	// cout << index << endl;

	 
	 int i = 0;
	 while (index != -1) {
		 auto temp = newStr.sub(0, index);//
//		 cout << "---------" << endl;
		 res[i].append(temp.m_data);
		
		 newStr = newStr.sub(index + 1, newStr.m_size);
		 index = newStr.find(str);
		 i++;
		// cout << i << endl;
		// cout << index << endl;
	 }
	 return res;
 }