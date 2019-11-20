// ��������
// �ð����⵵ = O(N*logN)
#include <iostream>

using namespace std;

int n = 10;
int sorted[10]; // ���� �迭�� �ݵ�� ���� ������ ����

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	// ���� ������� �迭�� ����
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
	// ���� �����͵� ����
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
	// ���ĵ� �迭�� ����
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	// ũ�Ⱑ ���� ū���
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