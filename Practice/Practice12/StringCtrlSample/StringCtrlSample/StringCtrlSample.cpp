#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strTest;
	strTest.SetString("������");
	cout << strTest << endl;

	return 0;
}