// Ω∫≈√
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();

	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}