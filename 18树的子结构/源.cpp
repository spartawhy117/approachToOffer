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

bool CompareTree(BinaryTreeNode* p1,BinaryTreeNode* p2)
{
	bool result = false;

	if (p1->m_nValue == p2->m_nValue)
	{
		if (p2->m_pLeft == nullptr&&p2->m_pRight==nullptr)
			return true;

		if (p2->m_pLeft != nullptr)
		{
			result = CompareTree(p1->m_pLeft, p2->m_pLeft);
		}

		if(result)
		{
			if (p2->m_pRight != nullptr)
			{
				result = CompareTree(p1->m_pRight, p2->m_pRight);
			}
		}

		return result;
	}
	else
		return false;
	
}

bool HasSubTree(BinaryTreeNode* p1,BinaryTreeNode* p2)
{
	bool result = false;
	if (p1 == nullptr || p2 == nullptr)
		return result;
	if(p1->m_nValue== p2->m_nValue)
	{
		result = CompareTree(p1, p2);	
	}
	if(!result)
	{
		//当前根节点相同，但是子树不同的时候，仍然需要尝试左边大树的每一个节点
		if (p1->m_pLeft != nullptr)
		{
			result = HasSubTree(p1->m_pLeft, p2);
		}
		if (!result&&p1->m_pRight != nullptr)
		{
			result = HasSubTree(p1->m_pRight, p2);
		}
	}
		return result;
	
	
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


	BinaryTreeNode* node11 = new BinaryTreeNode(8);
	BinaryTreeNode* node12 = new BinaryTreeNode(9);
	BinaryTreeNode* node13 = new BinaryTreeNode(2);
	node11->m_pLeft = node12;
	node11->m_pRight = node13;

	if(HasSubTree(node1, node11))
	{
		cout << "has subtree";
	}


	system("pause");
}
