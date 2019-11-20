// 너비 우선 탐색(BFS)
// 탐색을 할 때 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘
// 최단경로를 찾아주는 알고리즘
// 큐 사용
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n = 7;
int checked[7];
vector<int> v[8];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	checked[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!checked[y])
			{
				q.push(y);
				checked[y] = true;
			}
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 1과 2를 연결
	v[1].push_back(2);
	v[2].push_back(1);

	// 1과 3를 연결
	v[1].push_back(3);
	v[3].push_back(1);

	// 2과 3를 연결
	v[2].push_back(3);
	v[3].push_back(2);

	// 2과 4를 연결
	v[2].push_back(4);
	v[4].push_back(2);

	// 2과 5를 연결
	v[2].push_back(5);
	v[5].push_back(2);

	// 3과 6를 연결
	v[3].push_back(6);
	v[6].push_back(3);

	// 3과 7를 연결
	v[3].push_back(7);
	v[7].push_back(3);

	// 4과 5를 연결
	v[4].push_back(5);
	v[5].push_back(4);

	// 6과 7를 연결
	v[6].push_back(7);
	v[7].push_back(6);

	// BFS를 수행
	bfs(1);

	return 0;
}