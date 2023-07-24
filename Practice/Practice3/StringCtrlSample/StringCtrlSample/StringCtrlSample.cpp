#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int main()
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");
	
	// 복사 생성
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	// 단순 대입 연산자 호출
	strNewData = strTest;
	cout << strTest.GetString() << endl;

	return 0;
}