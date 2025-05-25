#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		for (int j = 0; j < k; ++j) {
			cout << "=";
		}
		cout << "\n";
	}
}