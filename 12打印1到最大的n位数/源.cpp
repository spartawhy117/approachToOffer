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
			//�����ȫ��0
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
	//��Ϊ�����index����Ҫ�ı�ģ�����ֻҪ�ж�index�ǲ������һλ+1
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
	//��Ҫע��n���ܳ���long long��λ��
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
