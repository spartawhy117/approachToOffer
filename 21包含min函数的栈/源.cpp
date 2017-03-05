#include  "MiniStack.h"
#include <iostream>

int main(int argc, char* argv[])
{
	MiniStack<int> stack;

	stack.push(3);
	cout << stack.min()<<" ";
	stack.push(4);
	cout << stack.min()<<" ";

	stack.push(2);
	cout << stack.min()<<" ";

	stack.push(1);
	cout << stack.min()<<" ";

	stack.pop();
	cout << stack.min() << " ";

	stack.pop();
	cout << stack.min() << " ";

	stack.push(0);
	cout << stack.min() << " ";

	system("pause");
}
