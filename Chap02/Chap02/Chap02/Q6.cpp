// ���� �ڵ��� ���� ����� �ۼ��ϼ���.
// �ĺ��� �˻������� ���� ȣ���ϴ� �Լ��� TEST ���ӽ����̽��� �ִ� �Լ��̹Ƿ� �ش� �Լ� ���� ��Ͽ� nData ������ �����Ƿ�
// 100 �̴�.
#include <iostream>
using namespace std;

int nData = 200;

namespace TEST
{
	int nData = 100;
	void TestFunc(void)
	{
		cout << nData << endl;
	}
}

int main()
{
	TEST::TestFunc();

	return 0;
}