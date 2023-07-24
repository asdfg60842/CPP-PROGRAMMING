// 추상 자료형 사용의 예
// 빠른 연산이 필요한 순간에 switch-case 문이나 다중 if 문을 사용하는 것은 매우 비효율적.
// 프로그램에서 가장 여유로운 순간은 '사용자 입력' 순간이다.
// 다음 프로그램은 사용자로부터 나이를 입력받고, 요금을 계산하는 프로그램이다.
// 나이 입력 시 다중 if문으로 효율이 떨어지는 연산을 실행하여 요금을 계산하고,
// 출력하는 부분은 다중 if문이나 switch-case 문 없이 즉시 실행한다는 데 있다.
#include <iostream>
using namespace std;

#define DEFAULT_FARE 1000

class CPerson
{
public:
	CPerson() { }
	virtual ~CPerson()
	{
		cout << "virtual ~CPerson()" << endl;
	}

	// 요금 계산 인터페이스(순수 가상 함수)
	// 모든 파생 클래스는 이 함수가 정의되어 있다해도 무방함.
	virtual void CalcFare() = 0;

	virtual unsigned int GetFare()
	{
		return m_nFare;
	}

protected:
	unsigned int m_nFare = 0;
};

class CBaby
	: public CPerson
{
public:
	// 영유아(0~7세) 요금계산
	virtual void CalcFare()
	{
		m_nFare = 0;
	}
};

class CChild
	: public CPerson
{
public:
	// 어린이(8~13세) 요금계산
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 50 / 100; // 50%
	}
};

class CTeen
	: public CPerson
{
public:
	// 청소년(14~19tp) 요금계산
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 75 / 100; // 75%
	}
};

class CAdult
	: public CPerson
{
public:
	// 성인(20세 이상) 요금계산
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE; // 100%
	}
};

int main()
{
	// 순수 가상 함수를 가진 순수 가상 클래스에서의 객체 생성은 불가능하나, 추상자료형으로 존재 가능하다.
	CPerson* arList[3] = { 0, };
	int nAge = 0;

	// 1. 자료 입력: 사용자 입력에 따라서 생성할 객체 선택
	for (auto& person : arList)
	{
		cout << "나이를 입력하세요 : ";
		cin >> nAge;
		
		// 추상 자료형이지만 가상함수는 실형식인 파생클래스가 호출됨
		// CalcFare() 함수가 가상함수이기 때문에 사용자 입력에 따라 실제로 생성된 '실 형식' 의 CalcFare 가 호출됨.
		if (nAge < 8)
			person = new CBaby;
		else if (nAge < 14)
			person = new CChild;
		else if (nAge < 20)
			person = new CTeen;
		else
			person = new CAdult;

		// 생성한 객체에 맞는 요금이 자동으로 계산된다.
		person->CalcFare();
	}

	// 2. 자료 출력 : 계산한 요금을 활용하는 부분
	for (auto person : arList)
		cout << person->GetFare() << "원" << endl;

	// 3. 자료 삭제 및 종료
	for (auto person : arList)
		delete person;

	return 0;
}