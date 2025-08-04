#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define APPLE 1

int N,K;
int L;
vector<vector<int>> v;
bool Finish = false;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct Snake {
	deque<pair<int, int>> body;
	int dir = 0;
	int head = 0;
	int tail = 0;
};
Snake s;


void StretchHead() {
	int ny = s.body.front().first + dy[s.dir];
	int nx = s.body.front().second + dx[s.dir];
	if (ny < 0 || ny >= N || nx < 0 || nx >= N) { // 벽에 부딪히거나
		// 게임 종료 시키기.
		Finish = true;
		return;
	}
	for (int i = 0; i < s.body.size(); ++i) { // 몸과 부딪히면
		if (ny == s.body[i].first && nx == s.body[i].second) {
			//게임 종료 시키기.
			Finish = true;
			return;
		}
	}
	/*벽, 몸과 부딪히지 않았으니*/
	if (v[ny][nx] == 1) {
		v[ny][nx] = 0;
		s.body.push_front({ ny,nx });
	}
	else {
		s.body.pop_back();
		s.body.push_front({ ny,nx });
	}
}

int main() {
	cin >> N;
	cin >> K;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		v[r-1][c-1] = APPLE;
	}

	cin >> L;
	vector<pair<int, char>> convert(L);
	for (int i = 0; i < L; ++i) {
		int X;
		char C;
		cin >> X >> C;
		convert[i] = { X,C };
	}

	s.body.push_back({ 0,0 });
	int idx = 0;
	int time = 0;
	while (1) {
		StretchHead();
		time++;
		if (Finish)
			break;
		if (idx < L && convert[idx].first == time) {
			if (convert[idx].second == 'D') {
				s.dir = (s.dir + 1) % 4;
			}
			else {
				s.dir = (s.dir + 3) % 4;
			}
			idx++;
		}
	}
	cout << time << "\n";
}