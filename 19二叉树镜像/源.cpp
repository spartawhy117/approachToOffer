#include <iostream>
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
void MirrorRecursively(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	else if (pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr)
		return ;

	BinaryTreeNode* pTemp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTemp;

	if(pRoot->m_pLeft!=nullptr)
	{
		MirrorRecursively(pRoot->m_pLeft);
	}
	if(pRoot->m_pRight!=nullptr)
	{
		MirrorRecursively(pRoot->m_pRight);
	}
}

void PrintTree(BinaryTreeNode* p)
{
	if (p)
	{
		cout << p->m_nValue<<" ";
	}
	if (p->m_pLeft)
	{
		cout << "left is:";
		PrintTree(p->m_pLeft);
	}

	if (p->m_pRight)
	{
		cout << "right is:";
		PrintTree(p->m_pRight);
	}
	if (p->m_pLeft == nullptr&&p->m_pRight == nullptr)
	{
		cout << " end node" << endl;

	}


	return;
}

int main(int argc, char* argv[])
{
	BinaryTreeNode* node1 = new BinaryTreeNode(8);
	BinaryTreeNode* node2 = new BinaryTreeNode(8);
	BinaryTreeNode* node3 = new BinaryTreeNode(7);
	BinaryTreeNode* node4 = new BinaryTreeNode(9);
	BinaryTreeNode* node5 = new BinaryTreeNode(2);
	BinaryTreeNode* node6 = new BinaryTreeNode(4);
	BinaryTreeNode* node7 = new BinaryTreeNode(7);


	node1->m_pLeft = node2;
	node1->m_pRight = node3;
	node2->m_pLeft = node4;
	node2->m_pRight = node5;
	node5->m_pLeft = node6;
	node5->m_pRight = node7;

	MirrorRecursively(node1);

	PrintTree(node1);

	system("pause");
}
