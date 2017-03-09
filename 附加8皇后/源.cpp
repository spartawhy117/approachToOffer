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
			//�ж����� 
			//�еĲ�ľ���ֵ ���� ��Ӧ�����е�ֵ�Ĳ�ľ���ֵ
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

	//columnindex �������ǵڼ��У�����������ǵڼ��еĵĻʺ����ڵ���
	int ColumnIndex[8];
	for(int i=0;i<8;i++)
	{
		ColumnIndex[i] = i;
	}
	int count = 0;
	//��Ϊ��ʼ����ÿ�е����ݲ�ͬ
	//ȫ�����������������ж��Ƿ�Խ�����������
	Permutation(ColumnIndex, ColumnIndex, 8, count);

	cout << count<<endl;

}

int main(int argc, char* argv[])
{
	Queen();
	system("pause");
}
