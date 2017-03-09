#include <iostream>
#include <vector>
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

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//判断是不是叶节点，不是叶结点也继续向下，不进行剪枝
	bool isLeaf = pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr;
	if(currentSum==expectedSum&&isLeaf)
	{
		cout << "path has been found";
		vector<int>::iterator iter = path.begin();
		while ( iter != path.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;
	}

	if (pRoot->m_pLeft != nullptr)
		FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
	if (pRoot->m_pRight != nullptr)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);


	//因为是前序遍历，深度优先，所以只需要在到达叶结点后返回就行
	path.pop_back();

}
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;
	vector<int> path;
	int currentSum = 0;

	FindPath(pRoot, expectedSum, path, currentSum);

}

int main(int argc, char* argv[])
{
	BinaryTreeNode* node1 = new BinaryTreeNode(10);
	BinaryTreeNode* node2 = new BinaryTreeNode(5);
	BinaryTreeNode* node3 = new BinaryTreeNode(12);
	BinaryTreeNode* node4 = new BinaryTreeNode(4);
	BinaryTreeNode* node5 = new BinaryTreeNode(7);

	node1->m_pLeft = node2;
	node1->m_pRight = node3;
	node2->m_pLeft = node4;
	node2->m_pRight = node5;

	int sum = 22;

	FindPath(node1, sum);

	system("pause");

}
