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
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main(void){
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j)
			v[i][j] = s[j] - '0';
	}

	vector<int> ans;
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = cnt;

				int cur_cnt = 0;
				while (!q.empty()) {
					auto it = q.front();
					q.pop();
					int y = it.first;
					int x = it.second;
					++cur_cnt;

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N || v[ny][nx] == 0 || visited[ny][nx])
							continue;
						q.push({ ny,nx });
						visited[ny][nx] = cnt;
					}
				}
				ans.push_back(cur_cnt);
				++cnt;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt - 1 << "\n";
	for (int &i : ans)
		cout << i << "\n";
}