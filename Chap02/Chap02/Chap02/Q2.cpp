// Q2. 다음 두 함수는 문법적으로 문제가 없습니다. 하지만 호출하는 코드에서 문제가 발생할 수 있습니다. 어떤 문제인지 답하세요.
#include <iostream>
using namespace std;

void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int a, int b = 10)
{
	cout << "TestFunc(int, int)" << endl;
}

int main()
{
	// 아래와 같이 함수 호출시 '모호성' 발생
	TestFunc(5);

	return 0;
}