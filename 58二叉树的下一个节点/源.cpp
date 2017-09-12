#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* m_m_pParent;
	BinaryTreeNode* m_m_pLeft;
	BinaryTreeNode* m_m_pRight;
	
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if(pNode->m_m_pRight!=nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_m_pRight;
		while (pRight->m_m_pLeft!=nullptr)
		{
			pRight = pRight->m_m_pLeft;

		}

		pNext = pRight;
	}
	else if(pNode->m_m_pParent!=nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_m_pParent;
		//��һ���ж����������� һ���ǵ�ǰ�ڵ��Ǹ��ڵ�������� һ���ǲ��ǣ�ֱ�ӷ��ظ��ڵ�
		while (pParent!=nullptr&&pCurrent==pParent->m_m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_m_pParent;
		}
		pNext = pParent;
	}

	return pNext;
}