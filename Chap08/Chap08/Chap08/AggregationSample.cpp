// Aggregation 관계
// 인스턴스가 소멸되어도 구성 요소들은 소멸되지 않음.
// CMyUI 클래스는 CMyList 클래스의 인스턴스가 참조로 전달되도록 함.
// 프로그램의 제어 시스템, 사용자 인터페이스, 원본 데이터는 '분리' 하는것이 원칙이다.
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
	// 참조 멤버는 반드시 초기화 목록을 이용해 초기화하여야 한다.
	CMyUI(CMyList& rList)
		: m_list(rList)
	{

	}

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
	CMyList &m_list;
};

int main()
{
	// 자료구조와 UI 객체를 별도로 선언하고 연결한다.
	CMyList list;
	CMyUI ui(list);
	ui.Run();

	return 0;
}