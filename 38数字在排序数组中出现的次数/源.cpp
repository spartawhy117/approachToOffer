#include <iostream>
using namespace std;
enum choose
{
	First = 0,
	Last = 1
};

int GetKey(int* data,int length,int k,int start,int end,int firstOrlast)
{
	if (start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];


	if(firstOrlast==First)
	{
		if (middleData == k)
		{
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
			{
				return  middleIndex;
			}
			else
				end = middleIndex - 1;
		}
		else if (middleData > k)
			end = middleIndex - 1;
		else
			start = middleIndex + 1;
	}
	else
	{
		if (middleData == k)
		{
			if ((middleIndex <length-1 && data[middleIndex +1] != k) || middleIndex == length-1)
			{
				return  middleIndex;
			}
			else
				end = middleIndex + 1;
		}
		else if (middleData < k)
			end = middleIndex + 1;
		else
			start = middleIndex - 1;
	}

	return GetKey(data, length, k, start, end, firstOrlast);
}

int GetNumofK(int*data,int l,int k)
{

	//因为都是用快排查找一个特定的数，所以时间复杂度还是logn
	int n = 0;
	if(data!=nullptr&&l>0)
	{
		int first = GetKey(data, l, k, 0, l - 1, First);
		int last = GetKey(data, l, k, 0, l - 1, Last);

		if(first>-1&&last>-1)
		{
			n = last - first + 1;
		}
	}

	return  n;
}

int main(int argc, char* argv[])
{
	int data[] = { 1,2,3,3,3,3,4,5 };
	cout << GetNumofK(data,8,3)<<endl;

	system("pause");

}
