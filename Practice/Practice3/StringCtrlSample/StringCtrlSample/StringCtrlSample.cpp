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
	
	// ���� ����
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	// �ܼ� ���� ������ ȣ��
	strNewData = strTest;
	cout << strTest.GetString() << endl;

	return 0;
}