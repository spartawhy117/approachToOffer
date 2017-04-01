#include <iostream>
using namespace std;
class A;
A* Array[2];
class  A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};
//Ä£°å
template <unsigned int n>struct Sum
{
	enum Value{N=Sum<n-1>::N+n};
};
template<> struct Sum<1>
{
	enum Value{N=1};
};

int main(int argc, char* argv[])
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int n = 8;
	int value = Array[1]->Sum(n);
	cout << value << endl;

	Sum<100> sum;
	value = sum.N;

	cout << value << endl;
	system("pause");
}
