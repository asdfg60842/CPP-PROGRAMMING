// Q2. 각종 대입 연산자들의 적절한 반환 형식은 무엇입니까?
// 단순대입, 복합대입, 이동대입 연산자들의 적절한 반환 형식은 참조자로 설정한다.
#include <iostream>
using namespace std;

class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		cout << "CMyData(int)" << endl;
		m_pnData = new int(nParam);
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}
	~CMyData()
	{
		delete m_pnData;
	}

	operator int()
	{
		return *m_pnData;
	}

	// 덧셈 연산자 다중정의
	CMyData operator+(const CMyData& rhs)
	{
		return CMyData(*m_pnData + *rhs.m_pnData);
	}

	// 단순 대입 연산자 다중 정의
	CMyData& operator=(const CMyData& rhs)
	{
		cout << "operator=" << endl;
		if (this == &rhs)
			return *this;

		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);

		return *this;
	}

	// 이동 대입 연산자 다중 정의
	CMyData& operator=(CMyData&& rhs)
	{
		cout << "operator=(Move)" << endl;

		// 얕은 복사를 수행하고 원본은 Null 로 초기화한다.
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;

		return *this;
	}
	
private:
	int* m_pnData = nullptr;
};

int main()
{
	CMyData a(0), b(3), c(4);
	cout << "*****Before*****" << endl;

	// 이동 대입 연산자 실행
	a = b + c;
	cout << "*****After*****" << endl;
	cout << a << endl;
	
	// 단순 대입 연산자 실행
	a = b;
	cout << a << endl;

	return 0;
}