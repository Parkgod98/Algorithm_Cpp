#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dz[2] = { 1, - 1 };
int r, c,h;

void PrintV(vector<vector<vector<int>>> &v) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				cout << v[i][j][k] << " ";
			}
			cout << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> r >> h;
	vector<vector<vector<int>>> v(h, vector<vector<int>>(r, vector<int>(c, 0)));
	vector<vector<vector<int>>> visited(h, vector<vector<int>>(r, vector<int>(c, 0)));
	queue<vector<int>> q;

	int total_tomato = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				cin >> v[i][j][k]; 
				if (v[i][j][k] == 1) {
					q.push({ i,j,k });
					visited[i][j][k] = 1;
				}
				else if (v[i][j][k] == 0)
					total_tomato++;
				
			}
		}
	}

	int days = 0;
	while (!q.empty()) {
		vector<int> tmp = q.front();
		q.pop();
		int z, y, x;
		z = tmp[0];
		y = tmp[1];
		x = tmp[2];

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[z][ny][nx] || v[z][ny][nx] == -1)
				continue;
			q.push({ z,ny,nx });
			visited[z][ny][nx] = visited[z][y][x] + 1;
			total_tomato--;
		}
		for (int i = 0; i < 2; ++i) {
			int nz = z + dz[i];
			if (nz < 0 || nz >= h || visited[nz][y][x] || v[nz][y][x] == -1)
				continue;
			q.push({ nz,y,x });
			visited[nz][y][x] = visited[z][y][x] + 1;
			total_tomato--;
		}
		days = visited[z][y][x];
	}

	if (total_tomato > 0)
		cout << -1 << "\n";
	else {
		cout << days-1 << "\n";
	}
}