// 정적 바인딩(Static Binding) 또는 이른 바인딩(Early Binding)
// 바인딩이란 함수나 변수의 주소가 결정되는 것을 말하는데, 이 주소가 컴파일 타임에 결정되면 정적 바인딩 또는 이른 바인딩이라 한다.
#include <iostream>
using namespace std;

void TestFunc(int nParam)
{

}

int main()
{
	// 함수 이름인 'TestFunc' 는 상수이고, 함수 호출 연산자의 피연산자이다.
	// 따라서 호출할 함수가 달라질 가능성은 없다.
	// 정적 바인딩은 기계어로 번역했을때, 주소가 명백히 드러난다.
	// call 어셈블리 코드의 피연산자는 'TestFunc' 라는 상수이다.
	// 00411883  call        TestFunc (041136Bh)
	// 머신코드 수준에서 호출할 함수가 결정된 것.
	TestFunc(10);

	return 0;
}