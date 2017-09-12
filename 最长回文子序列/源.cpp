#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetLongPalindrome(const string &str)
{
	//求反序串 获得最大子序列
	string _reverseStr="";
	for(string::reverse_iterator rit=str.rbegin();rit!=str.rend();++rit)
	{
		_reverseStr += *rit;
	}

	int size = str.size();

	vector<vector<int> > _lcs(size+1,vector<int>(size+1));

	int i, j;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(str[i-1]==_reverseStr[j-1])
			{
				_lcs[i][j] = _lcs[i - 1][j - 1] + 1;
			}
			else
			{
				_lcs[i][j] = max(_lcs[i - 1][j], _lcs[i][j - 1]);
			}
		}
	}

	return size - _lcs[size][size];


}