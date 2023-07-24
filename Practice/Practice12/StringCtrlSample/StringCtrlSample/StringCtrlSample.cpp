#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strTest;
	strTest.SetString("°³»õ³¢");
	cout << strTest << endl;

	return 0;
}