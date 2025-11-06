#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	v = vector<pair<int, int>>(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		v[i] = { a * 100 + b, c * 100 + d };
	}
	sort(v.begin(), v.end());


	int cur_end = 301;
	int max_end = 301;

	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		auto it = v[i];
		int start = it.first;
		int end = it.second;

		if (max_end >= 1201)
			break;

		if (start > cur_end) {
			cur_end = max_end;
			++cnt;
		}


		if (start > cur_end)
			break;

		max_end = max(max_end, end);
	}

	if (max_end >= 1201)
		cout << cnt << "\n";
	else
		cout << 0 << "\n";
}