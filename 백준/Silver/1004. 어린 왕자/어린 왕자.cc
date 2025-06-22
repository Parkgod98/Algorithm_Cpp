#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int cx, cy, r;

bool In(int x, int y) {

	int distance = pow(x - cx, 2) + pow(y - cy, 2);
	if (distance > r*r)
		return false;
	return true;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> cx >> cy >> r;

			bool imin = In(x1,y1);
			bool yourin = In(x2,y2);

			if ((imin && !yourin) || (!imin && yourin)) {
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
}  