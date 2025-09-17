#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int n, m, k;
vector<vector<int>> v;

// m 질, s 속, d 방향
struct Atom {
	int y, x, m, s, d;
};
vector<Atom> atom;

void Move() {
	int sz = atom.size();
	for (int i = 0; i < sz; ++i) {
		int y = atom[i].y;
		int x = atom[i].x;
		int s = atom[i].s;
		int d = atom[i].d;
		int ny = y + dy[d] * s;
		int nx = x + dx[d] * s;

		ny = ((abs(ny / n) + 1)*n + ny) % n;
		nx = ((abs(nx / n) + 1)*n + nx) % n;
		atom[i].y = ny;
		atom[i].x = nx;
	}
}

void Combine() {
	vector<vector<vector<Atom>>> visited(n, vector<vector<Atom>>(n));

	int sz = atom.size();
	for (int i = 0; i < sz; ++i) {
		int y = atom[i].y;
		int x = atom[i].x;
		visited[y][x].push_back(atom[i]);
	}

	vector<Atom> new_atom;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int sz = visited[i][j].size();
			if (sz >= 2) {

				int sum_m, sum_s;
				sum_m = sum_s = 0;
				bool Only_angle, Only_Diagonal;
				Only_angle = Only_Diagonal = true;
				for (auto &it : visited[i][j]) {
					sum_m += it.m;
					sum_s += it.s;
					if (it.d == 0 || it.d == 2 || it.d == 4 || it.d == 6)
						Only_Diagonal = false;
					else if (it.d == 1 || it.d == 3 || it.d == 5 || it.d == 7)
						Only_angle = false;
				}

				int m = sum_m / 5;
				int s = sum_s / sz;
				if (m == 0)
					continue;
				if (Only_angle || Only_Diagonal) {
					for (int d = 0; d < 8; d += 2) 
						new_atom.push_back({ i,j,m,s,d });
				}
				else {
					for (int d = 1; d < 8; d += 2)
						new_atom.push_back({ i,j,m,s,d });
				}
			}
			else if(sz == 1){
				new_atom.push_back(visited[i][j][0]);
			}
		}
	}

	atom = new_atom;
}

int GetSum() {
	int sum = 0;

	int sz = atom.size();
	for (int i = 0; i < sz; ++i) {
		sum += atom[i].m;
	}

	return sum;
}
int main(void) {
	cin >> n >> m >> k;
	atom = vector<Atom>(m);
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		atom[i] = { y-1,x-1,m,s,d };
	}

	for (int i = 0; i < k; ++i) {
		Move();
		Combine();
	}

	cout << GetSum() << "\n";
}