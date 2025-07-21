#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N,dir;
vector<vector<int>> v;
int cnt;

bool Check(int y, int x) {

	return (y >= 1 && y <= N && x >= 1 && x <= N) && v[y][x] != 1;
}

void DFS(int y1, int x1, int y2, int x2, int dir) {
	if (y2 == N && x2 == N) {
		++cnt;
		return;
	}

	if (dir == 0) { // 가로
		if (Check(y1, x1 + 1) && Check(y2,x2+1)) 
			DFS(y1, x1 + 1, y2, x2 + 1, 0);
		if (Check(y1, x1 + 1) && Check(y2 + 1, x2 + 1) && Check(y2+1,x2) && Check(y2,x2+1))
			DFS(y1, x1 + 1, y2 + 1, x2 + 1, 1);
	}
	else if (dir == 1) { // 대각
		if (Check(y1 + 1, x1+1) && Check(y2, x2+1))
			DFS(y1 + 1, x1+1, y2, x2+1, 0);
		if (Check(y1 + 1, x1+1) && Check(y2 + 1, x2))
			DFS(y1 + 1, x1+1, y2 + 1, x2, 2);
		if (Check(y1 + 1, x1+1) && Check(y2 + 1, x2 + 1) && Check(y2 + 1, x2) && Check(y2, x2 + 1))
			DFS(y1 + 1, x1+1, y2 + 1, x2 + 1, 1);
	}
	else { // 세로
		if (Check(y1+1, x1) && Check(y2+1, x2))
			DFS(y1+1, x1, y2+1, x2, 2);
		if (Check(y1+1, x1) && Check(y2 + 1, x2 + 1) && Check(y2 + 1, x2) && Check(y2, x2 + 1))
			DFS(y1+1, x1, y2 + 1, x2 + 1, 1);
	}
}
int main() {
	cin >> N;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> v[i][j];
	}

	DFS(1, 1, 1, 2, dir);

	cout << cnt << "\n";
}