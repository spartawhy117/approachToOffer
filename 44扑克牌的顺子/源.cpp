#include <iostream>
#include <algorithm>
using namespace std;

//�Ѵ���С������0����λ
bool IsContinusous(int* numbers,int length)
{
	if(numbers==nullptr||length<1)
	{
		return false;
	}
	//������ Ȼ��ͳ��0����Ŀ�ͼ����
	sort(numbers,numbers+length ,less<int>());
	int numZero = 0;
	int numGap = 0;
	for (int i = 0; i < length&&numbers[i] == 0; ++i)
		++numZero;

	int small = numZero;
	int big = small + 1;
	while (big<length)
	{
		if (numbers[small] == numbers[big])
			return false;

		numGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}
	return (numGap > numZero) ? false:true;
}


int main(int argc, char* argv[])
{
	int data[] = {1,3,4,5,0,7,0};
	if (IsContinusous(data, 7))
		cout << "true";
	else
		cout << "false";

	system("pause");


}
