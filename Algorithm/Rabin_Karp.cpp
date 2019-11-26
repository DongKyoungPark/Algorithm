// ��� ī��
// �ð� ���⵵ = O(N)
// �׻� �������� ������ �Ϲ����� ��� ������ �۵��ϴ� ������ ������ ���ڿ� ��Ī �˰���
// ��� ī�� �˰����� �ؽ�(Hash) ����� ���
// �ؽô� �Ϲ������� �� �����͸� �װ��� ��¡�ϴ� ª�� �����ͷ� �ٲپ��ִ� ���
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
				cout << i + 1 << "��°���� �߰��߽��ϴ�." << '\n';
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