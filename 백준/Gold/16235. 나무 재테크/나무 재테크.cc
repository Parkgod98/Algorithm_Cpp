#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
/*
격자는 최대 10x10
바이러스도 그러면 최대 100개
싸이클은 최대 1000번 

초기에는 각 칸에 다 5만큼 양분 들어있음.
매 루프마다 NxN에 양분 더하는 게 생김.
어차피 100*1000이라. 유의미하지 않음.
그 다음부터 m개의 바이러스 정보 들어옴.
입력 ㅂ아ㅣ러스 위치는 모두 다르다고 가정해도 됨.
*/
int n, m, k;
vector<vector<int>> v;
vector<vector<int>> plus_virus;

struct Virus {
	int y, x;
	int age;

	bool operator<(const Virus &other) const {
		return age > other.age;
	}
};
vector<vector<deque<Virus>>> virus_map;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
set<pair<int, int>> virus_location;
vector<Virus> bunsik_virus;

void Eat() {

	bunsik_virus.clear();
	for (auto it = virus_location.begin(); it != virus_location.end();) {
		int y = it->first;
		int x = it->second;

		int sz = virus_map[y][x].size();
		int k = 0;
		int plus_energy = 0;
		for (int i = 0; i < sz; ++i) {
			int age = virus_map[y][x][i].age;
			if (v[y][x] - age >= 0) {
				v[y][x] -= age;
				virus_map[y][x][i].age++;
				if (virus_map[y][x][i].age % 5 == 0)
					bunsik_virus.push_back({ y,x,virus_map[y][x][i].age });
			}
			else {
				k++;
				plus_energy += (virus_map[y][x][i].age / 2);
			}
		}
		v[y][x] += plus_energy;
		for (int j = 0; j < k; ++j)
			virus_map[y][x].pop_back();
		if (virus_map[y][x].size() == 0)
			it = virus_location.erase(it);
		else
			++it;
	}
}

void Bunsik() {

	vector<vector<int>> visited(n, vector<int>(n));
	
	int sz = bunsik_virus.size();
	for (int i = 0; i < sz; ++i) {
		int y = bunsik_virus[i].y;
		int x = bunsik_virus[i].x;

		for (int d = 0; d < 8; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;
			visited[ny][nx]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j]) {
				for (int k = 0; k < visited[i][j]; ++k) {
					virus_map[i][j].push_front({ i,j,1 });
				}
				virus_location.insert({ i,j });
			}
		}
	}
}

void AllPlus() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			v[i][j] += plus_virus[i][j];
	}
}

int CountVirus() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cnt += virus_map[i][j].size();
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;
	v = vector<vector<int>>(n, vector<int>(n, 5));
	plus_virus = vector<vector<int>>(n, vector<int>(n));
	virus_map = vector<vector<deque<Virus>>>(n, vector<deque<Virus>>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> plus_virus[i][j];
	}

	for (int i = 0; i < m; ++i) {
		int r, c, age;
		cin >> r >> c >> age;
		virus_location.insert({ r - 1,c - 1});
		virus_map[r - 1][c - 1].push_back({ r - 1,c - 1,age });
	}

	for (int i = 0; i < k; ++i) {
		Eat();
		Bunsik();
		AllPlus();
	}
	cout << CountVirus() << "\n";
}