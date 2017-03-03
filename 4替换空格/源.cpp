#include <iostream>
using namespace std;
char* ReplaceBlank(char str[] ,int length)
{
	
	if(str==nullptr&&length<=0)
		return nullptr;

	int originalLength = 0;
	int blanksNum = 0;
	while(str[originalLength]!='\0')
	{
		++originalLength;
		if(str[originalLength]==' ')
		{
			++blanksNum;
		}
	}
	int newLength = length + 2 * blanksNum;
	
	char* newChar = new char[newLength];
	if(newLength<originalLength)
		return nullptr;


	int indexOfO=originalLength;
	int indexOfN = newLength-1;
	while (indexOfO>=0)
	{
		if (str[indexOfO] == ' ')
		{
			newChar[indexOfN--] = '0';
			newChar[indexOfN--] = '2';
			newChar[indexOfN--] = '%';

		}
		else
			newChar[indexOfN--] = str[indexOfO];

		--indexOfO;
	}

	return newChar;
}
int main()
{
	char str[14] = {"we are happy!"};//14

	//sizeof计算包括'\0'
	//strlen不包括'\0'
	size_t l = sizeof(str);
	char* newChar=ReplaceBlank(str, l);
	
	cout << newChar<<endl;
	delete newChar;
	system("pause");
}