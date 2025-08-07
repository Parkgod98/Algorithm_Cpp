#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <cmath>
using namespace std;
#define INF 9999999
int v[10][10] = { 0 };
int visited[10][10] = { 0 };
int mn = INF;
int num[6] = { 0,5,5,5,5,5 };

bool Can(int y, int x, int mode) {
	if(!(((y + mode) <= 10) && ((x + mode) <= 10)))
		return false;

	for (int i = y; i < y + mode; ++i) {
		for (int j = x; j < x + mode; ++j) {
			if (visited[i][j] || v[i][j] == 0)
				return false;
		}
	}
	return true;
}

void Visit(int y, int x, int mode, int value) {
	for (int i = y; i < y + mode; ++i) {
		for (int j = x; j < x + mode; ++j) {
			visited[i][j] = value;
		}
	}
}

bool Check() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (v[i][j] == 1 && !visited[i][j])
				return false;
		}
	}
	return true;
}

void DFS(int depth) {
	if (Check()) {
		mn = min(mn, depth);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {
				for (int mode = 5; mode >= 1; --mode) {
					if (num[mode] > 0 && Can(i, j, mode)) {
						Visit(i, j, mode, 1);
						num[mode]--;
						DFS(depth + 1);
						Visit(i, j, mode, 0);
						num[mode]++;
					}
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j)
			cin >> v[i][j];
	}

	DFS(0);
	if (mn == INF)
		cout << -1 << "\n";
	else
		cout << mn << "\n";
}
