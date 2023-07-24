// Q4. int�� ���� ���� ������ �Ű������� �ް� �� ������ ���� ��ȯ�ϴ� �Լ��� �ۼ��ϼ���.
// �Լ� ������ void Swap(int& a, int &b) �Դϴ�.
#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int tmp = b;
	b = a;
	a = tmp;
}

int main()
{
	int a(5);
	int b(7);

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	Swap(a, b);

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	return 0;
}