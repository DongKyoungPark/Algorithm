// 라빈 카프
// 시간 복잡도 = O(N)
// 항상 빠르지는 않지만 일반적인 경우 빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘
// 라빈 카프 알고리즘은 해시(Hash) 기법을 사용
// 해시는 일반적으로 긴 데이터를 그것을 상징하는 짧은 데이터로 바꾸어주는 기법
#include <iostream>

using namespace std;

void findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash = parentHash + parent[patternSize - 1 - j] * power;
				patternHash = patternHash + pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) 
					power = power * 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) +	parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				cout << i + 1 << "번째에서 발견했습니다." << '\n';
			}
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);

	return 0;
}