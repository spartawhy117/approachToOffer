#include <iostream>
using namespace std;
struct BinaryTreeNode
{
	BinaryTreeNode(int v) :m_nValue(v), m_pLeft(nullptr), m_pRight(nullptr)
	{
	}
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
BinaryTreeNode* ConstructBinaryTreeCore(int* s_preorder,int* e_preorder ,int* s_inorder,int* e_inorder)
{
	
	int rootValue = s_preorder[0];
	BinaryTreeNode *pRoot = new BinaryTreeNode(rootValue);

	//终止条件是关键
	if (s_preorder == e_preorder)
	{
		if(s_inorder==e_inorder&&s_preorder==s_inorder)
		{
			return pRoot;
		}
	}
	

	int leftLength = 0;
	int* rootInorder = s_inorder;
	//需要两个条件来判断，不能越界
	while (*rootInorder!=rootValue&&rootInorder<=e_inorder)
	{
		rootInorder++;
		
	}

	leftLength = rootInorder - s_inorder;
	
	if(leftLength>0)//这个判断控制也很重要
	{
		pRoot->m_pLeft = ConstructBinaryTreeCore(s_preorder + 1, s_preorder + leftLength, s_inorder, s_inorder + leftLength - 1);
	}
	if(leftLength<e_preorder-s_preorder)//如果根节点右侧全是左子树，那么没有右子树 很重要
	{
		pRoot->m_pRight = ConstructBinaryTreeCore(s_preorder + leftLength + 1, e_preorder, s_inorder + leftLength + 1, e_inorder);
	}
	
	

	return pRoot;
}


BinaryTreeNode* ConstructBinaryTree(int* preorder,int* inorder,int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	

	return ConstructBinaryTreeCore(preorder,preorder+length-1 ,inorder,inorder+length-1 );

}

void PrintTree(BinaryTreeNode* p)
{
	 if(p)
	 {
		 cout << p->m_nValue;
	 }
	 if(p->m_pLeft)
	 {
		 cout << "left is:";
		 PrintTree(p->m_pLeft);
	 }
	 
	 if(p->m_pRight)
	 {
		 cout << "right is:";
		 PrintTree(p->m_pRight);
	 }
	 if(p->m_pLeft==nullptr&&p->m_pRight==nullptr)
	 {
		 cout << " end node"<<endl;
		
	 }
	

	 return;
}
int main()
{
	int pre[] = {1,2,4,7,3,5,6,8};
	int in[] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode *p=ConstructBinaryTree(pre, in, 8);

	PrintTree(p);
	system("pause");
}