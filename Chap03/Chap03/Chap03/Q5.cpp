// Q5. 메서드 함수 내부에서 실제 클래스 인스턴스의 주소를 가리키는 포인터는 무엇인지 답하세요.
// this 포인터
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) 
		: m_nData(nParam)
	{

	}

	void PrintData()
	{
		// m_nData의 값을 출력한다.
		cout << m_nData << endl;
		
		// CMyData 클래스의 멤버인 m_nData의 값을 출력한다.
		cout << CMyData::m_nData << endl;

		// 메서드를 호출한 인스턴스의 m_nData의 값을 출력한다.
		cout << this->m_nData << endl;

		// 메서드를 호출한 인스턴스의 CMyData 클래스 멤버 m_nData를 출력한다.
		cout << this->CMyData::m_nData << endl;
	}

private:
	int m_nData;
};

int main()
{
	CMyData a(5), b(10);
	a.PrintData();
	b.PrintData();
}
