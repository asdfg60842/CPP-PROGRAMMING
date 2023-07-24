// Q3. 함수를 다중 정의하는 것보다는 함수 템플릿이 더 좋은 코드가 될 가능성이 높습니다. 이유를 답하세요.
// 함수의 다중정의의 경우 자료형이 무엇인가에 따라 동일한 일을 하는 함수가 여러개 생길수 있음.
// 템플릿의 경우 자료형을 직접 지정하지 않아도 쉽게 코드를 확장할수 있음.
#include <iostream>
using namespace std;

// 함수의 다중정의 (Overloading)
// 자료형에 따라 동일한 일을 하는 함수가 2개 생김
int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

// 템플릿 (Template)
// 자료형을 직접 지정하지 않아도 쉽게 확장 가능
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// 함수의 다중정의 (Overloading)
	cout << Add(3, 4) << endl;
	cout << Add(3.3, 4.4) << endl;

	// 템플릿 (Template)
	cout << Add<int>(3, 4) << endl;
	cout << Add<double>(3.3, 4.4) << endl;

	return 0;
}