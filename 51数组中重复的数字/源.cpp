#include  <iostream>
using namespace std;
bool Duplicate(int numbers[],int length,int* duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;

	}
	for(int  i=0;i<length;++i)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	for(int i=0;i<length;++i)
	{
		while (numbers[i]!=i)
		{
			if(numbers[i]==numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			//exchange
			swap(numbers[i], numbers[numbers[i]]);

		}
	}
}
int main(int argc, char* argv[])
{
	int data[] = {2,3,1,0,2,5,3};

}
