#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int v):m_nKey(v),m_pNext(nullptr)
	{
		
	}
	int m_nKey;
	ListNode* m_pNext;
};


unsigned int GetListLength(ListNode* pHead)
{
	unsigned int n = 0;
	ListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		++n;
		pNode = pNode->m_pNext;
	}

	return n;
}
ListNode* FindFirstCommonNode(ListNode *pHead1,ListNode*pHead2)
{
	
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);

	int lengthDiff = length1 - length2;

	ListNode* pLongHead = pHead1;
	ListNode* pShortHead = pHead2;

	if(length2>length1)
	{
		pLongHead = pHead2;
		pShortHead = pHead1;

		lengthDiff = length2 - length1;
	}

	for(int i=0;i<lengthDiff;++i)
	{
		pLongHead = pLongHead->m_pNext;
	}

	while (pLongHead!=nullptr&&pShortHead!=nullptr&&pLongHead!=pShortHead)
	{
		pLongHead = pLongHead->m_pNext;
		pShortHead = pShortHead->m_pNext;
	}

	ListNode* pCommon = pLongHead;

	return pCommon;

}

int main(int argc, char* argv[])
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	ListNode node6(6);
	ListNode node7(7);


	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node4.m_pNext = &node5;
	node3.m_pNext = &node6;
	node5.m_pNext = &node6;

	node6.m_pNext = &node7;

	ListNode* p = FindFirstCommonNode(&node1, &node4);

	cout << p->m_nKey << endl;
	system("pause");

}
