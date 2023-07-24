#include "stdafx.h"
#include "CMyString.h"

CMyString::CMyString()
	: m_pszData(nullptr), m_nLength(0)
{

}

CMyString::~CMyString()
{
	// ��ü�� �Ҹ��ϱ� ���� �޸𸮸� �����Ѵ�.
	Release();
}

int CMyString::SetString(const char* pszParam)
{
	// ���ο� ���ڿ� �Ҵ翡 �ռ� ���� ������ �����Ѵ�.
	Release();
	
	// Null�� �μ��� �Լ��� ȣ���ߴٴ� ���� �޸𸮸� �����ϰ�
	// Null�� �ʱ�ȭ �ϴ� ������ �� �� �ִ�.
	if (pszParam == nullptr)
		return 0;

	// ���̰� 0�� ���ڿ��� �ʱ�ȭ�� �ν��ϰ� ó���Ѵ�.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// ���ڿ��� ���� Null ���ڸ� ����� �޸𸮸� �Ҵ��Ѵ�.
	m_pszData = new char[nLength + 1];

	// ���� �Ҵ��� �޸𸮿� ���ڿ��� �����Ѵ�.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	// ���ڿ��� ���̸� ��ȯ�Ѵ�.
	return nLength;
}


const char* CMyString::GetString()
{
	return m_pszData;
}


void CMyString::Release()
{
	// �� �Լ��� ������ ȣ��� ��츦 ����� �ֿ� ����� �ʱ�ȭ �Ѵ�.
	if (m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}
