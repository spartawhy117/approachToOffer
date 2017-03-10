#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;
//用最大堆来储存 nlogk
//STL中set是红黑树实现
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setInterator;
void GetLastNumbers(const vector<int>& data,intSet &leastNumber,int k)
{
	leastNumber.clear();

	if(k<1||data.size()<k)
	{
		return;
	}
	vector<int>::const_iterator iter = data.cbegin();
	for(;iter!=data.cend();++iter)
	{
		if(leastNumber.size()<k)
		{
			leastNumber.insert(*iter);
		}

		else
		{
			setInterator iterSet = leastNumber.cbegin();
			if(*iter<*(leastNumber.cbegin()))
			{
				leastNumber.erase(iterSet);
				leastNumber.insert(*iter);
			}
		}
	}

}


int main(int argc, char* argv[])
{
	int arr[] = {4,5,1,6,2,7,3,8};
	vector<int> data(arr,arr+8);

	intSet result;
	int k = 4;
	GetLastNumbers(data, result, k);

	for(setInterator it=result.begin();it!=result.end();++it)
	{
		cout << *it << " ";
	}

	system("pause");
	
}
