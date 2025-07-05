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
vector<vector<int>> W;
vector<int> visited;
int mn = 2000000000;
void DFS(int start, int cur, int depth,int cost) {
	if (mn < cost)
		return;
	if (depth == N) {
		mn = min(cost, mn);
		return;
	}

	visited[cur] = 1;
	for (int i = 0; i < N; ++i) {
		if (W[cur][i] != 0) {
			if(!visited[i])
				DFS(start, i, depth + 1, cost + W[cur][i]);
			else if (depth == N - 1 && i == start) {
				DFS(start, i, depth + 1, cost + W[cur][i]);
			}
		}
	}
	visited[cur] = 0;
}


int main() {
	cin >> N;
	W = vector<vector<int>>(N, vector<int>(N));
	visited = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> W[i][j];
	}

	for (int i = 0; i < N; ++i) {
		DFS(i,i,0,0);
	}

	cout << mn << "\n";
}