#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int mn_x, mx_x, mn_y, mx_y;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		if (i == 0) {
			mn_x = mx_x = x;
			mn_y = mx_y = y;
		}
		else {
			if (mn_x > x)
				mn_x = x;
			else if (mx_x < x)
				mx_x = x;

			if (mn_y > y)
				mn_y = y;
			else if (mx_y < y)
				mx_y = y;
		}
	}

	int area = (mx_x - mn_x) * (mx_y - mn_y);
	cout << area << "\n";
}