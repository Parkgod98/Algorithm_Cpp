#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		int r_dist1 = (r1 - r2)*(r1 - r2);
		int r_dist2 = (r1 + r2) * (r1 + r2);

		int res = 0;
		if (dist == 0) {
			if (r_dist1 == 0)
				res = -1;
			else
				res = 0;
		}
		else if (dist == r_dist1 || dist == r_dist2) {
			res = 1;
		}
		else if (r_dist1 < dist && dist < r_dist2) {
			res = 2;
		}
		else
			res = 0;

		cout << res << "\n";
	}
}