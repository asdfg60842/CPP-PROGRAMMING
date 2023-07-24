#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	// CMyString a("Hello"), b("World"), c;
	// c = a + b;

	CMyString b("World"), c;
	c = "Hello" + b;
	cout << c << endl;

	return 0;
}