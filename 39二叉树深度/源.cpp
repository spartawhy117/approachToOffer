#include <iostream>
#include <vector>
using namespace std;
struct BinaryTreeNode
{
	BinaryTreeNode(int v) :m_nValue(v), m_pLeft(nullptr), m_pRight(nullptr)
	{
	}
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
int TreeDepth(BinaryTreeNode* pRoot)
{

	//�ݹ��ѯ
	if (pRoot == nullptr)
		return 0;
	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	return (left > right) ? (left + 1) : (right + 1);

}

bool IsBalanced(BinaryTreeNode* pRoot,int *depth)
{
	if(pRoot==nullptr)
	{
		*depth = 0;
		return true;
	}
	int left, right;
	//�ص�����һ�߱���һ���ж��Ƿ�ƽ��
	if(IsBalanced(pRoot->m_pLeft,&left)&&IsBalanced(pRoot->m_pRight,&right))
	{
		int diff = left - right;
		if(diff<=1&&diff>=-1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}