// Q2. Ŭ���� �ν��Ͻ��� ������ �� �ڵ����� ȣ��Ǵ� �Լ��� �����̸�, �Լ� ������ ���� ū ������ Ư¡�� �������� ���ϼ���.
// ��ü�� �����ɶ�, �����ڰ� �ڵ����� ȣ��Ǹ�, �Լ� �̸��� Ŭ���� �̸��� �����ϴ�. ����, ��ȯ������ ����.
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "CTest::~CTest()" << endl;
	}
};

int main()
{
	cout << "Begin" << endl;
	CTest a;
	cout << "End" << endl;

	return 0;
}