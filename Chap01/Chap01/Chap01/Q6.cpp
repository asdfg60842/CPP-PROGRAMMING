// Q6. ������ ���� int �迭�� ������������ ������ �� ȭ�鿡 ����� ����ϴ� ���α׷��� �ۼ��ϼ���.
// int aList[5] = { 10, 20, 30, 40, 50 };
// ��, ȭ�鿡 �迭 ������ ����� ���� �ݵ�� '���� ��� for��' �� ����ؾ� �մϴ�.
#include <iostream>
using namespace std;

int main()
{
	int aList[5] = { 20, 50, 10, 30, 40 };
	int tmp;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (aList[i] > aList[j]) 
			{
				tmp = aList[i];
				aList[i] = aList[j];
				aList[j] = tmp;
			}

	for (auto n : aList)
		cout << n << ' ';

	cout << endl;
	
	return 0;
}