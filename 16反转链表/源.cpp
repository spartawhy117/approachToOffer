#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int n) :m_nValue(n), m_pNext(nullptr) {}
	int m_nValue;
	ListNode* m_pNext;
};
ListNode* ReverseListNode(ListNode* pHead)
{
	//条件判断很重要
	if (pHead == nullptr)
		return nullptr;
	if(pHead->m_pNext==nullptr)
	{
		return pHead;
	}

	ListNode* pCurrent=pHead->m_pNext;
	ListNode* pPre=pHead;
	ListNode* pNext=pCurrent->m_pNext;
	pPre->m_pNext = nullptr;
	while (pNext!=nullptr)
	{
		pCurrent->m_pNext = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
		if (pNext->m_pNext != nullptr)
		{
			pNext = pNext->m_pNext;
		}
		else
			break;
		
	}
	pCurrent->m_pNext = pPre;

	return pCurrent;
	
}

int main(int argc, char* argv[])
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);

	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = node4;

	ListNode* root=ReverseListNode(node1);

	while (root!=nullptr)
	{
		cout << root->m_nValue << " ";
		root = root->m_pNext;
	}

	system("pause");
}
