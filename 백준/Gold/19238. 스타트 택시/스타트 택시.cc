#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
#define INF 99999999

int n, m, c;
vector<vector<int>> v;

bool Cant = false;
int cnt;

struct Car {
	int y, x;
	int battery = 0;
};

Car car;

struct Passenger {
	int sy, sx;
	int ey, ex;
	bool Finish = false;
};

vector<Passenger> p;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Init() {
	cin >> n >> m >> c;
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1)
				v[i][j] = -1;
		}
	}
	int y, x;
	cin >> y >> x;
	car.y = y-1;
	car.x = x-1;
	car.battery = c;

	p = vector<Passenger>(m + 1);
	for (int i = 1; i <= m; ++i) {
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;
		p[i] = { sy - 1,sx - 1,ey - 1,ex - 1 };
		v[sy - 1][sx - 1] = i;
	}

	cnt = m;
}

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

int FindNearMan() {

	vector<vector<int>> visited(n, vector<int>(n,INF));
	queue<pair<int, int>> q;

	q.push({ car.y,car.x });
	visited[car.y][car.x] = 1;

	// 거리는 전부 구했습니다.
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] != INF || v[ny][nx] == -1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	//PrintV(visited);

	int min_dist = INF;
	int who = 0;
	int r, c;
	r = c = INF;
	for (int i = 1; i <= m; ++i) {
		if (p[i].Finish)
			continue;
		int sy = p[i].sy;
		int sx = p[i].sx;
		int dist = visited[sy][sx] - 1;
		if (min_dist > dist) {
			who = i;
			min_dist = dist;
			r = sy;
			c = sx;
		}
		else if (min_dist == dist) {
			if (sy < r) {
				who = i;
				r = sy;
				c = sx;
			}
			else if (sy == r && sx < c) {
				who = i;
				c = sx;
			}
		}
	}

	if (car.battery < min_dist) {
		return -1;
	}
	else {
		// 갈수있다. 이동시켜버리자.
		car.y = r;
		car.x = c;
		car.battery -= min_dist;
		p[who].Finish = true;
		v[r][c] = 0;
		return who;
	}

	return -1;

	//PrintV(visited);
}

int FindGoal(int who) {

	int ey = p[who].ey;
	int ex = p[who].ex;

	vector<vector<int>> visited(n, vector<int>(n,INF));
	queue<pair<int, int>> q;

	q.push({ car.y,car.x });
	visited[car.y][car.x] = 1;

	// 거리는 전부 구했습니다.
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] != INF || v[ny][nx] == -1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	int dist = visited[ey][ex] - 1;

	if (car.battery < dist) {
		return -1;
	}
	else {
		car.y = ey;
		car.x = ex;
		car.battery -= dist;
		car.battery += (dist * 2);
		return 1;
	}
}

int main(void) {
	Init();

	while (1) {
		int who = FindNearMan();
		if (who == -1) {
			cout << -1 << "\n";
			break;
		}

		int possible = FindGoal(who);
		if (possible == -1) {
			cout << -1 << "\n";
			break;
		}
		else {
			--cnt;
		}


		if (cnt == 0) {
			cout << car.battery << "\n";
			break;
		}
	}

	return 0;

}