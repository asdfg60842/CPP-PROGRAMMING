#include "stdafx.h"
#include "CMyString.h"

int main()
{
	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	strLeft = CMyString("String");

	if (strLeft != strRight)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;

	return 0;
}