// 다음 코드의 실행 결과를 작성하세요.
// 식별자 검색순서에 따라 호출하는 함수가 TEST 네임스페이스에 있는 함수이므로 해당 함수 상위 블록에 nData 변수가 있으므로
// 100 이다.
#include <iostream>
using namespace std;

int nData = 200;

namespace TEST
{
	int nData = 100;
	void TestFunc(void)
	{
		cout << nData << endl;
	}
}

int main()
{
	TEST::TestFunc();

	return 0;
}