// Q1. �ڽ��� �̸��� ���̸� �Է¹ް�, "���� �̸��� ȫ�浿�̰�, 20���Դϴ�." ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
// ��, �ݵ�� std::cout, std::cin�� �̿��� �ۼ��մϴ�. 
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string strName;
	int nAge;

	cout << "�̸� : ";
	cin >> strName;

	cout << "���� : ";
	cin >> nAge;

	cout << "���� �̸��� " << strName << "�̰�, " << nAge << "�� �Դϴ�." << endl;

	return 0;
}