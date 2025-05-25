#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int a1, a2, a3, c1, c2, c3;

	cin >> a1 >> a2 >> a3 >> c1 >> c2 >> c3;

	int r1, r2, r3;

	r1 = c1 - a3;
	r2 = c2 / a2;
	r3 = c3 - a1;

	cout << r1 << " " << r2 << " " << r3 << "\n";
}