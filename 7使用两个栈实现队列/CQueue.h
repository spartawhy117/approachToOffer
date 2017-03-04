#pragma once
#include <stack>
using namespace std;
template <typename T> class CQueue
{
public:
	CQueue(void)
	{
		
	};
	~CQueue(void)
	{
		
	};

	void appendTail(const T& node)
	{
		stack1.push(node);
	};
	T deleteHead()
	{
		if(stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}

		}
		
		//注意为空也很重要
		if(stack2.size()==0)
		{
			throw new exception("queue is empty");
		}

		T node = stack2.top();
		stack2.pop();
		return node;
	};
private:
	stack<T> stack1;
	stack<T> stack2;


};