// ������
// �ð����⵵ = O(N*logN)
// �߰����� �迭�� �ʿ����� �ʴٴ� ������ �޸� ���鿡�� ȿ����
#include <iostream>

using namespace std;

int n = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// ���� ��ü Ʈ�� ������ �� ������ �ٲߴϴ�.
	for (int i = 0; i < n; i++)
	{
		int index = i;
		do
		{
			int root = (index - 1) / 2;
			if (heap[root] < heap[index])
			{
				int temp = heap[root];
				heap[root] = heap[index];
				heap[index] = temp;
			}
			index = root;
		} while (index != 0);
	}

	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int index = 1;
		do
		{
			index = 2 * root + 1;

			// �ڽ� �߿� �� ū ���� ã��
			if (heap[index] < heap[index + 1] && index < i - 1)
			{
				index++;
			}

			// ��Ʈ���� �ڽ��� �� ũ�ٸ� ��ȯ
			if (heap[root] < heap[index] && index < i)
			{
				int temp = heap[root];
				heap[root] = heap[index];
				heap[index] = temp;
			}
			root = index;
		} while (index < i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << heap[i] << ' ';
	}

	return 0;
}
