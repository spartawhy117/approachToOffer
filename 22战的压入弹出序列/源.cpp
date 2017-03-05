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

			//�����һ������������ջ�����֣���ôֱ�ӵ���
			//������ǣ����ǰ�ѹ��ջ������û��ѹ�������ѹ�븨��ջ
			//ֱ��һ����һ����Ҫ����������ѹ��ջ������
			//������ж�ѹ��ջ�ˣ���Ȼû���ҵ���һ���������֣��򲻿���
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