// Q5. 네임스페이스를 매번 작성하기 싫다면 미리 Using 선언을 하는것이 좋음.
// 네임스페이스의 중첩, 다중정의로 '모호성'이 발생할 수 있기 때문에, 상황에 따라 정확히 네임스페이스를 명시하는것이 중요.
#include <iostream>
using namespace std;

// 함수 다중정의
// 전역(개념상 무소속) TestFunc 함수
void TestFunc(void)
{
	cout << "::TestFunc()" << endl;
}

// 네임스페이스의 중첩
namespace TEST
{
	int g_nData = 100;

	// TEST 네임스페이스 소속 TestFunc 함수
	void TestFunc(void)
	{
		cout << "TEST::TestFunc()" << endl;
	}

	namespace DEV
	{
		int g_nData = 200;
		namespace WIN
		{
			int g_nData = 300;
		}
	}
}

int main()
{
	// 네임스페이스의 중첩
	cout << TEST::g_nData << endl;
	cout << TEST::DEV::g_nData << endl;
	cout << TEST::DEV::WIN::g_nData << endl;

	// 네임스페이스와 함수 다중정의
	::TestFunc();
	TEST::TestFunc();

	return 0;
}