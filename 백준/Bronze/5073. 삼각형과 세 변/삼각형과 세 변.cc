#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v(3);
	while (1) {
		for (int i = 0; i < 3; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());

		int a, b, c;
		a = v[0];
		b = v[1];
		c = v[2];

		if (a == 0 && b == 0 && c == 0)
			break;
		if (a + b <= c) {
			cout << "Invalid" << "\n";
		}
		else if (a == b && a == c && b == c) {
			cout << "Equilateral" << "\n";
		}
		else if (a != b && a != c && b != c) {
			cout << "Scalene" << "\n";
		}
		else
			cout << "Isosceles" << "\n";
	}
}