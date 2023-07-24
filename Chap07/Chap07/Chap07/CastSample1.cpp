// static_cast<> : 컴파일시 상향 혹은 하향 형변환 한다.
// 추상 자료형의 경우 자연스럽게 '상향 형변환' 이 묵시적으로 이루어진다.
// 그러나 기본 형식 포인터가 가리키는 대상을 파생 형식 포인터로 형변환하는 '하향 형변환'은 상속 관계에서만 가능하다.
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { }
	virtual ~CMyData() { }

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	int GetData()
	{
		return m_nData;
	}

private:
	int m_nData;
};

class CMyDataEx
	: public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam > 10)
			nParam = 10;

		CMyData::SetData(nParam);
	}

	void PrintData()
	{
		cout << "PrintData() : " << GetData() << endl;
	}
};

int main()
{
	// 파생 형식의 객체를 기본 형식으로 포인팅
	CMyData* pData = new CMyDataEx;
	CMyDataEx* pNewData = NULL;

	// CMyData::SetData() 함수를 호출
	// 따라서 10이 넘는지 검사하지 않음.
	pData->SetData(15);

	// 기본 형식에 대한 포인터이나 가리키는 대상은 파생 형식임.
	// 이 사실이 명확하므로 파생 형식에 대한 포인터로 형변환 시도.
	// CMyData* -> CMyDataEx* (하향 형변환)
	pNewData = static_cast<CMyDataEx*>(pData);
	pNewData->PrintData();
	delete pData;

	return 0;
}