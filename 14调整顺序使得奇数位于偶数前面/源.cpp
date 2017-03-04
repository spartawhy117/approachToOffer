#include <iostream>
using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
	//主要是传入函数参数
	if(pData==nullptr||length==0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin<pEnd)
	{
		while (pBegin<pEnd&&!func(*pBegin))
		{
			pBegin++;
		}
		while (pBegin<pEnd&&func(*pEnd))
		{
			pEnd--;
		}

		if(pBegin<pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderAsNeed(int* pData,unsigned int l)
{
	Reorder(pData, l, isEven);
}

int main(int argc, char* argv[])
{
	int arr[] = { 1,2,3,4,5 };
	ReorderAsNeed(arr, 5);

	for (int i = 0; i < 5; i++)
		cout << arr[i];
	system("pause");

}
