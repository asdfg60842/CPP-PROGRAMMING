#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int main()
{
	CMyString strData;
	strData.SetString("Hello");
	cout << strData.GetString() << endl;

	return 0;
}