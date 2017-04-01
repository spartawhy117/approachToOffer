#include <iostream>
#include <vector>
using namespace std;
void Mutiply(const vector<int>& array1,vector<int>& array2)
{
	int length1 = array1.size();
	int length2 = array2.size();


	if(length1==length2&&length2>1)
	{
		array2[0]=1;
		for(int i=1;i<length1;++i)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		int temp = 1;
		for(int i=length1-2;i>=0;--i)
		{
			temp *= array1[i + 1];
			array2[i] *= temp;
		}
	}

}


int main(int argc, char* argv[])
{
	vector<int> A = {1,2,3,4,5,6,7};
	vector<int> B(7,0);

	int size = A.size();
	Mutiply(A, B);
	for(int i=0;i<7;++i)
	{
		cout << B[i]<<" ";
	}
	cout << endl;
	system("pause");
}
