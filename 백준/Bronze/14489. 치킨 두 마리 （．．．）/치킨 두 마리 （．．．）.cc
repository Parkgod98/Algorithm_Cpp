#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b >= 2*c) {
		cout << a + b - 2*c;
	}
	else
		cout << a + b;
}