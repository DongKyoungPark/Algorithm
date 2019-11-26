// 인덱스 트리
// 2진 인덱스 구조를 활용하여 '구간 합' 문제를 효과적으로 해결해 줄 수 있는 자료 구조
// 펜윅 트리(Fenwick Tree)라고도 불리는 인덱스 트리는 세그먼트 트리와 비슷한 성능을 가지고 있지만 구현이 매우 간단하다는 특징

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
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	update(3, -2);
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	update(5, 2);
	// 2 ~ 5의 구간 합을 구합니다. 
	cout << getSection(2, 5) << '\n';
	// 1 ~ 5의 구간 합을 구합니다. 
	cout << getSection(1, 5) << '\n';
	
	return 0;
}