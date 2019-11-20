// 삽입정렬
// 데이터가 이미 거의 정렬된 상태에서 한해서는 어떤 알고리즘보다도 빠르다는 특징
// 시간복잡도 = O(N^2)
// 시간복잡도 효율성 = 1. 삽입정렬 2. 선택정렬 3. 버블정렬
#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int index;
	int temp;
	int arr[10] = { 2,5,7,6,3,9,8,10,1,4 };

	for (int i = 0; i < 9; i++)
	{
		index = i;
		while (arr[index] > arr[index + 1])
		{
			temp = arr[index];
			arr[index] = arr[index + 1];
			arr[index + 1] = temp;
			index--;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}