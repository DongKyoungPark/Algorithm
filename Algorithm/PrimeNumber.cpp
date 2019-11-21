// �����佺�׳׽��� ü
// �ð����⵵ = O(N^1/2)
// �Ҽ��� �Ǻ��ϴ� �˰���
#include <iostream>

using namespace std;

int n = 100;
int arr[101];

void primeNumberSieve()
{
	for (int i = 2; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i+i; j <= n; j+=i)
		{
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << ' ';
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	primeNumberSieve();

	return 0;
}