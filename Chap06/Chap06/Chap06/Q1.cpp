// Q1. 파생 클래스에서 일반 메서드를 재정의했다고 가정하겠습니다. 
// 만일, 파생 형식 인스턴스를 기본 형식에 대한 포인터로 포인팅하고 호출한다면 기본 형식과 파생 형식중
// 어느 클래스의 메서드가 호출될까요?
// 기본형식 클래스의 메서드가 호출됨. 
#include <iostream>
using namespace std;

class CMyData
{
public:
	int GetData()
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

class CMyDataEx
	: public CMyData
{
public:
	// 파생 클래스에서 기본 클래스의 메서드를 재정의 함.
	void SetData(int nParam)
	{
		if (nParam < 0)
			CMyData::SetData(0);
		
		if (nParam > 10)
			CMyData::SetData(10);
	}
};

int  main()
{
	CMyData* pData = new CMyDataEx;
	pData->SetData(5);
	delete pData;

	return 0;
}