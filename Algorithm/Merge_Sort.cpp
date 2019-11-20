// 병합정렬
// 시간복잡도 = O(N*logN)
#include <iostream>

using namespace std;

int n = 10;
int sorted[10]; // 정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	// 작은 순서대로 배열에 삽입
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	// 크기가 보다 큰경우
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[10] = { 2,5,7,6,3,9,8,10,1,4 };
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}