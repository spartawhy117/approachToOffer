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

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastInList)
{
	

	//中序遍历才能保持二叉树的排序
	if(pNode==nullptr)
		return;

	BinaryTreeNode* pCurrent = pNode;
	if (pCurrent->m_pLeft != nullptr)
		ConvertNode(pCurrent->m_pLeft, pLastInList);

	pCurrent->m_pLeft = *pLastInList;

	if (*pLastInList != nullptr)
		(*pLastInList)->m_pRight = pCurrent;

	*pLastInList = pCurrent;

	if (pCurrent->m_pRight != nullptr)
		ConvertNode(pNode->m_pRight, pLastInList);
}

BinaryTreeNode* ConverTree(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pLastInList = nullptr;
	ConvertNode(pRoot, &pLastInList);
	while (pLastInList->m_pLeft != nullptr)
	{
		pLastInList = pLastInList->m_pLeft;

	}

	return pLastInList;
}

void Print(BinaryTreeNode* pHead)
{
	while (pHead!=nullptr)
	{
		cout << pHead->m_nValue << " ";
		pHead = pHead->m_pRight;
	}
}

int main(int argc, char* argv[])
{
	BinaryTreeNode* node1 = new BinaryTreeNode(10);
	BinaryTreeNode* node2 = new BinaryTreeNode(6);
	BinaryTreeNode* node3 = new BinaryTreeNode(14);
	BinaryTreeNode* node4 = new BinaryTreeNode(4);
	BinaryTreeNode* node5 = new BinaryTreeNode(8);


	node1->m_pLeft = node2;
	node1->m_pRight = node3;
	node2->m_pLeft = node4;
	node2->m_pRight = node5;

	BinaryTreeNode* pListHead = ConverTree(node1);
	Print(pListHead);

	system("pause");
}
