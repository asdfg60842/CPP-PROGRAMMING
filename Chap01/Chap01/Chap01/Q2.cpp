// Q2. C++11 에서 auto 예약어는 어떤 의미인지 쓰고 코드로 예를 보이세요.
// auto 예약어란 컴파일러가 자동으로 변수의 자료형을 결정해주는 자료형
#include <iostream>
using namespace std;

int main() 
{
	int a(10);
	int b(5);
	auto c(b); // 초깃값 형식에 맞춰 인스턴스의 형식이 자동으로 결정됨.

	cout << a + b + c << endl;

	return 0;
}