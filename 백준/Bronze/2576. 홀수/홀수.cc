#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int mn = 101;
	int sum = 0;
	for (int i = 0; i < 7; ++i) {
		int n;
		cin >> n;
		
		if (n % 2 == 1) {
			sum += n;
			if (n < mn)
				mn = n;
		}
	}
	if (sum == 0)
		cout << -1;
	else {
		cout << sum << "\n";
		cout << mn << "\n";
	}
}