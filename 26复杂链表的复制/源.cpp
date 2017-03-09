#include<iostream>
using namespace std;
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
	ComplexListNode(int v):m_nValue(v),m_pNext(nullptr),m_pSibling(nullptr)
	{

	}
};

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		ComplexListNode* pClone = new ComplexListNode(pNode->m_nValue);
	
		pClone->m_pNext = pNode->m_pNext;

		pNode->m_pNext = pClone;

		pNode = pClone->m_pNext;
	}

}

void ConnectSiblingNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if(pNode->m_pSibling!=nullptr)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = nullptr;
	ComplexListNode* pCloneNode = nullptr;


	if(pNode!=nullptr)
	{
		pClonedHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode!=nullptr)
	{
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

void Print(ComplexListNode* pNode)
{
	while (pNode!=nullptr)
	{
		cout << pNode->m_nValue<<" ";
		if(pNode->m_pSibling
			!=nullptr)
			cout << pNode->m_pSibling->m_nValue<<endl;
		pNode = pNode->m_pNext;
	}
}


int main(int argc, char* argv[])
{
	ComplexListNode* pNode = new ComplexListNode(1);
	ComplexListNode* pNode1 = new ComplexListNode(2);
	ComplexListNode* pNode2 = new ComplexListNode(3);
	ComplexListNode* pNode3 = new ComplexListNode(4);
	ComplexListNode* pNode4 = new ComplexListNode(5);

	pNode->m_pNext = pNode1;
	pNode1->m_pNext = pNode2;
	pNode2->m_pNext = pNode3;
	pNode3->m_pNext = pNode4;




	pNode->m_pSibling = pNode2;
	pNode2->m_pSibling = pNode4;
	pNode4->m_pSibling = pNode2;

	

	CloneNodes(pNode);
	ConnectSiblingNode(pNode);
	ComplexListNode* pClone = ReconnectNodes(pNode);

	Print(pClone);

	system("pause");
}
