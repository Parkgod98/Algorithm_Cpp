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

int w, h;
vector<vector<int>> v;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {

	while (1) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			return 0;
		}

		v = vector<vector<int>>(h, vector<int>(w));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cin >> v[i][j];
		}

		vector<vector<int>> visited(h, vector<int>(w));
		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (v[i][j] == 1 && !visited[i][j]) {
					++cnt;
					q.push({ i,j });
					visited[i][j] = 1;

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int i = 0; i < 8; ++i) {
							int ny = y + dy[i];
							int nx = x + dx[i];
							if (ny < 0 || ny >= h || nx < 0 || nx >= w)
								continue;
							if (visited[ny][nx])
								continue;
							if (v[ny][nx] == 1) {
								q.push({ ny,nx });
								visited[ny][nx] = 1;
							}
						}
					}
				}
			}
		}

		cout << cnt << "\n";
	}
}  