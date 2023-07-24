#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strTest;

	// 문자열이 필터링되어 대체되는 경우
	strTest.SetString("개새끼");
	cout << strTest << endl;

	// 필터링되지 않는 경우
	strTest.SetString("Hello");
	cout << strTest << endl;

	return 0;
}