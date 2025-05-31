#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(1001, vector<int>(1001));

	for (int i = 1; i <= N; ++i) {
		int col, row;
		cin >> col >> row;

		int width, height;
		cin >> width >> height;
		for (int r = row; r < row + height; ++r)
			for (int c = col; c < col + width; ++c) 
				v[r][c] = i;
	}
	vector<int> v2(N + 1);
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			v2[v[i][j]]++;
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << v2[i] << "\n";
	}
}