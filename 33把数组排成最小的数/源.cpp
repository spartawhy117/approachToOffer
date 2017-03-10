#include <iostream>
using namespace std;
const int g_MaxLength = 10;
char* g_strCombine1 = new char[2 * g_MaxLength + 1];
char* g_strCombine2 = new char[2 * g_MaxLength + 1];

int Compare(const void* str1,const void* str2)
{
	strcpy_s(g_strCombine1, 2 * g_MaxLength + 1, static_cast<const char*>(str1));
	strcat_s(g_strCombine1, 2 * g_MaxLength + 1, static_cast<const char*>(str2));

	strcpy_s(g_strCombine2, 2 * g_MaxLength + 1, static_cast<const char*>(str2));
	strcat_s(g_strCombine2, 2 * g_MaxLength + 1, static_cast<const char*>(str1));


	return strcmp(g_strCombine1, g_strCombine2);

}

void PrintMinNumber(int* numbers,int length)
{
	if(numbers==nullptr||length<=0)
		return;

	char** strNumbers = new char*[length];
	for(int i=0;i<length;++i)
	{
		strNumbers[i] = new char[g_MaxLength + 1];
		sprintf_s(strNumbers[i], g_MaxLength + 1,"%d", numbers[i]);

	}

	//按照自定义的函数进行字典排序
	qsort(strNumbers, length, sizeof(char*), Compare);


	for(int i=0;i<length;++i)
	{
		cout << strNumbers[i];
	}
	cout << endl;

	for (int i = 0; i < length; ++i)
		delete[] strNumbers[i];
	delete[] strNumbers;

}

int main(int argc, char* argv[])
{
	int arr[] = { 3,32,321 };
	PrintMinNumber(arr, 3);

	system("pause");
}
