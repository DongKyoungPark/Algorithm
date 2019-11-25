// ���� ���� ���(SCC)
// �ð����⵵ = O(V+E)
// ���� SCC�� ���ϴ� �� ������ ���� ������ ������
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id;
int d[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;

// DFS�� �� ������ ���� ��ŭ ����
int dfs(int x)
{
	d[x] = ++id; // ��帶�� ������ ��ȣ�� �Ҵ�
	s.push(x); // ���ÿ� �ڱ� �ڽ��� ����

	int parent = d[x];
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (d[y] == 0)
			parent = min(parent, dfs(y)); // �湮���� ���� �̿�
		else if	(!finished[y])
			parent = min(parent, d[y]); // ó������ �̿�
	}

	// �θ� ��尡 �ڱ� �ڽ��� ���
	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	// �ڽ��� �θ� ���� ��ȯ�մϴ�.
	return parent;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 11;
	v[1].push_back(2);
	v[2].push_back(3);
	v[3].push_back(1);
	v[4].push_back(2);
	v[4].push_back(5);
	v[5].push_back(7);
	v[6].push_back(5);
	v[7].push_back(6);
	v[8].push_back(5);
	v[8].push_back(9);
	v[9].push_back(10);
	v[10].push_back(11);
	v[11].push_back(3);
	v[11].push_back(8);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
			dfs(i);
	}
	cout << "SCC�� ���� : " << SCC.size() << '\n';

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "��° SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}