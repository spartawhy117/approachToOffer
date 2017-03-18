#include <iostream>
#include <list>
using namespace std;

//链表模拟，需要注意迭代到STL尾部需要重新指向头部
int List_LastRemaining(unsigned int n,unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> numbers;
	for(int i=0;i<n;++i)
	{
		numbers.push_back(i);
	}

	list<int>::iterator iter = numbers.begin();
	while (numbers.size()>1)
	{
		for(int i=1;i<m;++i)
		{
			iter++;
			if (iter == numbers.end())
				iter = numbers.begin();
		}
		list<int>::iterator next = ++iter;
		if (next == numbers.end())
			next = numbers.begin();

		--iter;
		numbers.erase(iter);
		iter = next;
	}
	return *iter;
}

//f(n,m)={0    n=1}
//       {[f(n-1,m)+m]%n n>1}
int Mod_LastRemaining(unsigned int n,unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for(int i=2;i<=n;++i)
	{
		last = (last + m) % i;
	}
	return  last;
}


int main(int argc, char* argv[])
{
	cout << Mod_LastRemaining(7, 2);
	system("pause");
}
