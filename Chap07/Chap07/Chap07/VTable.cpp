// 가상 함수 테이블(Virtual Function Table) '함수 포인터 배열'
// CMyDataEx 클래스의 인스턴스가 선언되면 최초 CMyDataEx 클래스의 생성자가 호출된다.
// 하지만, 생성자의 실행은 하지 않고, 상위 클래스인 CMyData 생성자를 호출하고 실행하게 됨.
// 이후 CMyData 클래스의 생성자를 반환하고, CMyDataEx 클래스의 생성자가 호출되면 __vfptr을 덮어씀.
// __vfptr은 늘 가장 마지막에 파생된 클래스의 vtable 값으로 덮어씌어지므로 접근 형식에 상관 없이 실 형식의 함수가 호출될 수 밖에 없다.


#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		// __vfptr = CMyData의 vtable 주소;
		// __vfptr 값 : 0x0041ab34
		// __vfptr은 vtable 포인터로 가상함수로 선언된 멤버 함수들의 주소에 배열 형태로 접근이 가능함.
		cout << "CMyData()" << endl;
	}

	virtual ~CMyData() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2() { }
};

class CMyDataEx
	: public CMyData
{
public:
	CMyDataEx()
	{
		// __vfptr = CMyDataExd의 vtable 주소;
		// __vfptr 값 : 0x0041ab54
		// __vfptr 값이 변경됨으로 가리키는 함수 포인터 배열도 달라짐.
		cout << "CMyDataEx()" << endl;
	}

	virtual ~CMyDataEx() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2()
	{
		cout << "TestFunc2()" << endl;
	}
};

int main()
{
	// 추상 자료형
	// 파생 클래스 인스턴스를 참조하도록 선언 및 정의함.
	CMyData* pData = new CMyDataEx;
	
	// 가상함수의 경우 참조형식보다 실 형식을 우선함. 
	// CMyDataEx 클래스의 TestFunc2() 호출됨.
	pData->TestFunc2();
	delete pData;

	return 0;
}