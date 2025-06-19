#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int main() {
	long long X, Y;
	cin >> X >> Y;

	long long Z = Y * 100 / X;
	long long res = -1;
	if (Z >= 99) {
		res = -1;
	}
	else {
		if (((100 * Y - Z * X - X) % (Z - 99)) == 0) {
			res = ((100 * Y - Z * X - X) / (Z - 99));
		}
		else
			res = ((100 * Y - Z * X - X) / (Z - 99)) + 1;
	}
	cout << res << "\n";
}  