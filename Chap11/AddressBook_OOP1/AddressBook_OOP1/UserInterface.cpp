#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"

CUserInterface::CUserInterface(CMyList& rList)
	: m_List(rList)
{

}

CUserInterface::~CUserInterface(void)
{

}

void CUserInterface::Add(void)
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	cout << "Input name : ";
	cin >> szName;
	cout << endl;

	cout << "Input phone number : ";
	cin >> szPhone;
	cout << endl;

	m_List.AddNewNode(szName, szPhone);
}

int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n";
	cin >> nInput;

	return nInput;
}

void CUserInterface::Search(void)
{
	char szName[32] = { 0 };
	CUserData* pNode = NULL;

	cout << "Input name : ";
	cin >> szName;

	pNode = m_List.FindNode(szName);

	if (pNode != NULL)
		cout << "[" << pNode << "] " << pNode->GetName() << "\t" << pNode->GetPhone() << " [" << pNode->GetNext() << "]\n";
	else
		cout << "ERROR : 데이터를 찾을 수 없습니다." << endl;
}

void CUserInterface::Remove(void)
{
	char szName[32] = { 0 };
	
	cout << "Input name : ";
	cin >> szName;

	m_List.RemoveNode(szName);
}

int CUserInterface::Run(void)
{
	int nMenu = 0;

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:  // Add
			Add();
			break;
		case 2:  // Search
			Search();
			break;
		case 3:  // Print all
			//PrintAll();
			break;
		case 4:  // Remove
			Remove();
			break;
		}
	}

	return nMenu;
}