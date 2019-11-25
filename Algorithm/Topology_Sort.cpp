// 위상정렬(TS)
// 순서가 정해져있는 작업을 차례로 수행해야 할때 그 순서를 결정해주기 위해 사용하는 알고리즘
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n;
int inDegree[MAX];
vector<int> v[MAX];

void topologySort()
{
	int result[MAX];
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	// 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문
	for (int i = 1; i <= n; i++)
	{
		// n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것입니다.
		if (q.empty())
		{
			cout << "사이클이 발생했습니다";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << ' ';
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	n = 7;
	v[1].push_back(2);
	inDegree[2]++;
	v[1].push_back(5);
	inDegree[5]++;
	v[2].push_back(3);
	inDegree[3]++;
	v[3].push_back(4);
	inDegree[4]++;
	v[4].push_back(6);
	inDegree[6]++;
	v[5].push_back(6);
	inDegree[6]++;
	v[6].push_back(7);
	inDegree[7]++;
	topologySort();

	return 0;
}