// 다익스트라 알고리즘
// 최단 경로 탐색 알고리즘
// 다익스트라는 현실 세계에 사용하기 매우 적합한 알고리즘
// 하나의 최단 거리를 구할 때 그 이전까지 구했던 최단 거리 정보를 그대로 사용
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 6;
int INF = 1000000000;

vector<pair<int, int>> arr[7]; // 간선정보
int dist[7]; // 최소비용

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; // 힙 구조
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty())
	{
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화(-) 합니다.
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵합니다.
		if (dist[current] < distance)
			continue;
		for (int i = 0; i < arr[current].size(); i++)
		{
			// 선택된 노드의 인접 노드
			int next = arr[current][i].first;
			// 선택된 노드 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + arr[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체 합니다.
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

//
//// 전체 그래프를 초기화 합니다.
//int arr[6][6] = {
//	{0,2,5,1,INF,INF},
//	{2,0,3,2,INF,INF},
//	{5,3,0,3,1,5},
//	{1,2,3,0,1,INF},
//	{INF,INF,1,1,0,2},
//	{INF,INF,5,INF,2,0}
//};
//
//bool visited[6]; // 방문한 노드
//int dist[6]; // 최단 거리
//
//// 가장 최소 거리를 가지는 정점을 반환합니다.
//int getSmallIndex()
//{
//	int min = INF;
//	int index = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (dist[i] < min && !visited[i])
//		{
//			min = dist[i];
//			index = i;
//		}
//	}
//	return index;
//}
//
//// 다익스트라를 수행하는 함수입니다.
//void dijkstra(int start)
//{
//	for (int i = 0; i < n; i++)
//	{
//		dist[i] = arr[start][i];
//	}
//	visited[start] = true;
//	for (int i = 0; i < n - 2; i++)
//	{
//		int current = getSmallIndex();
//		visited[current] = true;
//		for (int j = 0; j < 6; j++)
//		{
//			if (!visited[j])
//			{
//				if (dist[current] + arr[current][j] < dist[j])
//				{
//					dist[j] = dist[current] + arr[current][j];
//				}
//			}
//		}
//	}
//}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}

	arr[1].push_back(make_pair(2, 2));
	arr[1].push_back(make_pair(3, 5));
	arr[1].push_back(make_pair(4, 1));

	arr[2].push_back(make_pair(1, 2));
	arr[2].push_back(make_pair(3, 3));
	arr[2].push_back(make_pair(4, 2));

	arr[3].push_back(make_pair(1, 5));
	arr[3].push_back(make_pair(2, 3));
	arr[3].push_back(make_pair(4, 3));
	arr[3].push_back(make_pair(5, 1));
	arr[3].push_back(make_pair(6, 5));

	arr[4].push_back(make_pair(1, 1));
	arr[4].push_back(make_pair(2, 2));
	arr[4].push_back(make_pair(3, 3));
	arr[4].push_back(make_pair(5, 1));
	
	arr[5].push_back(make_pair(3, 1));
	arr[5].push_back(make_pair(4, 1));
	arr[5].push_back(make_pair(6, 2));

	arr[6].push_back(make_pair(3, 5));
	arr[6].push_back(make_pair(5, 2));

	dijkstra(1);
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << ' ';
	}


	//dijkstra(0);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << dist[i] << ' ';
	//}

	return 0;
}