#pragma once
#include <stack>
using namespace std;
template <typename T>
class MiniStack
{
	
public:
	void push(const T& value)
	{
		m_data.push(value);
		if (m_min.size() == 0 || value < m_min.top())
		{
			m_min.push(value);
		}
		else
			m_min.push(m_min.top());
	


	}
	void pop()
	{
		m_data.pop();
		m_min.pop();
	}

	const T& min()const
	{
		if(m_min.size()>0&&m_data.size()>0)
		{
			return  m_min.top();
		}
	}
	

private:
	stack<int> m_data;
	stack<int> m_min;
};