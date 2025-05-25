#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int a_plus_b, a_minus_b;
	cin >> a_plus_b >> a_minus_b;
	
	int a = (a_plus_b + a_minus_b) / 2;
	int b = (a_plus_b - a_minus_b) / 2;

	if ((a_plus_b + a_minus_b) % 2 == 1 || b < 0) {
		cout << -1;
		return 0;
	}

	if (((a + b) != a_plus_b) || ((a - b) != a_minus_b)) {
		cout << -1;
	}
	else {
		if (a < b)
			swap(a, b);
		cout << a << " " << b << "\n";
	}
}