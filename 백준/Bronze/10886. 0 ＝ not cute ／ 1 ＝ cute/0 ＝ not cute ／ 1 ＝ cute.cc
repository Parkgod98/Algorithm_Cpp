#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		if (k == 0)
			k = -1;
		sum += k;
	}
	if (sum > 0)
		cout << "Junhee is cute!" << "\n";
	else
		cout << "Junhee is not cute!" << "\n";
}