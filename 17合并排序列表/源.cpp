#include <iostream>
using namespace std;
struct ListNode
{
	ListNode(int n) :m_nValue(n), m_pNext(nullptr) {}
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* MergeList(ListNode* p1,ListNode* p2)
{
	if(p1==nullptr&&p2==nullptr)
	{
		return nullptr;
	}
	else if(p2==nullptr)
	{
		return p1;
	}
	else if(p1==nullptr)
	{
		return  p2;
	}
	else
	{
		ListNode* mergeLits = nullptr;
		if(p1->m_nValue<=p2->m_nValue)
		{
			mergeLits = p1;
			mergeLits->m_pNext = MergeList(p1->m_pNext, p2);
		}
		else
		{
			mergeLits = p2;
			mergeLits->m_pNext = MergeList(p1, p2->m_pNext);
		}

		return mergeLits;
	}
	

}

int main(int argc, char* argv[])
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(5);
	ListNode* node4 = new ListNode(7);

	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = node4;

	ListNode* node5 = new ListNode(2);
	ListNode* node6 = new ListNode(3);
	ListNode* node7 = new ListNode(4);
	ListNode* node8 = new ListNode(5);

	node5->m_pNext = node6;
	node6->m_pNext = node7;
	node7->m_pNext = node8;


	ListNode* root = MergeList(node1, node5);

	while (root)
	{
		cout << root->m_nValue << " ";
		root = root->m_pNext;
	}

	system("pause");
}
