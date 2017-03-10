#include <iostream>
using namespace std;
int MaxSequence(int* arr,int lenghth)
{
	if (arr == nullptr || lenghth < 1)
		return -1;

	int indexBegin = 0;
	int indexEnd = 0;
	int sum = arr[0];
	int MaxSum = sum;
	int lastSum = MaxSum;

	for(int i=1;i<lenghth;++i)
	{
		lastSum = sum;
		sum += arr[i];

		if(sum>MaxSum)
		{
			MaxSum = sum;
			indexEnd = i;
		}

		if(lastSum<0&&sum>0)
		{
			indexBegin = i;
			sum = arr[i];
		}
	}

	cout << arr[indexBegin] << " " << arr[indexEnd]<<endl;
	return MaxSum;

}



int main(int argc, char* argv[])
{
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
	int v = MaxSequence(arr, 8);

	cout << v;

	system("pause");
}
