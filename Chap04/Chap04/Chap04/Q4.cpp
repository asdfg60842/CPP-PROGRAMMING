// Q4. 이동 시맨틱이 등장한 가장 큰 원인은 무엇으로 볼 수 있는지 답하세요.
// 이름 없는 임시객체가 생성될때 부하가 최소화 될 수 있도록 변경한 것.
// 사라질 객체에 대하여 깊은 복사를 수행하는 것이 아닌 얕은 복사를 진행하여 성능을 높임.
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData()
	{
		cout << "CTestData()" << endl;
	}

	~CTestData()
	{
		cout << "~CTestData()" << endl;
	}

	// 복사 생성자
	CTestData(const CTestData& rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	// 이동 생성자
	CTestData(const CTestData&& rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &&)" << endl;
	}

	CTestData& operator=(const CTestData&) = default;

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

CTestData TestFunc(int nParam)
{
	cout << "***TestFunc() : Begin***" << endl;
	CTestData a;
	a.SetData(nParam);
	cout << "***TestFunc() : End*****" << endl;

	return a;
}

int main()
{
	CTestData b;
	cout << "*Before**********" << endl;
	b = TestFunc(20);
	cout << "*After***********" << endl;
	CTestData c(b);

	return 0;
}