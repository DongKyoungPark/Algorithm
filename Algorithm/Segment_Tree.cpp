// ���׸�Ʈ Ʈ��
// �ð����⵵ = O(logN)
// ���� ���� �����Ͱ� ���������� ������ �� Ư���� ������ �������� ���� ���ϴ� ���
#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = { 1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5 };
int tree[4 * NUMBER]; // 4�� ���ϸ� ��� ������ Ŀ���� �� ����. ������ ���ؼ� 2�� ���� ������ ���̸� ������ ������. 

// start: ���� �ε���, end: �� �ε��� 
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// ��������� �� �κ����� ���� �ڿ� �� ���� �ڱ� �ڽ����� �մϴ�. 
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start: ���� �ε���, end: �� �ε���
// left, right: ���� ���� ���ϰ��� �ϴ� ���� 
int sum(int start, int end, int node, int left, int right) {
	// ���� �ۿ� �ִ� ���
	if (left > end || right < start) return 0;
	// ���� �ȿ� �ִ� ���
	if (left <= start && end <= right) return tree[node];
	// �׷��� �ʴٸ� �� �κ����� ������ ���� ���ϱ�
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start: ���� �ε���, end: �� �ε���
// index: ���� ���� �����ϰ��� �ϴ� ���
// dif: ������ �� 
void update(int start, int end, int node, int index, int dif) {
	// ���� �ۿ� �ִ� ��� 
	if (index < start || index > end) return;
	// ���� �ȿ� ������ �������� �ٸ� ���ҵ� ���� 
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// ���� �� Ʈ���� �ε����� �����ϰ�� ��� �ε��� 0���� �����մϴ�.
	// ���� �� Ʈ�� �����ϱ� 
	init(0, NUMBER - 1, 1);
	// ���� �� ���ϱ� 
	cout << "0���� 12������ ���� ��: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
	// ���� �� ���ϱ� 
	cout << "3���� 8������ ���� ��: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
	// ���� �� �����ϱ�
	cout << "�ε��� 5�� ���Ҹ� -5��ŭ ����" << '\n';
	update(0, NUMBER - 1, 1, 5, -5);
	// ���� �� �ٽ� ���ϱ� 
	cout << "3���� 8������ ���� ��: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';

	return 0;
}
