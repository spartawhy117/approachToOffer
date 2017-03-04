#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int n) :m_nValue(n), m_pNext(nullptr) {}
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* FindBackwardKth(ListNode *pHead,unsigned int k)
{

	if(pHead==nullptr||k==0)
		return nullptr;

	ListNode* pFast = pHead;
	ListNode* pSlow = nullptr;
	int count = 0;
	while (pFast->m_pNext!=nullptr)
	{
		pFast = pFast->m_pNext;
		count++;

		if (count == k - 1)
			break;
	}
	

	//k的长度大于链表长度
	if (count!=k-1)
	{
		return nullptr;
	}
	else
	{
		pSlow = pHead;
		while (pFast->m_pNext!= nullptr)
		{
			pFast = pFast->m_pNext;
			pSlow = pSlow->m_pNext;
		}

		return pSlow;
	}
		
	
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

	ListNode* noder1 = FindBackwardKth(node1,1);
	ListNode* noder2 = FindBackwardKth(node1,4);
	ListNode* noder3 = FindBackwardKth(node1,2);

	cout << noder2->m_nValue;


	system("pause");

}
