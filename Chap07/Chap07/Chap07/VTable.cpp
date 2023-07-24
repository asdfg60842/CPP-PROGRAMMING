// ���� �Լ� ���̺�(Virtual Function Table) '�Լ� ������ �迭'
// CMyDataEx Ŭ������ �ν��Ͻ��� ����Ǹ� ���� CMyDataEx Ŭ������ �����ڰ� ȣ��ȴ�.
// ������, �������� ������ ���� �ʰ�, ���� Ŭ������ CMyData �����ڸ� ȣ���ϰ� �����ϰ� ��.
// ���� CMyData Ŭ������ �����ڸ� ��ȯ�ϰ�, CMyDataEx Ŭ������ �����ڰ� ȣ��Ǹ� __vfptr�� ���.
// __vfptr�� �� ���� �������� �Ļ��� Ŭ������ vtable ������ ��������Ƿ� ���� ���Ŀ� ��� ���� �� ������ �Լ��� ȣ��� �� �ۿ� ����.


#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		// __vfptr = CMyData�� vtable �ּ�;
		// __vfptr �� : 0x0041ab34
		// __vfptr�� vtable �����ͷ� �����Լ��� ����� ��� �Լ����� �ּҿ� �迭 ���·� ������ ������.
		cout << "CMyData()" << endl;
	}

	virtual ~CMyData() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2() { }
};

class CMyDataEx
	: public CMyData
{
public:
	CMyDataEx()
	{
		// __vfptr = CMyDataExd�� vtable �ּ�;
		// __vfptr �� : 0x0041ab54
		// __vfptr ���� ��������� ����Ű�� �Լ� ������ �迭�� �޶���.
		cout << "CMyDataEx()" << endl;
	}

	virtual ~CMyDataEx() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2()
	{
		cout << "TestFunc2()" << endl;
	}
};

int main()
{
	// �߻� �ڷ���
	// �Ļ� Ŭ���� �ν��Ͻ��� �����ϵ��� ���� �� ������.
	CMyData* pData = new CMyDataEx;
	
	// �����Լ��� ��� �������ĺ��� �� ������ �켱��. 
	// CMyDataEx Ŭ������ TestFunc2() ȣ���.
	pData->TestFunc2();
	delete pData;

	return 0;
}