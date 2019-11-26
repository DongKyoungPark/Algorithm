// �ּ� ���� ����(LCA)
// Ʈ�� �������� Ư���� �� ����� ����� ���� �߿��� ���� ��¥�� ������ �ǹ�

#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11 // ��ü ����� ������ 2^10�� �����Դϴ�. 

using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

// �ٷ� �� �θ�� �����ϴ� �Լ��Դϴ�. 
void dfs(int x, int depth) {
	c[x] = true;
	d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
	}
}

// ��ü �θ� ���踦 �����ϴ� �Լ��Դϴ�. 
void setParent() {
	dfs(0, 0); // ��Ʈ�� 0���� �����մϴ�. 
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

// �ּ� ���� ������ ã�� �Լ��Դϴ�.
int LCA(int x, int y) {
	// y�� �� ���� �����մϴ�. 
	if (d[x] > d[y]) {
		swap(x, y);
	}
	// �� ����� ���̸� �����ϵ��� ����ϴ�. 
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}
	// �θ� ���� ��� ��ȯ�մϴ�. 
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		// ������ ���� �Ž��� �ö󰩴ϴ�. 
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	// �ٷ� �θ� ã���� �ϴ� �����Դϴ�. 
	return parent[x][0];
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	n = 21;
	// 0�� 1�� �����մϴ�.
	a[0].push_back(1);
	a[1].push_back(0);
	// 0�� 2�� �����մϴ�.
	a[0].push_back(2);
	a[2].push_back(0);
	// 1�� 3�� �����մϴ�.
	a[1].push_back(3);
	a[3].push_back(1);
	// 1�� 4�� �����մϴ�.
	a[1].push_back(4);
	a[4].push_back(1);
	// 2�� 5�� �����մϴ�.
	a[2].push_back(5);
	a[5].push_back(2);
	// 2�� 6�� �����մϴ�.
	a[2].push_back(6);
	a[6].push_back(2);
	// 3�� 7�� �����մϴ�.
	a[3].push_back(7);
	a[7].push_back(3);
	// 3�� 8�� �����մϴ�.
	a[3].push_back(8);
	a[8].push_back(3);
	// 4�� 9�� �����մϴ�.
	a[4].push_back(9);
	a[9].push_back(4);
	// 4�� 10�� �����մϴ�.
	a[4].push_back(10);
	a[10].push_back(4);
	// 4�� 11�� �����մϴ�.
	a[4].push_back(11);
	a[11].push_back(4);
	// 8�� 12�� �����մϴ�.
	a[8].push_back(12);
	a[12].push_back(8);
	// 8�� 13�� �����մϴ�.
	a[8].push_back(13);
	a[13].push_back(8);
	// 9�� 14�� �����մϴ�.
	a[9].push_back(14);
	a[14].push_back(9);
	// 10�� 15�� �����մϴ�.
	a[10].push_back(15);
	a[15].push_back(10);
	// 13�� 16�� �����մϴ�.
	a[13].push_back(16);
	a[16].push_back(13);
	// 13�� 17�� �����մϴ�.
	a[13].push_back(17);
	a[17].push_back(13);
	// 14�� 18�� �����մϴ�.
	a[14].push_back(18);
	a[18].push_back(14);
	// 15�� 19�� �����մϴ�.
	a[15].push_back(19);
	a[19].push_back(15);
	// 17�� 20�� �����մϴ�.
	a[17].push_back(20);
	a[20].push_back(17);
	setParent();
	cout << "5�� 7�� LCA: " << LCA(5, 7) << '\n';
	cout << "15�� 20�� LCA: " << LCA(15, 20) << '\n';
	cout << "16�� 17�� LCA: " << LCA(16, 17) << '\n';
	cout << "10�� 9�� LCA: " << LCA(10, 9) << '\n';
	cout << "3�� 17�� LCA: " << LCA(3, 17) << '\n';

	return 0;
}