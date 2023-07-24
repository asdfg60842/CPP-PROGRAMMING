// �޸� ���� ó��
// ���� �߻��� ����ȭ�� ����ó���� �ذ��� ����������.
#include <new>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nSize)
	{
		// �޸� �Ҵ翡 �����ϸ� ���ܸ� ������.
		m_pszData = new char[nSize];
	}

	~CTest()
	{
		delete[] m_pszData;
		cout << "���������� ��ü�� �Ҹ���" << endl;
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

		// ����ڰ� �Է��� ���� ���� ���� �״�� ����� ��ü�� ����
		cin >> nSize;
		CTest a(nSize);
	}

	// �޸� ������ ������ ��� �ڿ������� catch �� ������� �ڵ��� �帧�� �Ѿ��
	catch (bad_alloc& exp)
	{
		// �ý����� ���� ������ ����Ѵ�.
		cout << exp.what() << endl;
		cout << "ERROR : CTest()" << endl;
	}

	return 0;
}