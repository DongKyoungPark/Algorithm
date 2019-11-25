// �÷��̵� �ͼ� �˰���
// �ð����⵵ = O(n^3)
// ����������� ����������� �ִ� ��θ� ���ϴ� �˰���
// ���İ��� ������ �������� �˰����� ����
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
	// ��� �׷����� �ʱ�ȭ�մϴ�.
	int d[4][4];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = arr[i][j];
		}
	}

	// k = ���İ��� ���
	for (int k = 0; k < n; k++)
	{
		// i = ��� ���
		for (int i = 0; i < n; i++)
		{
			// j = ���� ���
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// ����� ����մϴ�.
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