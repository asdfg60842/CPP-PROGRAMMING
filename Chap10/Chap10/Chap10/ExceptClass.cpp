// 예외 클래스
// 예외 클래스를 만들어 사용하면 프로그램 내부에 만들어야 하는 모든 예외 정보를 한 클래스에서 만날 수 있다.
// 각종 오류를 포함한 예외 상황들을 정책적으로 관리하기 용이할 뿐만 아니라 디버깅하기도 수월해진다.
#include <iostream>
using namespace std;

class CMyException
{
public:
	// 예외 코드와 메세지를 입력받는다.
	CMyException(int nCode, const char* pszMsg)
	{
		m_nErrorCode = nCode;
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const
	{
		return m_nErrorCode;
	}

	const char* GetMessage() const
	{
		return m_szMsg;
	}

private:
	int m_nErrorCode;
	char m_szMsg[128];
};

int main()
{
	try
	{
		int nInput = 0;
		cout << "양의 정수를 입력하세요 : ";
		cin >> nInput;

		if (nInput < 0)
		{
			CMyException exp(10, "양의 정수를 입력해야 합니다.");
			throw exp;
		}
	}

	catch (CMyException& exp)
	{
		cout << "ERROR CODE [" << exp.GetErrorCode() << "] " << exp.GetMessage() << endl;
	}

	return 0;
}