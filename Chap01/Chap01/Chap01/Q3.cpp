// Q3. char[12] �迭 �޸𸮸� new �����ڷ� ���� �Ҵ��ϰ� �����ϴ� �ڵ� ���� �ۼ��ϼ���.
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