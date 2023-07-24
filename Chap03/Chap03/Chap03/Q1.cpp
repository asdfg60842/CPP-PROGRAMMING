// Q1. 클래스 접근 제어 지시자 중에서 private이 의미하는 것은 무엇인지 답하세요.
// 외부 접근 뿐만 아니라 파생 클래스로부터의 접근도 차단됨. 내부 멤버 이외의 접근이 차단됨.
#include <iostream>
using namespace std;

class CMyData
{
	// 기본 접근 제어 지시자는 'private' 이다.
	int m_nData;

public:
	int GetData(void)
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}
};

int main()
{
	CMyData data;

	data.SetData(10);
	cout << data.GetData() << endl;

	return 0;
}