#include <iostream>
#include "KStack.h"

int main()
{
	KStack* s1 = new KStack();
	int a = 20;
	float b = 11.2;
	float resB = 1.0;
	int resA = 0;

	s1->push(a);
	s1->push(b);

	s1->pop(resB);
	s1->pop(resA);
	std::cout << "resB : " << resB << std::endl;
	std::cout << "resA : " << resA << std::endl;
	return 0;
}
