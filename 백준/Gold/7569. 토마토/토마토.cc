#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H;
int arr[101][101][101];
int visited[101][101][101];
int dy[6] = { -1,0,1,0,0,0 };
int dx[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

struct Point {
	int z, y, x;
};
queue<Point> q;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	
	int cnt = 0;
	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push({ k,i,j });
					visited[k][i][j] = 1;
				}
				else if (arr[k][i][j] == 0)
					++cnt;
			}
		}
	}


	int mx = 0;
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		mx = max(visited[z][y][x], mx);
		for (int d = 0; d < 6; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			int nz = z + dz[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H || visited[nz][ny][nx])
				continue;
			if (arr[nz][ny][nx] == 0) {
				q.push({ nz,ny,nx });
				visited[nz][ny][nx] = visited[z][y][x]+1;
				--cnt;
			}
		}
	}

	if (!cnt)
		cout << mx-1 << "\n";
	else
		cout << -1 << "\n";

}