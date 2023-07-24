// Q5. 다중 상속의 모호성을 회피하려 합니다. 어떤 방법을 이용해야 합니까?
// 명시적인 호출을 통해 모호성을 회피할수 있다.  
#include <iostream>
using namespace std;

class CMyImage
{
public:
	CMyImage(int nHeight, int nWidth)
		: m_nHeight(nHeight), m_nWidth(nWidth)
	{
		cout << "CMyImage(int, int)" << endl;
	}

	int GetHeight() const
	{
		return m_nHeight;
	}

	int GetWidth() const
	{
		return m_nWidth;
	}

	int GetSize() const
	{
		return 0;
	}

protected:
	int m_nHeight;
	int m_nWidth;
};

class CMyShape
{
public:
	CMyShape(int nType)
		: m_nType(nType)
	{
		cout << "CMyShape(int)" << endl;
	}

	int GetType() const
	{
		return m_nType;
	}
	
	int GetSize() const
	{
		return 0;
	}

protected:
	int m_nType;
};

class CMyPicture
	: public CMyImage, public CMyShape
{
public:
	CMyPicture()
		: CMyImage(200, 120), CMyShape(1)
	{
		cout << "CMyPicture()" << endl;
	}
};

int main()
{
	CMyPicture a;
	
	// a.GetSize();
	// 상속받은 기본 클래스에 모두 GetSize() 함수가 있기 때문에 모호함
	// 명시적인 호출로 호출해야함
	a.CMyImage::GetSize();
	a.CMyShape::GetSize();

	cout << "Width : " << a.GetWidth() << endl;
	cout << "Height : " << a.GetHeight() << endl;
	cout << "Type : " << a.GetType() << endl;

	return 0;
}