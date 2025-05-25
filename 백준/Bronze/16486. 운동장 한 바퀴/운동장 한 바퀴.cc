#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int d1, d2;
	cin >> d1 >> d2;

	double pi = 3.141592;

	double res = 2 * pi*d2 + 2 * d1;

	cout.precision(6);
	cout << fixed;

	cout << res;
}