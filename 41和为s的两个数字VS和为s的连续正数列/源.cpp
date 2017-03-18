#include<iostream>
using namespace std;
//重点在于用两个指针
//一个指向较小的数，一个指向较大，根据区域内的和来判断
bool FindTwoWithSum(int data[], int length, int sum, int &n1, int& n2 )
{
	bool find = false;
	if (length < 1)
		return find;

	int head = 0;
	int behind = length - 1;
	while (head<behind)
	{
		int v = data[head] + data[behind];
		if(v==sum)
		{
			n1 = data[head];
			n2 = data[behind];
			find = true;
			break;
		}
		else if(v>sum)
		{
			behind--;
		}
		else
		{
			head++;
		}
	}
	return find;
}
void PrintContinuousSequence(int small, int big)
{
	for(int i=small;i<=big;++i)
	{
		cout << i << " ";
	}

	cout << endl;
}
void FindContinusSequnece(int sum)
{
	if(sum<3)
	{
		return;
	}
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small<middle)
	{
		if(curSum==sum)
		{
			PrintContinuousSequence(small, big);
		}
		while(curSum>sum&&small<middle)
		{
			curSum -= small;
			small++;
			 if(curSum==sum)
			 {
				 PrintContinuousSequence(small, big);
			 }
		}

		big++;
		curSum += big;
	}

}



int main(int argc, char* argv[])
{
	int data[] = {1,2,4,7,11,15};
	int n1, n2;
	if(FindTwoWithSum(data,6,15,n1,n2))
	{
		cout << n1 << " " << n2;
	}

	system("pause");
}
