#include "KArray.cpp"
#include "KList.cpp"
using namespace std;

void customArray();
void customList();
int main() {
	//customArray();
	customList();
}

void customArray() {
	auto a1 = new kArray<int>(5);
	a1->push(0);
	a1->push(1);
	a1->push(2);
	a1->push(3);
	a1->push(4);
	//a1->insert(1, 10);
	a1->show();
	/*a1->remove(10);
	a1->show();*/
	//a1->pop();
	//a1->show();

	//a1->clear();
	//a1->show();

	int index = a1->findeIndex(3);
	cout << index << endl;
}
void customList() {
	auto l1 = new klist<int>();
	l1->push(0);
	l1->push(1);
	l1->push(2);
	l1->push(3);
	l1->push(4);
	l1->push(5);
	l1->foreach();

	/*auto node1 = new klistNode<int>(10);
	l1->insert(node1, 2);
	l1->foreach();*/
	auto node1 = l1->find(3);
	l1->removeByIndex(1);
	l1->removeByNode(node1);
	l1->foreach();
	//l1->popAll();
}