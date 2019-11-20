// 선택 정렬
// 시간복잡도 = O(N^2)
#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int index, temp;
	int arr[10] = { 6,9,1,3,4,7,8,2,5,10 };

	for (int i = 0; i < 10; i++)
	{
		int min = 9999;
		for (int j = i; j < 10; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}