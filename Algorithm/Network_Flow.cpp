// 네트워크 플로우
// 시간복잡도 = O(VE^2)
// 특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘
// EX) 교통체증, 네트워크 데이터 전송 등의 다양한 분야에 활용
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6;
int result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> v[MAX];

void maxFlow(int start, int end)
{
	while (1)
	{
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++)
			{
				int y = v[x][i];
				// 방문하지 않은 노드 중에 용량이 남은경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)
				{
					q.push(y);
					d[y] = x; // 경로를 기억
					if (y == end)
						break; // 도착지에 도달한 경우
				}
			}
		}
		if (d[end] == -1)
			break; // 모든 경로를 찾은 뒤에 탈출
		int flow = INF;

		// 거꾸로 최소 유량 탐색		
		for (int i = end; i != start; i = d[i]) 
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		// 최소 유량만큼 추가한다.
		for (int i = end; i != start; i=d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	v[1].push_back(2);
	v[2].push_back(1);
	c[1][2] = 12;

	v[1].push_back(4);
	v[4].push_back(1);
	c[1][4] = 11;

	v[2].push_back(3);
	v[3].push_back(2);
	c[2][3] = 6;

	v[2].push_back(4);
	v[4].push_back(2);
	c[2][4] = 3;

	v[2].push_back(5);
	v[5].push_back(2);
	c[2][5] = 5;

	v[2].push_back(6);
	v[6].push_back(2);
	c[2][6] = 9;

	v[3].push_back(6);
	v[6].push_back(3);
	c[3][6] = 8;

	v[4].push_back(5);
	v[5].push_back(4);
	c[4][5] = 9;

	v[5].push_back(3);
	v[3].push_back(5);
	c[5][3] = 3;

	v[5].push_back(6);
	v[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	cout << result;

	return 0;
}