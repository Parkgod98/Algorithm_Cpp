#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<char>> v(8, vector<char>(8));

	int res = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> v[i][j];
			if (i % 2 == 0) {
				if (j % 2 == 0 && v[i][j] == 'F')
					++res;
			}
			else {
				if (j % 2 == 1 && v[i][j] == 'F')
					++res;
			}
		}
	}

	cout << res << "\n";
}