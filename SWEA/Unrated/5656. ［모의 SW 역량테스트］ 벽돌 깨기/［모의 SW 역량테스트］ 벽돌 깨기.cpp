#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N, W, H;
vector<vector<int>> v;
vector<vector<bool>> crashed;
int mn = 999999;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV() {
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Crash(int y, int x) {
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(H, vector<bool>(W));
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		auto it = q.front();
		int yy = it.first;
		int xx = it.second;
		int SZ = v[yy][xx] - 1;
		q.pop();

		for (int sz = 1; sz <= SZ; ++sz) {
			for (int i = 0; i < 4; ++i) {
				int ny = yy + dy[i] * sz;
				int nx = xx + dx[i] * sz;
				if (ny < 0 || ny >= H || nx < 0 || nx >= W || v[ny][nx] == 0 || visited[ny][nx])
					continue;
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}
	}
	
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (visited[i][j])
				v[i][j] = 0;
		}
	}

}

void Down() {
	for (int c = 0; c < W; ++c) { // 첫번째 열부터.
		for (int r = H - 1; r >= 0; --r) { // 바닥부터.
			if (v[r][c] != 0) {
				for (int first_z = H - 1; first_z > r; --first_z) {
					if (v[first_z][c] == 0) {
						v[first_z][c] = v[r][c];
						v[r][c] = 0;
						break;
					}
				}
			}
		}
	}
}

void DFS(int depth) {
	if (mn == 0)
		return;
	if (depth == N) {
		int cnt = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (v[i][j])
					++cnt;
			}
		}
		mn = min(mn, cnt);
		return;
	}
	bool flag = false;
	vector<vector<int>> new_v = v; // 원본 다시 저장해두고.
	for (int i = 0; i < W; ++i) {
		for (int j = 0; j < H; ++j) { // 열을 내려보면서
			if (v[j][i] >= 1) {			// 맨위 블럭 발견
				flag = true;
				Crash(j, i);	// 부수기
				Down();			// 내리기
				//PrintV();
				DFS(depth + 1); // 다음 상태 넘어가기.
				break;
			}
		}
		v = new_v; // 원상 복귀
	}

	if (!flag) {
		int cnt = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (v[i][j])
					++cnt;
			}
		}
		mn = min(mn, cnt);
		return ;
	}

}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> W >> H;
		v = vector<vector<int>>(H, vector<int>(W));
		crashed = vector<vector<bool>>(H, vector<bool>(W));
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j)
				cin >> v[i][j];
		}

		DFS(0);
		cout << "#" << tc  << " " << mn << "\n";
		mn = 999999;
	}
}