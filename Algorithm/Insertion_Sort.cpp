// ��������
// �����Ͱ� �̹� ���� ���ĵ� ���¿��� ���ؼ��� � �˰��򺸴ٵ� �����ٴ� Ư¡
// �ð����⵵ = O(N^2)
// �ð����⵵ ȿ���� = 1. �������� 2. �������� 3. ��������
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