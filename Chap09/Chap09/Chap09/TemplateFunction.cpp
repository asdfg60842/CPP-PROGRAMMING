// �Լ� ���ø� Ư��ȭ
// char* �� ���� Ư���� ������ ���� ��� ������ �ٸ� ���İ� ���� �ٸ� �ڵ带 �����ؾ��� ���� �ִ�.
// �̸� �и��ؼ� ó���ϴ� ���� Ư��ȭ �̴�.
#include <memory>
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// �� ���� ������ ��� char* �����̸� �� �Լ��� ��ü�ȴ�.
template< >
char* Add(char* pszLeft, char* pszRight)
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	// ���� �Ҵ��� �޸𸮿� ���ڿ��� �����Ѵ�.
	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}

int main()
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	char* pszResult = Add<char*>(const_cast<char *>("Hello"), const_cast<char *>("World"));
	cout << pszResult << endl;
	delete[] pszResult;

	return 0;
}