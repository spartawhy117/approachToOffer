#include <iostream>
using namespace std;
int Add(int num1,int num2)
{
	int sum, carry;
	do
	{
		//�����ǽ�λ
		sum = num1^num2;
		//���ǽ�λ
		carry = (num1&num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

int main(int argc, char* argv[])
{
	int v = Add(35, 47);
	cout << v << endl;


	system("pause");
}
