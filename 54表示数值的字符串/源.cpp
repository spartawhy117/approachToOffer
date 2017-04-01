#include <iostream>
using namespace std;

void ScanDigts(char** string)
{
	while (**string!='\0'&&**string>='0'&&**string<='9')
	{
		++(*string);
	}
}
bool IsExponential(char** string)
{
	if (**string != 'e'&&**string != 'E')
		return false;

	++(*string);
	if (**string == '+' || **string == '-')
		++(*string);
	if (**string == '\0')
		return false;

	ScanDigts(string);
	return (**string == '\0') ? true : false;

}
bool IsNumeric(char* string)
{
	if (string == nullptr)
		return false;
	if (*string == '+' || *string == '-')
		++string;
	if (*string == '\0')
		return false;
	bool numeric = true;
	ScanDigts(&string);

	if(*string!='\0')
	{
		if (*string == '.')
		{
			++string;
			ScanDigts(&string);
			if (*string == 'e' || *string == 'E')
				numeric = IsExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
			numeric = IsExponential(&string);
		else
			numeric = false;
	}
	return numeric&&*string == '\0';

}
int main(int argc, char* argv[])
{
	char* str = "-1E-16";
	if (IsNumeric(str))
		cout << "true";
	else
		cout << "false";

	system("pause");
}
