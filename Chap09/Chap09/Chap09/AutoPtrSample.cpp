// auto_ptr
// 동적 할당한 인스턴스를 '자동' 으로 삭제한다. 가장 오래 존재했던 스마트 포인터라 할 수 있다.
// 배열을 지원하지 않을 뿐더러 얕은 복사 문제 등이 있기에 사용하지 않는 것이 바람직함.
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
	// auto_ptr 예제 1 - 배열 동적할당 불가 문제
	cout << "*****Begin*****" << endl;
	{
		// 아래와 같이 배열로 동적할당 할 시 배열 형식으로 delete 하지 못해 문제가 발생함.
		// auto_ptr<CMyData> ptrTest(new CMyData[3]);

		// 속한 범위를 벗어나면 대상 객체는 자동으로 소멸된다.
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "*****End*******" << endl;


	// auto_ptr 예제2 - 얕은 복사 문제
	auto_ptr<CMyData> ptrTest(new CMyData);
	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	// 포인터를 대입하면 원본 포인터는 NULL 이 된다.
	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	// 이 코드는 실행이 불가능해진다.
	// ptrTest->TestFunc();

	return 0;
}