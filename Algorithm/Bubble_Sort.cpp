// 버블 정렬
// 시간복잡도 = O(N^2)
// 가장 비효율적인 정렬
#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int temp;
	int arr[10] = { 2,5,7,6,3,9,8,10,1,4 };

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}