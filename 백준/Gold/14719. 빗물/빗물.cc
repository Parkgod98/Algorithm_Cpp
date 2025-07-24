#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int H, W;
vector<vector<int>> v;
int main() {
	cin >> H >> W;

	v = vector<vector<int>>(H, vector<int>(W+2));

	

	for (int i = 1; i <= W; ++i) {
		int n;
		cin >> n;

		for (int j = 0; j < n; ++j) {
			v[H - 1-j][i] = 1;
		}
	}
	for (int i = 0; i < H; ++i) {
		v[i][0] = v[i][1];
		v[i][W + 1] = v[i][W];

	}

	int res = 0;
	for (int i = H - 1; i >= 0; --i) {
		int start, end;
		bool Left, Right;
		Left = Right = false;
		int cnt = 0;
		for (int j = 0; j < W + 2; ++j) {
			if (!Left && v[i][j] == 1) {
				Left = true;
			}
			else if (!Right && v[i][j] == 1) {
				if (Left) {
					res += cnt;
					cnt = 0;
				}
			}
			else if (Left && j !=0 && j!= W+1 && v[i][j] == 0)
				++cnt;
		}
	}

	cout << res << "\n";
}