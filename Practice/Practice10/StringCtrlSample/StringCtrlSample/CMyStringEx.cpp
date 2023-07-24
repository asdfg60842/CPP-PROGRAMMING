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
		// �����Ϳ� �����͸� ���� ������ �� �ּ� ���̿� ����� � �ִ����� ����ϴ� ��.
		return pszResult - GetString();

	return -1;
}				

int CMyStringEx::SetString(const char* pszParam)
{
	int nResult;

	if (strcmp(pszParam, "������") == 0)
		nResult = CMyString::SetString("���Ѹ�");
	else
		nResult = CMyString::SetString(pszParam);

	return nResult;
}