// Q3. ���� �ڵ忡�� 'm_nData(nParam)' �� ���� �κ��� �����̶� �θ����� ���ϼ���.
// CTest(int nParam)
//	 : m_nData(nParam)
// {
// 
// }
// �������� �ʱ�ȭ ������� ������ ���� ���� �� �ʱ�ȭ �ϰų�, ���� �ʱ�ȭ �ϴµ� ����.
#include <iostream>
using namespace std;

class CRefTest
{
public:
	// ������ ����� �ݵ�� ������ �ʱ�ȭ ����� �̿��� �ʱ�ȭ�Ѵ�.
	CRefTest(int& rParam)
		: m_nData(rParam)
	{

	}

	int GetData(void)
	{
		return m_nData;
	}
private:
	// ������ ����� ��ü�� ������ �� �ݵ�� �ʱ�ȭ�ؾ� �Ѵ�.
	int& m_nData;
};

int main()
{
	int a = 10;
	CRefTest t(a);

	cout << t.GetData() << endl;

	// ���� ������ a�� ���� ������.
	a = 20;
	cout << t.GetData() << endl;

	return 0;
}