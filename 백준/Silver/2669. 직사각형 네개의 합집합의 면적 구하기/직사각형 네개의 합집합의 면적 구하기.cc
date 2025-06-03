#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <set>
using namespace std;

int arr[103][103] = { 0 };
int main() {

	for (int i = 0; i < 4; ++i) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for (int c = lx; c < rx; ++c) {
			for (int r = ly; r < ry; ++r) {
				arr[r][c] = 1;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 103; ++i) {
		for (int j = 0; j < 103; ++j) {
			if (arr[i][j])
				++res;
		}
	}
	cout << res << "\n";
}