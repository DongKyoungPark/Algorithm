// ���̳��� ���α׷���(DP)
// �ϳ��� ������ �� �ѹ��� Ǯ���� �ϴ� �˰���
// ���̳��� ���α׷����� ������ �����Ͽ� ����� �� �ֽ��ϴ�.
// 1�� ����. ū ������ ���� ������ ���� �� �ֽ��ϴ�.
// 2�� ����. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����մϴ�.
#include <iostream>

using namespace std;

int result[100];

int fibonachi(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;

	//�޸������̼��� ����Ͽ� �̹� ����� ����� �迭�� ����
	if (result[x] != 0)
		return result[x];

	return result[x] = fibonachi(x - 1) + fibonachi(x - 2);
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fibonachi(10);

	return 0;
}