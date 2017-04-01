#include <iostream>
using namespace std;
bool MatchCore(char* str,char* pattern)
{
	if(*str=='\0'&&*pattern=='\0')
	{
		return true;
	}
	if (*str != '\0'&&*pattern == '\0')
		return false;

	if(*(pattern+1)=='*')
	{
		if(*pattern==*str||(*pattern=='.'&&*str!='\0'))
		{
			//���� ������һ���׶�
			return MatchCore(str + 1, pattern + 2)
				//����Ŀǰ���״̬
				|| MatchCore(str + 1, pattern)
				//���� *
				|| MatchCore(str, pattern + 2);
		}
		else
		{// ���� *
			return MatchCore(str, pattern + 2);
		}
	}
	if (*str==*pattern||(*pattern=='.'&&*str!='\0'))
	{
		return MatchCore(str + 1, pattern + 1);
	}

	return false;
}
bool Match(char* str,char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	return MatchCore(str, pattern);
}


int main(int argc, char* argv[])
{
	char* str = "aaa";
	char* pattern = "ab*ac*a";

	if (Match(str, pattern))
	{
		cout << "true";
	}
	else
		cout << "false";

	system("pause");
}
