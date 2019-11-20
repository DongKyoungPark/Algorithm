// 퀵정렬
// 시간복잡도 =	O(N*logN)
// ex) 이미 정렬이 되어 있는 최악의 경우 O(N^2)
#include <iostream>

using namespace std;

int n = 10;
int sorted[] = { 2,5,7,6,3,9,8,10,1,4 };

void quickSort(int* _data, int _start, int _end)
{
	if (_start >= _end) // 원소가 1개인 경우
		return;

	int key = _start; // 키는 첫번째 원소
	int i = _start + 1;
	int j = _end;
	int temp;

	while (i <= j) // 엇갈릴 때까지 반복
	{
		while (_data[i] <= _data[key] && i <= _end) // 키 값보다 큰 값을 만날 때까지
		{
			i++;
		}
		while (_data[j] >= _data[key] && j > _start) // 키 값보다 작은 값을 만날 때까지
		{
			j--;
		}
		if (i > j) // 현재 엇갈린 상태면 키 값과 교체
		{
			temp = _data[j];
			_data[j] = _data[key];
			_data[key] = temp;
		}
		else // 엇갈리지 않았다면 i와 j를 교체
		{
			temp = _data[i];
			_data[i] = _data[j];
			_data[j] = temp;
		}
	}
	quickSort(_data, _start, j - 1);
	quickSort(_data, j + 1, _end);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	quickSort(sorted, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << sorted[i] << ' ';
	}

	return 0;
}