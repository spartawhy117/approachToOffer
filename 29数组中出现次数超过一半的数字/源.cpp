#include <iostream>
using namespace std;

int MoreThanHalf(int* arr,int length)
{

	int lastNumer=arr[0];
	int count=1;
	
	for(int i=1;i<length;i++)
	{
		if(arr[i]==lastNumer)
		{
			count++;
		}
		else
		{
			count--;
		}

		if(count==0)
		{
			lastNumer = arr[i];
			count = 1;
		}
	}

	return lastNumer;
}

int main(int argc, char* argv[])
{
	int arr[] = {1,2,2,2,2,2,3,4,5};
	
	int r = MoreThanHalf(arr, 9);

	cout << r;

	system("pause");
}
