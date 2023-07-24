// Q2. 소멸자를 반드시 가상화해야 하는 경우는 어떤 경우인지 답하세요.
// 추상 자료형을 사용하고, 객체를 동적 할당 및 해제를 하게된다면 소멸자 가상화가 필요하다.
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		m_pszData = new char[32];
	}

	// 소멸자를 가상 함수로 선언
	virtual ~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pszData;
	}

private:
	char* m_pszData;
};

class CMyDataEx
	: public CMyData
{
public:
	CMyDataEx()
	{
		m_pnData = new int;
	}

	// 기본 클래스에서 소멸자를 가상화 하였기 때문에, 파생 클래스의 소멸자까지 호출됨.
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
		delete m_pnData;
	}

private:
	int* m_pnData;
};

int main()
{
	CMyData* pData = new CMyDataEx;

	delete pData;
	
	return 0;
}