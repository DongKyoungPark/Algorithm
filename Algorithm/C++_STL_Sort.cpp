#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a < b; // ��������
	// return a > b; // ��������
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a[10] = { 2,5,7,6,3,9,8,10,1,4 };

	sort(a, a + 10, compare);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}

	return 0;
}