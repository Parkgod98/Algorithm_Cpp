#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L;
	cin >> L;

	long long res = 0;

	long long w = 1;
	long long r = 31;
	for (int i = 0; i < L; ++i) {
		char c;
		cin >> c;
		int n = (res + (c - 'a' + 1)*w);
		res = (res + (c-'a' + 1)*w) % 1234567891;
		w *= r;
	}

	cout << res << "\n";
}