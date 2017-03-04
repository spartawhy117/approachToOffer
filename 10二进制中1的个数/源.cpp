#include <iostream>
using namespace  std;
int NumbersOf1(int n)
{
	//直接右移操作数是无法处理负数的
	int count = 0;
	 while(n)
	 {
		 ++count;
		 n = n&(n - 1);//会吧把该操作数左右边的1变为0
	 }
	 return  count;
}

int main(int argc, char* argv[])
{
	cout<<NumbersOf1(-8);
	system("pause");
}
