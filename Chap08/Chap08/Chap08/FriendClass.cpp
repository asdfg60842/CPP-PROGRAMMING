// friend 클래스
// friend 로 선언한 클래스 통째로 접근 제어 지시자의 영향을 받지 않게 되므로 모든 메서드에 접근이 허용됨.
// 주로 자료와 구조를 구별해서 관리하기 위해 사용함. (ex. 연결 리스트)
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

private:
	CNode m_HeadNode;
};

int main()
{
	CMyList list;

	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}