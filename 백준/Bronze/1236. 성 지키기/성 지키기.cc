#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;

	vector<int> row(r), col(c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			char c;
			cin >> c;
			if (c == 'X') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	int r_cnt, c_cnt;
	r_cnt = c_cnt = 0;
	for (int i = 0; i < r; ++i) {
		if (row[i] == 0)
			++r_cnt;
	}
	for (int i = 0; i < c; ++i) {
		if (col[i] == 0)
			++c_cnt;
	}

	cout << max(r_cnt, c_cnt) << "\n";
}