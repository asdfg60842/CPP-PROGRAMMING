// Q3. char[12] 배열 메모리를 new 연산자로 동적 할당하고 해제하는 코드 예를 작성하세요.
#include <iostream>
using namespace std;

int main()
{
	char* arr = new char[12]{ "Hello, C++!" };

	for (int i = 0; i < 12; i++)
		cout << arr[i];

	cout << endl;

	delete[] arr;
}