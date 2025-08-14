#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M, K;
vector<vector<int>> v,visited;
vector<pair<int, int>> used;
struct Micro {
	int y, x;
	int num;
	int dir;
	bool die = false;
};
vector<Micro> micro;
void PrintV(vector<vector<int>> &v) {
	cout << "\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void InitVisited() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			visited[i][j] = 0;
	}
}

void CheckVisited() {
	used.clear();
	int SZ = micro.size();
	for (int i = 1; i < SZ; ++i) {
		if (!micro[i].die) {
			int y = micro[i].y;
			int x = micro[i].x;
			int dir = micro[i].dir;
			//cout << y << " " << x << " " << "\n";
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			//cout << ny << " " << nx << "\n";
			if (visited[ny][nx] == 0)
				used.push_back({ ny,nx });
			visited[ny][nx]++;
		}
	}
	//PrintV(visited);
}

Micro MergeMicro(int y,int x, vector<int> &tmp) {
	int dir = -1;
	int sum_num = 0;
	int SZ = tmp.size();
	int mx = 0;
	int mx_idx = -1;
	int my_dir = -1;
	for (int i = 0; i < SZ; ++i) {
		int num = micro[tmp[i]].num;
		int dir = micro[tmp[i]].dir;
		sum_num += num;
		if (num > mx) {
			mx = num;
			mx_idx = tmp[i];
			my_dir = dir;
		}
		micro[tmp[i]].die = true;
	}

	Micro res = { y,x,sum_num,my_dir };
	return res;
}

void UpdateMicro() {

	for (auto &p : used) {
		int i = p.first;
		int j = p.second;

		if (visited[i][j] >= 2) {

			vector<int> tmp;
			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				if (v[ny][nx]) {
					int idx = v[ny][nx];
					int dir = micro[idx].dir;

					if (ny + dy[dir] == i && nx + dx[dir] == j) {
						tmp.push_back(idx);
						v[ny][nx] = 0;
					}
				}
			}
			Micro new_micro = MergeMicro(i, j, tmp);
			micro[tmp[0]] = new_micro;
		}
		else if (visited[i][j] == 1) {

			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				if (v[ny][nx]) {
					int idx = v[ny][nx];
					int dir = micro[idx].dir;
					if (ny + dy[dir] == i && nx + dx[dir] == j) {
						v[ny][nx] = 0;
						micro[idx].y = i;
						micro[idx].x = j;
						//v[ny][nx] = idx; // 끝나고 한번에 처리해야겠다.
						break;
					}
				}
			}
		}
	}
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			
		}
	}*/
}

void MarkingMicroInMap() {
	int sz = micro.size();
	for (int i = 1; i < sz; ++i) {
		if (!micro[i].die) {
			int y = micro[i].y;
			int x = micro[i].x;
			v[y][x] = i;
		}
	}
}

void MadicineDie() {
	int SZ = micro.size();
	for (int i = 1; i < SZ; ++i) {
		if (!micro[i].die) {
			int y = micro[i].y;
			int x = micro[i].x;
			if (y == 0 || x == 0 || y == N - 1 || x == N - 1) {
				micro[i].num /= 2;
				if (micro[i].dir == 0)
					micro[i].dir = 1;
				else if (micro[i].dir == 1)
					micro[i].dir = 0;
				else if (micro[i].dir == 2)
					micro[i].dir = 3;
				else if (micro[i].dir == 3)
					micro[i].dir = 2;
				if (micro[i].num == 0) {
					micro[i].die = true;
				}
			}
		}
	}
}

int CheckSum() {
	int sum = 0;
	int sz = micro.size();
	for (int i = 1; i < sz; ++i) {
		if (!micro[i].die) {
			sum += micro[i].num;
		}
	}
	return sum;
}


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K;
		v = vector<vector<int>>(N, vector<int>(N));
		visited = vector<vector<int>>(N, vector<int>(N));
		micro = vector<Micro>(K+1);
		for (int i = 1; i <= K; ++i) {
			int y, x, num, dir;
			cin >> y >> x >> num >> dir;
			micro[i] = { y,x,num,dir-1 };
			v[y][x] = i; //맵에 해당 micro의 index를 기록. // 바로 접근 가능.
		}

		int time = 1;
		while (time <= M) {
			//PrintV(v);
			InitVisited();
			CheckVisited();
			UpdateMicro();
			MarkingMicroInMap();
			MadicineDie();
			//PrintV(v);
			++time;
		}

		cout << "#" << tc << " " << CheckSum() << "\n";
	}
}


