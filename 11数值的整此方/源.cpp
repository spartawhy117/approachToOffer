#include <iostream>
using namespace std;

double Power(double base, int exponent)
{
	if (base == 0.0&&exponent <=0)
		return 0.0;
	//主要是指数需要判断正负号
	unsigned int e = 0;
	if (exponent < 0)
	{
		e = static_cast<unsigned int>(-exponent);
	}
	else
		e = static_cast<unsigned int>(exponent);

	double result = 1.0;
	for(int i=1;i<=e;i++)
	{
		result *= base;
	}

	if (exponent<0)
	{
		result = 1.0 / result;
	}

	return result;
}

int main(int argc, char* argv[])
{
	
	cout << Power(5.0, 0) << " " << Power(-5.0, -3);
	system("pause");
	
}
