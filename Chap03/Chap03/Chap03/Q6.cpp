// Q6. 상수형 메서드에서 할수 없는 일은 무엇인지 답하세요.
// 멤버 변수에 읽기 접근은 가능하지만, 쓰기는 허용되지 않음.
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam)
		: m_nData(nParam)
	{
	
	}
	
	~CTest()
	{

	}

	int GetData() const
	{
		// 멤버 변수의 값을 읽을 수는 있지만, 쓸 수는 없다.
		// m_nData = 10; 불가

		// 상수화된 메서드가 아니라면 호출 불가
		// SetData(10); 불가
		return m_nData;
	}

	int SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}