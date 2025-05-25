#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	for (int i = 0; i < 3; ++i) {
		int zero, one;
		zero = one = 0;

		for (int j = 0; j < 4; ++j) {
			int n;
			cin >> n;
			if (n == 0)
				++zero;
			else
				++one;
		}

		switch (one) {
		case 4:
			cout << "E";
			break;
		case 3:
			cout << "A";
			break;
		case 2:
			cout << "B";
			break;
		case 1:
			cout << "C";
			break;
		case 0:
			cout << "D";
			break;
		}
		cout << "\n";
	}
}