// ���ͽ�Ʈ�� �˰���
// �ִ� ��� Ž�� �˰���
// ���ͽ�Ʈ��� ���� ���迡 ����ϱ� �ſ� ������ �˰���
// �ϳ��� �ִ� �Ÿ��� ���� �� �� �������� ���ߴ� �ִ� �Ÿ� ������ �״�� ���
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 6;
int INF = 1000000000;

vector<pair<int, int>> arr[7]; // ��������
int dist[7]; // �ּҺ��

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; // �� ����
	pq.push(make_pair(start, 0));
	// ����� ������� ó���ϹǷ� ť�� ���
	while (!pq.empty())
	{
		int current = pq.top().first;
		// ª�� ���� ���� ������ ����ȭ(-) �մϴ�.
		int distance = -pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ�մϴ�.
		if (dist[current] < distance)
			continue;
		for (int i = 0; i < arr[current].size(); i++)
		{
			// ���õ� ����� ���� ���
			int next = arr[current][i].first;
			// ���õ� ��� ���ļ� ���� ���� ���� ���
			int nextDistance = distance + arr[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü �մϴ�.
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

//
//// ��ü �׷����� �ʱ�ȭ �մϴ�.
//int arr[6][6] = {
//	{0,2,5,1,INF,INF},
//	{2,0,3,2,INF,INF},
//	{5,3,0,3,1,5},
//	{1,2,3,0,1,INF},
//	{INF,INF,1,1,0,2},
//	{INF,INF,5,INF,2,0}
//};
//
//bool visited[6]; // �湮�� ���
//int dist[6]; // �ִ� �Ÿ�
//
//// ���� �ּ� �Ÿ��� ������ ������ ��ȯ�մϴ�.
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
//// ���ͽ�Ʈ�� �����ϴ� �Լ��Դϴ�.
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