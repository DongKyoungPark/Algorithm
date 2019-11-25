// 플로이드 와샬 알고리즘
// 시간복잡도 = O(n^3)
// 모든정점에서 모든정점으로 최단 경로를 구하는 알고리즘
// 거쳐가는 정점을 기준으로 알고리즘을 수행
#include <iostream>

using namespace std;

int n = 4;
int INF = 10000000;
int arr[4][4] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

void floydWarshall()
{
	// 결과 그래프를 초기화합니다.
	int d[4][4];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = arr[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < n; k++)
	{
		// i = 출발 노드
		for (int i = 0; i < n; i++)
		{
			// j = 도착 노드
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과를 출력합니다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	floydWarshall();

	return 0;
}