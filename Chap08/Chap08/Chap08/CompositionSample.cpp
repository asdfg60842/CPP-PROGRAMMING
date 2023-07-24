// Composition ����
// �ν��Ͻ��� �Ҹ��ϸ�, ������ҵ� �Բ� �Ҹ���.
// CMyUI Ŭ������ CMyList Ŭ������ �ν��Ͻ��� ��� �����ͷ� ������ �ִ�.
// ����, CMyUI Ŭ������ �ν��Ͻ��� �����Ǹ�, CMyList Ŭ������ �ν��Ͻ��� ���� �����ȴ�.
// �ݴ��, CMyUI Ŭ������ �ν��Ͻ��� �Ҹ�Ǹ�, CMyList Ŭ������ �ν��Ͻ��� ���� �Ҹ�ȴ�.
#include <iostream>
using namespace std;

class CNode
{
	// friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// ���� ���� ����Ʈ�� ������ ������
	// ������ ������ �������
	char m_szName[32];
	// ���� ��带 ������ �������
	CNode* pNext = nullptr;
};

class CMyList
{
public:
	CMyList()
		: m_HeadNode("Dummy Head")
	{

	}

	~CMyList()
	{
		// ����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);

		// ����Ʈ�� ���ο� ��带 �߰�
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// ����Ʈ�� ��� ��� ���� ���
	void Print()
	{
		CNode* pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

class CMyUI
{
public:
	// �޴� ��� �� ����� �Է� Ȯ��
	int PrintMenu()
	{
		system("cls");
		cout << "[1] Add\t" << "[2] Print\t" << "[0] Exit\n";
		cout.flush();

		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// ���������� �޴��� ����ϴ� ���� �̺�Ʈ �ݺ���
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1: // Add
				cout << "�̸� : ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;
			case 2: // Print
				m_list.Print();
				break;

			default:
				break;
			}
		}
	}

private:
	// UI Ŭ���� ���ο� �ڷᱸ���� ���Եȴ�.
	CMyList m_list;
};

int main()
{
	CMyUI ui;
	ui.Run();

	return 0;
}