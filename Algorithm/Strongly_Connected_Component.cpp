// 강한 결합 요소(SCC)
// 시간복잡도 = O(V+E)
// 같은 SCC에 속하는 두 정점은 서로 도달이 가능함
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

// DFS는 총 정점의 갯수 만큼 실행
int dfs(int x)
{
	d[x] = ++id; // 노드마다 고유한 번호를 할당
	s.push(x); // 스택에 자기 자신을 삽입

	int parent = d[x];
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (d[y] == 0)
			parent = min(parent, dfs(y)); // 방문하지 않은 이웃
		else if	(!finished[y])
			parent = min(parent, d[y]); // 처리중인 이웃
	}

	// 부모 노드가 자기 자신인 경우
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
	// 자신의 부모 값을 반환합니다.
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
	cout << "SCC의 갯수 : " << SCC.size() << '\n';

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "번째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}