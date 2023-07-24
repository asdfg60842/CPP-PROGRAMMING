// Q1. �Լ��� �Ű������� �⺻ ������ �ƴ϶� Ŭ������� �Ű����� ������ ��� ���ϴ� ���� �ٶ������� ������ ���ϼ���.
// ����� ������ - �Լ��� ���μ��� ����� ������ �Լ� ȣ�� ������ ���� ����� �� �ֱ� ����
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

// �Ű������� Ŭ������ ���� '����� ����'
void TestFunc(const CTestData& param)
{
	cout << "TestFunc()" << endl;

	// ��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� ������ �� ����.
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