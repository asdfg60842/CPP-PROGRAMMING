#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strLeft("Hello"), strRight("World");
	cout << strLeft + strRight << endl;

	return 0;
}