#include <iostream>
using namespace std;
bool Check(int *arr)
{
	bool result = true;
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<8;j++)
		{
			int indexDiff =i - j;
			int diff = arr[i] - arr[j];
			//判断条件 
			//行的差的绝对值 等于 相应行中列的值的差的绝对值
			if (indexDiff == diff || -indexDiff == diff)
			{
				result = false;
				return result;
			}
		}
	}

	return result;
}

void Permutation(int *arr,int *begin,int length,int& count)
{

	if((begin-arr)==length-1)
	{	
		if (Check(arr))
			count++;
	}
	else
	{
		for (int* p = begin; p <= arr + length - 1; ++p)
		{
			int temp = *begin;
			*begin = *p;
			*p = temp;

			Permutation(arr, begin + 1, length, count);

			temp = *begin;
			*begin = *p;
			*p = temp;
		}
	}
	
}

void Queen()
{

	//columnindex 横坐标是第几行，里面的数字是第几行的的皇后所在的列
	int ColumnIndex[8];
	for(int i=0;i<8;i++)
	{
		ColumnIndex[i] = i;
	}
	int count = 0;
	//因为初始化的每行的数据不同
	//全排列这个这个数据再判断是否对角线满足条件
	Permutation(ColumnIndex, ColumnIndex, 8, count);

	cout << count<<endl;

}

int main(int argc, char* argv[])
{
	Queen();
	system("pause");
}
