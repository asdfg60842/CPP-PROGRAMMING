// Q3. 다음 코드에서 'm_nData(nParam)' 이 속한 부분을 무엇이라 부르는지 답하세요.
// CTest(int nParam)
//	 : m_nData(nParam)
// {
// 
// }
// 생성자의 초기화 목록으로 참조형 변수 선언 후 초기화 하거나, 변수 초기화 하는데 사용됨.
#include <iostream>
using namespace std;

class CRefTest
{
public:
	// 참조형 멤버는 반드시 생성자 초기화 목록을 이용해 초기화한다.
	CRefTest(int& rParam)
		: m_nData(rParam)
	{

	}

	int GetData(void)
	{
		return m_nData;
	}
private:
	// 참조형 멤버는 객체가 생성될 때 반드시 초기화해야 한다.
	int& m_nData;
};

int main()
{
	int a = 10;
	CRefTest t(a);

	cout << t.GetData() << endl;

	// 참조 원본인 a의 값이 수정됨.
	a = 20;
	cout << t.GetData() << endl;

	return 0;
}