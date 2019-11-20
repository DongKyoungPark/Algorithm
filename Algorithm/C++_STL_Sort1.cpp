#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector < pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("박동경0", make_pair(90, 19880304)));
	v.push_back(pair<string, pair<int, int>>("박동경1", make_pair(97, 19880305)));
	v.push_back(pair<string, pair<int, int>>("박동경2", make_pair(95, 19880306)));
	v.push_back(pair<string, pair<int, int>>("박동경3", make_pair(90, 19880307)));
	v.push_back(pair<string, pair<int, int>>("박동경4", make_pair(88, 19880308)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << ' ';
	}

	return 0;
}