#include "stdafx.h"
#include "MyList.h"

CMyList::CMyList(void)
	: m_Head()
{

}

CMyList::~CMyList(void)
{

}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	if (FindNode(pszName) != NULL)
		return 0;

	//CUserData* pNewUser = new CUserData
}

void CMyList::PrintAll(void)
{

}

CUserData* CMyList::FindNode(const char* pszName)
{
	return 0;
}

int CMyList::RemoveNode(const char* pszNode)
{
	return 0;
}

void CMyList::ReleaseList(void)
{

}