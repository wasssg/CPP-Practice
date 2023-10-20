#include "RingBuffer.h"
int main() {
	RingBuffer* rBuf = new RingBuffer(3);
	for (int i = 0; i < 10000; i++)
	{
		rBuf->push(i);
	}
	cout << rBuf->getSize() << "    ";
	

	for (int i = 0; i < 1340; i++) {
		rBuf->pop();
	}
	cout << rBuf->getSize() << "    ";
}