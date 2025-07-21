#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N;
#define INF 2000000001
vector<int> v;

int main() {
	cin >> N;

	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	int s = 0;
	int e = N - 1;
	int mn = INF;

	pair<int, int> res;
	while (s < N &&  s < e) {
		int cur = v[s] + v[e];
		if (mn > abs(cur)) {
			mn = abs(cur);
			res.first = v[s];
			res.second = v[e];

			if (mn == 0)
				break;
		}

		if (cur < 0)
			++s;
		else
			e--;
	}
	
	cout << res.first << " " << res.second << "\n";
}
