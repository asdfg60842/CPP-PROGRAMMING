// Q6. 다음과 같은 int 배열을 오름차순으로 정렬한 후 화면에 결과를 출력하는 프로그램을 작성하세요.
// int aList[5] = { 10, 20, 30, 40, 50 };
// 단, 화면에 배열 내용을 출력할 때는 반드시 '범위 기반 for문' 을 사용해야 합니다.
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