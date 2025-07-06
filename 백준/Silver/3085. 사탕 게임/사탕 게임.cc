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
vector<vector<char>> v;

int Check() {
	int mx_len = 0;
	for (int i = 0; i < N; ++i) {
		int len = 1;
		for (int j = 0; j < N-1; ++j) {
			if (v[i][j] == v[i][j + 1]) {
				len++;
			}
			else
				len = 1;
			mx_len = max(len, mx_len);
		}
		
		if (mx_len == N)
			return N;
	}

	for (int j = 0; j < N; ++j) {
		int len = 1;
		for (int i = 0; i < N - 1; ++i) {
			if (v[i][j] == v[i+1][j]) {
				len++;
			}
			else
				len = 1;
			mx_len = max(len, mx_len);
		}
		if (mx_len == N)
			return N;
	}

	return mx_len;
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	v = vector<vector<char>>(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}


	int mx = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N-1; ++j) {
			if (v[i][j] != v[i][j + 1]) {
				swap(v[i][j], v[i][j + 1]);
				mx = max(mx,Check());
				swap(v[i][j], v[i][j + 1]);
			}
			if (v[j][i] != v[j+1][i]) {
				swap(v[j][i], v[j+1][i]);
				mx = max(mx, Check());
				swap(v[j][i], v[j+1][i]);
			}
			if (mx == N)
				break;
		}
		if (mx == N)
			break;
	}

	cout << mx << "\n";
}