// 그리디 알고리즘
// 당장 눈 앞에 보이는 최적의 상황만을 쫓는 알고리즘
// 무조건 큰 경우대로, 무조건 작은 경우대로, 무조건 긴 경우대로, 무조건 짧은 경우대로 등으로 극단적으로 문제에 접근
#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, result = 0;
	cin >> n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	cout << result;

	return 0;
}