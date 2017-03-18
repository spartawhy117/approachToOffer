#include <iostream>
using namespace std;

//从头到尾翻转
void Reverse(char* pBegin,char* pEnd)
{
	if(pBegin==nullptr||pEnd==nullptr)
		return;

	while (pBegin<pEnd)
	{
		auto temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++; pEnd--;
	}
}
//翻转空格间的每一个单词
char* ReverseSentence(char* pData)
{
	if (pData == nullptr)
		return nullptr;

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd!='\0')
	{
		pEnd++;
	}
	pEnd--;

	Reverse(pBegin, pEnd);

	pBegin = pEnd = pData;

	while (*pBegin!='\0')
	{
		if(*pBegin==' ')
		{
			pBegin++; pEnd++;
		}

		else if(*pEnd==' '||*pEnd=='\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}

//先翻转每个部分的内的字符，再翻转整个字符
char* LeftRotateString(char* pStr,int n)
{
	if(pStr!=nullptr)
	{
		int nlength = static_cast<int>(strlen(pStr));
		if(nlength>0&&n>0&&n<nlength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondFirst = pStr + n;
			char* pSecondEnd = pStr + nlength - 1;

			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondFirst, pSecondEnd);
			Reverse(pFirstStart, pSecondEnd);
		}

	}

	return pStr;
}


int main(int argc, char* argv[])
{
	char data[] = { "I am a student" };
	char* c = ReverseSentence(data);
	cout << c << endl;
	c = LeftRotateString(data, 4);
	cout << c << endl;

	system("pause");

}
