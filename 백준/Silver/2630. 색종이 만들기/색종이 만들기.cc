#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N;
vector<vector<int>> v;
int w, b;

void Check(int y_off, int x_off, int sz) {
	bool flag = true;
	int color = v[y_off][x_off];
	for (int i = y_off; i < y_off+sz; ++i) {
		for (int j = x_off; j < x_off+sz; ++j) {
			if (v[i][j] != color) {
				flag = false;
				Check(y_off, x_off, sz / 2);
				Check(y_off + (sz / 2), x_off, sz / 2);
				Check(y_off, x_off + (sz / 2), sz / 2);
				Check(y_off + (sz / 2), x_off + (sz / 2), sz / 2);
				return;
			}
		}
	}

	if (flag) {
		if (color == 1)
			++b;
		else
			++w;
	}
}

int main() {
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}

	Check(0, 0, N);

	cout << w << "\n" << b << "\n";
}  