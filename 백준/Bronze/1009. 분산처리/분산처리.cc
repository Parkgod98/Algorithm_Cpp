#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		int a, b;
		cin >> a >> b;

		int start = 1;
		for (int j = 0; j < b; ++j) {
			start *= a;
			start %= 10;
		}
		if (start == 0)
			cout << 10;
		else
			cout << start;
		cout << "\n";
	}
}