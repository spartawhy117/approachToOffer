#include <iostream>
using namespace  std;
int NumbersOf1(int n)
{
	//ֱ�����Ʋ��������޷���������
	int count = 0;
	 while(n)
	 {
		 ++count;
		 n = n&(n - 1);//��ɰѸò��������ұߵ�1��Ϊ0
	 }
	 return  count;
}

int main(int argc, char* argv[])
{
	cout<<NumbersOf1(-8);
	system("pause");
}
