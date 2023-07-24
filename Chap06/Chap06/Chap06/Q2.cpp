// Q2. A는 B의, B는 C의 기본 클래스일 때 C 클래스의 인스턴스를 선언한다고 가정하면 가장 먼저 '실행' 되는 생성자는 어느 클래스의 생성자입니까?
// 가장 먼저 호출되는 생성자는 C 클래스 이지만, 실행은 호출순서와 반대로 A 클래스의 생성자가 먼저 호출됨
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