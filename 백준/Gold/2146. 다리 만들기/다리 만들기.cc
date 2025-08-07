#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0};
int dx[4] = { 0,1,0,-1};

int n;
vector<vector<int>> v;
vector<vector<bool>> visited;

//void PrintV(vector<vector<int>>& v) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j)
//			cout << v[i][j] << " ";
//		cout << "\n";
//	}
//}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<vector<bool>>(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}

	vector<vector<pair<int, int>>> island;
	queue<pair<int, int>> q;
	int s = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {
				vector<pair<int, int>> tmp;
				island.push_back(tmp);
				s++;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();
					island[s].push_back({ it.first,it.second });
					for (int k = 0; k < 4; ++k) {
						int ny = it.first + dy[k];
						int nx = it.second + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || v[ny][nx] == 0)
							continue;
						q.push({ ny,nx });
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	//cout << "\n" << island.size() << "\n";
	int mn = n * n;
	for (int i = 0; i < island.size(); ++i) {
		for (int j = i+1; j < island.size(); ++j) {
			for (auto& p1 : island[i]) {
				for (auto& p2 : island[j]) {
					int dist = abs(abs(p1.first - p2.first ) + abs(p1.second - p2.second));
					//if (dist < mn) {
					//	cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
					//}
					mn = min(dist, mn);
				}
			}
		}
	}

	cout << mn -1;
}