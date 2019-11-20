// 합집합 찾기
// 서로소 집합 알고리즘
// 여러 개의 노드가 존재할 때 두개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별
#include <iostream>

using namespace std;

// 부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
	// 재귀함수 종료 
	if (parent[x] == x)
		return x;

	return parent[x] = getParent(parent, parent[x]);
}

// 각 부모 노드를 합칩니다.
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// 같은 부모를 가지는지 확인
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
	cout << "1과 5는 연결되어있나요?" << '\n' << findParent(parent, 1, 5) << '\n';

	unionParent(parent, 1, 5);
	cout << "1과 5는 연결되어있나요?" << '\n' << findParent(parent, 1, 5) << '\n';

	return 0;
}