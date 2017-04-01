#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int v):value(v),pNext(nullptr)
	{
		
	}
	int value;
	ListNode* pNext;
};
ListNode* MeetingNode(ListNode* pHead)
{
	if(pHead==nullptr)
	{
		return nullptr;
	}

	ListNode* pSlow = pHead->pNext;
	if (pSlow == nullptr)
		return nullptr;

	ListNode* pFast = pSlow->pNext;
	while (pFast!=nullptr&&pSlow!=nullptr)
	{
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->pNext;

		pFast = pFast->pNext;
		if (pFast != nullptr)
			pFast = pFast->pNext;

	}
	return nullptr;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);

	if (meetingNode == nullptr)
		return nullptr;

	int nodesLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->pNext!=meetingNode)
	{
		pNode1 = pNode1->pNext;
		++nodesLoop;
	}

	pNode1 = pHead;
	for(int i=0;i<nodesLoop;++i)
	{
		pNode1 = pNode1->pNext;
	}

	ListNode* pNode2 = pHead;
	while (pNode1!=pNode2)
	{
		pNode1 = pNode1->pNext;
		pNode2 = pNode2->pNext;

	}

	return pNode1;
}
int main(int argc, char* argv[])
{
	ListNode p1(1);
	ListNode p2(2);
	ListNode p3(3);
	ListNode p4(4);
	ListNode p5(5);
	ListNode p6(6);
	p1.pNext = &p2;
	p2.pNext = &p3;
	p3.pNext = &p4;
	p4.pNext = &p5;
	p5.pNext = &p6;
	p6.pNext = &p3;

	ListNode* p = EntryNodeOfLoop(&p1);

	cout << p->value << endl;

	system("pause");
}
