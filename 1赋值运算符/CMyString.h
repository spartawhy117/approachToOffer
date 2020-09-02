#pragma once
class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str)
	{
		
	}
	CMyString& CMyString::operator=(const CMyString& str)
	{
		if (this == &str)
			return *this;

		CMyString tmp(str);
		char *value = tmp.m_pData;
		//可以析构原有的资源
		tmp.m_pData = this->m_pData;

		this->m_pData = value;

		return  *this;
	}
private:
	char* m_pData;
};