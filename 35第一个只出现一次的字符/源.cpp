#include <iostream>
using namespace std;
char FirstNotRepeateChar(char* pStr)
{

	if(pStr==nullptr)
	{
		return '\0';
	}

	const int tableSize = 256;
	unsigned int hashTable[tableSize];

	for(unsigned int i=0;i<tableSize;i++)
		hashTable[i] = 0;

	char* pHashKey = pStr;
	while (*pHashKey!='\0')
	{
		hashTable[*(pHashKey++)]++;
	}

	pHashKey = pStr;
	while (*pHashKey!='\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
}


int main(int argc, char* argv[])
{
	char* str = "abaccdeff";
	char c = FirstNotRepeateChar(str);

	cout << c << endl;
	system("pause");
}


