// Q6. ����� �޼��忡�� �Ҽ� ���� ���� �������� ���ϼ���.
// ��� ������ �б� ������ ����������, ����� ������ ����.
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam)
		: m_nData(nParam)
	{
	
	}
	
	~CTest()
	{

	}

	int GetData() const
	{
		// ��� ������ ���� ���� ���� ������, �� ���� ����.
		// m_nData = 10; �Ұ�

		// ���ȭ�� �޼��尡 �ƴ϶�� ȣ�� �Ұ�
		// SetData(10); �Ұ�
		return m_nData;
	}

	int SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}