// ���� ���ε�(Dynamic Binding) �Ǵ� ���� ���ε�(Late Binding)
// ������ ���α׷��� ����Ǵ� ���߿�(��Ÿ�� - Runtime) �ּҰ� �����Ǵ� ���� ���� ���ε��̶� �Ѵ�.
#include <iostream>
using namespace std;

void TestFunc1(int nParam)
{

}

void TestFunc2(int nParam)
{

}

int main()
{
	int nInput = 0;
	cin >> nInput;
	void(*pfTest)(int) = NULL;

	if (nInput > 10)
		pfTest = TestFunc1;
	else
		pfTest = TestFunc2;

	// pfTest�� �Լ� ������ �����̴�. 
	// �� ������ ���� ���α׷��� ���� �� �����ؼ� ����ڰ� ������ �Է��ϱ� ������ � �Լ��� ȣ��� ������ Ȯ���Ҽ� ����.
	// ����� �ڵ带 ���캸�� ������ ���� ���� Ȯ���Ǿ� ���� �ʴ�.
	// 00411930  call        dword ptr[pfTest]
	// call ����� �ڵ��� �ǿ����ڰ� ����� �ƴ϶� ������ �����̹Ƿ� ������ ����� �ּ��� �Լ��� ȣ��� ���̴�.
	pfTest(10);

	return 0;
}