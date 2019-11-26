// �̺� ��Ī
// �ð����⵵ = O(V*E)
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> v[MAX];
int d[MAX];
bool c[MAX];
int n = 3;
int m, s;

// ��Ī�� ������ ��� true, ������ ��� false
bool dfs(int x)
{
	// ����� ��� ��忡 ���ؼ� �� �� �ִ��� �õ�
	for (int i = 0; i < v[x].size(); i++)
	{
		int t = v[x][i];
		// �̹� ó���� ���� ���̻� �� �ʿ䰡 ����
		if (c[t])
			continue;
		c[t] = true;
		// ����ְų� ���� ��忡 �� �� ������ �ִ� ���
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

	// �ִ��� ��� �ֽ��ϴ�.
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i))
			count++;
	}
	cout << count << "���� ��Ī�� �̷�������ϴ�." << '\n';

	for (int i = 1; i <= 100; i++)
	{
		if (d[i] != 0)
			cout << d[i] << " -> " << i << '\n';
	}

	return 0;
}