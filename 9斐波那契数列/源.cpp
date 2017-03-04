#include <iostream>
using namespace std;
long long Fibonacci(unsigned int n)
{
	int result[] = { 0,1 };
	if(n<2)
	{
		return result[n];

	}
	else
	{
		long long number_s=0;
		long long number_b=1;
		long long number_r = 0;
		for(int i=2;i<=n;i++)
		{
			number_r = number_s + number_b;
			number_s = number_b;
			number_b = number_r;
		}

		return number_r;
	}
}

int  main(int argc, char* argv[])
{
	cout << Fibonacci(6);

	system("pause");
}
