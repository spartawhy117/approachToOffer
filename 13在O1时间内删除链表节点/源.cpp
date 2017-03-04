#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int n) :m_nValue(n), m_pNext(nullptr){}
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
	if(pListHead==nullptr||pToBeDeleted==nullptr)
		return;

	//不是最后的节点
	//把删除的下一个节点复制到当前节点的位置，删除下一个节点
	if(pToBeDeleted->m_pNext!=nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = nullptr;

	}

	else if (pToBeDeleted==*pListHead)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	else
	{
		ListNode* pNode = *pListHead;
		if(pNode->m_pNext!=pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;

	}
}

int main(int argc, char* argv[])
{
	ListNode* node1 = new ListNode(4);
	ListNode* node2 = new ListNode(5);
	ListNode* node3 = new ListNode(6);
	ListNode* node4 = new ListNode(7);

	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = node4;

	DeleteNode(&node1, node3);
	DeleteNode(&node1, node3);
	while (node1)
	{
		cout << node1->m_nValue << " ";
		node1 = node1->m_pNext;
	}
	cout << endl;

	system("pause");

}
