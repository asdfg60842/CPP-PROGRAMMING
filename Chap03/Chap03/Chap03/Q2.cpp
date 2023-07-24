// Q2. 클래스 인스턴스가 생성될 때 자동으로 호출되는 함수는 무엇이며, 함수 원형의 가장 큰 외형상 특징은 무엇인지 답하세요.
// 객체가 생성될때, 생성자가 자동으로 호출되며, 함수 이름이 클래스 이름과 동일하다. 또한, 반환형식이 없다.
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "CTest::~CTest()" << endl;
	}
};

int main()
{
	cout << "Begin" << endl;
	CTest a;
	cout << "End" << endl;

	return 0;
}