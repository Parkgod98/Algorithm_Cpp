#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	if (T % 10 != 0) {
		cout << -1 << "\n";
	}
	else {
		int a, b, c;
		a = T / 300;
		T %= 300;
		b = T / 60;
		T %= 60;
		c = T / 10;
		
		cout << a << " " << b << " " << c << "\n";
	}
}