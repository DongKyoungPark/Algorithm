// ��������(TS)
// ������ �������ִ� �۾��� ���ʷ� �����ؾ� �Ҷ� �� ������ �������ֱ� ���� ����ϴ� �˰���
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

	// ���� ������ 0�� ��带 ť�� ����
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	// ���� ������ ������ ����Ƿ��� ��Ȯ�� N���� ��带 �湮
	for (int i = 1; i <= n; i++)
	{
		// n���� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �߻��� ���Դϴ�.
		if (q.empty())
		{
			cout << "����Ŭ�� �߻��߽��ϴ�";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			// ���Ӱ� ���������� 0�� �� ������ ť�� �����մϴ�.
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