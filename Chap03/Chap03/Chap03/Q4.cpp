// Q4. ���� �ڵ忡�� �߸��� ���� �����̸� ���� ������ ���Ϸ��� ��� �����ؾ� �ϴ��� ���ϼ���.
// class CRefTest
// {
// public:
//	 CRefTest(int &rParam)
//	 {
// 		 m_nData = rParam;
//	 }
//
//	 int GetData(void) { return m_nData; }
//
// private:
//	 int &m_nData;
// };
// ������ ������ ������ �ʱ�ȭ ����� ���� �ʱ�ȭ �ؾߵ�.
#include <iostream>

class CRefTest
{
public:
	CRefTest(int& rParam)
		: m_nData(rParam)
	{

	}

	int GetData(void) { return m_nData; }
	
private:
	int& m_nData;
};

int main()
{
	return 0;
}