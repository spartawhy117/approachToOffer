#include <iostream>
using namespace std;
int Min(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Invaild input");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1]>=numbers[index2])
	{
		if(index2-index1==1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;

		if(numbers[index1]==numbers[index2]&&numbers[index2]==numbers[indexMid])
		{
			int result = numbers[0];
			for(int i=0;i<length;i++)
			{
				if (numbers[i] < result)
					result = numbers[i];
			}
			return result;
		}
		if(numbers[indexMid]>=numbers[index1])
		{
			index1 = indexMid;
		}
		else if(numbers[indexMid]<=numbers[index2])
		{
			index2 = indexMid;
		}

		return numbers[indexMid];
	}
}
int main(int argc, char* argv[])
{
	int arr[] = {1,0,1,1,1,1};
	cout << Min(arr, 6);
	system("pause");
}
