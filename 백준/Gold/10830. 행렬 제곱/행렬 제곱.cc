#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N;
long long B;
vector<vector<int>> v;
vector<vector<int>> Square(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> ret(N, vector<int>(N));
	for (int k = 0; k < N; ++k) {
		for (int c = 0; c < N; ++c) {
			for (int r = 0; r < N; ++r) {
				ret[k][c] += a[k][r] * b[r][c];
			}
			ret[k][c] %= 1000;
		}
	}

	return ret;
}

void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

int main() {
	cin >> N >> B;
	vector<vector<int>> ret;

	v = ret = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
		ret[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) {
			ret = Square(ret, v);
		}
		v = Square(v,v);

		B /= 2;
	}
	PrintV(ret);

}
