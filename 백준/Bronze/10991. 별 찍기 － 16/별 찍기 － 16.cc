#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j < n; ++j)
			cout << " ";
		for (int j = 0; j < i; ++j) {
			cout << "* ";
		}
		cout << "\n";
	}
}