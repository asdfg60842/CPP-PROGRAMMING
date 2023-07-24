// Ŭ���� ���ø� Ư��ȭ
#include <iostream>
using namespace std;

template<typename T>
class CMyData
{
	CMyData(T param)
		: m_Data(param)
	{
	
	}
	
	T GetData() const
	{
		return m_Data;
	}

	void SetData(T param)
	{
		m_Data = param;
	}

private:
	T m_Data;
};

template < >
class CMyData<char*> // Ư��ȭ ��� �ڷ��� ����
{
public:
	CMyData(char* pszParam)
	{
		int nLen = strlen(pszParam);
		m_Data = new char[nLen + 1];
	}

	~CMyData()
	{
		delete[] m_Data;
	}

	char* GetData() const
	{
		return m_Data;
	}

private:
	char* m_Data;
};

int main()
{
	CMyData<char*> a("Hello");
	cout << a.GetData() << endl;
	
	return 0;
}