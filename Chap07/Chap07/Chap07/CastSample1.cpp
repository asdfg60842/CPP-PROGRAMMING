// static_cast<> : �����Ͻ� ���� Ȥ�� ���� ����ȯ �Ѵ�.
// �߻� �ڷ����� ��� �ڿ������� '���� ����ȯ' �� ���������� �̷������.
// �׷��� �⺻ ���� �����Ͱ� ����Ű�� ����� �Ļ� ���� �����ͷ� ����ȯ�ϴ� '���� ����ȯ'�� ��� ���迡���� �����ϴ�.
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
	// �Ļ� ������ ��ü�� �⺻ �������� ������
	CMyData* pData = new CMyDataEx;
	CMyDataEx* pNewData = NULL;

	// CMyData::SetData() �Լ��� ȣ��
	// ���� 10�� �Ѵ��� �˻����� ����.
	pData->SetData(15);

	// �⺻ ���Ŀ� ���� �������̳� ����Ű�� ����� �Ļ� ������.
	// �� ����� ��Ȯ�ϹǷ� �Ļ� ���Ŀ� ���� �����ͷ� ����ȯ �õ�.
	// CMyData* -> CMyDataEx* (���� ����ȯ)
	pNewData = static_cast<CMyDataEx*>(pData);
	pNewData->PrintData();
	delete pData;

	return 0;
}