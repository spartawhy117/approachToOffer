#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int v) :value(v), pNext(nullptr)
	{

	}
	int value;
	ListNode* pNext;
};
void DeleteDuplicate(ListNode** pHead)
{
	if(pHead==nullptr||*pHead==nullptr)
		return;
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode!=nullptr)
	{
		ListNode* pNext = pNode->pNext;
		bool needDelete = false;
		if (pNext != nullptr&&pNext->value == pNode->value)
			needDelete = true;
		if(!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->pNext;
		}
		else
		{
			int value = pNode->value;
			ListNode* pToBeDelete = pNode;
			while (pToBeDelete!=nullptr&&pToBeDelete->value==value)
			{
				pNext = pToBeDelete->pNext;
				delete pToBeDelete;
				pToBeDelete = nullptr;

				pToBeDelete = pNext;
			}

			if (pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->pNext = pNext;

			pNode = pNext;
		}
	}
}

