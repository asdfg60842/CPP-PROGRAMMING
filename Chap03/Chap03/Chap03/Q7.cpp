// Q7. 정적 멤버에서는 '이것'을 사용할 수 없습니다. 이것은 무엇입니까?
// this 포인터 사용불가
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam)
		: m_nData(nParam)
	{
		m_nCount++;
	}
	
	int GetData()
	{
		return m_nData;
	}

	void ResetCount()
	{
		m_nCount = 0;
	}

	// 정적 메서드 선언 및 정의
	static int GetCount()
	{
		return m_nCount;
	};

private:
	int m_nData;
	
	// 정적 멤버 변수 선언(정적 멤버 변수는 선언과 정의를 분리해야함)
	static int m_nCount;
};

// 정적 멤버 변수 정의(정적 멤버 변수는 선언과 정의를 분리해야함)
int CTest::m_nCount = 0;

int main()
{
	CTest a(5), b(10);
	
	// 정적 멤버에 접근
	cout << a.GetCount() << endl;
	b.ResetCount();

	// 정적 멤버에 접근. 인스턴스 없이 접근 가능
	cout << CTest::GetCount() << endl;

	return 0;
}