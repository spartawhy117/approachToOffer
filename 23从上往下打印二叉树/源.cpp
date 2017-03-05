#include <iostream>
#include <deque>
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
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if(pRoot==nullptr)
		return;

	//只有存指针才能有向下的链接
	//使用队列更加方便
	deque<BinaryTreeNode*> printQueue;

	printQueue.push_back(pRoot);

	while(printQueue.size()>0)
	{
		BinaryTreeNode* pNode = printQueue.front();
		printQueue.pop_front();

		cout << pNode->m_nValue<<" ";

		if (pNode->m_pLeft != nullptr)
		{
			printQueue.push_back(pNode->m_pLeft);

		}
		if(pNode->m_pRight!=nullptr)
		{
			printQueue.push_back(pNode->m_pRight);
		}

	}
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

	PrintFromTopToBottom(node1);

	system("pause");
}

