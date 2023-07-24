// Q1. 다음 두 함수 원형에서 잘못된 점은 무엇인지 답하세요.
// int TestFunc(int nParam1 = 5, int nParam2, int nParam3 = 10)
// int TestFunc(int nParam1 = 5, int nParam2)
// 왼쪽 매개변수에 디폴트 값을 기술하려면 나머지 모든 매개변수의 디폴트값을 기술해야함.
#include <iostream>
using namespace std;

// 위의 함수 원형을 올바르게 변경하면 다음과 같음.
// 단, 매개변수 하나 또는 두개를 실인수로 함수를 호출하게 되면 '모호성' 발생
// int TestFunc(int nParam1 = 5, int nParam2 = 10, int nParam3 = 10)
// {
//	 return nParam1 + nParam2 + nParam3;
// }
//
// int TestFunc(int nParam1 = 5, int nParam2 = 10)
// {
//	 return nParam1 + nParam2;
// }

int main()
{
	return 0;
}