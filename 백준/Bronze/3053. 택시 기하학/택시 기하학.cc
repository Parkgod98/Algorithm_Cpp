#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int r;
	cin >> r;

	double pi = 3.14159265358979323846;

	double res1, res2;
	res1 = pi * r*r;
	res2 = r*r + r*r;

	cout.precision(6);
	cout << fixed;

	cout << res1 << "\n" << res2 << "\n";
}