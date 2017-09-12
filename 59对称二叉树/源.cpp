#include <iostream>
using namespace  std;
struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* m_m_pLeft;
	BinaryTreeNode* m_m_pRight;
};
bool IsSymmetrical(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	if (pRoot1->m_value != pRoot2->m_value)
		return false;

	return IsSymmetrical(pRoot1->m_m_pLeft, pRoot2->m_m_pRight)
	&& IsSymmetrical(pRoot1->m_m_pRight, pRoot2->m_m_pLeft);
}
bool IsSymmetrical(BinaryTreeNode* pRoot)
{
	return IsSymmetrical(pRoot, pRoot);
}