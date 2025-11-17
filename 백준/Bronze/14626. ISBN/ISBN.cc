#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int start = 1;
	int tar = -1;
	int m = (s[s.size() - 1] - '0');

	int sum = 0;
	for (int i = 0; i < 12; ++i) {
		if (s[i] == '*') {
			tar = start;
		}
		else
			sum += (start * (s[i] - '0'));
		if (start == 1)
			start = 3;
		else
			start = 1;
	}

	
	for (int i = 0; i <= 9; ++i) {
		if ((sum + i * tar + m) % 10 == 0 ) {
			cout << i << "\n";
			return 0;
		}
	}
}