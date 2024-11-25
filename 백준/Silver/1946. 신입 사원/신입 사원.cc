#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{

	return a.first < b.first;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int j = 0; j < n; ++j) {
			int a, b;
			cin >> a >> b;
			v[j] = { a,b };
		}

		sort(v.begin(), v.end(), compare);
		
		int standard = v[0].second;
		int cnt = 1;
		for (int j = 1; j < n; ++j) {
			if (standard > v[j].second) {
				cnt++;
				standard = v[j].second;
			}
		}
		cout << cnt << "\n";
	}
}