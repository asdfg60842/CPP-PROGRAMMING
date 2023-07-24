// 동적 바인딩(Dynamic Binding) 또는 늦은 바인딩(Late Binding)
// 빌드한 프로그램이 실행되는 도중에(런타임 - Runtime) 주소가 결정되는 것을 동적 바인딩이라 한다.
#include <iostream>
using namespace std;

void TestFunc1(int nParam)
{

}

void TestFunc2(int nParam)
{

}

int main()
{
	int nInput = 0;
	cin >> nInput;
	void(*pfTest)(int) = NULL;

	if (nInput > 10)
		pfTest = TestFunc1;
	else
		pfTest = TestFunc2;

	// pfTest는 함수 포인터 변수이다. 
	// 이 변수의 값은 프로그램을 빌드 후 실행해서 사용자가 정수를 입력하기 전에는 어떤 함수가 호출될 것인지 확정할수 없음.
	// 어셈블리 코드를 살펴보면 다음과 같이 값이 확정되어 있지 않다.
	// 00411930  call        dword ptr[pfTest]
	// call 어셈블리 코드의 피연산자가 상수가 아니라 포인터 변수이므로 변수에 저장된 주소의 함수가 호출될 것이다.
	pfTest(10);

	return 0;
}