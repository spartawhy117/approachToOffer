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
		//��ǰ��һλ��ʣ�µ�ÿһλ���н���
		for(char* pCh=pBegin;*pCh!='\0';++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;


			//�ݹ���һλ
			PermutationRecursion(pStr, pBegin + 1);


			//����˳�򽻻�����
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
