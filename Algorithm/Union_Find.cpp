// ������ ã��
// ���μ� ���� �˰���
// ���� ���� ��尡 ������ �� �ΰ��� ��带 �����ؼ�, ���� �� �� ��尡 ���� ���� �׷����� ���ϴ��� �Ǻ�
#include <iostream>

using namespace std;

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

	int parent[11];
	for (int i = 1; i <= 10; i++)
	{
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);

	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	cout << "1�� 5�� ����Ǿ��ֳ���?" << '\n' << findParent(parent, 1, 5) << '\n';

	unionParent(parent, 1, 5);
	cout << "1�� 5�� ����Ǿ��ֳ���?" << '\n' << findParent(parent, 1, 5) << '\n';

	return 0;
}