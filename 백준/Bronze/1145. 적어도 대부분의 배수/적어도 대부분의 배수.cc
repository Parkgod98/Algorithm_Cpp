#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int GetGCD(int a, int b) {

	while (a%b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int GetLCM(int a, int b) {
	int gcd = GetGCD(a, b);

	return a * b / gcd;
}

int main() {
	vector<int> v(5);
	for (int i = 0; i < 5; ++i) {
		cin >> v[i];
	}

	int mn = v[0] * v[1] * v[2] * v[3];
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				int lcm = GetLCM(GetLCM(v[i], v[j]), v[k]);
				if (mn > lcm)
					mn = lcm;
			}
		}
	}
	cout << mn << "\n";
}