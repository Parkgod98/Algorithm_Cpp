#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
#define INF 999999999
int n;
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[5] = { 0,-1,-1,1,1 };
int dx[5] = { 0,1,-1,-1,1 };
int mn = INF;
int all_sum = 0;

void PrintV(vector<vector<int>> &v) {
	cout << "\n";

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

pair<int, int> FindSharp(int d) {

	if (d == 1) {

		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (visited[i][j] == d) {
					return { i,j };
				}
			}
		}
	}
	else if (d == 2) {
		for (int j = n - 1; j >= 0; --j) {
			for (int i = 0; i < n; ++i)
				if (visited[i][j] == d)
					return { i,j };
		}
	}
	else if (d == 3) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j] == d)
					return { i,j };
			}
		}
	}
	else if (d == 4) {
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
				if (visited[i][j] == d)
					return { i,j };
			}
		}
	}
}
int Calc(vector<vector<int>> t_visited) {
	int s1, s2, s3, s4, s5;
	s1 = s2 = s3 = s4 = s5 = 0;
	pair<int, int> left, right, up, down;
	left = FindSharp(4);
	right = FindSharp(2);
	up = FindSharp(3);
	down = FindSharp(1);

	for (int i = up.first + 1; i <= down.first - 1; ++i) {
		bool Start = false;
		for (int j = 0; j < n; ++j) {
			if (Start && t_visited[i][j])
				break;
			if (Start)
				t_visited[i][j] = 6;
			if (t_visited[i][j] && !Start)
				Start = true;
		}
	}
	//PrintV(t_visited);

	//  y = -1(x-left.first) +left.second -> x + y = left.first + left.second;
	// y = (x-right.first) + right.second -> y - x = right.second - right.first;
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (t_visited[i][j])
				s1 += v[i][j];
			else {
				if (i < left.first && j <= up.second && i + j < (left.first + left.second)) {
					s2 += v[i][j];
				}
				else if (i <= right.first && j > up.second &&  j - i > (right.second - right.first)) {
					//cout << i << " " << j << "\n";
					s3 += v[i][j];
				}
				else if (i >= left.first && j < down.second && j - i  < (left.second - left.first)) {
					//cout << i << " " << j << "\n";

					s4 += v[i][j];
				}
				else if (i > right.first && j >= down.second && i + j  > (right.first + right.second)) {
					s5 += v[i][j];
				}
			}
		}
	}

	//cout << "up : " << up.first << " " << up.second << "\n";
	//cout << "down : " << down.first << " " << down.second << "\n";
	//cout << "left : " << left.first << " " << left.second << "\n";
	//cout << "right : " << right.first << " " << right.second << "\n";

	//cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << "\n";
	int lmn = INF;
	int lmx = 0;
	lmn = min(min(s1, s2), min(min(s3, s4), s5));
	lmx = max(max(s1, s2), max(max(s3, s4), s5));
	//cout << lmx << " "
	//cout << lmx - lmn << "\n";

	return lmx-lmn;
}


void DFS(int y, int x, int dir, int sy, int sx) {

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		return;
	if (visited[ny][nx] && dir == 4 && ny == sy && nx == sx) {
		mn = min(Calc(visited), mn);
		//PrintV(visited);
		return;
	}
	else if (visited[ny][nx] && (ny != sy && nx != sx))
		return;
	

	visited[ny][nx] = dir;
	//PrintV(visited);

	DFS(ny, nx, dir, sy, sx);
	visited[ny][nx] = 0;
	if (dir + 1 != 5) {
		visited[ny][nx] = dir + 1;
		//PrintV(visited);

		DFS(ny, nx, dir + 1, sy, sx);
		visited[ny][nx] = 0;
	}
}


int main() {
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	visited = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			all_sum += v[i][j];
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = 1;
			DFS(i, j, 1,i,j);
			visited[i][j] = 0;
		}
	}

	cout << mn << "\n";
}
