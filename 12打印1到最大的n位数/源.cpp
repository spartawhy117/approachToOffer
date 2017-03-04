#include <iostream>
using namespace std;

void Print(int *arr,int l)
{
	int index = 0;
	for(int i=0;i<l;i++)
	{
		if (arr[i] != 0)
		{
			index = i;
			break;
		}
		else
		{
			//不输出全是0
			if(i==l-1)
				return;
		}
		
	}
	
	for(int i=index;i<l;i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
void PrintCore(int *arr,int index,int length)
{
	//因为传入的index是需要改变的，所以只要判断index是不是最后一位+1
	if(index==length)
	{
		Print(arr,length);
		return;
	}
	

	for(int i=0;i<=9;i++)
	{
		arr[index] = i;
		PrintCore(arr, index+1, length);
	}

}

void PrintToMaxOfNDigtals(int n)
{
	//需要注意n可能超过long long的位数
	if(n<=0)
		return;
	int* arr = new int[n]{0};

	for(int i=0;i<=9;i++)
	{
		arr[0] = i;
		PrintCore(arr, 1, n);
	}

	delete[] arr;
}

int main(int argc, char* argv[])
{
	PrintToMaxOfNDigtals(2);
	system("pause");
}
