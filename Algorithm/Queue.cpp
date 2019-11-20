// ť
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	queue<int> q;

	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}