// Q4. ���� ���� �Լ��� ����� ���� Ŭ������ ���� ���� Ŭ�����Դϴ�. �� ���� ���� Ŭ������ �Ļ� Ŭ�������� �ݵ�� �ؾ��ϴ� ���� �����Դϱ�?
// ���� ���� �Լ��� ������ ���� �ص�����, ���Ǵ� �̷��� �ϵ��� �̷�� �Լ��̴�.
// ���� ���� �Լ��� ����� ���� Ŭ������ �Ļ� Ŭ���������� �ݵ�� ���� ���� �Լ��� ������ �ؾ��Ѵ�.
#include <iostream>
using namespace std;

class CMyInterface
{
public:
	CMyInterface()
	{
		cout << "CMyInterface()" << endl;
	}

	// ���� �ְ� ���Ǵ� ���� ���� ���� �Լ�
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

	// ���� ���� �Լ��� �Ļ� Ŭ�������� '�ݵ��' ������ �ؾ��Ѵ�.
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
	// ���� ���� Ŭ������ �ν��Ͻ��� ���� �� ������ �� ����.
	// CMyInterface a;
	CMyData a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}