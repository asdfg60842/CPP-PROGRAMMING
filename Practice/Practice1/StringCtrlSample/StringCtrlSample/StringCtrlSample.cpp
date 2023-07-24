#include "stdafx.h"
#include "CMyString.h"

int main()
{
	CMyString strData;
	strData.SetString("Hello");
	cout << strData.GetString() << endl;

	return 0;
}