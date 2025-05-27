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
		if (i == n) {
			for (int j = 1; j <= 2*n-1; ++j)
				cout << "*";
		}
		else if(i == 1){
			cout << "*";
		}
		else {
			cout << "*";
			for (int j = 0; j < 2 * i - 3; ++j)
				cout << " ";
			cout << "*";
		}
		cout << "\n";
	}
}