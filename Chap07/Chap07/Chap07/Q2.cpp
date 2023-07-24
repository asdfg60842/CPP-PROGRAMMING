// Q2. �Ҹ��ڸ� �ݵ�� ����ȭ�ؾ� �ϴ� ���� � ������� ���ϼ���.
// �߻� �ڷ����� ����ϰ�, ��ü�� ���� �Ҵ� �� ������ �ϰԵȴٸ� �Ҹ��� ����ȭ�� �ʿ��ϴ�.
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		m_pszData = new char[32];
	}

	// �Ҹ��ڸ� ���� �Լ��� ����
	virtual ~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pszData;
	}

private:
	char* m_pszData;
};

class CMyDataEx
	: public CMyData
{
public:
	CMyDataEx()
	{
		m_pnData = new int;
	}

	// �⺻ Ŭ�������� �Ҹ��ڸ� ����ȭ �Ͽ��� ������, �Ļ� Ŭ������ �Ҹ��ڱ��� ȣ���.
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
		delete m_pnData;
	}

private:
	int* m_pnData;
};

int main()
{
	CMyData* pData = new CMyDataEx;

	delete pData;
	
	return 0;
}