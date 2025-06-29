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
int a, b, c;

void Check(int y_off, int x_off, int SZ) {

	int cur_color = v[y_off][x_off];

	for (int i = y_off; i < y_off + SZ; ++i) {
		for (int j = x_off; j < x_off + SZ; ++j) {
			if (v[i][j] != cur_color) {
				Check(y_off, x_off, SZ / 3);
				Check(y_off+SZ/3, x_off, SZ / 3);
				Check(y_off + 2*(SZ / 3), x_off, SZ / 3);
				Check(y_off, x_off + SZ / 3, SZ / 3);
				Check(y_off, x_off + 2*(SZ / 3), SZ / 3);
				Check(y_off + SZ / 3, x_off + SZ / 3, SZ / 3);
				Check(y_off + 2*(SZ / 3), x_off + SZ / 3, SZ / 3);
				Check(y_off + SZ / 3, x_off + 2*(SZ / 3), SZ / 3);
				Check(y_off+ 2 * (SZ / 3), x_off+ 2 * (SZ / 3), SZ / 3);
				return;
			}
		}
	}
	if (cur_color == -1)
		a++;
	else if (cur_color == 0)
		b++;
	else
		c++;
}


int main() {
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}
	Check(0, 0, N);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
}