// Q5. ���ӽ����̽��� �Ź� �ۼ��ϱ� �ȴٸ� �̸� Using ������ �ϴ°��� ����.
// ���ӽ����̽��� ��ø, �������Ƿ� '��ȣ��'�� �߻��� �� �ֱ� ������, ��Ȳ�� ���� ��Ȯ�� ���ӽ����̽��� ����ϴ°��� �߿�.
#include <iostream>
using namespace std;

// �Լ� ��������
// ����(����� ���Ҽ�) TestFunc �Լ�
void TestFunc(void)
{
	cout << "::TestFunc()" << endl;
}

// ���ӽ����̽��� ��ø
namespace TEST
{
	int g_nData = 100;

	// TEST ���ӽ����̽� �Ҽ� TestFunc �Լ�
	void TestFunc(void)
	{
		cout << "TEST::TestFunc()" << endl;
	}

	namespace DEV
	{
		int g_nData = 200;
		namespace WIN
		{
			int g_nData = 300;
		}
	}
}

int main()
{
	// ���ӽ����̽��� ��ø
	cout << TEST::g_nData << endl;
	cout << TEST::DEV::g_nData << endl;
	cout << TEST::DEV::WIN::g_nData << endl;

	// ���ӽ����̽��� �Լ� ��������
	::TestFunc();
	TEST::TestFunc();

	return 0;
}