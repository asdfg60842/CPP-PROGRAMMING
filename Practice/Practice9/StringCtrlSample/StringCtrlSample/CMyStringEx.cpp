#include "stdafx.h"
#include "CMyStringEx.h"

CMyStringEx::CMyStringEx()
{

}

CMyStringEx::~CMyStringEx()
{

}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == nullptr || GetString() == nullptr )
		return -1;

	const char* pszResult = strstr(GetString(), pszParam);

	if (pszResult != nullptr)
		// 포인터와 포인터를 빼는 행위는 두 주소 사이에 대상이 몇개 있는지를 계산하는 것.
		return pszResult - GetString();

	return -1;
}				