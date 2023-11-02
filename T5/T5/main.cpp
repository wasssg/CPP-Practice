#include "RingBuffer.h"
int main() {
	RingBuffer* rBuf = new RingBuffer(3);
	for (int i = 0; i < 9; i++)
	{
		rBuf->push(i);
		cout <<i+1<<"  "<< rBuf->getSize() << endl;
	}	

	cout << "---------------------------------------" << endl;
	
	for (int i = 0; i < 5; i++) {
		rBuf->pop();
		cout << i + 1 << "  " << rBuf->getSize() << endl;
	}
	
}