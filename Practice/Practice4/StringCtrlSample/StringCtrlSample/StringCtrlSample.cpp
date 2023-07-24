#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& strParam)
{
	cout << static_cast<char*>(strParam) << endl;
}

int main()
{
	CMyString strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));

	return 0;
}