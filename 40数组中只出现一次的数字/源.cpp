#include <iostream>
using namespace std;
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num&1)==0)&&(indexBit<8*sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num,unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}
void FindNumsAppearOnce(int data[],int length,int* num1,int* num2)
{
	if(data==nullptr||length<2)
	{
		return;
	}

	//这道题重点在于异或 相同的数字异或操作后会变0
	int resultExclusiveOR = 0;

	for(int i=0;i<length;i++)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for(int j=0;j<length;++j)
	{
		if (IsBit1(data[j], indexOf1))
		{
			*num1 ^= data[j];
		}
		else
			*num2 ^= data[j];
	}

}

int main(int argc, char* argv[])
{
	int data[] = {2,4,3,6,3,2,5,5};
	int num1, num2;
	FindNumsAppearOnce(data, 8, &num1, &num2);
	cout << num1 << " " << num2;
	system("pause");

	return 0;
}
