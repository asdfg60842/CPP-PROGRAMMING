// Q4. inline �Լ��� ��ũ���� ����� ������ �������� ���ϼ���.
// ���������� �Լ�ȣ���� ���� �ʾ� ȣ�⿡ ���� ������带 ���ҽ�ų�� ����.
#include <iostream>
#define Add(a, b) a + b
using namespace std;

__inline int add(int a, int b)
{
	return a + b;
}

int main()
{
	// ��ũ�� ���
	cout << Add(3, 4) << endl;
	
	// �ζ��� �Լ� ���
	cout << add(3, 4) << endl;

	return 0;
}

