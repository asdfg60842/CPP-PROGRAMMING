// 템플릿 매개변수
// 템플릿 선언시 다음과 같이 형식을 여러 개 작성할 수 있다.
// template<typename T, typename T2>
// 형식 중 일부는 구체적으로 작성할 수 있다. 또한 템플릿 매개변수는 클래스 내에서 모두 접근이 가능하다.
// template<typename T, int nSize>
// 템플릿 매개변수를 함수처럼 선언할 수 있고, 디폴트 값을 지정할 수도 있다.
// template<typename T = int, int nSize = 3>
#include <iostream>
using namespace std;

template<typename T, int nSize>
class CMyArray
{
public:
	// nSize 변수는 템플릿 매개변수이다.
	CMyArray()
	{
		m_pData = new T[nSize];
	}

	~CMyArray()
	{
		delete[] m_pData;
	}

	// 배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	// 상수화 된 배열 연산자
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}

	// 배열 요소의 개수를 반환
	int GetSize()
	{
		return nSize;
	}

private:
	T* m_pData = nullptr;
};

int main()
{
	CMyArray<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (int i = 0; i < 3; i++)
		cout << arr[i] << endl;

	return 0;
}