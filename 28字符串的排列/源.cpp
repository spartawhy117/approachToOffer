#include <iostream>
using namespace std;
void PermutationRecursion(char *pStr,char* pBegin)
{
	if(*pBegin=='\0')
	{
		cout << pStr << endl;
	}
	else
	{
		//当前第一位和剩下的每一位进行交换
		for(char* pCh=pBegin;*pCh!='\0';++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;


			//递归下一位
			PermutationRecursion(pStr, pBegin + 1);


			//控制顺序交换回来
			temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;

		}
	}


}

void Permutation(char* pStr)
{
	if(pStr==nullptr)
		return;

	PermutationRecursion(pStr, pStr);

}

int main(int argc, char* argv[])
{
	char str[] = {"abc"};
	Permutation(str);

	system("pause");
}
