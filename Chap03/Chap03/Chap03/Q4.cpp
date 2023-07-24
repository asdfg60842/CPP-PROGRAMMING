// Q4. 다음 코드에서 잘못된 점은 무엇이며 문법 오류를 피하려면 어떻게 수정해야 하는지 답하세요.
// class CRefTest
// {
// public:
//	 CRefTest(int &rParam)
//	 {
// 		 m_nData = rParam;
//	 }
//
//	 int GetData(void) { return m_nData; }
//
// private:
//	 int &m_nData;
// };
// 참조형 변수는 생성자 초기화 목록을 통해 초기화 해야됨.
#include <iostream>

class CRefTest
{
public:
	CRefTest(int& rParam)
		: m_nData(rParam)
	{

	}

	int GetData(void) { return m_nData; }
	
private:
	int& m_nData;
};

int main()
{
	return 0;
}