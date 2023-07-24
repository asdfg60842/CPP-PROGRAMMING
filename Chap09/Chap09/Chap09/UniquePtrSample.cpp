// unique_ptr 
// shared_ptr 과 달리 한 대상을 오로지 한 포인터로만 포인팅한다. 즉, 하나의 소유자만 허용함.
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

int main()
{
	unique_ptr<CTest> ptr1(new CTest);

	// 아래 코드들은 컴파일 오류가 발생함.
	// unique_ptr<CTest> ptr2(ptr1);
	// ptr2 = ptr1;

	return 0;
}