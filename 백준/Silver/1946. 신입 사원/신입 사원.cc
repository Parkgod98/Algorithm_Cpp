#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			v[i] = { a,b };
		}
		
		sort(v.begin(), v.end());
		int mx = 1;
		int cur = v[0].second;
		for (int i = 1; i < N; ++i) {
			if (v[i].second < cur) {
				++mx;
				cur = v[i].second;
			}
		}
		cout << mx << "\n";
	}
}