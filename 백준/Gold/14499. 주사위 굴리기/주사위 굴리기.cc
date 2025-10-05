#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int N, M, y, x, K;
vector<vector<int>> v;
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
pair<int, int> top_bottom, left_right, front_rear;
void Change(int dir) {
	if (dir == 1) {
		// left가 top으로 top이 right로 right가 bottom으로 bottom이 left로
		swap(left_right, top_bottom);
		swap(left_right.first, left_right.second);
	}
	else if (dir == 2) {
		swap(left_right, top_bottom);
		swap(top_bottom.first, top_bottom.second);
	}
	else if (dir == 3) {
		swap(top_bottom, front_rear);
		swap(front_rear.first, front_rear.second);
	}
	else if (dir == 4) {
		swap(top_bottom, front_rear);
		swap(top_bottom.first, top_bottom.second);
	}
}
void Move(int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
		return;
	}

	Change(dir);

	if (v[ny][nx] == 0) {
		v[ny][nx] = top_bottom.second;
		y = ny;
		x = nx;
		cout << top_bottom.first << "\n";
	}
	else {
		top_bottom.second = v[ny][nx];
		v[ny][nx] = 0;
		cout << top_bottom.first << "\n";
		y = ny;
		x = nx;
	}
}
int main() {
	cin >> N >> M >> y >> x >> K;
	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}

	top_bottom = left_right = front_rear = { 0,0 };
	for (int i = 0; i < K; ++i) {
		int dir;
		cin >> dir;
		Move(dir);
	}
}