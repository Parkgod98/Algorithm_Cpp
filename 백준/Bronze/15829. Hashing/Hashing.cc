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

	long long r = 31;
	for (int i = 0; i < L; ++i) {
		char c;
		cin >> c;
		long long n = (c - 'a' + 1);
		for (int j = 0; j < i; ++j) {
			n = (n *r)%1234567891;
		}
		res = (res+ n)%1234567891;
	}

	cout << res << "\n";
}