// Q4. 순수 가상 함수를 멤버로 갖는 클래스는 순수 가상 클래스입니다. 이 순수 가상 클래스의 파생 클래스에서 반드시 해야하는 일은 무엇입니까?
// 순수 가상 함수는 선언은 지금 해두지만, 정의는 미래에 하도록 미뤄둔 함수이다.
// 순수 가상 함수를 멤버로 갖는 클래스의 파생 클래스에서는 반드시 순수 가상 함수를 재정의 해야한다.
#include <iostream>
using namespace std;

class CMyInterface
{
public:
	CMyInterface()
	{
		cout << "CMyInterface()" << endl;
	}

	// 선언만 있고 정의는 없는 순수 가상 함수
	virtual int GetData() const = 0;
	virtual void SetData(int nParam) = 0;
};

class CMyData
	: public CMyInterface
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	// 순수 가상 함수는 파생 클래스에서 '반드시' 재정의 해야한다.
	virtual int GetData() const
	{
		return m_nData;
	}

	virtual void SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

int main()
{
	// 순수 가상 클래스는 인스턴스를 선언 및 정의할 수 없다.
	// CMyInterface a;
	CMyData a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}