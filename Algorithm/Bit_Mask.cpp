// 비트 마스크
// 비트(Bit)를 마스킹(Masking)하는 기술
// 메모리를 적게 사용할 수 있습니다.
// 프로그램이 더욱 빠르게 동작합니다.
// 소스 코드가 직관적으로 변경됩니다.

#include <iostream>

using namespace std;

// 2진수 형태로 출력하기 
void show(int* a) {
	for (int i = 32; i > 0; i--) {
		cout << ((*a & (1 << i - 1)) ? 1 : 0);
	}
}

// 모든 원소를 삭제하기 
void init(int* a) {
	*a = 0;
}

// 모든 원소를 포함시키기 
void full(int* a) {
	*a = -1;
}

// 특정 원소를 삭제하기
void drop(int* a, int i) {
	*a &= ~(1 << i);
}

// 특정 원소를 포함시키기
void set(int* a, int i) {
	*a |= (1 << i);
}

// 특정 원소 토글하기
void toggle(int* a, int i) {
	*a ^= (1 << i);
}

// 특정 원소의 포함 여부를 확인하기
bool isSet(int* a, int i) {
	return *a & (1 << i);
}

// 마지막 원소 구하기
int getLast(int* a) {
	return (*a & -*a);
}

// 마지막 원소 삭제하기
void dropLast(int* a) {
	*a &= (*a - 1);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;

	init(&a);
	cout << "모든 원소 삭제: "; show(&a);
	cout << '\n';

	full(&a);
	cout << "모든 원소 포함: "; show(&a);
	cout << '\n';

	drop(&a, 5);
	cout << "5번째 인덱스 삭제: "; show(&a);
	cout << '\n';

	set(&a, 5);
	cout << "5번째 인덱스 포함: "; show(&a);
	cout << '\n';

	cout << "5번째 인덱스 포함 여부: " << isSet(&a, 5);
	cout << '\n';

	toggle(&a, 5);
	cout << "5번째 인덱스 토글: "; show(&a);
	cout << '\n';

	cout << "5번째 인덱스 포함 여부: " << isSet(&a, 5);
	cout << '\n';

	dropLast(&a);
	dropLast(&a);
	dropLast(&a);
	cout << "마지막 원소 3개 삭제: "; show(&a);
	cout << '\n';

	cout << "마지막 원소 구하기: " << getLast(&a);
	cout << '\n';
	
	return 0;
}