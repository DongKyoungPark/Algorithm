// ���� �켱 Ž��(DFS)
// Ž���� �Կ� �־ ���� ���� ���� �켱������ Ž��
// ���� ���
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n = 7;
int checked[7];
vector<int> v[8];

void dfs(int x)
{
	if (checked[x])
		return;

	checked[x] = true;
	cout << x << ' ';
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		dfs(y);
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 1�� 2�� ����
	v[1].push_back(2);
	v[2].push_back(1);

	// 1�� 3�� ����
	v[1].push_back(3);
	v[3].push_back(1);

	// 2�� 3�� ����
	v[2].push_back(3);
	v[3].push_back(2);

	// 2�� 4�� ����
	v[2].push_back(4);
	v[4].push_back(2);

	// 2�� 5�� ����
	v[2].push_back(5);
	v[5].push_back(2);

	// 3�� 6�� ����
	v[3].push_back(6);
	v[6].push_back(3);

	// 3�� 7�� ����
	v[3].push_back(7);
	v[7].push_back(3);

	// 4�� 5�� ����
	v[4].push_back(5);
	v[5].push_back(4);

	// 6�� 7�� ����
	v[6].push_back(7);
	v[7].push_back(6);

	// BFS�� ����
	dfs(1);

	return 0;
}