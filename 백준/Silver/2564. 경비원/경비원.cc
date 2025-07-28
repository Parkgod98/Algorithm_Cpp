#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

struct info {
	int d;
	int y, x;
};

int main() {
	cin >> M >> N;

	int num;
	cin >> num;

	vector<info> v(num);
	for (int i = 0; i < num; ++i) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			v[i] = { 1,0,b };
		}
		else if (a == 2) {
			v[i] = { 2,N,b };
		}
		else if (a == 3) {
			v[i] = { 3,b,0 };
		}
		else {
			v[i] = { 4,b,M };
		}
	}

	info dg;
	int a, b;
	cin >> a >> b;
	if (a == 1) {
		dg = { 1,0,b };
	}
	else if (a == 2) {
		dg = { 2,N,b };
	}
	else if (a == 3) {
		dg = { 3,b,0 };
	}
	else {
		dg = { 4, b,M };
	}

	int sum = 0;
	int sz = 2*N + 2*M;
	for (int i = 0; i < num; ++i) {
		int d = v[i].d;
		int y = v[i].y;
		int x = v[i].x;

		int sd = dg.d;
		int sy = dg.y;
		int sx = dg.x;

		int right = 0;
		int left = 0;
		if (d == sd) {
			sum += (abs(y - sy) + abs(x - sx));
		}
		else {
			if (sd == 1 && (d == 3 || d == 4) ||(sd == 2 &&(d ==3||d==4)) || (sd == 3 && (d == 1 || d == 2)) || (sd == 4 && (d == 1 || d == 2))) {
				right = (abs(y - sy) + abs(x - sx));
				left = sz - right;
			}
			else if ((sd == 1 && d == 2) || (sd == 2 && d == 1)) {
				right = abs(sx + N + x);
				left = sz - right;
			}
			else if ((sd == 3 && d == 4) || (sd == 4 && d == 3)) {
				right = abs(M + sy + y);
				left = sz - right;
			}
			sum += min(right, left);
		}
	}

	cout << sum << "\n";
}