#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {

	int sum = 0;
	bool sequence = true;
	for (int i = 0; i < 10; ++i) {
		int n;
		cin >> n;

		if (sequence && abs(sum - 100) >= abs(sum + n - 100)) {
			sum += n;
		}
		else
			sequence = false;
	}
	cout << sum << "\n";
}