#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	string N;
	cin >> N;

	int limit = N.size();

	if (limit == 1) {
		cout << "NO" << "\n";
	}
	else {
		for (int i = 0; i < limit; ++i) {
			int left_side = 1;

			for (int j = 0; j <= i; ++j) {
				left_side *= (N[j]-'0');
			}

			int right_side = 1;
			for (int j = i + 1; j < limit; ++j)
				right_side *= (N[j] - '0');

			if (left_side == right_side) {
				cout << "YES" << "\n"; 
				return 0;
			}
		}
		cout << "NO" << "\n";
	}

}