// Q1. Ŭ���� ���� ���� ������ �߿��� private�� �ǹ��ϴ� ���� �������� ���ϼ���.
// �ܺ� ���� �Ӹ� �ƴ϶� �Ļ� Ŭ�����κ����� ���ٵ� ���ܵ�. ���� ��� �̿��� ������ ���ܵ�.
#include <iostream>
using namespace std;

class CMyData
{
	// �⺻ ���� ���� �����ڴ� 'private' �̴�.
	int m_nData;

public:
	int GetData(void)
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}
};

int main()
{
	CMyData data;

	data.SetData(10);
	cout << data.GetData() << endl;

	return 0;
}