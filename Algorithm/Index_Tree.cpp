// �ε��� Ʈ��
// 2�� �ε��� ������ Ȱ���Ͽ� '���� ��' ������ ȿ�������� �ذ��� �� �� �ִ� �ڷ� ����
// ���� Ʈ��(Fenwick Tree)��� �Ҹ��� �ε��� Ʈ���� ���׸�Ʈ Ʈ���� ����� ������ ������ ������ ������ �ſ� �����ϴٴ� Ư¡

#include <iostream>
#define NUMBER 6

using namespace std;

int tree[NUMBER];

int sum(int i) {
	int result = 0;
	while (i > 0) {
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}

void update(int i, int dif) {
	while (i <= NUMBER) {
		tree[i] += dif;
		i += (i & -i);
	}
}

int getSection(int start, int end) {
	return sum(end) - sum(start - 1);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	update(1, 1);
	update(2, 2);
	update(3, 3);
	update(4, 4);
	update(5, 5);
	// 2 ~ 5�� ���� ���� ���մϴ�. 
	cout << getSection(2, 5) << '\n';
	update(3, -2);
	// 2 ~ 5�� ���� ���� ���մϴ�. 
	cout << getSection(2, 5) << '\n';
	update(5, 2);
	// 2 ~ 5�� ���� ���� ���մϴ�. 
	cout << getSection(2, 5) << '\n';
	// 1 ~ 5�� ���� ���� ���մϴ�. 
	cout << getSection(1, 5) << '\n';
	
	return 0;
}