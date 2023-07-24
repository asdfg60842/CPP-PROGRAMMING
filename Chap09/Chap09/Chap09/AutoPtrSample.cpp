// auto_ptr
// ���� �Ҵ��� �ν��Ͻ��� '�ڵ�' ���� �����Ѵ�. ���� ���� �����ߴ� ����Ʈ �����Ͷ� �� �� �ִ�.
// �迭�� �������� ���� �Ӵ��� ���� ���� ���� ���� �ֱ⿡ ������� �ʴ� ���� �ٶ�����.
#include <memory>
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	~CMyData()
	{
		cout << "~CMyData()" << endl;
	}

	void TestFunc()
	{
		cout << "CMyData::TestFunc()" << endl;
	}
};

int main()
{
	// auto_ptr ���� 1 - �迭 �����Ҵ� �Ұ� ����
	cout << "*****Begin*****" << endl;
	{
		// �Ʒ��� ���� �迭�� �����Ҵ� �� �� �迭 �������� delete ���� ���� ������ �߻���.
		// auto_ptr<CMyData> ptrTest(new CMyData[3]);

		// ���� ������ ����� ��� ��ü�� �ڵ����� �Ҹ�ȴ�.
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "*****End*******" << endl;


	// auto_ptr ����2 - ���� ���� ����
	auto_ptr<CMyData> ptrTest(new CMyData);
	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	// �����͸� �����ϸ� ���� �����ʹ� NULL �� �ȴ�.
	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	// �� �ڵ�� ������ �Ұ���������.
	// ptrTest->TestFunc();

	return 0;
}