#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };


vector<vector<char>> init() {
	int N;
	cin >> N;
	vector<vector<char>> v(N, vector<char>(N, 0));
	for(int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < N; ++j)
			v[i][j] = s[j];
	}
	return v;
}

void PrintV(vector<vector<char>>& v) {
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v.size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}


int main(void) {
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case) {
		vector<vector<char>> v = init();
		queue<pair<int, int>> q;
		int N = v.size();
		vector<vector<bool>> visited(N, vector<bool>(N, false));

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(v[i][j] == '.') {
					int cnt = 0;
					for(int k = 0; k < 8; ++k) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if(ny < 0 || nx < 0 || ny >= N || nx >= N)
							continue;
						if(v[ny][nx] == '*')
							++cnt;
					}
					v[i][j] = cnt +'0';
				}
			}
		}
		//PrintV(v);
		int cnt = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(v[i][j] == '0' && !visited[i][j]) {
					++cnt;
					q.push({ i,j });
					while(!q.empty()) {
						auto it = q.front();
						int y = it.first;
						int x = it.second;
						q.pop();
						visited[y][x] = 1;
						for(int k = 0; k < 8; ++k) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if(ny < 0 || nx < 0 || ny >= N || nx >= N || v[ny][nx] == '*')
								continue;
							if(v[ny][nx] == '0' && !visited[ny][nx])
								q.push({ ny,nx });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(v[i][j] != '*' && !visited[i][j])
					++cnt;
			}
		}

		cout << "#" << test_case << " " << cnt << "\n";

	}
}