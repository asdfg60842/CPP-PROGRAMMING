// shared_ptr 은 auto_ptr 과 달리 배열로 객체를 삭제할 수 있는 방법을 제공한다.
// shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
// 위와 같이 삭제 함수를 등록하는 것 이외에도 reset() 메서드를 호출해 가리키는 대상을 즉시 삭제할 수 있다.
#include <memory>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest()" << endl;
	}

	void TestFunc()
	{
		cout << "TestFunc()" << endl;
	}
};

void RemoveTest(CTest* pTest)
{
	cout << "RemoveTest()" << endl;

	// 대상을 배열로 삭제한다.
	delete[] pTest;
}

int main()
{
	cout << "*****Begin*****" << endl;

	// 대상 객체를 소멸할 함수를 별도로 등록한다.
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
	cout << "*****End*******" << endl;

	return 0;
}