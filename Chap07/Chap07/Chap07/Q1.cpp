// Q1. ���� �Լ��� ����ϴ� ���� ū ������ �������� ���ϼ���.
// �Ļ� Ŭ�������� �������� ������ ����ϴ� ��� �Լ��̴�. �Ļ� Ŭ�������� ������ �ϸ� ������ ���ǰ� ������ ���õȴ�.
// �����Լ��� �ڽ��� ȣ���ϴ� ��ü�� ���� Ÿ�Կ� ���� ���� ȣ���� �Լ��� �����ȴ�.
#include <iostream>
using namespace std;

class CMyData
{
public:
	// ���� �Լ��� ���� �� �����ߴ�.
	virtual void PrintData()
	{
		cout << "CMyData : " << m_nData << endl;
	}

	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;

		// �� ������ �Լ��� ȣ��ȴ�.
		// �Ļ� ���Ŀ��� PrintData() �Լ��� ������ �Ѵٸ�, �Ʒ� �ڵ�� '�̷�'�� �Լ��� ȣ���ϴ� ���̴�.
		PrintData();
		cout << "****************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx
	: public CMyData
{
public:
	// �⺻ Ŭ������ ���� �Լ� ����� ������ ��.
	// ���� ���Ǵ� ���õ�
	virtual void PrintData()
	{
		cout << "CMyDataEx : " << m_nData * 2 << endl;
	}
};

int main()
{
	CMyDataEx a;
	a.PrintData();

	CMyData &b = a;

	// ���� ���Ŀ� ������� �� ������ �Լ��� ȣ���.
	b.PrintData();

	a.TestFunc();

	return 0;
}