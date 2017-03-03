#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	ListNode(int v):m_nKey(v),m_pNext(nullptr)
	{};
	int m_nKey;
	ListNode* m_pNext;
};

void PrintReverseList(ListNode* pHead)
{
	stack<int> values;
	if (pHead == nullptr)

		return;
	while(pHead)
	{
		values.push(pHead->m_nKey);
		pHead = pHead->m_pNext;
	}

	while (!values.empty())
	{
		int val = values.top();
		cout << val << " ";
		values.pop();
	}
}

int main()
{
	ListNode *p1=new ListNode(5);
	ListNode *p2= new ListNode(6);
	ListNode *p3= new ListNode(3);
	p1->m_pNext = p2;
	p2->m_pNext = p3;

	PrintReverseList(p1);
	system("pause");

}