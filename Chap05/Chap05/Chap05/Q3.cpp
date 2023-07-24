// Q3. 후위식 단항 증가 연산자를 작성하려고 합니다. 적절한 함수 원형을 예로 들어보세요.
// int operator++(int) 가 되어야 함
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
		: m_nData(nParam)
	{

	}

	// 형변환
	operator int()
	{
		return m_nData;
	}

	// 전위 증가 연산자
	int operator++()
	{
		cout << "operator++()" << endl;
		return ++m_nData;
	}

	// 후위 증가 연산자
	int operator++(int)
	{
		cout << "operator++(int)" << endl;
		int nData = m_nData;
		m_nData++;

		return nData;
	}

private:
	int m_nData = 0;
};

int main()
{
	CMyData a(10);

	// 전위 증가 연산자 호출
	cout << ++a << endl;

	// 후위 증가 연산자 호출
	cout << a++ << endl;
	cout << a << endl;

	return 0;
}