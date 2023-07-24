// Q1. 자신의 이름과 나이를 입력받고, "나의 이름은 홍길동이고, 20살입니다." 라고 출력하는 프로그램을 작성하세요.
// 단, 반드시 std::cout, std::cin을 이용해 작성합니다. 
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string strName;
	int nAge;

	cout << "이름 : ";
	cin >> strName;

	cout << "나이 : ";
	cin >> nAge;

	cout << "나의 이름은 " << strName << "이고, " << nAge << "살 입니다." << endl;

	return 0;
}