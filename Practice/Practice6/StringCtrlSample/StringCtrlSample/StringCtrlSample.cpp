#include "stdafx.h"
#include "CMyString.h"

int main()
{
	CMyString strLeft("Hello"), strRight("World"), strResult;
	strResult = strLeft + strRight;
	cout << strResult << endl;
	
	cout << strLeft << endl;
	strLeft += CMyString("World");
	cout << strLeft << endl;

	return 0;
}