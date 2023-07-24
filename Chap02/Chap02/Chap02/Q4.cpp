// Q4. inline 함수와 매크로의 공통된 장점은 무엇인지 답하세요.
// 내부적으로 함수호출을 하지 않아 호출에 의한 오버헤드를 감소시킬수 있음.
#include <iostream>
#define Add(a, b) a + b
using namespace std;

__inline int add(int a, int b)
{
	return a + b;
}

int main()
{
	// 매크로 사용
	cout << Add(3, 4) << endl;
	
	// 인라인 함수 사용
	cout << add(3, 4) << endl;

	return 0;
}

