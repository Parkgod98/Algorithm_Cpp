#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int h, m, h1, m1;
		cin >> h >> m >> h1 >> m1;

		int m2 = m + m1;
		int h2 = (h + h1 + m2 / 60);
		m2 %= 60;
		if (h2 % 12 == 0)
			h2 = 12;
		else
			h2 %= 12;
		cout << "#" << tc << " " << h2 << " " << m2 << "\n";
	}
}