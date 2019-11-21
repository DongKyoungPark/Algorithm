// 다이나믹 프로그래밍(DP)
// 하나의 문제는 단 한번만 풀도록 하는 알고리즘
// 다이나믹 프로그래밍은 다음의 가정하에 사용할 수 있습니다.
// 1번 가정. 큰 문제를 작은 문제로 나눌 수 있습니다.
// 2번 가정. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일합니다.
#include <iostream>

using namespace std;

int result[100];

int fibonachi(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;

	//메모이제이션을 사용하여 이미 계산한 결과를 배열에 저장
	if (result[x] != 0)
		return result[x];

	return result[x] = fibonachi(x - 1) + fibonachi(x - 2);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fibonachi(10);

	return 0;
}