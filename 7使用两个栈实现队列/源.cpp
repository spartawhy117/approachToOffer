#include  "CQueue.h"
#include <iostream>

int main()
{
	CQueue<int> queue;
	queue.appendTail(4);
	queue.appendTail(5);
	queue.appendTail(3);
	cout<<queue.deleteHead()<<" ";
	queue.appendTail(6);

	cout << queue.deleteHead() << " ";

	system("pause");
}
