// Q2. A�� B��, B�� C�� �⺻ Ŭ������ �� C Ŭ������ �ν��Ͻ��� �����Ѵٰ� �����ϸ� ���� ���� '����' �Ǵ� �����ڴ� ��� Ŭ������ �������Դϱ�?
// ���� ���� ȣ��Ǵ� �����ڴ� C Ŭ���� ������, ������ ȣ������� �ݴ�� A Ŭ������ �����ڰ� ���� ȣ���
#include <iostream>
using namespace std;

class CMyDataA
{
public:
	CMyDataA()
	{
		cout << "CMyDataA()" << endl;
	}

	~CMyDataA()
	{
		cout << "~CMyDataA()" << endl;
	}
};

class CMyDataB
	: public CMyDataA
{
public:
	CMyDataB()
	{
		cout << "CMyDataB()" << endl;
	}

	~CMyDataB()
	{
		cout << "~CMyDataB()" << endl;
	}
};

class CMyDataC
	: public CMyDataB
{
public:
	CMyDataC()
	{
		cout << "CMyDataC()" << endl;
	}
	
	~CMyDataC()
	{
		cout << "~CMyDataC()" << endl;
	}
};

int main()
{
	cout << "*****Begin*****" << endl;
	CMyDataC data;
	cout << "*****End*******" << endl;

	return 0;
}