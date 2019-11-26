// ���ڿ� ��Ī �˰���(KMP)
// Ư���� ���� ���� �� �� �ȿ��� �ϳ��� ���ڿ��� ã�� �˰���
#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << i - patternSize + 2 << "��°���� ã�ҽ��ϴ�." << '\n';
				j = table[j];
			}
			else
				j++;
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	KMP(parent, pattern);

	/*vector<int> table = makeTable(pattern);
	for (int i = 0; i < table.size(); i++)
	{
		cout << table[i] << ' ';
	}*/

	return 0;
}

//// �ܼ� ���ڿ� ��Ī �˰���
//int findString(string parent, string pattern)
//{
//	int parentSize = parent.size();
//	int patternSize = pattern.size();
//
//	for (int i = 0; i <= parentSize - patternSize; i++)
//	{
//		bool finded = true;
//		for (int j = 0; j < patternSize; j++)
//		{
//			if (parent[i + j] != pattern[j])
//			{
//				finded = false;
//				break;
//			}
//		}
//		if (finded)
//			return i;
//	}
//	return -1;
//}
//
//int main(void)
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	string parent = "Hello World";
//	string pattern = "llo W";
//	int result = findString(parent, pattern);
//	if (result == -1)
//		cout << "ã�� �� �����ϴ�.";
//	else
//		cout << result + 1 << "��°���� ã�ҽ��ϴ�.";
//
//	return 0;
//}