// Q7. ���� ��������� '�̰�'�� ����� �� �����ϴ�. �̰��� �����Դϱ�?
// this ������ ���Ұ�
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam)
		: m_nData(nParam)
	{
		m_nCount++;
	}
	
	int GetData()
	{
		return m_nData;
	}

	void ResetCount()
	{
		m_nCount = 0;
	}

	// ���� �޼��� ���� �� ����
	static int GetCount()
	{
		return m_nCount;
	};

private:
	int m_nData;
	
	// ���� ��� ���� ����(���� ��� ������ ����� ���Ǹ� �и��ؾ���)
	static int m_nCount;
};

// ���� ��� ���� ����(���� ��� ������ ����� ���Ǹ� �и��ؾ���)
int CTest::m_nCount = 0;

int main()
{
	CTest a(5), b(10);
	
	// ���� ����� ����
	cout << a.GetCount() << endl;
	b.ResetCount();

	// ���� ����� ����. �ν��Ͻ� ���� ���� ����
	cout << CTest::GetCount() << endl;

	return 0;
}