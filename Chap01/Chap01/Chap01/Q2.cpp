// Q2. C++11 ���� auto ������ � �ǹ����� ���� �ڵ�� ���� ���̼���.
// auto ������ �����Ϸ��� �ڵ����� ������ �ڷ����� �������ִ� �ڷ���
#include <iostream>
using namespace std;

int main() 
{
	int a(10);
	int b(5);
	auto c(b); // �ʱ갪 ���Ŀ� ���� �ν��Ͻ��� ������ �ڵ����� ������.

	cout << a + b + c << endl;

	return 0;
}