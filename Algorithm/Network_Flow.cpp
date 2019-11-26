// ��Ʈ��ũ �÷ο�
// �ð����⵵ = O(VE^2)
// Ư���� �������� �ٸ� �������� �����Ͱ� �󸶳� ���� �帣�� �ִ°��� �����ϴ� �˰���
// EX) ����ü��, ��Ʈ��ũ ������ ���� ���� �پ��� �о߿� Ȱ��
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
				// �湮���� ���� ��� �߿� �뷮�� �������
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)
				{
					q.push(y);
					d[y] = x; // ��θ� ���
					if (y == end)
						break; // �������� ������ ���
				}
			}
		}
		if (d[end] == -1)
			break; // ��� ��θ� ã�� �ڿ� Ż��
		int flow = INF;

		// �Ųٷ� �ּ� ���� Ž��		
		for (int i = end; i != start; i = d[i]) 
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		// �ּ� ������ŭ �߰��Ѵ�.
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