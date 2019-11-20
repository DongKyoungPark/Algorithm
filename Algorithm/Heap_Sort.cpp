// 힙정렬
// 시간복잡도 = O(N*logN)
// 추가적인 배열이 필요하지 않다는 점에서 메모리 측면에서 효율적
#include <iostream>

using namespace std;

int n = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 먼저 전체 트리 구조를 힙 구조로 바꿉니다.
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

	// 크기를 줄여가며 반복적으로 힙을 구성
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

			// 자식 중에 더 큰 값을 찾기
			if (heap[index] < heap[index + 1] && index < i - 1)
			{
				index++;
			}

			// 루트보다 자식이 더 크다면 교환
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
