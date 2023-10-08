#include<iostream>
#include <Kstring.h>
using namespace std;
int main() {
	//auto str1 = kString("abcdefg");
	//auto str2 = str1.sub(1, 5);
	//auto str3 = kString("123");
	//const char* char1="123";

	//cout << str1.append(char1);
	//cout << endl;
	//cout << str2 << endl;
	//cout << str1.find("ce");
	auto str4 = KString("23a22222a123a5555a11111");
	auto res=str4.split("a");
	cout << res[2] << endl;
	/*for (int i = 0; i < res->len(); i++) {
		cout << res[i] << endl;
	}*/
	//auto str = str4.sub(0, 2);
		//cout << str << endl;
}