// 이분 매칭
// 시간복잡도 = O(V*E)
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> v[MAX];
int d[MAX];
bool c[MAX];
int n = 3;
int m, s;

// 매칭에 성공한 경우 true, 실패한 경우 false
bool dfs(int x)
{
	// 연결된 모든 노드에 애해서 들어갈 수 있는지 시도
	for (int i = 0; i < v[x].size(); i++)
	{
		int t = v[x][i];
		// 이미 처리한 노드는 더이상 볼 필요가 없음
		if (c[t])
			continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	v[1].push_back(1);
	v[1].push_back(2);
	v[1].push_back(3);
	v[2].push_back(1);
	v[3].push_back(2);
	int count = 0;

	// 최대한 우겨 넣습니다.
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))
			count++;
	}
	cout << count << "개의 매칭이 이루어졌습니다." << '\n';

	for (int i = 1; i <= 100; i++)
	{
		if (d[i] != 0)
			cout << d[i] << " -> " << i << '\n';
	}

	return 0;
}