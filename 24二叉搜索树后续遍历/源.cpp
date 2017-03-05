#include <iostream>
using namespace std;
bool IsTraversalOrderofBST(int *seq,int length)
{

	//��Ϊ��������������������ʵ������
	if (seq == nullptr || length < 0)
		return false;

	int root = seq[length - 1];

	//����С�ڸ��ڵ�Ľڵ�
	int left = 0;
	for(; left<length-1; left++)
	{
		if(seq[left]>root)
			break;
	}

	//�Ҳ�����нڵ�Ļ������붼���ڸ��ڵ� ��Ȼֱ�ӷ���false
	int rigth = left;
	for(;rigth<length-1;rigth++)
	{
		if (seq[rigth] < root)
			return false;
	}

	//�ݹ�������������������
	bool left_b = true;
	if(left>0)
	{
		left_b = IsTraversalOrderofBST(seq, left);

	}
	bool right_b = true;
	if(left<length-1)
	{
		right_b = IsTraversalOrderofBST(seq + left, length - left - 1);
	}

	return left_b&&right_b;
}
bool Test(bool(*func)(int* ,int ),int*arr, int l)
{
	if (func(arr, l))
		return true;
	return false;
		
}

int main(int argc, char* argv[])
{
	int seq[] = { 5,7,6,9,11,10,8 };

	int seq2[] = { 7,4,6,5 };

	if (Test(IsTraversalOrderofBST, seq, 7))
		cout << "seq1 is" << endl;;

	if (Test(IsTraversalOrderofBST, seq2, 4))
		cout << "seq2 is";

	system("pause");
}
