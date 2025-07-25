#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N;
typedef long long ll;
double Area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	double ans = 0;

	ans = 0.5*((x1*y2 + x2 * y3 + x3*y1) - (x3*y2  +x2 * y1 +x1*y3));

	return ans;
}

int main() {
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	double ans = 0;
	for (int i = 1; i < N -1 ; ++i) {
		ans += Area(v[0].first, v[0].second, v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	}
	cout << fixed;
	cout.precision(1);

	cout << abs(ans) << "\n";
}