#include <iostream>
using namespace std;
//���λ��1�ĸ�����ʣ�µ�λ���ǲ���1������
int PowerBase10(unsigned int n)
{
	int result = 1;
	for(unsigned int i=0;i<n;++i)
	{
		result *= 10;
	}

	return result;
}

int NumberOf1(const char* strN)
{
	if (!strN || *strN<'0' || *strN>'9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;

	//if is 21345
	//numFirstDigit��10000-19999�ĵ�һ��λ�е���Ŀ
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	//10000~12345 �����λ��ȥ��ʣ�µ����ּ�1
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	//1346~21345 ���˵�һλ֮�����Ŀ�е���Ŀ
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	//��1~1345�е���Ŀ
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Bettween1AndN(int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf_s(strN, "%d", n);

	return NumberOf1(strN);
}

int main(int argc, char* argv[])
{
	int v = NumberOf1Bettween1AndN(10000);

	cout << v;

	system("pause");
}
