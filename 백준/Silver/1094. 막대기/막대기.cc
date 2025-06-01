#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	int X;
	cin >> X;

	int cnt = 0;
	while (X != 0) {
		if (X % 2 == 1)
			++cnt;
		X /= 2;
	}
	cout << cnt;
}