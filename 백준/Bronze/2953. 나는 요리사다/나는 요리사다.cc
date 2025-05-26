#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int idx, mx;
	idx = mx = 0;
	for (int i = 1; i <= 5; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int score = a + b + c + d;
		if (mx < score) {
			idx = i;
			mx = score;
		}
	}

	cout << idx << " " << mx << "\n";
}