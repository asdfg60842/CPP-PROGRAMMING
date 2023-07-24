// Composition 관계
// 인스턴스가 소멸하면, 구성요소도 함께 소멸함.
// CMyUI 클래스는 CMyList 클래스의 인스턴스를 멤버 데이터로 가지고 있다.
// 따라서, CMyUI 클래스의 인스턴스가 생성되면, CMyList 클래스의 인스턴스도 같이 생성된다.
// 반대로, CMyUI 클래스의 인스턴스가 소멸되면, CMyList 클래스의 인스턴스도 같이 소멸된다.
#include <iostream>
using namespace std;

class CNode
{
	// friend 클래스 선언
	friend class CMyList;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// 단일 연결 리스트로 관리할 데이터
	// 저장할 데이터 멤버변수
	char m_szName[32];
	// 다음 노드를 저장할 멤버변수
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
		// 리스트에 담긴 데이터들을 모두 출력하고 삭제
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

		// 리스트에 새로운 노드를 추가
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// 리스트의 모든 노드 값을 출력
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
	// 메뉴 출력 및 사용자 입력 확인
	int PrintMenu()
	{
		system("cls");
		cout << "[1] Add\t" << "[2] Print\t" << "[0] Exit\n";
		cout.flush();

		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// 지속적으로 메뉴를 출력하는 메인 이벤트 반복문
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1: // Add
				cout << "이름 : ";
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
	// UI 클래스 내부에 자료구조가 포함된다.
	CMyList m_list;
};

int main()
{
	CMyUI ui;
	ui.Run();

	return 0;
}