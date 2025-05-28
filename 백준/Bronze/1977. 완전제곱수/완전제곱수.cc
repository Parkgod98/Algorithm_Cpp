#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	int mn, sum;
	mn = 100000;
	sum = 0;
	for (int i = 1; i <= 100; ++i) {
		int n = i * i;
		if (n >= M && n <= N) {
			sum += n;
			if (n < mn)
				mn = n;
		}
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << mn << "\n";
}