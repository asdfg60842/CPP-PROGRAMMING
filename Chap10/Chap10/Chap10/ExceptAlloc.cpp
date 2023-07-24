// 메모리 예외 처리
// 예외 발생시 구조화된 예외처리로 해결이 가능해진다.
#include <new>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nSize)
	{
		// 메모리 할당에 실패하면 예외를 던진다.
		m_pszData = new char[nSize];
	}

	~CTest()
	{
		delete[] m_pszData;
		cout << "정상적으로 객체가 소멸함" << endl;
	}

private:
	char* m_pszData;
};

int main()
{
	try
	{
		int nSize;
		cout << "Input Size : ";

		// 사용자가 입력한 값을 검증 없이 그대로 사용해 객체를 생성
		cin >> nSize;
		CTest a(nSize);
	}

	// 메모리 생성에 실패할 경우 자연스럽게 catch 문 블록으로 코드의 흐름이 넘어옴
	catch (bad_alloc& exp)
	{
		// 시스템이 밝힌 원인을 출력한다.
		cout << exp.what() << endl;
		cout << "ERROR : CTest()" << endl;
	}

	return 0;
}