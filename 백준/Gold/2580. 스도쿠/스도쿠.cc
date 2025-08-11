#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(9, vector<int>(9));
vector<pair<int, int>> zero;
bool Finish = false;

vector<int> GetAvailable(int y, int x) {
	vector<int> visited(10);
	for (int i = 0; i < 9; ++i) {
		if (i != x)
			visited[v[y][i]] = 1;
		if (i != y)
			visited[v[i][x]] = 1;
	}
	int yy = y / 3;
	int xx = x / 3;
	for (int i = yy * 3; i < yy * 3 + 3; ++i) {
		for (int j = xx * 3; j < xx * 3 + 3; ++j) {
			if (i != y && j != x) {
				visited[v[i][j]] = 1;
			}
		}
	}
	vector<int> tmp;
	for (int i = 1; i <= 9; ++i) {
		if (!visited[i])
			tmp.push_back(i);
	}
	return tmp;
}

void DFS(int idx) {
	if (Finish)
		return;
	if (idx >= zero.size()) {
		Finish = true;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}

	int sz = zero.size();
	for (int i = idx; i < sz; ++i) {
		auto it = zero[i];
		int y = it.first;
		int x = it.second;
		vector<int> possible = GetAvailable(y, x);
		for (int k = 0; k < possible.size(); ++k) {
			v[y][x] = possible[k];
			DFS(i + 1);
			v[y][x] = 0;
		}
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 0)
				zero.push_back({ i,j });
		}
	}

	DFS(0);
}