// Q1. �Ļ� Ŭ�������� �Ϲ� �޼��带 �������ߴٰ� �����ϰڽ��ϴ�. 
// ����, �Ļ� ���� �ν��Ͻ��� �⺻ ���Ŀ� ���� �����ͷ� �������ϰ� ȣ���Ѵٸ� �⺻ ���İ� �Ļ� ������
// ��� Ŭ������ �޼��尡 ȣ��ɱ��?
// �⺻���� Ŭ������ �޼��尡 ȣ���. 
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
	// �Ļ� Ŭ�������� �⺻ Ŭ������ �޼��带 ������ ��.
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