// Q3. �Լ��� ���� �����ϴ� �ͺ��ٴ� �Լ� ���ø��� �� ���� �ڵ尡 �� ���ɼ��� �����ϴ�. ������ ���ϼ���.
// �Լ��� ���������� ��� �ڷ����� �����ΰ��� ���� ������ ���� �ϴ� �Լ��� ������ ����� ����.
// ���ø��� ��� �ڷ����� ���� �������� �ʾƵ� ���� �ڵ带 Ȯ���Ҽ� ����.
#include <iostream>
using namespace std;

// �Լ��� �������� (Overloading)
// �ڷ����� ���� ������ ���� �ϴ� �Լ��� 2�� ����
int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

// ���ø� (Template)
// �ڷ����� ���� �������� �ʾƵ� ���� Ȯ�� ����
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// �Լ��� �������� (Overloading)
	cout << Add(3, 4) << endl;
	cout << Add(3.3, 4.4) << endl;

	// ���ø� (Template)
	cout << Add<int>(3, 4) << endl;
	cout << Add<double>(3.3, 4.4) << endl;

	return 0;
}