#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strTest;

	// ���ڿ��� ���͸��Ǿ� ��ü�Ǵ� ���
	strTest.SetString("������");
	cout << strTest << endl;

	// ���͸����� �ʴ� ���
	strTest.SetString("Hello");
	cout << strTest << endl;

	return 0;
}