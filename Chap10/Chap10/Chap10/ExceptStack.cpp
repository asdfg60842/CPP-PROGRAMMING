// 스택 풀기(Stack Unwinding)
#include <iostream>
using namespace std;

void TestFunc1()
{
	// 가장 마지막에 호출된 함수가 예외를 던진다.
	cout << "***TestFunc1() - Begin***" << endl;
	
	// 함수의 반환 없이 예외처리됨.
	// 스택이 원래대로 풀어짐
	// 즉, TestFunc3() 가 호출되기 전으로 돌아감
	throw 0;

	cout << "****TestFunc1() - End****" << endl;
}

void TestFunc2()
{
	cout << "***TestFunc2() - Begin***" << endl;
	TestFunc1();
	cout << "****TestFunc2() - End****" << endl;
}

void TestFunc3()
{
	cout << "***TestFunc3() - Begin***" << endl;
	TestFunc2();
	cout << "****TestFunc3() - End****" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}

	catch (...)
	{
		// 함수들을 반환하지 않고 스택이 즉시 풀려 흐름이 넘어온다.
		cout << "Exception handling" << endl;
	}

	return 0;
}