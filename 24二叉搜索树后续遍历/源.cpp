#include <iostream>
using namespace std;
bool IsTraversalOrderofBST(int *seq,int length)
{

	//因为是搜索二叉树，所以其实有排序
	if (seq == nullptr || length < 0)
		return false;

	int root = seq[length - 1];

	//搜索小于根节点的节点
	int left = 0;
	for(; left<length-1; left++)
	{
		if(seq[left]>root)
			break;
	}

	//右侧如果有节点的话，必须都大于根节点 不然直接返回false
	int rigth = left;
	for(;rigth<length-1;rigth++)
	{
		if (seq[rigth] < root)
			return false;
	}

	//递归搜索左子树和右子树
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
