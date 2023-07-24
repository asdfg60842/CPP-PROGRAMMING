// Q1. 가상 함수를 사용하는 가장 큰 이유는 무엇인지 답하세요.
// 파생 클래스에서 재정의할 것으로 기대하는 멤버 함수이다. 파생 클래스에서 재정의 하면 과거의 정의가 완전히 무시된다.
// 가상함수는 자신을 호출하는 객체의 동적 타입에 따라 실제 호출할 함수가 결정된다.
#include <iostream>
using namespace std;

class CMyData
{
public:
	// 가상 함수로 선언 및 정의했다.
	virtual void PrintData()
	{
		cout << "CMyData : " << m_nData << endl;
	}

	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;

		// 실 형식의 함수가 호출된다.
		// 파생 형식에서 PrintData() 함수를 재정의 한다면, 아래 코드로 '미래'의 함수를 호출하는 것이다.
		PrintData();
		cout << "****************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx
	: public CMyData
{
public:
	// 기본 클래스의 가상 함수 멤버를 재정의 함.
	// 기존 정의는 무시됨
	virtual void PrintData()
	{
		cout << "CMyDataEx : " << m_nData * 2 << endl;
	}
};

int main()
{
	CMyDataEx a;
	a.PrintData();

	CMyData &b = a;

	// 참조 형식에 상관없이 실 형식의 함수가 호출됨.
	b.PrintData();

	a.TestFunc();

	return 0;
}