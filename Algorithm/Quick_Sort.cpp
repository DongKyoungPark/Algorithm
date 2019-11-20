// ������
// �ð����⵵ =	O(N*logN)
// ex) �̹� ������ �Ǿ� �ִ� �־��� ��� O(N^2)
#include <iostream>

using namespace std;

int n = 10;
int sorted[] = { 2,5,7,6,3,9,8,10,1,4 };

void quickSort(int* _data, int _start, int _end)
{
	if (_start >= _end) // ���Ұ� 1���� ���
		return;

	int key = _start; // Ű�� ù��° ����
	int i = _start + 1;
	int j = _end;
	int temp;

	while (i <= j) // ������ ������ �ݺ�
	{
		while (_data[i] <= _data[key] && i <= _end) // Ű ������ ū ���� ���� ������
		{
			i++;
		}
		while (_data[j] >= _data[key] && j > _start) // Ű ������ ���� ���� ���� ������
		{
			j--;
		}
		if (i > j) // ���� ������ ���¸� Ű ���� ��ü
		{
			temp = _data[j];
			_data[j] = _data[key];
			_data[key] = temp;
		}
		else // �������� �ʾҴٸ� i�� j�� ��ü
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