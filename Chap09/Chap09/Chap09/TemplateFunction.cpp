// 함수 템플릿 특수화
// char* 와 같은 특별한 형식이 있을 경우 나머지 다른 형식과 전혀 다른 코드를 적용해야할 때가 있다.
// 이를 분리해서 처리하는 것이 특수화 이다.
#include <memory>
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 두 개의 변수가 모두 char* 형식이면 이 함수로 대체된다.
template< >
char* Add(char* pszLeft, char* pszRight)
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	// 새로 할당한 메모리에 문자열을 복사한다.
	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}

int main()
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	char* pszResult = Add<char*>(const_cast<char *>("Hello"), const_cast<char *>("World"));
	cout << pszResult << endl;
	delete[] pszResult;

	return 0;
}