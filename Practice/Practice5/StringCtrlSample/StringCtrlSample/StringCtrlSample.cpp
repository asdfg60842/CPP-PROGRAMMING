#include "stdafx.h"
#include "CMyString.h"

CMyString TestFunc(void)
{
	CMyString strTest("TestFunc() return");
	cout << static_cast<char*>(strTest) << endl;

	return strTest;
}

int main()
{
	TestFunc();

	return 0;
}