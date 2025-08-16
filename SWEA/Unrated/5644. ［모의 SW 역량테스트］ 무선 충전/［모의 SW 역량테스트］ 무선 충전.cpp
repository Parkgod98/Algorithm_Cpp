#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, A; // 총 이동시간(M), BC의 개수(A)
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int sum = 0;
struct Point {
	int y, x;
};
struct BC{
	int y,x;
	int coverage;
	int battery;
};
vector<Point> a_path, b_path;
vector<BC> bc_list;

void Input() {
	cin >> M >> A;
	int sy, sx;
	sy = sx = 0;
	
	a_path = vector<Point>(M+1);
	a_path[0] = { sy,sx };
	for (int i = 1; i <= M; ++i) {
		int dir;
		cin >> dir;
		--dir;
		if (dir == -1) {
			a_path[i] = { sy,sx };
		}
		else {
			sy += dy[dir];
			sx += dx[dir];
			a_path[i] = { sy,sx };
		}
	}

	b_path = vector<Point>(M+1);
	sy = sx = 9;
	b_path[0] = { sy,sx };
	for (int i = 1; i <= M; ++i) {
		int dir;
		cin >> dir;
		--dir;
		if (dir == -1) {
			b_path[i] = { sy,sx };
		}
		else {
			sy += dy[dir];
			sx += dx[dir];
			b_path[i] = { sy,sx };
		}
	}

	bc_list = vector<BC>(A);
	for (int i = 0; i < A; ++i) {
		int x, y, C, P;
		cin >> x >> y >> C >> P;
		bc_list[i] = { y-1,x-1,C,P };
	}

	sum = 0;
}

void Charge(int time) {
	vector<int> visited(A);
	int ay = a_path[time].y;
	int ax = a_path[time].x;

	int by = b_path[time].y;
	int bx = b_path[time].x;

	for (int i = 0; i < A; ++i) {
		BC bc = bc_list[i];
		int bc_y = bc.y;
		int bc_x = bc.x;
		int limit = bc.coverage;

		int a_dist = abs(bc_y - ay) + abs(bc_x - ax);
		int b_dist = abs(bc_y - by) + abs(bc_x - bx);

		if (a_dist <= limit)
			visited[i] += 1;
		if (b_dist <= limit)
			visited[i] += 2;
	}

	vector<int> a, b, c;
	for (int i = 0; i < A; ++i) {
		if (visited[i] == 3)
			c.push_back(i);
	}
	int a_mx, b_mx, t_mx, two_mx;
	a_mx = b_mx = t_mx = two_mx = 0;
	for (int i = 0; i < A; ++i) {
		if (visited[i] == 1 && a_mx < bc_list[i].battery)
			a_mx = bc_list[i].battery;
		if (visited[i] == 2 && b_mx < bc_list[i].battery)
			b_mx = bc_list[i].battery;
	}
	for (int i = 0; i < c.size(); ++i) {
		t_mx = max(t_mx, bc_list[c[i]].battery);
		for (int j = i+1; j < c.size(); ++j) {
			if (two_mx < bc_list[c[i]].battery + bc_list[c[j]].battery)
				two_mx = bc_list[c[i]].battery + bc_list[c[j]].battery;
		}
	}

	int c1 = a_mx + b_mx;
	int c2 = t_mx + b_mx;
	int c3 = a_mx + t_mx;
	int c4 = two_mx;
	sum += max(max(c1, c2), max(c3, c4));

}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();

		int st = 0;
		int prev = 0;
		while (st <= M) {
			Charge(st);
			++st;
			//cout << sum - prev << "\n";
			//prev = sum;
		}
		cout << "#" << tc << " " << sum << "\n";
	}
}
