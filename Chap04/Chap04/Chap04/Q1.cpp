// Q1. 함수의 매개변수가 기본 형식이 아니라 클래스라면 매개변수 형식은 어떻게 정하는 것이 바람직한지 이유를 답하세요.
// 상수형 참조자 - 함수의 실인수로 기술한 변수가 함수 호출 때문에 값이 변경될 수 있기 때문
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam)
		: m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	int GetData() const
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

// 매개변수가 클래스에 대한 '상수형 참조'
void TestFunc(const CTestData& param)
{
	cout << "TestFunc()" << endl;

	// 피호출자 함수에서 매개변수 인스턴스의 값을 변경할 수 없다.
	//param.SetData(20);
}

int main()
{
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);

	cout << "a : " << a.GetData() << endl;

	cout << "*****End*****" << endl;

	return 0;
}