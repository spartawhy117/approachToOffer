#include <iostream>
#include <stack>
using namespace std;
bool IsPopOrder(int *pPush,int* pPop,int length)
{
	bool bPossible = false;

	if(pPush!=nullptr&&pPop!=nullptr&&length>0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stackData;

		while (pNextPop-pPop<length)
		{

			//如果下一个弹出数字是栈顶数字，那么直接弹出
			//如果不是，我们把压入栈序列中没有压入的数字压入辅助栈
			//直到一个下一个需要弹出的数字压入栈顶而已
			//如果所有都压入栈了，仍然没有找到下一个弹出数字，则不可能
			while (stackData.empty()||stackData.top()!=*pNextPop)
			{
				if (pNextPush - pPush == length)
					break;

				stackData.push(*pNextPush);
				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == length)
			bPossible = true;
	}


	return bPossible;
	
}