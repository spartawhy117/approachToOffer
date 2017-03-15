#include <iostream>
using namespace std;
int Min(int num1,int num2,int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;

}
int GetUglyNumber(unsigned index)
{
	if (index <= 0)
		return 0;
	int* pUglyArray = new int[index];
	pUglyArray[0] = 1;
	int nextIndex = 1;
	int* indexMultiply2 = pUglyArray;
	int* indexMultiply3 = pUglyArray;
	int* indexMultiply5 = pUglyArray;

	while (nextIndex< index)
	{
		
		int min = Min(*indexMultiply2 * 2, *indexMultiply3 * 3, *indexMultiply5 * 5);
		pUglyArray[nextIndex] = min;

		//NOTE: 总有一个数乘以2,3,5刚大于目前新生成的丑数，下一次就比较这三个刚大于的数
		while (*indexMultiply2*2<=pUglyArray[nextIndex])
		{
			++indexMultiply2;
		}
		while (*indexMultiply3 * 3 <= pUglyArray[nextIndex])
		{
			++indexMultiply3;
		}
		while (*indexMultiply5* 5 <= pUglyArray[nextIndex])
		{
			++indexMultiply5;
		}

		++nextIndex;
	}

	int ugly = pUglyArray[nextIndex - 1];
	delete[] pUglyArray;
	return ugly;

}


int main(int argc, char* argv[])
{
	int v = GetUglyNumber(1500);
	cout << v<<endl;

	system("pause");

}
