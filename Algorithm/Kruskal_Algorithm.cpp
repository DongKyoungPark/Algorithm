// ũ�罺Į �˰���
// �ּ� ��� ���� Ʈ���� ����� ���� ��ǥ���� �˰���
// ���� ���� ������� ��� ��带 �����ϱ� ���� ����ϴ� �˰���
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x)
{
	// ����Լ� ���� 
	if (parent[x] == x)
		return x;

	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��Ĩ�ϴ�.
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// ���� �θ� �������� Ȯ��
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	return 0;
}


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// ������ ������� �������� ����
	sort(v.begin(), v.end());

	// �� ������ ���Ե� �׷����� ������� ����
	int parent[7];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	// �Ÿ��� ���� 0���� �ʱ�ȭ
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// ������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ�� �߻����� ���� ���� ����
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
		{
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << '\n';

	return 0;
}